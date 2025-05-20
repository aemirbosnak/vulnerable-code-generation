//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket, client_socket;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr, client_addr;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <IP address> <port number>\n", argv[0]);
        exit(1);
    }

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Error binding socket: %s\n", strerror(errno));
        exit(1);
    }

    if (listen(server_socket, 5) == -1) {
        fprintf(stderr, "Error listening on socket: %s\n", strerror(errno));
        exit(1);
    }

    printf("Server is listening on %s:%d\n", argv[1], atoi(argv[2]));

    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, sizeof(client_addr));
        if (client_socket == -1) {
            fprintf(stderr, "Error accepting connection: %s\n", strerror(errno));
            continue;
        }

        printf("Client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            memset(buffer, 0, BUFFER_SIZE);
            if (recv(client_socket, buffer, BUFFER_SIZE, 0) <= 0) {
                fprintf(stderr, "Error receiving data: %s\n", strerror(errno));
                break;
            }

            printf("Received message: %s\n", buffer);

            if (send(client_socket, buffer, strlen(buffer), 0) <= 0) {
                fprintf(stderr, "Error sending data: %s\n", strerror(errno));
                break;
            }
        }

        close(client_socket);
    }

    close(server_socket);
    return 0;
}