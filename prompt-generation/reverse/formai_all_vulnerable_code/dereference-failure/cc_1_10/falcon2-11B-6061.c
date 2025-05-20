//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>
#include <getopt.h>

#define DEFAULT_TIMEOUT 5

void usage(char *prog) {
    fprintf(stderr, "Usage: %s [-t timeout] hostname\n", prog);
    fprintf(stderr, "Example: %s -t 10 www.google.com\n", prog);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    int timeout = DEFAULT_TIMEOUT;
    char *hostname = NULL;

    struct option long_options[] = {
        {"timeout", required_argument, NULL, 't'},
        {0, 0, 0, 0}
    };

    int opt;
    while ((opt = getopt_long(argc, argv, "t:h:", long_options, NULL))!= -1) {
        switch (opt) {
            case 't':
                timeout = atoi(optarg);
                break;
            case 'h':
                hostname = optarg;
                break;
            case '?':
                usage(argv[0]);
                break;
            default:
                usage(argv[0]);
        }
    }

    if (optind < argc - 1) {
        usage(argv[0]);
    }

    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_DGRAM;

    struct addrinfo *servinfo, *p;

    int s;
    if ((s = getaddrinfo(hostname, NULL, &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s));
        exit(1);
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if ((s = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }
        if (connect(s, p->ai_addr, p->ai_addrlen) == -1) {
            close(s);
            perror("connect");
            continue;
        }

        char buffer[100];
        memset(buffer, 0, sizeof(buffer));
        if (sendto(s, buffer, 1, 0, p->ai_addr, p->ai_addrlen) == -1) {
            perror("sendto");
            close(s);
            continue;
        }

        if (recvfrom(s, buffer, sizeof(buffer), 0, NULL, NULL) == -1) {
            perror("recvfrom");
            close(s);
            continue;
        }

        printf("Ping to %s: %d ms\n", hostname, (int)buffer[0]);
        close(s);
        break;
    }

    freeaddrinfo(servinfo);

    return 0;
}