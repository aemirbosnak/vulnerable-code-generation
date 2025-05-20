//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

// Define the IP address and port of the server
#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8080

// Define the size of the buffer for receiving data from the server
#define BUFFER_SIZE 1024

// Create a socket for communication with the server
int create_socket() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error creating socket");
        exit(1);
    }
    return sockfd;
}

// Connect the socket to the server
void connect_socket(int sockfd) {
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    int status = connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if (status == -1) {
        perror("Error connecting to server");
        exit(1);
    }
}

// Send data to the server
void send_data(int sockfd, char* data) {
    int len = strlen(data);
    int bytes_sent = send(sockfd, data, len, 0);
    if (bytes_sent == -1) {
        perror("Error sending data");
        exit(1);
    }
}

// Receive data from the server
char* receive_data(int sockfd) {
    char* buffer = malloc(BUFFER_SIZE);
    int bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        perror("Error receiving data");
        exit(1);
    }
    return buffer;
}

// Close the socket
void close_socket(int sockfd) {
    close(sockfd);
}

int main() {
    // Create a socket
    int sockfd = create_socket();

    // Connect the socket to the server
    connect_socket(sockfd);

    // Send a message to the server
    char* message = "Hello from client!";
    send_data(sockfd, message);

    // Receive a response from the server
    char* response = receive_data(sockfd);
    printf("Response from server: %s\n", response);

    // Close the socket
    close_socket(sockfd);

    return 0;
}