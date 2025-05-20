//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAXLINE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[MAXLINE];

    if (argc!= 3) {
        fprintf(stderr, "usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    listen(sockfd, 5);

    while (1) {
        sockfd = accept(sockfd, NULL, NULL);
        if (sockfd < 0) {
            perror("accept failed");
            exit(1);
        }

        printf("Connected by %s\n", inet_ntoa(serv_addr.sin_addr));
        fflush(stdout);

        while ((n = read(sockfd, buffer, MAXLINE)) > 0) {
            write(sockfd, buffer, n);
            fflush(stdout);
        }
        close(sockfd);
    }

    close(sockfd);
    return 0;
}