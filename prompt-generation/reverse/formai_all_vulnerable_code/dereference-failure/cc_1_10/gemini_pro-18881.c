//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFSIZE 1024

int main(int argc, char **argv) {
    int sockfd, n;
    struct sockaddr_in servaddr;
    char sendline[BUFSIZE], recvline[BUFSIZE];

    if (argc != 3) {
        fprintf(stderr, "usage: %s <IP address> <port>\n", argv[0]);
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(argv[1]);
    servaddr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(1);
    }

    while ((n = read(sockfd, recvline, BUFSIZE)) > 0) {
        printf("%s", recvline);
        bzero(recvline, BUFSIZE);
    }

    if (n < 0) {
        perror("read");
        exit(1);
    }

    close(sockfd);

    return 0;
}