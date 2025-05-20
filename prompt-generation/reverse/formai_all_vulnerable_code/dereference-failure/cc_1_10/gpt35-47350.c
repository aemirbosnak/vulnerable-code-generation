//FormAI DATASET v1.0 Category: Client Server Application ; Style: dynamic
// A dynamic C client-server application that sends and receives messages

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

// Function to handle error messages
void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    // Ensure that port number is provided as command line argument
    if (argc < 2) {
        fprintf(stderr,"ERROR, no port provided\n");
        exit(1);
    }

    // Create a new socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
       error("ERROR opening socket");

    // Clear server address structure
    bzero((char *) &serv_addr, sizeof(serv_addr));

    // Get port number from command line argument & set server address
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Bind socket to server address
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR on binding");

    // Listen for incoming connections
    listen(sockfd,5);
    clilen = sizeof(cli_addr);

    // Accept incoming connections
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0)
        error("ERROR on accept");

    // Prompt user to enter message to send to client
    printf("Please enter the message: ");
    bzero(buffer,256);
    fgets(buffer,255,stdin);

    // Send message to client
    n = write(newsockfd,buffer,strlen(buffer));
    if (n < 0)
         error("ERROR writing to socket");

    bzero(buffer,256);

    // Receive message from client
    n = read(newsockfd,buffer,255);
    if (n < 0)
         error("ERROR reading from socket");

    // Print received message
    printf("Message from client: %s\n",buffer);

    // Close sockets
    close(newsockfd);
    close(sockfd);

    return 0;
}