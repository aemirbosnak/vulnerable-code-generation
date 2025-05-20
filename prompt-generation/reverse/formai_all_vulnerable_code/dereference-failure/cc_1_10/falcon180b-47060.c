//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    struct addrinfo hints, *result, *rp;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    int s = getaddrinfo(argv[1], argv[2], &hints, &result);
    if (s!= 0) {
        error("getaddrinfo");
    }

    for (rp = result; rp!= NULL; rp = rp->ai_next) {
        s = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        if (s == -1) {
            continue;
        }

        break;
    }

    if (rp == NULL) {
        error("socket");
    }

    if (connect(s, rp->ai_addr, rp->ai_addrlen) == -1) {
        error("connect");
    }

    char buffer[BUFFER_SIZE];
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        if (fgets(buffer, BUFFER_SIZE, stdin) == NULL) {
            break;
        }

        send(s, buffer, strlen(buffer), 0);

        if (recv(s, buffer, BUFFER_SIZE, 0) <= 0) {
            break;
        }

        printf("%s", buffer);
    }

    close(s);
    freeaddrinfo(result);

    return 0;
}