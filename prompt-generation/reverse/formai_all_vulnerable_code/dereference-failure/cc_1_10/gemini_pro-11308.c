//GEMINI-pro DATASET v1.0 Category: Networking ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

int main(int argc, char *argv[])
{
    // Check for command-line arguments
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get the host name and port number from the command line
    char *hostname = argv[1];
    int port = atoi(argv[2]);

    // Get the IP address of the host
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL)
    {
        fprintf(stderr, "Error: Could not resolve hostname %s\n", hostname);
        exit(EXIT_FAILURE);
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        fprintf(stderr, "Error: Could not create socket\n");
        exit(EXIT_FAILURE);
    }

    // Connect to the host
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    memcpy(&serv_addr.sin_addr, host->h_addr, host->h_length);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        fprintf(stderr, "Error: Could not connect to host %s:%d\n", hostname, port);
        exit(EXIT_FAILURE);
    }

    // Send a message to the host
    const char *message = "Hello, world!\n";
    int n = write(sockfd, message, strlen(message));
    if (n < 0)
    {
        fprintf(stderr, "Error: Could not send message to host\n");
        exit(EXIT_FAILURE);
    }

    // Receive a message from the host
    char buffer[256];
    n = read(sockfd, buffer, sizeof(buffer) - 1);
    if (n < 0)
    {
        fprintf(stderr, "Error: Could not receive message from host\n");
        exit(EXIT_FAILURE);
    }

    // Print the message from the host
    buffer[n] = '\0';
    printf("Received message from host: %s\n", buffer);

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}