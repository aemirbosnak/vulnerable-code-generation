//FormAI DATASET v1.0 Category: Networking ; Style: dynamic
// This is a simple client-server program in C using sockets and dynamic memory allocation.
// The client sends a string to the server, which returns it in upper-case letters.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int sockfd, newsockfd, clilen, n;
    struct sockaddr_in serv_addr, cli_addr;
    char *buffer = (char*)malloc(256);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    // Initialize socket structure
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    // Bind the host address
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR on binding");

    // Listen for incoming connections
    listen(sockfd, 5);

    // Accept actual connection
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0)
        error("ERROR on accept");

    // Receive message from client
    bzero(buffer, 256);
    n = read(newsockfd, buffer, 255);
    if (n < 0)
        error("ERROR reading from socket");
    printf("Here is the message: %s\n", buffer);

    // Convert message to upper-case letters
    int i;
    for (i = 0; i < strlen(buffer); i++)
        buffer[i] = toupper(buffer[i]);

    // Send message back to client
    n = write(newsockfd, buffer, strlen(buffer));
    if (n < 0)
        error("ERROR writing to socket");

    // Close sockets and free memory
    close(newsockfd);
    close(sockfd);
    free(buffer);

    return 0;
}