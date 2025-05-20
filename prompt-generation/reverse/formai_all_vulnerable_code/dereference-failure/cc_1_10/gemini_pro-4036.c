//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define PORT 3490 // The port you want the server to listen on

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    // Check if the correct number of arguments were passed
    if (argc < 2) {
        fprintf(stderr, "ERROR: No port provided\n");
        exit(1);
    }

    // Get the port number from the command line
    portno = atoi(argv[1]);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "ERROR: Could not create socket\n");
        exit(1);
    }

    // Set the server address
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Bind the socket to the server address
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "ERROR: Could not bind socket\n");
        exit(1);
    }

    // Listen for incoming connections
    listen(sockfd, 5);

    // Accept incoming connections
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) {
        fprintf(stderr, "ERROR: Could not accept connection\n");
        exit(1);
    }

    // Read data from the client
    bzero(buffer, 256);
    n = read(newsockfd, buffer, 255);
    if (n < 0) {
        fprintf(stderr, "ERROR: Could not read from socket\n");
        exit(1);
    }

    // Print the data received from the client
    printf("Here is the message: %s\n", buffer);

    // Write data to the client
    n = write(newsockfd, "I got your message", 18);
    if (n < 0) {
        fprintf(stderr, "ERROR: Could not write to socket\n");
        exit(1);
    }

    // Close the connection
    close(newsockfd);
    close(sockfd);

    return 0;
}