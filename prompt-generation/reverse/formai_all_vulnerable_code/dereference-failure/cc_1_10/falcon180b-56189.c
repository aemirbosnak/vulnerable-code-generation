//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_LINE 1024
#define BACKLOG 10

int main(int argc, char *argv[]) {
    int listen_fd, conn_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;

    if (argc!= 3) {
        printf("Usage: %s <ip> <port>\n", argv[0]);
        exit(1);
    }

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(listen_fd, BACKLOG) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    while (1) {
        addr_size = sizeof(client_addr);
        conn_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &addr_size);

        if (conn_fd == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        char buffer[MAX_LINE];
        memset(buffer, 0, MAX_LINE);

        while (1) {
            int bytes_received = recv(conn_fd, buffer, MAX_LINE, 0);

            if (bytes_received <= 0) {
                printf("Connection closed\n");
                close(conn_fd);
                break;
            }

            send(conn_fd, buffer, strlen(buffer), 0);
        }
    }

    close(listen_fd);
    return 0;
}