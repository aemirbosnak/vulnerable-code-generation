//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAXLINE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in servaddr;
    char sendline[MAXLINE], recvline[MAXLINE];

    if (argc != 3) {
        fprintf(stderr, "usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket error");
        exit(1);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));

    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("inet_pton error");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("connect error");
        exit(1);
    }

    while (1) {
        printf("Enter message to send:");
        if (fgets(sendline, MAXLINE, stdin) == NULL) {
            perror("fgets error");
            exit(1);
        }

        if (send(sockfd, sendline, strlen(sendline), 0) < 0) {
            perror("send error");
            exit(1);
        }

        if (recv(sockfd, recvline, MAXLINE, 0) == 0) {
            perror("recv error");
            exit(1);
        }

        printf("Received message: %s", recvline);
    }

    close(sockfd);
    return 0;
}