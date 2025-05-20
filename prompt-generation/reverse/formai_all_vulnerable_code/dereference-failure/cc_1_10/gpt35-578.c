//FormAI DATASET v1.0 Category: Networking ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_MSG_SIZE 100

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno, clilen, n;
    char buffer[MAX_MSG_SIZE];
    struct sockaddr_in serv_addr, cli_addr;

    if (argc < 2) {
        fprintf(stderr,"ERROR, no port provided\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR on binding");
    }

    listen(sockfd, 5);
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

    if (newsockfd < 0) {
        error("ERROR on accept");
    }

    printf("Connection established with %s\n", inet_ntoa(cli_addr.sin_addr));

    while (1) {
        bzero(buffer, MAX_MSG_SIZE);
        n = read(newsockfd, buffer, MAX_MSG_SIZE - 1);

        if (n < 0) {
            error("ERROR reading from socket");
        }

        printf("Message received: %s\n", buffer);

        n = write(newsockfd, "I got your message", 18);

        if (n < 0) {
            error("ERROR writing to socket");
        }

        if (strcmp(buffer, "quit\n") == 0) {
            break;
        }
    }

    printf("Closing connection with %s\n", inet_ntoa(cli_addr.sin_addr));
    close(newsockfd);
    close(sockfd);

    return 0;
}