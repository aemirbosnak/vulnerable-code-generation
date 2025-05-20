//Falcon2-11B DATASET v1.0 Category: File Synchronizer ; Style: distributed
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define PORT 8080
#define MAX_BUFFER 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        return 1;
    }

    int sockfd, newsockfd, n;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t addrlen;
    char buffer[MAX_BUFFER];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    memset((char *) &serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR on binding");

    listen(sockfd, 5);
    addrlen = sizeof(cli_addr);

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &addrlen);
        if (newsockfd < 0)
            error("ERROR on accept");

        printf("Client connected: %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));
        fflush(stdout);

        while ((n = recv(newsockfd, buffer, MAX_BUFFER, 0)) > 0) {
            if (n == 0)
                break;
            printf("Received %d bytes: %s\n", n, buffer);
            fflush(stdout);
            send(newsockfd, buffer, n, 0);
        }

        close(newsockfd);
    }

    close(sockfd);
    return 0;
}