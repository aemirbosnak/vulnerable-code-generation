//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>

int main()
{
    int sockfd, sin_port, i, n;
    struct sockaddr_in serv_addr;
    char buf[1024];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(6));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Bind the socket to a port
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for connections
    listen(sockfd, 1);

    // Accept a connection
    sin_port = ntohs(((struct sockaddr_in *)accept(sockfd, NULL, NULL))->sin_port);
    printf("Client connected from port %d\n", sin_port);

    // Send a message to the client
    n = write(sockfd, "Hello, world!", 13);
    if (n < 0)
    {
        perror("Error sending message");
        exit(1);
    }

    // Receive a message from the client
    n = read(sockfd, buf, 1024);
    if (n < 0)
    {
        perror("Error receiving message");
        exit(1);
    }

    // Print the client's message
    printf("Client message: %s\n", buf);

    // Close the socket
    close(sockfd);

    return 0;
}