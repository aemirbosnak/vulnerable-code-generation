//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAX_LINE 4096

int main(int argc, char *argv[])
{
    int sockfd, n;
    char recvline[MAX_LINE + 1];
    struct sockaddr_in servaddr;

    if (argc != 3) {
        fprintf(stderr, "usage: %s <ip address> <port>\n", argv[0]);
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));

    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(1);
    }

    char request[MAX_LINE];
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", argv[1]);
    if (write(sockfd, request, strlen(request)) < 0) {
        perror("write");
        exit(1);
    }

    while ((n = read(sockfd, recvline, MAX_LINE)) > 0) {
        recvline[n] = '\0';
        if (fputs(recvline, stdout) == EOF) {
            perror("fputs");
            exit(1);
        }
    }

    if (n < 0) {
        perror("read");
        exit(1);
    }

    close(sockfd);
    exit(0);
}