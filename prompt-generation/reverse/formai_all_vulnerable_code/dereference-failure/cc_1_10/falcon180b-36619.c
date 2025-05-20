//Falcon-180B DATASET v1.0 Category: Networking ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_LINE 1024
#define MAX_HOST 1024
#define MAX_PORT 1024

int main(int argc, char *argv[]) {
    int sock;
    struct addrinfo hints, *servinfo, *p;
    int rv;
    int numbytes;
    char sendline[MAX_LINE];
    char recvline[MAX_LINE];

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo("localhost", "daytime", &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
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
        exit(1);
    }

    while (1) {
        fputs("Enter a string to send: ", stdout);
        fgets(sendline, MAX_LINE, stdin);
        numbytes = strlen(sendline);
        if (send(sock, sendline, numbytes, 0) == -1) {
            perror("send");
            break;
        }

        numbytes = 0;
        while ((numbytes < MAX_LINE - 1) && (rv = recv(sock, recvline + numbytes, MAX_LINE - numbytes - 1, 0)) > 0) {
            numbytes += rv;
        }

        if (rv == -1) {
            perror("recv");
            break;
        }

        recvline[numbytes] = '\0';
        printf("Received: %s\n", recvline);
    }

    close(sock);
    exit(0);
}