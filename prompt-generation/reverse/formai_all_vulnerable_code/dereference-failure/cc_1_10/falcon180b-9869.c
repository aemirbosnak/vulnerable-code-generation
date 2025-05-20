//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_PORTS 65535

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s <hostname/IP> <port range>\n", argv[0]);
        exit(1);
    }

    char *hostname = argv[1];
    char *port_range = argv[2];

    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    int rv = getaddrinfo(hostname, NULL, &hints, &res);
    if (rv!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
    }

    for (int i = 1; i <= MAX_PORTS; i++) {
        if (i < atoi(port_range))
            continue;
        if (i > atoi(port_range))
            break;

        int sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
        if (sock == -1) {
            perror("socket");
            continue;
        }

        struct sockaddr_in addr;
        memcpy(&addr, res->ai_addr, res->ai_addrlen);
        addr.sin_port = htons(i);

        if (connect(sock, (struct sockaddr *)&addr, res->ai_addrlen) == 0) {
            printf("Port %d is open.\n", i);
            close(sock);
        } else if (errno == ECONNREFUSED) {
            printf("Port %d is closed.\n", i);
        } else {
            perror("connect");
        }
    }

    freeaddrinfo(res);
    return 0;
}