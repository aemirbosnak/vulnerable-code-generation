//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s <IP address> <port>\n", argv[0]);
        return 1;
    }

    int sockfd, port;
    struct sockaddr_in servaddr;

    // Create a socket.
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket.\n");
        return 1;
    }

    // Convert the port number to an integer.
    port = atoi(argv[2]);

    // Set the server address.
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(argv[1]);
    servaddr.sin_port = htons(port);

    // Connect to the server.
    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1) {
        printf("Error connecting to server.\n");
        return 1;
    }

    // Send a message to the server.
    char* message = "Hello, world!";
    if (send(sockfd, message, strlen(message), 0) == -1) {
        printf("Error sending message to server.\n");
        return 1;
    }

    // Receive a message from the server.
    char buffer[256];
    int n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n == -1) {
        printf("Error receiving message from server.\n");
        return 1;
    }

    // Print the message from the server.
    printf("Message from server: %s\n", buffer);

    // Close the socket.
    close(sockfd);

    return 0;
}