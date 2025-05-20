//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <listen_port> <destination_address:destination_port>\n", argv[0]);
        return -1;
    }

    // Parse arguments
    char *listen_port_str = argv[1];
    char *dst_addr_str = argv[2];

    char *colon_pos = strchr(dst_addr_str, ':');
    if (colon_pos == NULL) {
        printf("Invalid destination address: '%s'\n", dst_addr_str);
        return -1;
    }

    char dst_addr[32];
    strncpy(dst_addr, dst_addr_str, colon_pos - dst_addr_str);
    dst_addr[colon_pos - dst_addr_str] = '\0';

    char *dst_port_str = colon_pos + 1;
    int dst_port = atoi(dst_port_str);

    // Create listening socket
    int listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock < 0) {
        perror("Failed to create listening socket");
        return -1;
    }

    // Bind to listen port
    struct sockaddr_in listen_addr;
    memset(&listen_addr, 0, sizeof(listen_addr));
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_port = htons(atoi(listen_port_str));
    listen_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(listen_sock, (struct sockaddr *)&listen_addr, sizeof(listen_addr)) < 0) {
        perror("Failed to bind listening socket");
        return -1;
    }

    // Start listening
    if (listen(listen_sock, 5) < 0) {
        perror("Failed to start listening");
        return -1;
    }

    // Accept incoming connections
    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);

        int client_sock = accept(listen_sock, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_sock < 0) {
            perror("Failed to accept incoming connection");
            continue;
        }

        printf("Accepted incoming connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Fork new process to handle connection
        pid_t pid = fork();
        if (pid < 0) {
            perror("Failed to fork");
            continue;
        }

        if (pid == 0) {  // Child process
            // Create socket to destination server
            int dst_sock = socket(AF_INET, SOCK_STREAM, 0);
            if (dst_sock < 0) {
                perror("Failed to create socket to destination server");
                exit(1);
            }

            // Connect to destination server
            struct sockaddr_in dst_addr_struct;
            memset(&dst_addr_struct, 0, sizeof(dst_addr_struct));
            dst_addr_struct.sin_family = AF_INET;
            dst_addr_struct.sin_port = htons(dst_port);
            dst_addr_struct.sin_addr.s_addr = inet_addr(dst_addr);

            if (connect(dst_sock, (struct sockaddr *)&dst_addr_struct, sizeof(dst_addr_struct)) < 0) {
                perror("Failed to connect to destination server");
                exit(1);
            }

            // Start proxying data between client and destination server
            char buffer[BUFFER_SIZE];

            while (1) {
                // Wait for data from client or destination server
                fd_set readfds;
                FD_ZERO(&readfds);
                FD_SET(client_sock, &readfds);
                FD_SET(dst_sock, &readfds);

                int max_fd = (client_sock > dst_sock ? client_sock : dst_sock);

                if (select(max_fd + 1, &readfds, NULL, NULL, NULL) < 0) {
                    perror("Error in select");
                    exit(1);
                }

                // Forward data from client to destination server
                if (FD_ISSET(client_sock, &readfds)) {
                    int n = recv(client_sock, buffer, BUFFER_SIZE, 0);
                    if (n < 0) {
                        perror("Recv from client failed");
                        exit(1);
                    }

                    if (n == 0) {
                        printf("Connection closed by client\n");
                        break;
                    }

                    if (send(dst_sock, buffer, n, 0) < 0) {
                        perror("Send to destination server failed");
                        exit(1);
                    }
                }

                // Forward data from destination server to client
                if (FD_ISSET(dst_sock, &readfds)) {
                    int n = recv(dst_sock, buffer, BUFFER_SIZE, 0);
                    if (n < 0) {
                        perror("Recv from destination server failed");
                        exit(1);
                    }

                    if (n == 0) {
                        printf("Connection closed by destination server\n");
                        break;
                    }

                    if (send(client_sock, buffer, n, 0) < 0) {
                        perror("Send to client failed");
                        exit(1);
                    }
                }
            }

            // Close sockets and exit child process
            close(client_sock);
            close(dst_sock);
            exit(0);
        }

        close(client_sock);  // Parent process
    }

    return 0;
}