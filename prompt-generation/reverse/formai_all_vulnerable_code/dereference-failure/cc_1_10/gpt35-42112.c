//FormAI DATASET v1.0 Category: Chat server ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024

void error(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    if (argc < 2) {
        fprintf(stderr,"ERROR, no port provided\n");
        exit(1);
    }

    // Create socket file descriptor
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");

    // Clear server address structure
    bzero((char *) &serv_addr, sizeof(serv_addr));

    // Port number provided as command line argument
    portno = atoi(argv[1]);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Bind socket to port
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
        error("ERROR on binding");

    listen(sockfd,5);
    clilen = sizeof(cli_addr);

    // Accept incoming client connections
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) 
        error("ERROR on accept");

    // Start surrealist chat
    printf("Welcome to the Surreal Chat Server. Enter your name:\n");
    bzero(buffer, BUFFER_SIZE);
    n = read(newsockfd,buffer,BUFFER_SIZE-1);
    if (n < 0) error("ERROR reading from socket");
    printf("Hello, %s!\n",buffer);

    printf("Let's start with a nonsensical question:\n");
    n = write(newsockfd, "What is the sound of a cat eating a rainbow?", 44);
    if (n < 0) error("ERROR writing to socket");

    // Wait for client response
    bzero(buffer, BUFFER_SIZE);
    n = read(newsockfd,buffer,BUFFER_SIZE-1);
    if (n < 0) error("ERROR reading from socket");
    printf("Client response: %s\n",buffer);

    printf("Now let's explore the depths of your subconscious. Think of a color and type it:\n");
    bzero(buffer, BUFFER_SIZE);
    fgets(buffer, BUFFER_SIZE-1, stdin);
    n = write(newsockfd, buffer, strlen(buffer));
    if (n < 0) error("ERROR writing to socket");

    // Wait for client response
    bzero(buffer, BUFFER_SIZE);
    n = read(newsockfd,buffer,BUFFER_SIZE-1);
    if (n < 0) error("ERROR reading from socket");
    printf("Client response: %s\n",buffer);

    printf("Let's end this surreal chat with a poem. Type a line:\n");
    bzero(buffer, BUFFER_SIZE);
    fgets(buffer, BUFFER_SIZE-1, stdin);
    n = write(newsockfd, buffer, strlen(buffer));
    if (n < 0) error("ERROR writing to socket");

    printf("Waiting for another line...\n");
    bzero(buffer, BUFFER_SIZE);
    n = read(newsockfd,buffer,BUFFER_SIZE-1);
    if (n < 0) error("ERROR reading from socket");
    printf("Client response: %s\n",buffer);

    printf("And with that, our surreal journey comes to an end. Goodbye!\n");

    close(newsockfd);
    close(sockfd);
    return 0;
}