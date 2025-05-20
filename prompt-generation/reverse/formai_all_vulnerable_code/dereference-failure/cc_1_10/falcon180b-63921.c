//Falcon-180B DATASET v1.0 Category: Chat server ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket;
    int client_socket;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    socklen_t client_addr_size;
    char buffer[BUFFER_SIZE];

    if (argc!= 2) {
        printf("Usage: %s <port_number>\n", argv[0]);
        exit(1);
    }

    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket: %s\n", strerror(errno));
        exit(1);
    }

    if (listen(server_socket, 5) == -1) {
        printf("Error listening on socket: %s\n", strerror(errno));
        exit(1);
    }

    printf("Server started on port %s\n", argv[1]);

    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_size);

        if (client_socket == -1) {
            printf("Error accepting connection: %s\n", strerror(errno));
            continue;
        }

        printf("Client connected with IP address: %s and port number: %d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            memset(buffer, 0, BUFFER_SIZE);

            if (recv(client_socket, buffer, BUFFER_SIZE, 0) == 0) {
                printf("Client disconnected\n");
                close(client_socket);
                break;
            }

            printf("Message received from client: %s\n", buffer);

            if (send(client_socket, buffer, strlen(buffer), 0) == -1) {
                printf("Error sending message to client: %s\n", strerror(errno));
                break;
            }
        }
    }

    close(server_socket);
    return 0;
}