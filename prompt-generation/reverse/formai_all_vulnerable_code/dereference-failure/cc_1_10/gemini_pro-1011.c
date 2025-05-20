//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[])
{
    // Check if the user provided enough arguments.
    if (argc != 4)
    {
        printf("Usage: %s <server_ip> <server_port> <email_address>\n", argv[0]);
        exit(1);
    }

    // Get the server's IP address and port number.
    char *server_ip = argv[1];
    int server_port = atoi(argv[2]);

    // Get the email address of the recipient.
    char *email_address = argv[3];

    // Create a socket to connect to the server.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Set up the server's address.
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(server_ip);
    server_addr.sin_port = htons(server_port);

    // Connect to the server.
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Error connecting to server");
        exit(1);
    }

    // Send the email address of the recipient to the server.
    int len = strlen(email_address);
    if (send(sockfd, &len, sizeof(int), 0) < 0)
    {
        perror("Error sending email address");
        exit(1);
    }
    if (send(sockfd, email_address, len, 0) < 0)
    {
        perror("Error sending email address");
        exit(1);
    }

    // Receive the response from the server.
    char response[256];
    if (recv(sockfd, response, sizeof(response), 0) < 0)
    {
        perror("Error receiving response");
        exit(1);
    }

    // Print the response from the server.
    printf("%s\n", response);

    // Close the socket.
    close(sockfd);

    return 0;
}