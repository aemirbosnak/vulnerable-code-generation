//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int listen_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];

    if (argc!= 3) {
        printf("Usage: %s <port> <ip>\n", argv[0]);
        exit(1);
    }

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    inet_pton(AF_INET, argv[2], &server_addr.sin_addr);

    if (bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(listen_fd, 5) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Proxy server started on port %s\n", argv[1]);

    while (1) {
        client_fd = accept(listen_fd, (struct sockaddr *)&client_addr, sizeof(client_addr));
        if (client_fd == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            memset(buffer, 0, BUFFER_SIZE);
            int bytes_received = recv(client_fd, buffer, BUFFER_SIZE, 0);

            if (bytes_received == 0) {
                printf("Client disconnected\n");
                close(client_fd);
                break;
            } else if (bytes_received == -1) {
                printf("Error receiving data\n");
                close(client_fd);
                break;
            }

            send(client_fd, buffer, bytes_received, 0);
        }
    }

    close(listen_fd);
    return 0;
}