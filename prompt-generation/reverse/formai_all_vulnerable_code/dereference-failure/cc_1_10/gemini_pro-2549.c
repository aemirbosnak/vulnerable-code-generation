//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_SIZE 1024

// Function to create a socket
int create_socket() {
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
    return sockfd;
}

// Function to bind the socket to a port
void bind_socket(int sockfd, int port) {
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(port);
    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("socket bind failed");
        exit(EXIT_FAILURE);
    }
}

// Function to listen for incoming connections
void listen_for_connections(int sockfd) {
    if (listen(sockfd, 5) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }
}

// Function to accept incoming connections
int accept_connection(int sockfd) {
    int newsockfd;
    struct sockaddr_in cliaddr;
    socklen_t clilen = sizeof(cliaddr);
    if ((newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr, &clilen)) < 0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }
    return newsockfd;
}

// Function to send data to the client
void send_data(int sockfd, char *data) {
    if (send(sockfd, data, strlen(data), 0) < 0) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }
}

// Function to receive data from the client
char *receive_data(int sockfd) {
    char *buffer = malloc(MAX_SIZE);
    memset(buffer, 0, MAX_SIZE);
    if (recv(sockfd, buffer, MAX_SIZE, 0) < 0) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }
    return buffer;
}

// Main function
int main() {
    int sockfd, newsockfd;
    char *buffer;

    // Create a socket
    sockfd = create_socket();

    // Bind the socket to a port
    bind_socket(sockfd, PORT);

    // Listen for incoming connections
    listen_for_connections(sockfd);

    // Accept incoming connections
    newsockfd = accept_connection(sockfd);

    // Send data to the client
    send_data(newsockfd, "Hello from the server!");

    // Receive data from the client
    buffer = receive_data(newsockfd);
    printf("Message from the client: %s\n", buffer);

    // Close the socket
    close(newsockfd);
    close(sockfd);

    return 0;
}