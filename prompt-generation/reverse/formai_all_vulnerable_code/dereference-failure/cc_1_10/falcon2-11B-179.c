//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <host>\n", argv[0]);
        return 1;
    }

    char host[NI_MAXHOST];
    getnameinfo(argv[1], strlen(argv[1]), host, NI_MAXHOST, NULL, 0, NI_NUMERICHOST);

    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    struct addrinfo *result, *rp;
    int rv = getaddrinfo(host, "80", &hints, &result);
    if (rv!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    for (rp = result; rp!= NULL; rp = rp->ai_next) {
        int sockfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        if (sockfd < 0) {
            continue;
        }

        rv = connect(sockfd, rp->ai_addr, rp->ai_addrlen);
        if (rv < 0) {
            close(sockfd);
            continue;
        }

        char buf[256];
        int n = read(sockfd, buf, sizeof(buf));
        if (n < 0) {
            close(sockfd);
            continue;
        }

        printf("%s", buf);
        close(sockfd);
        break;
    }

    freeaddrinfo(result);

    return 0;
}