//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <netdb.h>

#define BUF_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int listen_fd, client_fd, conn_fd;
    struct sockaddr_in listen_addr, client_addr, conn_addr;
    socklen_t addr_size;
    char buf[BUF_SIZE];
    int n;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1)
        error("socket");

    listen_addr.sin_family = AF_INET;
    listen_addr.sin_port = htons(atoi(argv[1]));
    listen_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(listen_fd, (struct sockaddr *)&listen_addr, sizeof(listen_addr)) == -1)
        error("bind");

    if (listen(listen_fd, 5) == -1)
        error("listen");

    printf("Proxy server started on port %s\n", argv[1]);

    while (1) {
        addr_size = sizeof(client_addr);
        client_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &addr_size);
        if (client_fd == -1)
            error("accept");

        printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            n = recv(client_fd, buf, BUF_SIZE, 0);
            if (n <= 0)
                break;

            send(client_fd, buf, n, 0);
        }

        close(client_fd);
    }

    return 0;
}