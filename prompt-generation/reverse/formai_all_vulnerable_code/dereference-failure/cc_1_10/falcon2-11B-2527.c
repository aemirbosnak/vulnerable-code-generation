//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <signal.h>
#include <errno.h>
#include <time.h>

int main()
{
    struct addrinfo hints, *servinfo, *p;
    int sockfd, n;
    char *buf = (char *) malloc(1024);
    char *port = "8080";
    char *host = "127.0.0.1";
    char *message = "Hello World";
    int ret;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((ret = getaddrinfo(host, port, &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(ret));
        return 1;
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            perror("connect");
            continue;
        }

        printf("Connected to %s:%s\n", host, port);
        break;
    }

    if (p == NULL) {
        fprintf(stderr, "Failed to connect to any\n");
        return 1;
    }

    while (1) {
        n = read(sockfd, buf, sizeof(buf));
        if (n == -1) {
            perror("read");
            break;
        }

        if (n == 0)
            break;

        write(sockfd, buf, n);
    }

    close(sockfd);
    return 0;
}