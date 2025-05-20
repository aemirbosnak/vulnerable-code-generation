//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char **argv) {
    int sockfd;
    struct sockaddr_in serveraddr;
    char sendbuf[BUF_SIZE];
    char recvbuf[BUF_SIZE];
    int n;

    if (argc!= 4) {
        printf("Usage: %s <server> <port> <file>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(atoi(argv[2]));
    serveraddr.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1) {
        perror("connect");
        exit(1);
    }

    FILE *fp = fopen(argv[3], "r");
    if (fp == NULL) {
        perror("fopen");
        exit(1);
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, fp))!= -1) {
        if (line[read - 1] == '\n') {
            line[--read] = '\0';
        }

        send(sockfd, line, strlen(line), 0);
        memset(recvbuf, 0, BUF_SIZE);

        n = recv(sockfd, recvbuf, BUF_SIZE - 1, 0);
        if (n <= 0) {
            break;
        }

        printf("Received: %s", recvbuf);
    }

    fclose(fp);
    close(sockfd);

    return 0;
}