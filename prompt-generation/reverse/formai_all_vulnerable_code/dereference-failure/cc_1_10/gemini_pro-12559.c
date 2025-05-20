//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_LINE 8192

int main(int argc, char **argv) {
    int sockfd, port;
    struct sockaddr_in servaddr;
    char sendline[MAX_LINE], recvline[MAX_LINE];

    if (argc != 3) {
        printf("usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    port = atoi(argv[2]);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);

    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(1);
    }

    while (fgets(sendline, MAX_LINE, stdin) != NULL) {
        if (send(sockfd, sendline, strlen(sendline), 0) < 0) {
            perror("send");
            exit(1);
        }

        if (recv(sockfd, recvline, MAX_LINE, 0) == 0) {
            perror("recv");
            exit(1);
        }

        printf("%s", recvline);
    }

    close(sockfd);
    exit(0);
}