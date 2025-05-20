//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <target> <port>\n", argv[0]);
        return 1;
    }

    struct sockaddr_in addr;
    int sockfd, port;
    char buf[256];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &addr.sin_addr) <= 0) {
        perror("inet_pton");
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("connect");
        return 1;
    }

    if (send(sockfd, "GET / HTTP/1.1\r\nHost: " "example.com\r\n\r\n", 73, 0) < 0) {
        perror("send");
        return 1;
    }

    if (recv(sockfd, buf, 256, 0) <= 0) {
        perror("recv");
        return 1;
    }

    printf("Response: %s\n", buf);

    close(sockfd);

    return 0;
}