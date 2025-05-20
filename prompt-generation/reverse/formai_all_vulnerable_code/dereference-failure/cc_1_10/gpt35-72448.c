//FormAI DATASET v1.0 Category: Chat server ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFFER_SIZE 256

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    // Check if port number is provided
    if (argc < 2) {
        printf("Error: No port number provided.\n");
        exit(1);
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: Failed to create socket.\n");
        exit(1);
    }

    // Set server address properties
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Bind socket to server address
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: Failed to bind socket to server address.\n");
        exit(1);
    }

    // Listen for incoming connections
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    // Accept incoming connections and create new socket for communication
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) {
        printf("Error: Failed to accept incoming connection.\n");
        exit(1);
    }

    // Communicate with client
    while (1) {
        // Receive message from client
        bzero(buffer, BUFFER_SIZE);
        n = read(newsockfd, buffer, BUFFER_SIZE);
        if (n < 0) {
            printf("Error: Failed to read from socket.\n");
            exit(1);
        }

        // Print received message
        printf("Message from client: %s", buffer);

        // Inquire for input and send response to client
        printf("Enter message for client: ");
        bzero(buffer, BUFFER_SIZE);
        fgets(buffer, BUFFER_SIZE, stdin);
        n = write(newsockfd, buffer, strlen(buffer));
        if (n < 0) {
            printf("Error: Failed to write to socket.\n");
            exit(1);
        }
    }

    // Close sockets
    close(newsockfd);
    close(sockfd);

    return 0;
}