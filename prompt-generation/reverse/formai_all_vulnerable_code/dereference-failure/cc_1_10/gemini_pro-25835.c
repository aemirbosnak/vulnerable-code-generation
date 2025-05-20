//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#define PORT  5000
#define BUFF_SIZE 1024

int main() {
    int sockfd, newsockfd, n;
    socklen_t clilen;
    char buffer[BUFF_SIZE];
    struct sockaddr_in serv_addr, cli_addr;

    // Create a TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Set the server address
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    // Bind the socket to the server address
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    // Listen for connections
    if (listen(sockfd, 5) < 0) {
        perror("ERROR on listen");
        exit(1);
    }

    // Accept connections
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    // Read data from the client
    bzero(buffer, BUFF_SIZE);
    n = read(newsockfd, buffer, BUFF_SIZE - 1);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    // Write data to the client
    n = write(newsockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    // Close the connection
    close(newsockfd);
    close(sockfd);

    return 0;
}