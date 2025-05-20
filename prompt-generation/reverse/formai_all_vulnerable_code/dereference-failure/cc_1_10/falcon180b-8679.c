//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/time.h>
#include <time.h>

#define MAX_BUFFER 1024

int main(int argc, char *argv[]) {
    int sock;
    struct addrinfo hints, *servinfo, *p;
    char s[INET6_ADDRSTRLEN];
    int rv;
    char buffer[MAX_BUFFER];
    int bytes_sent;
    int bytes_received;
    char *ptr;

    if (argc!= 3) {
        printf("Usage: %s <host> <email>\n", argv[0]);
        return 1;
    }

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(argv[1], "smtp", &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if ((sock = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }

        if (connect(sock, p->ai_addr, p->ai_addrlen) == -1) {
            close(sock);
            perror("connect");
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "failed to connect\n");
        return 1;
    }

    printf("Connected to %s\n", argv[1]);

    snprintf(buffer, MAX_BUFFER, "EHLO %s\r\n", argv[1]);
    send(sock, buffer, strlen(buffer), 0);

    bytes_sent = 0;
    while (bytes_sent < strlen(buffer)) {
        bytes_received = recv(sock, buffer + bytes_sent, MAX_BUFFER - bytes_sent, 0);
        if (bytes_received <= 0) {
            break;
        }
        bytes_sent += bytes_received;
    }

    close(sock);
    return 0;
}