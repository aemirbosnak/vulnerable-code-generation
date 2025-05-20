//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define BUF_SIZE 65536

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <target_ip>\n", argv[0]);
        return 1;
    }

    struct addrinfo hints, *servinfo, *p;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    int sockfd;
    int ret;

    if ((ret = getaddrinfo(argv[1], NULL, &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(ret));
        return 1;
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd == -1) {
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "Failed to connect to %s\n", argv[1]);
        return 1;
    }

    char buffer[BUF_SIZE];
    int n;

    while ((n = read(sockfd, buffer, BUF_SIZE)) > 0) {
        printf("%s", buffer);
    }

    printf("\n");

    close(sockfd);

    return 0;
}