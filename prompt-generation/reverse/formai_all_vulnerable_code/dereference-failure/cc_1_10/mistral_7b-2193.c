//MISTRAL-7B DATASET v1.0 Category: Networking ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, clilen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[256];

    if (argc < 2) {
        fprintf(stderr,"ERROR : %s port number is missing\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR on binding");

    listen(sockfd,5);
    clilen = sizeof(cli_addr);

    int newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0)
        error("ERROR on accept");

    bzero(buffer,256);

    while(1) {
        int n = recv(newsockfd,buffer,255,0);
        if (n < 0)
            error("ERROR reading from socket");
        printf("Client: %s",buffer);
        bzero(buffer,256);

        fgets(buffer,255,stdin);
        send(newsockfd,buffer,strlen(buffer),0);
    }

    close(newsockfd);
    close(sockfd);
    return 0;
}