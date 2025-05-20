//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <netdb.h>

void die(const char *s) {
    perror(s);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sock, r;
    struct sockaddr_in sa;
    char host[NI_MAXHOST];
    char service[NI_MAXSERV];
    int i, rv;
    struct addrinfo hints, *res;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s host service\n", argv[0]);
        exit(1);
    }

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    rv = getaddrinfo(argv[1], argv[2], &hints, &res);
    if (rv!= 0) {
        die("getaddrinfo");
    }

    sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sock == -1) {
        die("socket");
    }

    r = connect(sock, res->ai_addr, res->ai_addrlen);
    if (r == -1) {
        if (errno == EINPROGRESS) {
            fprintf(stderr, "Connection in progress\n");
            fflush(stderr);
        } else {
            die("connect");
        }
    }

    while (1) {
        char buf[1024];
        int n;

        n = read(sock, buf, sizeof(buf));
        if (n == 0) {
            break;
        } else if (n == -1) {
            if (errno == EINTR) {
                continue;
            } else {
                die("read");
            }
        }

        buf[n] = '\0';
        printf("%.*s", n, buf);
        fflush(stdout);
    }

    close(sock);
    return 0;
}