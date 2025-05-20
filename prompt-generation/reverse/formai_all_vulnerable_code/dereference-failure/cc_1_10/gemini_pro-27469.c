//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Function to create a socket
int create_socket() {
    int sockfd;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error creating socket");
        exit(1);
    }

    return sockfd;
}

// Function to bind a socket to an address and port
void bind_socket(int sockfd, struct sockaddr_in *addr) {
    int addr_len = sizeof(*addr);

    // Bind the socket to the address and port
    if (bind(sockfd, (struct sockaddr *)addr, addr_len) == -1) {
        perror("Error binding socket");
        exit(1);
    }
}

// Function to listen for incoming connections
void listen_socket(int sockfd) {
    if (listen(sockfd, 5) == -1) {
        perror("Error listening for incoming connections");
        exit(1);
    }
}

// Function to accept an incoming connection
int accept_connection(int sockfd) {
    int new_sockfd;
    struct sockaddr_in client_addr;
    int client_addr_len = sizeof(client_addr);

    // Accept an incoming connection
    new_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
    if (new_sockfd == -1) {
        perror("Error accepting incoming connection");
        exit(1);
    }

    return new_sockfd;
}

// Function to send data to a socket
void send_data(int sockfd, const char *data) {
    int data_len = strlen(data);

    // Send the data to the socket
    if (send(sockfd, data, data_len, 0) == -1) {
        perror("Error sending data");
        exit(1);
    }
}

// Function to receive data from a socket
char *receive_data(int sockfd) {
    char *data;
    int data_len;

    // Receive the data from the socket
    data_len = recv(sockfd, data, 1024, 0);
    if (data_len == -1) {
        perror("Error receiving data");
        exit(1);
    }

    // Null-terminate the data
    data[data_len] = '\0';

    return data;
}

// Function to close a socket
void close_socket(int sockfd) {
    if (close(sockfd) == -1) {
        perror("Error closing socket");
        exit(1);
    }
}

int main() {
    int sockfd, new_sockfd;
    struct sockaddr_in addr;
    char *data;

    // Create a socket
    sockfd = create_socket();

    // Bind the socket to an address and port
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = INADDR_ANY;
    bind_socket(sockfd, &addr);

    // Listen for incoming connections
    listen_socket(sockfd);

    // Accept an incoming connection
    new_sockfd = accept_connection(sockfd);

    // Receive data from the client
    data = receive_data(new_sockfd);

    // Send data to the client
    send_data(new_sockfd, "Hello, world!");

    // Close the socket
    close_socket(sockfd);
    close_socket(new_sockfd);

    return 0;
}