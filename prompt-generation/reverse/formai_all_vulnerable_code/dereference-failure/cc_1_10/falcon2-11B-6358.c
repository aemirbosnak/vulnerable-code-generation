//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr, cli_addr;
    int opt = 1;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);

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

    if (listen(sockfd, 5) < 0) {
        perror("listen");
        exit(1);
    }

    while (1) {
        socklen_t clilen = sizeof(cli_addr);
        cli_addr.sin_family = AF_INET;
        cli_addr.sin_addr.s_addr = INADDR_ANY;
        cli_addr.sin_port = htons(portno);

        int newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("accept");
            continue;
        }

        bzero(stdout, 1);
        bzero(stderr, 1);
        dup2(newsockfd, STDOUT_FILENO);
        dup2(newsockfd, STDERR_FILENO);

        n = 0;
        while ((n = read(newsockfd, &n, 1)) > 0) {
            write(newsockfd, &n, 1);
        }

        close(newsockfd);
    }

    return 0;
}