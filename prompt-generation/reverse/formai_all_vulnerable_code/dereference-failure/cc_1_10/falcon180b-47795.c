//Falcon-180B DATASET v1.0 Category: Networking ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024
#define LISTEN_BACKLOG 10

void error_handling(char *message);

int main(int argc, char **argv) {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    int opt = 1;
    int addrlen = sizeof(struct sockaddr_in);
    char buffer[BUFFER_SIZE];

    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        error_handling("socket failed");
    }

    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        error_handling("bind failed");
    }

    if (listen(server_socket, LISTEN_BACKLOG) == -1) {
        error_handling("listen failed");
    }

    printf("Server is listening on port %s\n", argv[1]);

    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen);
        if (client_socket == -1) {
            error_handling("accept failed");
        }

        printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            memset(buffer, 0, BUFFER_SIZE);
            int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
            if (bytes_received <= 0) {
                break;
            }

            printf("Received: %s\n", buffer);

            send(client_socket, buffer, strlen(buffer), 0);
        }

        close(client_socket);
    }

    close(server_socket);
    return 0;
}

void error_handling(char *message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(1);
}