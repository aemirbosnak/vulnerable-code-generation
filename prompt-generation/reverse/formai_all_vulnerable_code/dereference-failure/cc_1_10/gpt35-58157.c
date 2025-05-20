//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: unmistakable
//Header files required for TCP/IP programming

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

//Function prototypes
void error(const char *msg);

int main(int argc, char *argv[])
{
    //Variables declaration
    int sockfd, newsockfd, portno, clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;
    
    //Check for the command line arguments
    if (argc < 2) {
        fprintf(stderr,"ERROR, no port provided\n");
        exit(1);
    }
    
    //Create a new socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
       error("ERROR opening socket");
    
    //Initialize the server address variables
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    
    //Bind the socket to the server address
    if (bind(sockfd, (struct sockaddr *) &serv_addr,
             sizeof(serv_addr)) < 0) 
             error("ERROR on binding");
             
    //Listen for incoming connections
    listen(sockfd,5);
    clilen = sizeof(cli_addr);
    
    //Accept incoming connections
    newsockfd = accept(sockfd, 
                 (struct sockaddr *) &cli_addr, 
                 &clilen);
                 
    if (newsockfd < 0) 
          error("ERROR on accept");
          
    //Handle the communication with the client
    bzero(buffer,256);
    n = read(newsockfd,buffer,255);
    if (n < 0) error("ERROR reading from socket");
    printf("Here is the message: %s\n",buffer);
    n = write(newsockfd,"I got your message",18);
    if (n < 0) error("ERROR writing to socket");
    
    //Close the sockets
    close(newsockfd);
    close(sockfd);
    
    return 0; 
 }

//Error handling function
void error(const char *msg)
{
    perror(msg);
    exit(1);
}