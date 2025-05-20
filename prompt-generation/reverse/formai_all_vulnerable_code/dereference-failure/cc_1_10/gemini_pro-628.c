//GEMINI-pro DATASET v1.0 Category: Networking ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to an address
    struct sockaddr_in serv_addr;
    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(8080);
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    listen(sockfd, 5);

    // Accept a connection
    int newsockfd = accept(sockfd, (struct sockaddr *) NULL, NULL);
    if (newsockfd < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    // Read the data from the client
    char buffer[256];
    bzero(buffer, sizeof(buffer));
    int n = read(newsockfd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    // Send the data back to the client
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