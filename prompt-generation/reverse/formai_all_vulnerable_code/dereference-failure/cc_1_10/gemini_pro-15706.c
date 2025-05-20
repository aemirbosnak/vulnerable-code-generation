//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>

#define MAXLINE 1024
#define LISTENQ 1024

int main(int argc, char **argv) {
    int listenfd, connfd;
    struct sockaddr_in servaddr;
    char buff[MAXLINE];

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IPaddress> <Port>\n", argv[0]);
        exit(1);
    }

    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket error");
        exit(1);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(atoi(argv[2]));

    if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("bind error");
        exit(1);
    }

    if (listen(listenfd, LISTENQ) == -1) {
        perror("listen error");
        exit(1);
    }

    for (;;) {
        if ((connfd = accept(listenfd, (struct sockaddr *)NULL, NULL)) == -1) {
            perror("accept error");
            continue;
        }

        while (read(connfd, buff, MAXLINE) > 0) {
            if (strstr(buff, "DROP") != NULL) {
                printf("Dropping packet\n");
                close(connfd);
                break;
            } else {
                printf("Allowing packet\n");
                write(connfd, buff, strlen(buff));
            }
        }

        close(connfd);
    }

    exit(0);
}