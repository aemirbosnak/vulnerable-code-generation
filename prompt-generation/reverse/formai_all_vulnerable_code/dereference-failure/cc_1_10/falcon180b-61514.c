//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define TRUE    1
#define FALSE   0
#define PORT    80
#define MAX     100

int ping(char *hostname, int count);

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <hostname> <count>\n", argv[0]);
        exit(1);
    }

    char *hostname = argv[1];
    int count = atoi(argv[2]);

    if (ping(hostname, count) == TRUE)
        printf("Host %s is alive.\n", hostname);
    else
        printf("Host %s is not alive.\n", hostname);

    return 0;
}

int ping(char *hostname, int count) {
    struct addrinfo hints, *res;
    int sockfd, ret;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    ret = getaddrinfo(hostname, NULL, &hints, &res);
    if (ret!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(ret));
        exit(1);
    }

    for (int i = 0; i < count; i++) {
        sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
        if (sockfd == -1) {
            perror("socket");
            exit(1);
        }

        ret = connect(sockfd, res->ai_addr, res->ai_addrlen);
        if (ret == -1) {
            perror("connect");
            close(sockfd);
            continue;
        }

        char buffer[MAX];
        ret = read(sockfd, buffer, MAX);
        if (ret == -1) {
            perror("read");
            close(sockfd);
            continue;
        }

        close(sockfd);
        if (strstr(buffer, "HTTP/1.1")!= NULL)
            return TRUE;
    }

    return FALSE;
}