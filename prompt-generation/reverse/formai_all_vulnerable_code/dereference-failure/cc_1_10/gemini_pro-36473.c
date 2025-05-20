//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>

// Function to print the error message and exit the program
void error(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    // Variables to store the server's IP address, port number, and socket descriptor
    char *server_ip;
    int port_number;
    int sockfd;

    // Check if the user has provided the server's IP address and port number as command-line arguments
    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s <server_ip> <port_number>\n", argv[0]);
        exit(1);
    }

    // Parse the IP address and port number from the command-line arguments
    server_ip = argv[1];
    port_number = atoi(argv[2]);

    // Create a TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        error("Error creating socket");
    }

    // Set the server's IP address and port number in the socket address structure
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port_number);
    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0)
    {
        error("Error converting IP address");
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        error("Error connecting to server");
    }

    // Send a message to the server
    char *msg = "Hello, server!";
    int msg_len = strlen(msg);
    if (send(sockfd, msg, msg_len, 0) != msg_len)
    {
        error("Error sending message to server");
    }

    // Receive a message from the server
    char *response = malloc(1024);
    int response_len = recv(sockfd, response, 1024, 0);
    if (response_len < 0)
    {
        error("Error receiving message from server");
    }

    // Print the server's response
    printf("Server response: %s\n", response);

    // Close the socket
    close(sockfd);

    return 0;
}