//Falcon2-11B DATASET v1.0 Category: Networking ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 5

int main(int argc, char *argv[]) {
    int server_fd, new_socket, client_fd, addrlen;
    struct sockaddr_in server_addr, client_addr;
    struct hostent *server;

    // Create a server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = inet_addr(argv[2]);
    server = gethostbyname(argv[2]);

    if (server == NULL) {
        fprintf(stderr, "Hostname not found\n");
        return 1;
    }

    if (inet_pton(AF_INET, server->h_addr, &server_addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid address\n");
        return 1;
    }

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Bind failed");
        return 1;
    }

    if (listen(server_fd, MAX_CLIENTS) == -1) {
        perror("Listen failed");
        return 1;
    }

    printf("Server listening on %s:%d\n", argv[2], atoi(argv[1]));

    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen)) == -1) {
            perror("Accept failed");
            return 1;
        }

        printf("New client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        if (fork() == 0) {
            close(new_socket);
            while (1) {
                if ((client_fd = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen)) == -1) {
                    perror("Accept failed");
                    return 1;
                }

                printf("New client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
                send(client_fd, "Welcome to the chat!\n", 27, 0);

                while (1) {
                    char buf[256];
                    ssize_t bytes_read;

                    if ((bytes_read = recv(client_fd, buf, sizeof(buf), 0)) <= 0) {
                        if (bytes_read == 0) {
                            printf("Client disconnected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
                            break;
                        } else {
                            perror("Receive failed");
                            return 1;
                        }
                    }

                    printf("Received message: %s\n", buf);

                    if (send(new_socket, buf, bytes_read, 0) == -1) {
                        perror("Send failed");
                        return 1;
                    }
                }
            }
        } else {
            close(new_socket);
            while (1) {
                if ((client_fd = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen)) == -1) {
                    perror("Accept failed");
                    return 1;
                }

                printf("New client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

                while (1) {
                    char buf[256];
                    ssize_t bytes_read;

                    if ((bytes_read = recv(client_fd, buf, sizeof(buf), 0)) <= 0) {
                        if (bytes_read == 0) {
                            printf("Client disconnected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
                            break;
                        } else {
                            perror("Receive failed");
                            return 1;
                        }
                    }

                    printf("Received message: %s\n", buf);

                    if (send(new_socket, buf, bytes_read, 0) == -1) {
                        perror("Send failed");
                        return 1;
                    }
                }
            }
        }
    }
}