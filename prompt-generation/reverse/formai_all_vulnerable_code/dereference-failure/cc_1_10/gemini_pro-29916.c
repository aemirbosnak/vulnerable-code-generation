//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_LINE 1024

int main(int argc, char *argv[])
{
    int sockfd, n;
    char recvline[MAX_LINE + 1];
    struct sockaddr_in servaddr;

    if (argc != 4) {
        fprintf(stderr, "usage: %s <hostname> <port> <message>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    bzero(&servaddr, sizeof(servaddr));
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

    if (write(sockfd, argv[3], strlen(argv[3])) < 0) {
        perror("write");
        exit(1);
    }

    close(sockfd);

    return 0;
}