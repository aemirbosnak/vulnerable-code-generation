//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

// Define the port number for the server
#define PORT 8080

// Create a socket
int create_socket() {
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Could not create socket");
        exit(1);
    }
    return sockfd;
}

// Bind the socket to an address
void bind_socket(int sockfd) {
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("Could not bind socket");
        exit(1);
    }
}

// Listen for incoming connections
void listen_for_connections(int sockfd) {
    if (listen(sockfd, 5) == -1) {
        perror("Could not listen for connections");
        exit(1);
    }
}

// Accept incoming connections
int accept_connection(int sockfd) {
    int newsockfd;
    struct sockaddr_in cli_addr;
    int clilen = sizeof(cli_addr);
    if ((newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen)) == -1) {
        perror("Could not accept connection");
        exit(1);
    }
    return newsockfd;
}

// Send data to a client
void send_data(int sockfd, char *data) {
    if (send(sockfd, data, strlen(data), 0) == -1) {
        perror("Could not send data");
        exit(1);
    }
}

// Receive data from a client
char *receive_data(int sockfd) {
    char *buffer = malloc(1024);
    int n = read(sockfd, buffer, 1023);
    if (n == -1) {
        perror("Could not receive data");
        exit(1);
    }
    buffer[n] = '\0';
    return buffer;
}

// Close a socket
void close_socket(int sockfd) {
    if (close(sockfd) == -1) {
        perror("Could not close socket");
        exit(1);
    }
}

// Main function
int main() {
    // Create a socket
    int sockfd = create_socket();

    // Bind the socket to an address
    bind_socket(sockfd);

    // Listen for incoming connections
    listen_for_connections(sockfd);

    // Accept incoming connections
    int newsockfd = accept_connection(sockfd);

    // Send data to the client
    send_data(newsockfd, "Hello, world!\n");

    // Receive data from the client
    char *data = receive_data(newsockfd);
    printf("Received data: %s\n", data);

    // Close the sockets
    close_socket(newsockfd);
    close_socket(sockfd);

    return 0;
}