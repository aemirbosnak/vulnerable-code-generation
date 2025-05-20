//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void error(char *message) {
    perror(message);
    exit(1);
}

int main(int argc, char *argv[]) {
    int proxy_socket, client_socket, server_socket;
    struct sockaddr_in proxy_addr, client_addr, server_addr;
    char buffer[BUFFER_SIZE];

    if (argc != 3) {
        printf("Usage: %s <proxy_port> <server_port>\n", argv[0]);
        exit(1);
    }

    proxy_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_socket < 0) {
        error("Error creating proxy socket");
    }

    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = INADDR_ANY;
    proxy_addr.sin_port = htons(atoi(argv[1]));

    if (bind(proxy_socket, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr)) < 0) {
        error("Error binding proxy socket");
    }

    listen(proxy_socket, 5);

    while (1) {
        socklen_t client_addr_len = sizeof(client_addr);
        client_socket = accept(proxy_socket, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_socket < 0) {
            error("Error accepting client connection");
        }

        if (fork() == 0) { // child process
            close(proxy_socket);

            server_socket = socket(AF_INET, SOCK_STREAM, 0);
            if (server_socket < 0) {
                error("Error creating server socket");
            }

            server_addr.sin_family = AF_INET;
            server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
            server_addr.sin_port = htons(atoi(argv[2]));

            if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
                error("Error connecting to server");
            }

            // forward request
            while (recv(client_socket, buffer, BUFFER_SIZE, 0) > 0) {
                printf("%s", buffer);
                send(server_socket, buffer, strlen(buffer), 0);
                memset(buffer, 0, BUFFER_SIZE);
            }

            close(client_socket);
            close(server_socket);
            exit(0);
        } else { // parent process
            close(client_socket);
        }
    }

    return 0;
}