//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int listenfd, connfd, len;
    struct sockaddr_in serv_addr, cli_addr;
    int yes = 1;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd < 0) {
        perror("socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));

    if (bind(listenfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(listenfd, 5) < 0) {
        perror("listen");
        exit(1);
    }

    while (1) {
        connfd = accept(listenfd, (struct sockaddr *) &cli_addr, (socklen_t *) &len);
        if (connfd < 0) {
            perror("accept");
            continue;
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        // Handle incoming request here

        close(connfd);
    }

    return 0;
}