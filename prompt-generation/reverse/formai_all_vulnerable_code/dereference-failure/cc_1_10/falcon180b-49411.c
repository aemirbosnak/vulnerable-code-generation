//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUF_SIZE 8192
#define BACKLOG 10

int main(int argc, char *argv[]) {
    int listen_fd, conn_fd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUF_SIZE];
    int n;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <port> <hostname>\n", argv[0]);
        exit(1);
    }

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (listen_fd == -1) {
        fprintf(stderr, "Error opening socket: %s\n", strerror(errno));
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    inet_pton(AF_INET, argv[2], &server_addr.sin_addr);

    if (bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Error binding socket: %s\n", strerror(errno));
        exit(1);
    }

    if (listen(listen_fd, BACKLOG) == -1) {
        fprintf(stderr, "Error listening on socket: %s\n", strerror(errno));
        exit(1);
    }

    printf("Proxy server started on port %d\n", atoi(argv[1]));

    while (1) {
        socklen_t client_len;
        conn_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &client_len);

        if (conn_fd == -1) {
            fprintf(stderr, "Error accepting connection: %s\n", strerror(errno));
            continue;
        }

        printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while ((n = read(conn_fd, buffer, BUF_SIZE)) > 0) {
            write(STDOUT_FILENO, buffer, n);
        }

        close(conn_fd);
    }

    return 0;
}