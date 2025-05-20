//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <fcntl.h>

#define MAX_LINE_LEN 1024

int main(int argc, char* argv[])
{
    if (argc < 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr*) &servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    char buf[MAX_LINE_LEN];
    while (fgets(buf, MAX_LINE_LEN, stdin) != NULL) {
        if (send(sockfd, buf, strlen(buf), 0) < 0) {
            perror("send");
            exit(EXIT_FAILURE);
        }

        if (recv(sockfd, buf, MAX_LINE_LEN, 0) < 0) {
            perror("recv");
            exit(EXIT_FAILURE);
        }

        printf("%s", buf);
    }

    close(sockfd);
    exit(EXIT_SUCCESS);
}