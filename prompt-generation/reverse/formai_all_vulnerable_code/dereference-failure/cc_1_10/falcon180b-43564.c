//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_HOST_NAME 256
#define TIMEOUT_SEC 5
#define TIMEOUT_USEC 0

void print_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        return 1;
    }

    struct addrinfo hints, *result, *rp;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    int gai_error = getaddrinfo(argv[1], NULL, &hints, &result);
    if (gai_error!= 0) {
        print_error("getaddrinfo");
    }

    for (rp = result; rp!= NULL; rp = rp->ai_next) {
        int sockfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        if (sockfd == -1) {
            continue;
        }

        if (connect(sockfd, rp->ai_addr, rp->ai_addrlen)!= -1) {
            printf("Host is reachable\n");
            close(sockfd);
            freeaddrinfo(result);
            return 0;
        } else if (errno!= ECONNREFUSED) {
            close(sockfd);
        }
    }

    freeaddrinfo(result);
    return 1;
}