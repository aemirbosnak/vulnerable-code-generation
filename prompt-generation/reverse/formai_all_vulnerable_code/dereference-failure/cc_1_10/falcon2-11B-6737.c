//Falcon2-11B DATASET v1.0 Category: Networking ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, n;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[1024];

    if (argc!= 2) {
        fprintf(stderr, "usage: %s <port>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);

    if (portno <= 0 || portno >= 65536) {
        fprintf(stderr, "Invalid port number\n");
        exit(1);
    }

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
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &n);
        if (newsockfd < 0) {
            perror("accept");
            exit(1);
        }

        printf("Connection from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        while ((n = recv(newsockfd, buffer, sizeof(buffer), 0)) > 0) {
            send(sockfd, buffer, n, 0);
            printf("Received: %s\n", buffer);
        }

        printf("Connection closed\n");

        close(newsockfd);
    }

    return 0;
}