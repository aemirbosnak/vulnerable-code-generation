//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_BUF 1024

int main(int argc, char** argv) {
    int sockfd, newsockfd, portno, n;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX_BUF];

    // Check command line arguments
    if (argc < 3) {
        printf("Usage: %s <port> <email_address>\n", argv[0]);
        exit(1);
    }

    // Get port number from command line
    portno = atoi(argv[1]);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Set up server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Bind the socket to the server address
    if (bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    // Listen for incoming connections
    listen(sockfd, 5);

    // Accept incoming connection
    socklen_t clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr*)&cli_addr, &clilen);
    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    // Get email address from command line
    char* email_address = argv[2];

    // Send email address to client
    n = write(newsockfd, email_address, strlen(email_address));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    // Read response from client
    n = read(newsockfd, buffer, MAX_BUF);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    // Print response from client
    printf("%s\n", buffer);

    // Close socket
    close(newsockfd);
    close(sockfd);

    return 0;
}