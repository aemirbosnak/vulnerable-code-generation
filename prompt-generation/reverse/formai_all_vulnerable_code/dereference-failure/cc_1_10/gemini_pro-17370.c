//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

// This is a very simple client program for a text-based chat server.
// It connects to the server on a specified IP address and port,
// and then sends and receives messages until the user enters "quit".

int main(int argc, char *argv[])
{
    // Check if the user has specified the IP address and port of the server.
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <IP address> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the IP address and port of the server.
    char *ip_address = argv[1];
    int port = atoi(argv[2]);

    // Create a socket for connecting to the server.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Create a sockaddr_in structure for the server's address.
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip_address);

    // Connect to the server.
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Get the welcome message from the server.
    char welcome_msg[1024];
    if (recv(sockfd, welcome_msg, sizeof(welcome_msg), 0) == -1)
    {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Print the welcome message.
    printf("%s\n", welcome_msg);

    // Enter the main chat loop.
    char msg[1024];
    while (1)
    {
        // Get a message from the user.
        printf("> ");
        fgets(msg, sizeof(msg), stdin);

        // Check if the user has entered "quit".
        if (strcmp(msg, "quit\n") == 0)
        {
            break;
        }

        // Send the message to the server.
        if (send(sockfd, msg, strlen(msg), 0) == -1)
        {
            perror("send");
            return EXIT_FAILURE;
        }

        // Get the response from the server.
        char response[1024];
        if (recv(sockfd, response, sizeof(response), 0) == -1)
        {
            perror("recv");
            return EXIT_FAILURE;
        }

        // Print the response.
        printf("%s\n", response);
    }

    // Close the socket.
    close(sockfd);

    return EXIT_SUCCESS;
}