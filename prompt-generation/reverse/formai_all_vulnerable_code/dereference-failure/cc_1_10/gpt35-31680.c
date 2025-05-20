//FormAI DATASET v1.0 Category: Client Server Application ; Style: Cyberpunk
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_MESSAGE_LENGTH 100

void error(const char *message) {
    perror(message);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen;
    char buffer[MAX_MESSAGE_LENGTH];

    struct sockaddr_in serv_addr, cli_addr;
    int n;

    if(argc < 2) {
        fprintf(stderr,"ERROR: no port provided\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0)
        error("ERROR: could not create socket");

    memset(&serv_addr, 0, sizeof(serv_addr));
    portno = atoi(argv[1]);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    if(bind(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR: could not bind socket");

    listen(sockfd, 5);

    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr*) &cli_addr, &clilen);

    if(newsockfd < 0)
        error("ERROR: could not accept connection");

    // Cyberpunk flavor
    printf("\n\nWelcome to the Cyber Chat Server. Who are you?\n");
    printf("CONNECTING TO DATABASE...\n");
    printf("IDENTITY ESTABLISHED...\n");
    printf("WELCOME HACKER\n\n");

    while(1) {
        bzero(buffer, MAX_MESSAGE_LENGTH);
        n = read(newsockfd, buffer, MAX_MESSAGE_LENGTH);

        if(n < 0) {
            error("ERROR: could not read from socket");
            break;
        }

        printf("Message Received: %s", buffer);

        n = write(newsockfd, "I got your message", 18);

        if(n < 0) {
            error("ERROR: could not write to socket");
            break;
        }
    }

    close(newsockfd);
    close(sockfd);
    return 0;
}