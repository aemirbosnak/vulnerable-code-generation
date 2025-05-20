//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>

#define PORT 8080
#define BACKLOG 10
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int listen_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];

    if (argc!= 2) {
        printf("Usage:./server <port_number>\n");
        exit(1);
    }

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(listen_socket, BACKLOG) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Server listening on port %d\n", atoi(argv[1]));

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, sizeof(client_addr));
        if (client_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            memset(buffer, 0, BUFFER_SIZE);
            if (recv(client_socket, buffer, BUFFER_SIZE, 0) <= 0) {
                printf("Client disconnected\n");
                break;
            }

            printf("Received message: %s\n", buffer);

            if (send(client_socket, buffer, strlen(buffer), 0) <= 0) {
                printf("Error sending message\n");
                break;
            }
        }

        close(client_socket);
    }

    close(listen_socket);
    return 0;
}