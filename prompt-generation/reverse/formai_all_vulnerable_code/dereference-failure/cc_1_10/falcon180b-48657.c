//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

void die(const char *s) {
    perror(s);
    exit(1);
}

int main(int argc, char **argv) {
    char *host;
    int port;
    int sock;
    struct addrinfo hints, *servinfo, *p;
    char buffer[BUFFER_SIZE];

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s host port\n", argv[0]);
        return 1;
    }

    host = argv[1];
    port = atoi(argv[2]);

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(host, NULL, &hints, &servinfo)!= 0) {
        die("getaddrinfo");
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        sock = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sock == -1) {
            perror("socket");
            continue;
        }

        if (connect(sock, p->ai_addr, p->ai_addrlen)!= -1) {
            break;
        }

        close(sock);
    }

    if (p == NULL) {
        die("connect");
    }

    fprintf(stdout, "Connected to %s:%d\n", host, port);

    while (fgets(buffer, BUFFER_SIZE, stdin)!= NULL) {
        send(sock, buffer, strlen(buffer), 0);
    }

    close(sock);

    return 0;
}