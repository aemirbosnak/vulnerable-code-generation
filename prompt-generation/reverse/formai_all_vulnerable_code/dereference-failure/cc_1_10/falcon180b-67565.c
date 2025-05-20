//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

#define BUFFER_SIZE 8192

int main(int argc, char *argv[]) {
    int server_socket, client_socket, sock;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];

    if (argc!= 3) {
        printf("Usage: %s <server_address> <port>\n", argv[0]);
        exit(1);
    }

    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server: %s\n", strerror(errno));
        exit(1);
    }

    printf("Connected to server\n");

    while (1) {
        sock = accept(server_socket, (struct sockaddr *)&client_addr, sizeof(client_addr));

        if (sock == -1) {
            printf("Error accepting connection: %s\n", strerror(errno));
            exit(1);
        }

        printf("Accepted connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            ssize_t bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);

            if (bytes_received == -1) {
                printf("Error receiving data: %s\n", strerror(errno));
                exit(1);
            }

            if (bytes_received == 0) {
                printf("Connection closed by client\n");
                break;
            }

            ssize_t bytes_sent = send(server_socket, buffer, bytes_received, 0);

            if (bytes_sent == -1) {
                printf("Error sending data: %s\n", strerror(errno));
                exit(1);
            }
        }

        close(sock);
    }

    close(server_socket);

    return 0;
}