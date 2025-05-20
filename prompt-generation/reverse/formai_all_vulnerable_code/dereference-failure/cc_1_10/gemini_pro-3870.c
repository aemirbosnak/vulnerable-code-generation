//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

#define BUFLEN 512

int main(int argc, char **argv) {
    int sockfd, n;
    char buf[BUFLEN];
    struct sockaddr_in servaddr;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <ip address> <port number>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
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

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("connect");
        exit(1);
    }

    while (1) {
        memset(buf, 0, BUFLEN);
        printf("ftp> ");
        fgets(buf, BUFLEN, stdin);
        if (strncmp(buf, "quit", 4) == 0) {
            break;
        }
        if (send(sockfd, buf, strlen(buf), 0) == -1) {
            perror("send");
            exit(1);
        }
        if (recv(sockfd, buf, BUFLEN, 0) == -1) {
            perror("recv");
            exit(1);
        }
        printf("%s", buf);
    }

    close(sockfd);
    return 0;
}