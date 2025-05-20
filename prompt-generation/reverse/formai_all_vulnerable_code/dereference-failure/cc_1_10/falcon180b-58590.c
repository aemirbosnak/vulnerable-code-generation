//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define MAX_CONNECTIONS 10

int main(int argc, char *argv[]) {
    int server_socket, client_socket, new_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    int addrlen;

    if (argc!= 3) {
        printf("Usage: %s <port> <host>\n", argv[0]);
        return 1;
    }

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    inet_pton(AF_INET, argv[2], &server_addr.sin_addr);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        return 1;
    }

    if (listen(server_socket, MAX_CONNECTIONS) == -1) {
        printf("Error listening on socket\n");
        return 1;
    }

    printf("Proxy server started on port %s\n", argv[1]);

    while (1) {
        addrlen = sizeof(client_addr);
        new_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addrlen);

        if (new_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            memset(buffer, 0, BUFFER_SIZE);
            int bytes_received = recv(new_socket, buffer, BUFFER_SIZE, 0);

            if (bytes_received <= 0) {
                printf("Client disconnected\n");
                break;
            }

            send(new_socket, buffer, bytes_received, 0);
        }

        close(new_socket);
    }

    return 0;
}