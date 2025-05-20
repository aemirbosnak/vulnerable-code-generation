//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, newsockfd, clilen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[1024];

    if (argc < 2) {
        fprintf(stderr, "Usage: %s port_number\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[1]);
    if (portno <= 0 || portno > 65535) {
        fprintf(stderr, "port number is invalid\n");
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(0);
    }

    listen(sockfd, 5);

    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(0);
    }

    printf("Connection from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

    while (1) {
        bzero(buffer, 1024);
        read(newsockfd, buffer, 1024);
        printf("%s\n", buffer);
        send(newsockfd, buffer, strlen(buffer), 0);
    }

    close(sockfd);
    close(newsockfd);

    return 0;
}