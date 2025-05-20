//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

// Brushes and pigments for our masterpiece
int sockfd, newsockfd, portno, clilen;
char buffer[256];
struct sockaddr_in serv_addr, cli_addr;

// The canvas upon which we paint our masterpiece
int main(int argc, char *argv[]) {
    // First brushstroke: socket creation
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    // Canvas dimensions: setting server properties
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Second brushstroke: binding the canvas to the ethereal threads
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Binding failed");
        exit(1);
    }

    // Third brushstroke: listening for connections
    listen(sockfd, 5);

    // Infinite loop: the canvas never sleeps
    while (1) {
        // Waiting for a new connection, like a painter awaiting inspiration
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("Accept failed");
            continue;
        }

        // Receiving the masterpiece: reading from the socket
        bzero(buffer, 256);
        int n = read(newsockfd, buffer, 255);
        if (n < 0) {
            perror("Error reading from socket");
            continue;
        }
        printf("Client: %s\n", buffer);

        // Crafting a response: our artistic interpretation
        bzero(buffer, 256);
        strcpy(buffer, "Your masterpiece has been received, dear client.");
        n = write(newsockfd, buffer, strlen(buffer));
        if (n < 0) {
            perror("Error writing to socket");
            continue;
        }

        // Closing the connection: the artist's signature
        close(newsockfd);
    }

    // Farewell stroke: closing the canvas
    close(sockfd);
    return 0;
}