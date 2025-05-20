//FormAI DATASET v1.0 Category: Socket programming ; Style: scientific
/* This program uses socket programming to create a simple client-server communication system. The server waits for connections from clients and sends back a message to the client when a connection is established. The client sends a message to the server, which then responds back with a reversed message. This program is based on the scientific principles of network communication and socket programming. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFFER_SIZE 256

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno, n;
    socklen_t clilen;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in serv_addr, cli_addr;

    if (argc < 2) {
        fprintf(stderr,"ERROR, no port provided\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");

    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr,
             sizeof(serv_addr)) < 0) 
             error("ERROR on binding");

    listen(sockfd,5);
    clilen = sizeof(cli_addr);

    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) 
         error("ERROR on accept");

    bzero(buffer,BUFFER_SIZE);
    n = read(newsockfd,buffer,BUFFER_SIZE-1);
    if (n < 0) error("ERROR reading from socket");

    printf("Message from client: %s\n",buffer);

    // Reverse the message
    int len = strlen(buffer);
    for (int i = 0; i < len/2; i++) {
        char temp = buffer[i];
        buffer[i] = buffer[len-i-1];
        buffer[len-i-1] = temp;
    }

    n = write(newsockfd,buffer,strlen(buffer));
    if (n < 0) error("ERROR writing to socket");

    close(newsockfd);
    close(sockfd);

    return 0;
}