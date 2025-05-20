//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFSIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n, port;
    struct sockaddr_in servaddr;
    char sendline[BUFFSIZE], recvline[BUFFSIZE];

    if (argc != 3) {
        printf("usage: %s <ip address> <port>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    port = atoi(argv[2]);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("connect");
        exit(1);
    }

    while (1) {
        printf("ftp> ");
        fgets(sendline, BUFFSIZE, stdin);

        if (!strcmp(sendline, "quit\n")) {
            break;
        }

        n = write(sockfd, sendline, strlen(sendline));
        if (n == -1) {
            perror("write");
            exit(1);
        }

        n = read(sockfd, recvline, BUFFSIZE);
        if (n == -1) {
            perror("read");
            exit(1);
        }

        printf("%s", recvline);
    }

    close(sockfd);
    exit(0);
}