//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT_MAX 65535
#define PORT_DEFAULT 80
#define PORT_RANGE 100

int main(int argc, char* argv[]) {
    struct addrinfo hints, *result = NULL, *rp;
    char host[NI_MAXHOST];
    int rv, opt = 1, port = PORT_DEFAULT, count = 0;
    char *ptr;

    if (argc < 2) {
        printf("Usage: %s <IP Address/Domain Name> [-p <port number>]\n", argv[0]);
        return 1;
    }

    strcpy(host, argv[1]);
    ptr = strchr(host, ':');
    if (ptr!= NULL) {
        *ptr = '\0';
        port = atoi(ptr + 1);
    }

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(host, NULL, &hints, &result)!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    for (rp = result; rp!= NULL; rp = rp->ai_next) {
        if (rp->ai_family == AF_INET) {
            if (count == 0) {
                printf("Scanning %s on port %d...\n", host, port);
            }
            count++;
            if (connect(socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol), rp->ai_addr, rp->ai_addrlen) == 0) {
                printf("Port %d is open.\n", port);
            } else {
                printf("Port %d is closed.\n", port);
            }
        }
    }

    freeaddrinfo(result);

    return 0;
}