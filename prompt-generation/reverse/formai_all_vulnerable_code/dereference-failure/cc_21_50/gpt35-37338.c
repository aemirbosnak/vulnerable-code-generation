//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s port\n", argv[0]);
        exit(1);
    }

    int server_fd, client_fd[MAX_CLIENTS], max_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(struct sockaddr_in);
    char buffer[BUFFER_SIZE];

    fd_set read_fds, write_fds, except_fds;

    // Create server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    // Set server address information
    memset((char*) &server_addr, 0, sizeof(struct sockaddr_in));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));

    // Bind server socket to address
    if (bind(server_fd, (struct sockaddr*) &server_addr, sizeof(struct sockaddr_in)) < 0) {
        perror("bind");
        exit(1);
    }

    // Listen for client connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(1);
    }

    // Initialize client file descriptors and set of file descriptors
    for (int i = 0; i < MAX_CLIENTS; i++) {
        client_fd[i] = -1;
    }

    FD_ZERO(&read_fds);
    FD_ZERO(&write_fds);
    FD_ZERO(&except_fds);
    FD_SET(server_fd, &read_fds);

    max_fd = server_fd;

    printf("HTTP Proxy Server running on port %d\n", atoi(argv[1]));

    // Serve clients indefinitely
    while (true) {
        if (select(max_fd + 1, &read_fds, &write_fds, &except_fds, NULL) < 0) {
            perror("select");
            exit(1);
        }

        // Check for new connections
        if (FD_ISSET(server_fd, &read_fds)) {
            int new_client_fd;
            if ((new_client_fd = accept(server_fd, (struct sockaddr*) &client_addr, &addr_len)) < 0) {
                perror("accept");
                continue;
            }

            printf("New client connected: %s\n", inet_ntoa(client_addr.sin_addr));

            // Add new client fd to list of active file descriptors
            bool client_added = false;
            for (int i = 0; i < MAX_CLIENTS; i++) {
                if (client_fd[i] == -1) {
                    client_fd[i] = new_client_fd;
                    FD_SET(client_fd[i], &read_fds);
                    if (client_fd[i] > max_fd) {
                        max_fd = client_fd[i];
                    }
                    client_added = true;
                    break;
                }
            }

            if (!client_added) {
                printf("Client limit exceeded.\n");
                close(new_client_fd);
            }
        }

        // Check for client input
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (FD_ISSET(client_fd[i], &read_fds)) {
                int read_size;
                if ((read_size = recv(client_fd[i], buffer, BUFFER_SIZE, 0)) <= 0) {
                    // Client disconnected
                    printf("Client disconnected: %s\n", inet_ntoa(client_addr.sin_addr));
                    close(client_fd[i]);
                    FD_CLR(client_fd[i], &read_fds);
                    client_fd[i] = -1;
                } else {
                    // Connection alive, send request to target server
                    struct hostent* target = gethostbyname(buffer);
                    struct sockaddr_in target_addr;
                    memset((char*) &target_addr, 0, sizeof(struct sockaddr_in));
                    target_addr.sin_family = AF_INET;
                    memcpy((char*) &target_addr.sin_addr.s_addr,
                           (char*) target->h_addr,
                           target->h_length);
                    target_addr.sin_port = htons(80);

                    int target_fd;
                    if ((target_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
                        perror("socket");
                        exit(1);
                    }

                    if (connect(target_fd, (struct sockaddr*) &target_addr, sizeof(target_addr)) < 0) {
                        perror("connect");
                        exit(1);
                    }

                    printf("Connected to target server: %s\n", buffer);

                    if (send(target_fd, buffer, strlen(buffer), 0) < 0) {
                        perror("send");
                        exit(1);
                    }

                    printf("Request sent to target server:\n%s", buffer);

                    memset(buffer, 0, BUFFER_SIZE);
                    while ((read_size = recv(target_fd, buffer, BUFFER_SIZE, 0)) > 0) {
                        printf("Received response from target server:\n%s", buffer);
                        if (send(client_fd[i], buffer, read_size, 0) < 0) {
                            perror("send");
                            exit(1);
                        }
                        memset(buffer, 0, BUFFER_SIZE);
                    }

                    if (read_size < 0) {
                        perror("recv");
                        exit(1);
                    }

                    printf("Connection to target server closed.\n");

                    close(target_fd);
                }
            }
        }
    }

    return 0;
}