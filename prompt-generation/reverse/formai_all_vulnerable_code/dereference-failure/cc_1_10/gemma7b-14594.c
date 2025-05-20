//Gemma-7B DATASET v1.0 Category: Simple HTTP Proxy ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 4096

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    int sockfd, clientfd, serverfd;
    struct sockaddr_in client_addr, server_addr;
    struct hostent *host;

    // Bind to a port
    serverfd = socket(AF_INET, SOCK_STREAM, htons(8080));
    if (serverfd == -1)
    {
        perror("Error binding socket");
        exit(1);
    }

    // Set up the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    // Listen for clients
    listen(serverfd, 10);

    // Accept a client connection
    clientfd = accept(serverfd, (struct sockaddr *)&client_addr, NULL);
    if (clientfd == -1)
    {
        perror("Error accepting client connection");
        exit(1);
    }

    // Get the client's hostname
    host = gethostbyaddr(&client_addr.sin_addr, sizeof(client_addr.sin_addr), AF_INET);
    printf("Client connected from: %s\n", host->h_name);

    // Read data from the client
    int num_read = read(clientfd, buffer, MAX_BUFFER_SIZE);
    if (num_read > 0)
    {
        // Write data to the server
        write(serverfd, buffer, num_read);
    }

    // Close the client connection
    close(clientfd);

    // Close the server socket
    close(serverfd);

    return 0;
}