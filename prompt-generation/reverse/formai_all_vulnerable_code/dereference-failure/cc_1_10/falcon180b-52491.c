//Falcon-180B DATASET v1.0 Category: Chat server ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket, new_socket;
    struct sockaddr_in server_addr, client_addr;
    int opt = 1;
    int addrlen = sizeof(client_addr);
    char buffer[BUFFER_SIZE];

    if (argc!= 2) {
        printf("Usage:./chat_server <port>\n");
        exit(1);
    }

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(server_socket, MAX_CLIENTS) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Server started on port %d\n", atoi(argv[1]));

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        new_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addrlen);

        if (new_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        printf("New client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            memset(buffer, 0, BUFFER_SIZE);
            int bytes_received = recv(new_socket, buffer, BUFFER_SIZE, 0);

            if (bytes_received <= 0) {
                printf("Client disconnected\n");
                close(new_socket);
                break;
            }

            printf("Message from client: %s", buffer);

            send(new_socket, buffer, strlen(buffer), 0);
        }
    }

    return 0;
}