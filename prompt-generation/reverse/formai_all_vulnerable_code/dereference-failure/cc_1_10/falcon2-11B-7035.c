//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/time.h>
#include <signal.h>

void sig_handler(int signum) {
    fprintf(stderr, "Caught signal %d, exiting\n", signum);
    exit(1);
}

int main(int argc, char *argv[]) {
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(server_addr);
    int sockfd, newsockfd, portno, n;
    struct timeval timeout;
    fd_set readfds;
    char buffer[1024];

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <server_port>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);

    if (portno <= 0 || portno >= 65536) {
        fprintf(stderr, "Invalid port number\n");
        exit(1);
    }

    signal(SIGINT, sig_handler);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    listen(sockfd, 5);

    while (1) {
        FD_ZERO(&readfds);
        FD_SET(sockfd, &readfds);

        timeout.tv_sec = 5;
        timeout.tv_usec = 0;

        if (select(sockfd + 1, &readfds, NULL, NULL, &timeout) < 1) {
            perror("select");
            exit(1);
        }

        if (FD_ISSET(sockfd, &readfds)) {
            newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, &addr_len);
            if (newsockfd < 0) {
                perror("accept");
                exit(1);
            }

            printf("Connected by %s\n", inet_ntoa(client_addr.sin_addr));

            while ((n = recv(newsockfd, buffer, sizeof(buffer), 0)) > 0) {
                send(sockfd, buffer, n, 0);
            }

            close(newsockfd);
        }
    }

    close(sockfd);
    return 0;
}