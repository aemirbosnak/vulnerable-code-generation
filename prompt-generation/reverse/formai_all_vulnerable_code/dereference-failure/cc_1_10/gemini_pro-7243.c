//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_in servaddr;

    if (argc != 3) {
        printf("Usage: %s <IP address> <port>\n", argv[0]);
        return 1;
    }

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return 1;
    }

    // Initialize the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        return 1;
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        return 1;
    }

    // Send a message to the server
    char *message = "Hello from the client!";
    if (send(sockfd, message, strlen(message), 0) < 0) {
        perror("send");
        return 1;
    }

    // Receive a message from the server
    char buffer[BUF_SIZE];
    int n;
    if ((n = recv(sockfd, buffer, BUF_SIZE, 0)) < 0) {
        perror("recv");
        return 1;
    }
    buffer[n] = '\0';

    // Print the message from the server
    printf("Received from server: %s\n", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}