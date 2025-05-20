//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>

#define MAX_BUF_SIZE 1024

int main()
{
    // Declare variables
    int sockfd, portno;
    char buf[MAX_BUF_SIZE], hostname[100];
    struct sockaddr_in server_addr;
    struct hostent *server;

    // Get hostname and port number from user
    printf("Enter hostname: ");
    scanf("%s", hostname);
    printf("Enter port number: ");
    scanf("%d", &portno);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Get the server's IP address
    server = gethostbyname(hostname);
    if (server == NULL)
    {
        perror("Error getting server IP address");
        exit(1);
    }

    // Set up the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(portno);
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Error connecting to server");
        exit(1);
    }

    // Send a message to the server
    sprintf(buf, "Hello from client!\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0)
    {
        perror("Error sending message to server");
        exit(1);
    }

    // Receive a message from the server
    if (recv(sockfd, buf, MAX_BUF_SIZE, 0) < 0)
    {
        perror("Error receiving message from server");
        exit(1);
    }

    // Print the message received from the server
    printf("Message received from server: %s\n", buf);

    // Close the socket
    close(sockfd);

    return 0;
}