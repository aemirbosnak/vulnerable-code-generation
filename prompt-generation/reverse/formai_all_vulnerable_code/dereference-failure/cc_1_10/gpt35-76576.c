//FormAI DATASET v1.0 Category: Chat server ; Style: Alan Touring
// Welcome to the Chatbot server program!
// Written in the style of Alan Turing

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
    // Declare variables
    int sockfd, newsockfd, portno, clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    // Initialize socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Initialize server address
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Bind socket to address
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    // Listen for clients
    listen(sockfd,5);
    clilen = sizeof(cli_addr);

    // Accept incoming clients
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    // Communication loop
    while(1){

        // Clear buffer
        bzero(buffer,256);

        // Read from client
        n = read(newsockfd,buffer,255);

        // Error handling
        if (n < 0) {
            perror("ERROR reading from socket");
            break;
        }

        // If user says "Bye", close server
        if(strcmp(buffer,"Bye\n")==0){
            n = write(newsockfd,"Goodbye!\n",9);
            if (n < 0) {
                perror("ERROR writing to socket");
            }
            break;
        }

        // Write to client
        printf("Client: %s",buffer);
        n = write(newsockfd,"I am a Chatbot server.\n",23);
        if (n < 0) {
            perror("ERROR writing to socket");
            break;
        }
    }

    // Close socket
    close(newsockfd);
    close(sockfd);
    return 0;
}