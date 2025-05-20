//FormAI DATASET v1.0 Category: Client Server Application ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFFER_SIZE 256

// Function to print error messages
void error(const char *msg)
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

    // Check if port number is provided as command-line argument
    if (argc < 2) {
        fprintf(stderr,"ERROR, no port provided\n");
        exit(1);
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");

    // Set server address
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Bind socket to server address and port
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
        error("ERROR on binding");

    // Listen for incoming connections
    listen(sockfd, 5);

    // Accept incoming connections
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) 
        error("ERROR on accept");

    // Read data from client
    bzero(buffer, BUFFER_SIZE);
    if (read(newsockfd, buffer, BUFFER_SIZE - 1) < 0) 
        error("ERROR reading from socket");

    // Print message from client
    printf("Client: %s\n", buffer);

    // Send response to client
    const char* response = "Hello from server!";
    if (write(newsockfd, response, strlen(response)) < 0) 
        error("ERROR writing to socket");

    // Close sockets
    close(newsockfd);
    close(sockfd);

    return 0;
}