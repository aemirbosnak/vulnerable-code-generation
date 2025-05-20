//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>
#include <errno.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen, n;
    char buffer[BUFSIZE];
    struct sockaddr_in serv_addr, cli_addr;
    int optval;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("ERROR opening socket");
        exit(0);
    }

    optval = 1;
    setsockopt(sockfd, IPPROTO_TCP, TCP_NODELAY, &optval, sizeof(optval));

    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("ERROR on binding");
        exit(0);
    }

    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) {
        printf("ERROR on accept");
        exit(0);
    }

    while (1) {
        bzero(buffer, BUFSIZE);
        n = read(newsockfd, buffer, BUFSIZE);
        if (n < 0) {
            printf("ERROR reading from socket\n");
            exit(0);
        } else if (n == 0) {
            break;
        }
        printf("Message from client: %s\n", buffer);

        n = write(newsockfd, buffer, strlen(buffer)+1);
        if (n < 0) {
            printf("ERROR writing to socket\n");
            exit(0);
        }
        printf("Message echoed back to client: %s\n", buffer);
    }

    close(newsockfd);
    close(sockfd);

    return 0;
}