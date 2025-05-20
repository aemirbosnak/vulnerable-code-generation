//Gemma-7B DATASET v1.0 Category: Chat server ; Style: immersive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>

#define PORT 8888

int main()
{
    int sockfd, newsockfd, clientlen;
    struct sockaddr_in server_addr, client_addr;

    // Bind the socket to a port
    sockfd = socket(AF_INET, SOCK_STREAM, htons(PORT));
    if (sockfd < 0)
    {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for clients
    listen(sockfd, &clientlen);

    // Accept a client connection
    newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, (int *) &clientlen);
    if (newsockfd < 0)
    {
        perror("Error accepting client connection");
        exit(1);
    }

    // Get the client's message
    char message[256];
    recv(newsockfd, message, 256, 0);

    // Print the client's message to the server
    printf("Client: %s\n", message);

    // Send a message back to the client
    send(newsockfd, message, strlen(message), 0);

    // Close the client connection
    close(newsockfd);

    // Close the server socket
    close(sockfd);

    return 0;
}