//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    char buf[BUF_SIZE];
    struct sockaddr_in servaddr;
    struct hostent *hostinfo;

    if (argc!= 2) {
        printf("Usage: %s <IP Address>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    hostinfo = gethostbyname(argv[1]);
    if (hostinfo == NULL) {
        printf("Host not found\n");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    memcpy(&servaddr.sin_addr, hostinfo->h_addr, hostinfo->h_length);
    servaddr.sin_port = htons(7);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("connect");
        exit(1);
    }

    while (1) {
        memset(buf, 0, BUF_SIZE);
        n = read(sockfd, buf, BUF_SIZE);
        if (n <= 0) {
            printf("Connection closed\n");
            break;
        }
        printf("%s", buf);
    }

    close(sockfd);
    return 0;
}