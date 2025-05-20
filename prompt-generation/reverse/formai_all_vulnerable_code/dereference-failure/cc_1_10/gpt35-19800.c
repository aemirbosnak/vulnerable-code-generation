//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAXLINE 4096

void error(char *msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char **argv) {
    int sockfd, n;
    char recvline[MAXLINE + 1];
    struct sockaddr_in servaddr;

    if (argc != 3) {
        error("usage: ./imap_client <IPaddress> <port>");
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error("socket error");
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        error("inet_pton error");
    }

    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        error("connect error");
    }

    char buf[4096];
    sprintf(buf, "LOGIN %s %s", "username", "password");

    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        error("send error");
    }

    n = recv(sockfd, recvline, MAXLINE, 0);
    if (n < 0) {
        error("recv error");
    }
    recvline[n] = 0; /* null terminate */
    printf("Server response: %s\n", recvline);

    sprintf(buf, "SELECT INBOX");

    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        error("send error");
    }

    n = recv(sockfd, recvline, MAXLINE, 0);
    if (n < 0) {
        error("recv error");
    }
    recvline[n] = 0; /* null terminate */
    printf("Server response: %s\n", recvline);

    sprintf(buf, "FETCH 1:10");

    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        error("send error");
    }

    n = recv(sockfd, recvline, MAXLINE, 0);
    if (n < 0) {
        error("recv error");
    }
    recvline[n] = 0; /* null terminate */
    printf("Server response: %s\n", recvline);

    exit(0);
}