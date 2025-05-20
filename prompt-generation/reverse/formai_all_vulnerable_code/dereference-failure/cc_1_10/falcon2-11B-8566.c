//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    int sockfd, newsockfd, portno, n;
    struct sockaddr_in serv_addr, cli_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        return 1;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        return 1;
    }

    portno = atoi(argv[2]);

    while (1) {
        bzero((char *) &cli_addr, sizeof(cli_addr));
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &n);

        if (newsockfd < 0) {
            perror("ERROR on accept");
            continue;
        }

        char buffer[1024];
        n = read(newsockfd, buffer, sizeof(buffer));

        if (n < 0) {
            perror("ERROR reading from socket");
            continue;
        }

        printf("Received: %s\n", buffer);

        n = write(newsockfd, buffer, sizeof(buffer));

        if (n < 0) {
            perror("ERROR writing to socket");
            continue;
        }

        close(newsockfd);
    }

    close(sockfd);
    return 0;
}