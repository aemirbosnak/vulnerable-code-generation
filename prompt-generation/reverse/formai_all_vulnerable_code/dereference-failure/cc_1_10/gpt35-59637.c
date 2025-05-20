//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: authentic
/* This program demonstrates a client-server application using TCP/IP protocol in C */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

void error(const char *msg){
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]){

    int sockfd, newsockfd, portno, clilen, n;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;

    if (argc < 2){
        fprintf(stderr, "Usage: %s port_number\n", argv[0]);
        exit(1);
    }
    
     /* Create a new socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0){ 
        error("ERROR opening socket");
    }
    
     /* Set server address properties */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    
    /* Bind the socket to the server address */
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0){ 
        error("ERROR on binding");
    }
    
    /* Start listening for incoming connections */
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);
    
    /* Accept a connection request */
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0){ 
        error("ERROR on accept");
    }
    
    /* Clear the buffer */
    bzero(buffer, 256);
    
    /* Read data from the client */
    n = read(newsockfd, buffer, 255);
    if (n < 0){
        error("ERROR reading from socket");
    }
    
    /* Print the message */
    printf("Here is the message: %s\n", buffer);
    
    /* Send a response back to the client */
    n = write(newsockfd, "I got your message", 18);
    if (n < 0){
        error("ERROR writing to socket");
    }
    
    /* Close the sockets */
    close(newsockfd);
    close(sockfd);
    
    return 0;
}