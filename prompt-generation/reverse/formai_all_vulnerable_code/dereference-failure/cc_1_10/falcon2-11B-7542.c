//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>

void sig_handler(int signo) {
    fprintf(stderr, "Ping test terminated by signal %d.\n", signo);
    exit(signo);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        exit(1);
    }

    int sock;
    struct addrinfo hints, *servinfo, *p;
    struct sockaddr_in serv_addr;
    int rv;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(argv[1], "80", &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if ((sock = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }

        if (connect(sock, p->ai_addr, p->ai_addrlen) == -1) {
            perror("connect");
            close(sock);
            continue;
        }

        char msg[100];
        sprintf(msg, "PING %s\r\n", argv[1]);
        write(sock, msg, strlen(msg));

        if (read(sock, msg, 100)!= -1) {
            printf("%s\n", msg);
        }

        close(sock);
    }

    freeaddrinfo(servinfo);

    return 0;
}