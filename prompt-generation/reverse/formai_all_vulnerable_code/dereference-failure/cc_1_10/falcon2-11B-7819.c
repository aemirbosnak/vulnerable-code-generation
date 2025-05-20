//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: asynchronous
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

#define BACKLOG 10
#define MAXLINE 1024

void handle_sigpipe(int signo)
{
    perror("Read failed");
    exit(1);
}

void handle_sigint(int signo)
{
    printf("Interrupted by user\n");
    exit(1);
}

int main(int argc, char *argv[])
{
    int listenfd, connfd, n;
    struct sockaddr_in servaddr;
    char buffer[MAXLINE];
    pid_t childpid;

    if (argc < 2) {
        printf("Usage: %s <ip-address>\n", argv[0]);
        return 1;
    }

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd < 0) {
        perror("socket");
        exit(1);
    }

    bzero((char *) &servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
    servaddr.sin_port = htons(atoi(argv[2]));

    if (bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(listenfd, BACKLOG) < 0) {
        perror("listen");
        exit(1);
    }

    while (1) {
        printf("Waiting for connection\n");
        connfd = accept(listenfd, NULL, NULL);
        if (connfd < 0) {
            perror("accept");
            exit(1);
        }

        printf("Connected to client\n");

        signal(SIGPIPE, handle_sigpipe);
        signal(SIGINT, handle_sigint);

        while ((n = read(connfd, buffer, MAXLINE)) > 0) {
            printf("Received: %s\n", buffer);
            write(connfd, "ACK", 3);
        }

        if (n < 0) {
            perror("read");
        } else {
            close(connfd);
        }
    }

    return 0;
}