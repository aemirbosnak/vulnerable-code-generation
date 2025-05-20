//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_LINE 1024
#define BACKLOG 10

int main(int argc, char **argv) {
    int listen_fd, conn_fd, client_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[MAX_LINE];
    int addrlen = sizeof(client_addr);
    int opt = 1;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <port> <ip>\n", argv[0]);
        exit(1);
    }

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        fprintf(stderr, "Error creating socket\n");
        exit(1);
    }

    setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    inet_pton(AF_INET, argv[2], &server_addr.sin_addr);

    if (bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Error binding socket\n");
        exit(1);
    }

    if (listen(listen_fd, BACKLOG) == -1) {
        fprintf(stderr, "Error listening on socket\n");
        exit(1);
    }

    while (1) {
        conn_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &addrlen);
        if (conn_fd == -1) {
            fprintf(stderr, "Error accepting connection\n");
            continue;
        }

        printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            memset(buffer, 0, MAX_LINE);
            if (recv(conn_fd, buffer, MAX_LINE, 0) <= 0) {
                fprintf(stderr, "Error reading from socket\n");
                break;
            }

            printf("Received: %s", buffer);

            if (send(conn_fd, buffer, strlen(buffer), 0) <= 0) {
                fprintf(stderr, "Error writing to socket\n");
                break;
            }
        }

        close(conn_fd);
    }

    close(listen_fd);
    return 0;
}