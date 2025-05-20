//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: systematic
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>

#define MAXLINE 4096

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    int sockfd;
    struct sockaddr_in servaddr;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));

    struct hostent *hp;
    if ((hp = gethostbyname(argv[1])) == NULL) {
        perror("gethostbyname");
        exit(1);
    }

    bzero(&servaddr.sin_addr, sizeof(servaddr.sin_addr));
    memcpy(&servaddr.sin_addr, hp->h_addr_list[0], hp->h_length);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(1);
    }

    char buf[MAXLINE];
    int n;

    while ((n = read(sockfd, buf, MAXLINE)) > 0) {
        if (write(1, buf, n) < 0) {
            perror("write");
            exit(1);
        }
    }
    if (n < 0) {
        perror("read");
        exit(1);
    }

    close(sockfd);
    return 0;
}