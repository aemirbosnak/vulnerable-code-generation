//Falcon2-11B DATASET v1.0 Category: Building a HTTP Client ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    char *host = argv[1];
    char *port = argv[2];

    int sockfd;
    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(host);
    servaddr.sin_port = htons(atoi(port));

    int n = connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    if (n < 0) {
        perror("connect");
        exit(1);
    }

    char request[1024];
    snprintf(request, sizeof(request), "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", host);
    write(sockfd, request, strlen(request));

    char response[1024];
    int len = read(sockfd, response, sizeof(response));
    if (len < 0) {
        perror("read");
        exit(1);
    }

    printf("Response:\n%s", response);

    close(sockfd);
    return 0;
}