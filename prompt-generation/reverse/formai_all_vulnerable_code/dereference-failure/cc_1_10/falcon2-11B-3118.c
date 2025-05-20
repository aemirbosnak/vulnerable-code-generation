//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: asynchronous
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>

#define PORT 25

void signal_handler(int signum) {
    printf("Caught signal %d, exiting...\n", signum);
    exit(0);
}

int main() {
    signal(SIGINT, signal_handler);
    signal(SIGTERM, signal_handler);

    struct addrinfo hints, *servinfo, *p;
    int rv, sockfd, n;
    char *host = "smtp.gmail.com";
    char buf[1024];
    struct hostent *server;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(host, NULL, &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype,
            p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }
        break;
    }

    if (p == NULL) {
        fprintf(stderr, "Failed to create socket\n");
        return 1;
    }

    if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
        perror("connect");
        close(sockfd);
        return 1;
    }

    printf("Connected to %s\n", host);

    while (1) {
        memset(buf, 0, sizeof(buf));
        printf("SMTP> ");
        fgets(buf, sizeof(buf), stdin);
        send(sockfd, buf, strlen(buf), 0);
        n = recv(sockfd, buf, sizeof(buf), 0);
        buf[n] = '\0';
        printf("Received: %s\n", buf);
    }

    return 0;
}