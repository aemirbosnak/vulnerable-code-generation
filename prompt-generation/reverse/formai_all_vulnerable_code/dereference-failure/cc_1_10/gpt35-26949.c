//FormAI DATASET v1.0 Category: Simple Web Server ; Style: artistic
/*
 *  The Artistic Simple Web Server
 *
 *  This program opens a socket, listens for incoming requests and serves HTML pages
 *  to clients who request them. It is written in C and features recycling, error handling
 *  interactivity and a dash of creativity.
 *
 *  Written by the talented chatbot, AI-9000
 *       
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define DEFAULT_PORT 8080
#define BUFFER_SIZE 1024

void error(char *msg) { //Handles error messages
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {

    int sockfd, newsockfd, portno, clientlen;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    if (argc < 2) {
        portno = DEFAULT_PORT;
    } else {
        portno = atoi(argv[1]);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0); //Create a socket
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    memset((char *) &serv_addr, 0, sizeof(serv_addr)); //Initialize server address

    serv_addr.sin_family = AF_INET; //Setting up the server to accept incoming connections
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr,
             sizeof(serv_addr)) < 0) { 
        error("ERROR on binding");
    }

    listen(sockfd, 5); //Listen for incoming requests, maximum 5 clients.

    while (1) { //Waiting for incoming requests
        clientlen = sizeof(cli_addr);
        newsockfd = accept(sockfd,
                           (struct sockaddr *) &cli_addr,
                           &clientlen); 
        if (newsockfd < 0) {
            error("ERROR on accept");
        }

        memset(buffer, 0, BUFFER_SIZE); //Initialize buffer
        n = read(newsockfd, buffer, BUFFER_SIZE - 1); //Reading incoming requests
        if (n < 0) {
            error("ERROR reading from socket");
        }

        printf("%s\n", buffer); //Print incoming GET request to console
        
        n = write(newsockfd, "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><body><h1>Welcome to the Artistic Simple Web Server!</h1><img src='https://picsum.photos/200/300'><p>The page is under construction, please check back later!</p></body></html>", strlen("HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><body><h1>Welcome to the Artistic Simple Web Server!</h1><img src='https://picsum.photos/200/300'><p>The page is under construction, please check back later!</p></body></html>")); //Sending HTTP response to client
        if (n < 0) {
            error("ERROR writing to socket");
        }

        close(newsockfd); //Closing connection
    }

    close(sockfd); //Closing socket
    return 0; //Returning success
}