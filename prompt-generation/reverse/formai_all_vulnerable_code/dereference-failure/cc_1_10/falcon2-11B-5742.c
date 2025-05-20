//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <netdb.h>
#include <pthread.h>

int main(int argc, char **argv) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;
    int newsockfd;

    if (argc < 2) {
        fprintf(stderr, "usage: %s port\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[1]);

    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "no such host\n");
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(0);
    }

    printf("connected to server\n");

    while (1) {
        bzero((char *) &cli_addr, sizeof(cli_addr));
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &n);
        if (newsockfd < 0) {
            perror("accept failed");
            exit(0);
        }

        pid_t pid = fork();
        if (pid == 0) {
            printf("New thread created with PID %d\n", getpid());
            close(sockfd);
            close(newsockfd);
            sleep(5);
            printf("Thread exiting...\n");
            exit(0);
        }
        else {
            close(newsockfd);
            printf("Thread exited with PID %d\n", getpid());
        }
    }

    return 0;
}