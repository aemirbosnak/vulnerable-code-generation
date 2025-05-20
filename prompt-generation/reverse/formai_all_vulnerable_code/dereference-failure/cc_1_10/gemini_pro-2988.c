//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080

int main() {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to an address
    struct sockaddr_in serv_addr;
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sockfd, 5) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Accept an incoming connection
    int newsockfd;
    socklen_t clilen;
    struct sockaddr_in cli_addr;
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    // Read the data from the client
    char buffer[256];
    bzero(buffer, 256);
    int n = read(newsockfd, buffer, 255);
    if (n < 0) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    // Write the data back to the client
    n = write(newsockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    // Close the connection
    close(newsockfd);
    close(sockfd);

    return 0;
}