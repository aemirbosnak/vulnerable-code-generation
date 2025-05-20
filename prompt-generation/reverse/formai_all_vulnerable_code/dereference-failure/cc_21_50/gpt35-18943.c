//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int server_fd, client_fd, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *bad_request = "HTTP/1.1 400 Bad Request\r\n\r\n";
    char *not_found = "HTTP/1.1 404 Not Found\r\n\r\n";
    char *ok_response = "HTTP/1.1 200 OK\r\n\r\n";
    char *proxy_response = "HTTP/1.1 200 Connection Established\r\n\r\n";

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options to allow reuse of address and port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                   &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Fill sockaddr_in struct with address and port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(atoi(argv[1]));

    // Bind server socket to sockaddr_in struct
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 5) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("HTTP proxy server listening on port %d.\n", atoi(argv[1]));

    while (1) { // Keep listening for incoming connections
        // Accept incoming connection
        if ((client_fd = accept(server_fd, (struct sockaddr *)&address,
                                (socklen_t*)&addrlen)) < 0 ) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        printf("Incoming connection accepted.\n");

        // Read incoming request from client
        if (read(client_fd, buffer, 1024) < 0) {
            perror("read failed");
            exit(EXIT_FAILURE);
        }

        // Extract hostname and port number from request
        char *hostname = strtok(buffer, " ");
        if (hostname == NULL) {
            send(client_fd, bad_request, strlen(bad_request), 0);
            close(client_fd);
            continue;
        }
        if (strcmp(hostname, "CONNECT") == 0) { // For HTTPS requests, tunnel connection
            hostname = strtok(NULL, ":");
            if (hostname == NULL) {
                send(client_fd, bad_request, strlen(bad_request), 0);
                close(client_fd);
                continue;
            }
            int port = atoi(strtok(NULL, " "));
            if (port == 0) {
                send(client_fd, bad_request, strlen(bad_request), 0);
                close(client_fd);
                continue;
            }

            printf("HTTPS tunnel request received for %s:%d.\n", hostname, port);

            // Connect to destination server
            int dest_fd;
            struct sockaddr_in dest_address;
            if ((dest_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
                perror("socket failed");
                exit(EXIT_FAILURE);
            }
            dest_address.sin_family = AF_INET;
            if (inet_pton(AF_INET, hostname, &dest_address.sin_addr) <= 0) {
                perror("inet_pton failed");
                exit(EXIT_FAILURE);
            }
            dest_address.sin_port = htons(port);
            if (connect(dest_fd, (struct sockaddr *)&dest_address, sizeof(dest_address)) < 0) {
                perror("connect failed");
                exit(EXIT_FAILURE);
            }

            printf("Connected to destination server for HTTPS tunnel.\n");

            // Send OK response to client
            send(client_fd, proxy_response, strlen(proxy_response), 0);

            // Start bidirectional data transfer between client and destination server
            while (1) {
                fd_set read_fds;
                FD_ZERO(&read_fds);
                FD_SET(client_fd, &read_fds);
                FD_SET(dest_fd, &read_fds);
                if (select(FD_SETSIZE, &read_fds, NULL, NULL, NULL) < 0) {
                    perror("select failed");
                    exit(EXIT_FAILURE);
                }
                if (FD_ISSET(client_fd, &read_fds)) {
                    valread = read(client_fd, buffer, 1024);
                    if (valread <= 0) {
                        break;
                    }
                    if (write(dest_fd, buffer, valread) < 0) {
                        perror("write failed");
                        exit(EXIT_FAILURE);
                    }
                }
                if (FD_ISSET(dest_fd, &read_fds)) {
                    valread = read(dest_fd, buffer, 1024);
                    if (valread <= 0) {
                        break;
                    }
                    if (write(client_fd, buffer, valread) < 0) {
                        perror("write failed");
                        exit(EXIT_FAILURE);
                    }
                }
            }

            printf("HTTPS tunnel closed.\n");

            close(dest_fd);
        } else { // For HTTP requests, proxy request to destination server
            hostname = strtok(hostname, "//");
            if (hostname == NULL) {
                send(client_fd, bad_request, strlen(bad_request), 0);
                close(client_fd);
                continue;
            }

            char *path = strtok(NULL, " ");
            if (path == NULL) {
                send(client_fd, bad_request, strlen(bad_request), 0);
                close(client_fd);
                continue;
            }

            printf("HTTP request received for %s%s.\n", hostname, path);

            // Connect to destination server
            int dest_fd;
            struct sockaddr_in dest_address;
            if ((dest_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
                perror("socket failed");
                exit(EXIT_FAILURE);
            }
            dest_address.sin_family = AF_INET;
            if (inet_pton(AF_INET, hostname, &dest_address.sin_addr) <= 0) {
                perror("inet_pton failed");
                exit(EXIT_FAILURE);
            }
            dest_address.sin_port = htons(80);
            if (connect(dest_fd, (struct sockaddr *)&dest_address, sizeof(dest_address)) < 0) {
                perror("connect failed");
                exit(EXIT_FAILURE);
            }

            printf("Connected to destination server for HTTP request.\n");

            // Send request to destination server
            char request[1024];
            sprintf(request, "GET %s HTTP/1.1\r\n"
                              "Host: %s\r\n"
                              "\r\n", path, hostname);
            if (write(dest_fd, request, strlen(request)) < 0) {
                perror("write failed");
                exit(EXIT_FAILURE);
            }

            // Receive response from destination server and forward to client
            if (read(dest_fd, buffer, 1024) < 0) {
                perror("read failed");
                exit(EXIT_FAILURE);
            }
            if (strstr(buffer, "404") != NULL) { // Not Found response from server
                send(client_fd, not_found, strlen(not_found), 0);
            } else { // Forward response to client
                send(client_fd, ok_response, strlen(ok_response), 0);
                send(client_fd, buffer, strlen(buffer), 0);
            }

            printf("HTTP request completed.\n");

            close(dest_fd);
        }

        close(client_fd);
    }

    return 0;
}