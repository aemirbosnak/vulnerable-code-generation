//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT_MAX 65535
#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the hostname and port number
    char *hostname = argv[1];
    int port = atoi(argv[2]);

    // Check if the port is valid
    if (port < 0 || port > PORT_MAX)
    {
        fprintf(stderr, "Invalid port number: %d\n", port);
        return EXIT_FAILURE;
    }

    // Get the IP address of the hostname
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL)
    {
        fprintf(stderr, "Invalid hostname: %s\n", hostname);
        return EXIT_FAILURE;
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Connect to the server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *((struct in_addr *) host->h_addr);

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1)
    {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send a message to the server
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    strcpy(buffer, "Hello from the port scanner!");

    if (send(sockfd, buffer, strlen(buffer), 0) == -1)
    {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive a response from the server
    memset(buffer, 0, BUFFER_SIZE);

    if (recv(sockfd, buffer, BUFFER_SIZE, 0) == -1)
    {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Print the response from the server
    printf("Response from the server: %s\n", buffer);

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}