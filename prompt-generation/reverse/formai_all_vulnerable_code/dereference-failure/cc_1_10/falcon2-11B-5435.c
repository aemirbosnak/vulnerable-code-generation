//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int listenfd, connfd, n;
    struct sockaddr_in serv_addr, cli_addr;
    unsigned int serv_addrlen = sizeof(serv_addr);
    char buffer[1024];

    if (argc!= 2) {
        fprintf(stderr, "usage: %s port\n", argv[0]);
        exit(1);
    }

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd < 0) {
        fprintf(stderr, "Error opening socket\n");
        exit(1);
    }

    bzero((char *) &serv_addr, serv_addrlen);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(atoi(argv[1]));

    if (bind(listenfd, (struct sockaddr *) &serv_addr, serv_addrlen) < 0) {
        fprintf(stderr, "Error binding socket\n");
        exit(1);
    }

    if (listen(listenfd, 5) < 0) {
        fprintf(stderr, "Error listening on socket\n");
        exit(1);
    }

    while (1) {
        connfd = accept(listenfd, (struct sockaddr *) &cli_addr, (socklen_t *) &serv_addrlen);
        if (connfd < 0) {
            fprintf(stderr, "Error accepting connection\n");
            exit(1);
        }

        bzero(buffer, 1024);
        n = recv(connfd, buffer, 1024, 0);
        if (n <= 0) {
            fprintf(stderr, "Error reading from socket\n");
            exit(1);
        }

        printf("Connected by %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        send(connfd, buffer, n, 0);

        close(connfd);
    }

    close(listenfd);
    return 0;
}