//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdbool.h>

#define MAX_BUFFER_SIZE 1024

// Function to display error message and exit the program
void exitWithError(const char *errorMessage)
{
    perror(errorMessage);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
    if (argc != 3) // Check if command line arguments are correct
    {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *port = argv[2];

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        exitWithError("Error: failed to create socket\n");
    }

    // Get IP address from hostname
    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    int status = getaddrinfo(hostname, port, &hints, &res);
    if (status != 0)
    {
        exitWithError("Error: failed to get IP address from hostname\n");
    }

    // Connect to server
    int connectStatus = connect(sock, res->ai_addr, res->ai_addrlen);
    if (connectStatus < 0)
    {
        exitWithError("Error: failed to connect to server\n");
    }

    // Send request to server
    const char *request = "GET / HTTP/1.1\r\n\r\n";
    int requestSize = strlen(request);
    int bytesSent = send(sock, request, requestSize, 0);
    if (bytesSent != requestSize)
    {
        exitWithError("Error: failed to send request to server\n");
    }

    printf("Connecting to %s...\n", hostname);

    // Receive response from server
    char buffer[MAX_BUFFER_SIZE];
    memset(buffer, 0, sizeof(buffer));
    int bytesRead = recv(sock, buffer, MAX_BUFFER_SIZE - 1, 0);
    if (bytesRead < 0)
    {
        exitWithError("Error: failed to receive response from server\n");
    }

    // Display response from server
    printf("Response from server:\n%s\n", buffer);

    // Close socket
    close(sock);

    return EXIT_SUCCESS;
}