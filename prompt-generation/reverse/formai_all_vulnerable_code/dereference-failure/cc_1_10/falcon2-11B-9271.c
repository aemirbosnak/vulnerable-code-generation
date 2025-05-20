//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>

void sig_handler(int sig) {
    printf("Signal handler for SIGINT: Exiting\n");
    exit(0);
}

int main(int argc, char **argv) {
    int sockfd, newsockfd, portno, clilen, n;
    struct sockaddr_in serv_addr, cli_addr;
    struct sigaction sa;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);

    if (portno <= 0 || portno > 65535) {
        fprintf(stderr, "Invalid port number\n");
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    sa.sa_handler = sig_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("ERROR setting signal handler");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    if (listen(sockfd, 5) < 0) {
        perror("ERROR on listen");
        exit(1);
    }

    printf("Listening on port %d\n", portno);

    while (1) {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }

        pid_t pid = fork();
        if (pid < 0) {
            perror("ERROR on fork");
            exit(1);
        } else if (pid == 0) {
            close(sockfd);
            close(newsockfd);

            dup2(newsockfd, 0);
            dup2(newsockfd, 1);
            dup2(newsockfd, 2);

            close(newsockfd);

            while (1) {
                char buffer[1024];
                n = read(0, buffer, sizeof(buffer));
                if (n <= 0) {
                    break;
                }

                write(1, buffer, n);
            }

            exit(0);
        }
    }

    return 0;
}