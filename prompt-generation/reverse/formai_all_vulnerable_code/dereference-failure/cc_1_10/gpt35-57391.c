//FormAI DATASET v1.0 Category: Client Server Application ; Style: standalone
// A simple C program for a client-server communication

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

// Error function to handle error messages
void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno, clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;

    // Check if port number is provided
    if (argc < 2) {
        fprintf(stderr,"ERROR, no port provided\n");
        exit(1);
    }

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    // Initialize the server address
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Bind the socket to the server address
    if (bind(sockfd, (struct sockaddr *) &serv_addr,
             sizeof(serv_addr)) < 0)
        error("ERROR on binding");

    // Start listening for incoming connections
    listen(sockfd,5);
    clilen = sizeof(cli_addr);

    // Accept a connection from a client
    newsockfd = accept(sockfd,
                (struct sockaddr *) &cli_addr,
                &clilen);
    if (newsockfd < 0)
        error("ERROR on accept");

    // Send a welcome message to the client
    bzero(buffer,256);
    strcpy(buffer, "Welcome to my server!");
    write(newsockfd,buffer,strlen(buffer));

    // Read messages from the client and echo them back
    while (1) {
        bzero(buffer,256);
        read(newsockfd,buffer,255);
        if (strncmp("quit", buffer, 4) == 0)
            break;
        printf("Client: %s", buffer);
        write(newsockfd,buffer,strlen(buffer));
    }

    // Close the sockets
    close(newsockfd);
    close(sockfd);
    return 0;
}