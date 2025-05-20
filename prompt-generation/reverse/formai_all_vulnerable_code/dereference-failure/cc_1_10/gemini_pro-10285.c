//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    struct addrinfo hints, *res;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    int status = getaddrinfo(argv[1], "80", &hints, &res);
    if (status != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        return 1;
    }

    int sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    if (connect(sockfd, res->ai_addr, res->ai_addrlen) == -1) {
        perror("connect");
        return 1;
    }

    char buf[] = "HEAD / HTTP/1.1\r\nHost: "
                  "www.kernel.org\r\n\r\n";

    if (send(sockfd, buf, sizeof(buf), 0) == -1) {
        perror("send");
        return 1;
    }

    char response[1024];
    int n = recv(sockfd, response, sizeof(response), 0);
    if (n == -1) {
        perror("recv");
        return 1;
    }

    if (n > 0) {
        printf("Website is up!\n");
    } else {
        printf("Website is down!\n");
    }

    close(sockfd);
    freeaddrinfo(res);
    return 0;
}