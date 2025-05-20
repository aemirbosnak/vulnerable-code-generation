//Falcon2-11B DATASET v1.0 Category: Client Server Application ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <signal.h>
#include <pthread.h>
#include <semaphore.h>

#define PORT 8080
#define MAX_SIZE 1024
#define BUF_SIZE 100

void sig_handler(int signo) {
    printf("Caught signal %d\n", signo);
    exit(signo);
}

int main(int argc, char *argv[]) {
    struct sockaddr_in servaddr;
    int servfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[MAX_SIZE];
    char *message = "Hello, World!";
    char *newline = "\n";
    int i = 0;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(portno);

    servfd = socket(AF_INET, SOCK_STREAM, 0);
    if (servfd < 0) {
        perror("socket");
        exit(1);
    }

    if (bind(servfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("bind");
        exit(1);
    }

    listen(servfd, 5);

    clilen = sizeof(servaddr);
    newsockfd = accept(servfd, (struct sockaddr *) &servaddr, &clilen);
    if (newsockfd < 0) {
        perror("accept");
        exit(1);
    }

    while (1) {
        bzero(buffer, MAX_SIZE);
        read(newsockfd, buffer, MAX_SIZE);
        printf("%s", buffer);
        write(newsockfd, message, strlen(message));
        write(newsockfd, newline, 1);
    }

    close(newsockfd);
    return 0;
}