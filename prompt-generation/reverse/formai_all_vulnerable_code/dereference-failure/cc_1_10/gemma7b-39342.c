//Gemma-7B DATASET v1.0 Category: Intrusion detection system ; Style: genius
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netdb.h>

#define LISTEN_PORT 8080

int main()
{
    int sockfd, clientfd, sin_size, bytes_read;
    struct sockaddr_in server_addr, client_addr;
    char buf[1024], msg[1024], hostname[256];

    // Bind socket to port
    sockfd = socket(AF_INET, SOCK_STREAM, htons(LISTEN_PORT));
    if (sockfd < 0)
    {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for connections
    sin_size = sizeof(client_addr);
    clientfd = accept(sockfd, (struct sockaddr *)&client_addr, &sin_size);
    if (clientfd < 0)
    {
        perror("Error accepting connection");
        exit(1);
    }

    // Get client hostname
    gethostname(hostname, sizeof(hostname));
    printf("Client hostname: %s\n", hostname);

    // Read client message
    bytes_read = read(clientfd, msg, 1024);
    if (bytes_read < 0)
    {
        perror("Error reading message");
        exit(1);
    }

    // Print client message
    printf("Client message: %s\n", msg);

    // Send a response
    sprintf(buf, "Hello, %s!", msg);
    write(clientfd, buf, strlen(buf) + 1);

    // Close connection
    close(clientfd);
    close(sockfd);

    return 0;
}