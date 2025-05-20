//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define TRUE 1
#define FALSE 0

int main(int argc, char *argv[]) {
    int server_socket;
    int client_socket;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    char buffer[BUFFER_SIZE];
    int addrlen = sizeof(struct sockaddr_in);
    int opt = 1;
    int read_bytes;
    int sent_bytes;

    if (argc!= 3) {
        printf("Usage: %s <port> <host>\n", argv[0]);
        exit(1);
    }

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    inet_pton(AF_INET, argv[2], &server_addr.sin_addr);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(struct sockaddr_in)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(server_socket, 10) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    while (TRUE) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addrlen);
        if (client_socket == -1) {
            printf("Error accepting connection\n");
            exit(1);
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (TRUE) {
            memset(buffer, 0, BUFFER_SIZE);
            read_bytes = recv(client_socket, buffer, BUFFER_SIZE, 0);
            if (read_bytes <= 0) {
                printf("Client disconnected\n");
                break;
            }

            sent_bytes = send(server_socket, buffer, read_bytes, 0);
            if (sent_bytes <= 0) {
                printf("Server disconnected\n");
                break;
            }
        }

        close(client_socket);
    }

    close(server_socket);
    return 0;
}