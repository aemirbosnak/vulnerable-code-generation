//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_LINE 1024
#define BACKLOG 10

int main(int argc, char *argv[]) {
    int listen_fd, conn_fd, port;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len;
    char buffer[MAX_LINE];

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <port> <host>\n", argv[0]);
        exit(1);
    }

    port = atoi(argv[1]);
    inet_pton(AF_INET, argv[2], &server_addr.sin_addr);

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Error binding socket: %s\n", strerror(errno));
        exit(1);
    }

    if (listen(listen_fd, BACKLOG) == -1) {
        fprintf(stderr, "Error listening on socket: %s\n", strerror(errno));
        exit(1);
    }

    fprintf(stdout, "Proxy server started on port %d\n", port);

    while (1) {
        addr_len = sizeof(client_addr);
        conn_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &addr_len);
        if (conn_fd == -1) {
            fprintf(stderr, "Error accepting connection: %s\n", strerror(errno));
            continue;
        }

        fprintf(stdout, "Client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            memset(buffer, 0, MAX_LINE);
            ssize_t bytes_received = recv(conn_fd, buffer, MAX_LINE, 0);
            if (bytes_received <= 0) {
                fprintf(stdout, "Client disconnected\n");
                close(conn_fd);
                break;
            }

            fprintf(stdout, "Received data: %s", buffer);

            ssize_t bytes_sent = send(conn_fd, buffer, bytes_received, 0);
            if (bytes_sent!= bytes_received) {
                fprintf(stdout, "Error sending data: %s\n", strerror(errno));
            }
        }
    }

    close(listen_fd);
    return 0;
}