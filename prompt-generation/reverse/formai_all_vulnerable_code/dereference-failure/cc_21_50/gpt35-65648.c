//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFF_SIZE 4096

int main(int argc, char *argv[]) {

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    int port = atoi(argv[1]);

    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock == -1) {
        perror("ERROR: failed to create server socket");
        exit(1);
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(port),
        .sin_addr = {INADDR_ANY},
        .sin_zero = {0}
    };

    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("ERROR: failed to bind server socket");
        exit(1);
    }

    if (listen(server_sock, 10) == -1) {
        perror("ERROR: failed to listen on server socket");
        exit(1);
    }

    printf("Proxy server running on port %d\n", port);

    while (1) {
        struct sockaddr_in client_addr = {0};
        socklen_t client_addrlen = sizeof(client_addr);
        int client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_addrlen);
        if (client_sock == -1) {
            perror("ERROR: failed to accept client connection");
            continue;
        }

        printf("Client connected from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        char buffer[BUFF_SIZE];
        memset(buffer, 0, BUFF_SIZE);
        if (recv(client_sock, buffer, BUFF_SIZE - 1, 0) == -1) {
            perror("ERROR: failed to receive request from client");
            close(client_sock);
            continue;
        }

        char* request = buffer;
        char* dest_host = NULL;
        int dest_port = 0;
        int i;

        if (strncmp("GET", request, 3) == 0 || strncmp("POST", request, 4) == 0 || strncmp("PUT", request, 3) == 0 || strncmp("DELETE", request, 6) == 0) {
            for (i = 0; request[i] != '\n'; i++) {
                if (strncmp("Host:", &request[i], 5) == 0) {
                    dest_host = strtok(&request[i+6], ":");
                    dest_port = atoi(strtok(NULL, "\r"));
                    break;
                }
            }
        }

        if (dest_host != NULL && dest_port != 0) {
            int dest_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
            if (dest_sock == -1) {
                perror("ERROR: failed to create destination socket");
                close(client_sock);
                continue;
            }

            struct sockaddr_in dest_addr = {
                .sin_family = AF_INET,
                .sin_port = htons(dest_port)
            };
            inet_pton(AF_INET, dest_host, &dest_addr.sin_addr);
            memset(dest_addr.sin_zero, 0, sizeof(dest_addr.sin_zero));

            if (connect(dest_sock, (struct sockaddr *)&dest_addr, sizeof(dest_addr)) == -1) {
                perror("ERROR: failed to connect to destination server");
                close(client_sock);
                close(dest_sock);
                continue;
            }

            int bytes_sent = send(dest_sock, request, strlen(request), 0);
            if (bytes_sent == -1) {
                perror("ERROR: failed to send request to destination server");
                close(client_sock);
                close(dest_sock);
                continue;
            }

            memset(buffer, 0, BUFF_SIZE);
            while (1) {
                int bytes_received = recv(dest_sock, buffer, BUFF_SIZE - 1, 0);
                if (bytes_received == -1) {
                    perror("ERROR: failed to receive response from destination server");
                    close(client_sock);
                    close(dest_sock);
                    break;
                } else if (bytes_received == 0) {
                    break;
                } else {
                    bytes_sent = send(client_sock, buffer, bytes_received, 0);
                    if (bytes_sent == -1) {
                        perror("ERROR: failed to send response to client");
                        close(client_sock);
                        close(dest_sock);
                        break;
                    }
                    memset(buffer, 0, BUFF_SIZE);
                }
            }

            close(dest_sock);
            close(client_sock);
            printf("Connection closed\n");

        } else {
            fprintf(stderr, "ERROR: invalid request format\n");
            close(client_sock);
        }
    }

    return 0;
}