//Falcon2-11B DATASET v1.0 Category: Website Uptime Monitor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <fcntl.h>

#define TIMEOUT 5
#define HOSTNAME "www.example.com"
#define PORT 80

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <timeout>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int timeout = atoi(argv[1]);

    struct addrinfo hints, *res;
    int status;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    status = getaddrinfo(HOSTNAME, NULL, &hints, &res);
    if (status!= 0) {
        fprintf(stderr, "Error: %s\n", gai_strerror(status));
        exit(EXIT_FAILURE);
    }

    int sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd < 0) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    struct timeval tv;
    tv.tv_sec = 0;
    tv.tv_usec = timeout * 1000000;

    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof tv) < 0) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, res->ai_addr, res->ai_addrlen) < 0) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    int numbytes;
    char buf[1024];
    int rv;
    while (1) {
        rv = read(sockfd, buf, sizeof buf);
        if (rv < 0) {
            fprintf(stderr, "Error: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }

        if (rv == 0) {
            fprintf(stderr, "Error: connection closed\n");
            exit(EXIT_FAILURE);
        } else if (rv == 1) {
            fprintf(stderr, "Connection successful!\n");
            exit(EXIT_SUCCESS);
        }
    }

    close(sockfd);

    freeaddrinfo(res);

    return 0;
}