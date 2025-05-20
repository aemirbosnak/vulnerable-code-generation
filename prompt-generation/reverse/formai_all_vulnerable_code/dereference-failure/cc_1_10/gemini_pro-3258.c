//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: active
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// Define the port number for the server
#define PORT 8080

// Define the maximum size of the message that can be received
#define MAX_MESSAGE_SIZE 1024

// Define the IP address of the server
#define SERVER_IP "127.0.0.1"

// Create the socket
int create_socket() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }
    return sockfd;
}

// Connect to the server
void connect_to_server(int sockfd) {
    struct sockaddr_in servaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = inet_addr(SERVER_IP);
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) != 0) {
        perror("Failed to connect to server");
        exit(EXIT_FAILURE);
    }
}

// Send a message to the server
void send_message(int sockfd, char *message) {
    int len = strlen(message);
    if (send(sockfd, message, len, 0) != len) {
        perror("Failed to send message");
        exit(EXIT_FAILURE);
    }
}

// Receive a message from the server
char *receive_message(int sockfd) {
    char *message = (char *)malloc(MAX_MESSAGE_SIZE);
    int len = recv(sockfd, message, MAX_MESSAGE_SIZE, 0);
    if (len == -1) {
        perror("Failed to receive message");
        exit(EXIT_FAILURE);
    }
    message[len] = '\0';
    return message;
}

// Close the socket
void close_socket(int sockfd) {
    close(sockfd);
}

// Main function
int main() {
    // Create the socket
    int sockfd = create_socket();

    // Connect to the server
    connect_to_server(sockfd);

    // Send a message to the server
    char *message = "Hello from client!";
    send_message(sockfd, message);

    // Receive a message from the server
    char *response = receive_message(sockfd);
    printf("Response from server: %s\n", response);

    // Close the socket
    close_socket(sockfd);

    return 0;
}