//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFF_SIZE 1024

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <ip_address> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int sockfd;
    struct sockaddr_in servaddr;
    char *ip_addr = argv[1];
    int port = atoi(argv[2]);

    // Create a socket and double-check its validity.
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket creation failed");
        return EXIT_FAILURE;
    }

    // Initialize the server address structure.
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    // Convert the IP address string to binary form and double-check the conversion.
    if (inet_pton(AF_INET, ip_addr, &servaddr.sin_addr) <= 0)
    {
        perror("invalid IP address");
        return EXIT_FAILURE;
    }

    // Connect to the server and double-check the connection status.
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("connection failed");
        return EXIT_FAILURE;
    }

    char *message = "Hello from paranoid\n";

    // Send the message to the server and double-check the sending status.
    if (send(sockfd, message, strlen(message), 0) < 0)
    {
        perror("send failed");
        return EXIT_FAILURE;
    }

    char buffer[BUFF_SIZE];
    int n;

    // Receive a response from the server and double-check the receiving status.
    if ((n = recv(sockfd, buffer, BUFF_SIZE, 0)) < 0)
    {
        perror("recv failed");
        return EXIT_FAILURE;
    }

    buffer[n] = '\0'; // Null-terminate the received message.

    // Print the server's response and double-check the printing status.
    if (fputs(buffer, stdout) < 0)
    {
        perror("fputs failed");
        return EXIT_FAILURE;
    }

    // Close the socket and double-check the closing status.
    if (close(sockfd) < 0)
    {
        perror("close failed");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}