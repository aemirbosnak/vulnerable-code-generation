//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// Function to print a message
void printMessage(char *message) {
    printf("%s", message);
}

// Function to send a message to a client
void sendMessage(int sockfd, char *message) {
    int len = strlen(message);
    int sent = send(sockfd, message, len, 0);
    if (sent < 0) {
        perror("Error sending message");
        exit(1);
    }
}

// Function to receive a message from a client
char* receiveMessage(int sockfd) {
    char buffer[256];
    int len = recv(sockfd, buffer, 255, 0);
    if (len < 0) {
        perror("Error receiving message");
        exit(1);
    }
    buffer[len] = '\0';
    return buffer;
}

// Function to create a socket
int createSocket(int port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    int bindResult = bind(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
    if (bindResult < 0) {
        perror("Error binding socket");
        exit(1);
    }
    return sockfd;
}

// Main function
int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }
    int port = atoi(argv[1]);
    int sockfd = createSocket(port);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }
    printf("Server started on port %d\n", port);

    // Infinite loop to accept incoming connections
    while (1) {
        int clientSocket = accept(sockfd, NULL, NULL);
        if (clientSocket < 0) {
            perror("Error accepting client");
            exit(1);
        }
        char *message = receiveMessage(clientSocket);
        sendMessage(clientSocket, "Welcome to the server!\n");
        close(clientSocket);
    }
    return 0;
}