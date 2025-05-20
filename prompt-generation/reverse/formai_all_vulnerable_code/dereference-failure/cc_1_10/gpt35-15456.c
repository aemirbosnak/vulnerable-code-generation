//FormAI DATASET v1.0 Category: Simple Web Server ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    // Get port number from arguments
    if (argc < 2 || !isdigit(argv[1][0])) {
        fprintf(stderr, "Usage: %s PORT\n", argv[0]);
        exit(1);
    }
    int portno = atoi(argv[1]);

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    // Bind socket to port
    struct sockaddr_in serv_addr, cli_addr;
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR on binding");

    // Listen for incoming connections
    listen(sockfd, 5);
    printf("Server listening on port %d\n", portno);

    // Handle incoming connections
    while (1) {
        unsigned int clilen = sizeof(cli_addr);
        int newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0)
            error("ERROR on accept");

        // Read HTTP request from client
        char buffer[BUFFER_SIZE];
        bzero(buffer, BUFFER_SIZE);
        if (read(newsockfd, buffer, BUFFER_SIZE - 1) < 0)
            error("ERROR reading from socket");
        printf("Received from client:\n%s\n", buffer);

        // Send HTTP response to client
        char response[] = "HTTP/1.1 200 OK\nContent-Type: text/plain\n\nHello, World!";
        if (write(newsockfd, response, strlen(response)) < 0)
            error("ERROR writing to socket");

        close(newsockfd);
    }

    close(sockfd);
    return 0;
}