//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <time.h>

#define BUFSIZE 1024

// Global variables
int sockfd;
struct sockaddr_in server_addr;

// Function to initialize the socket
int init_socket(char *ip, int port) {
    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return -1;
    }

    // Set the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return -1;
    }

    return 0;
}

// Function to send a request to the server
int send_request(char *request) {
    // Send the request
    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("send");
        return -1;
    }

    return 0;
}

// Function to receive a response from the server
int receive_response(char *buffer) {
    // Receive the response
    if (recv(sockfd, buffer, BUFSIZE, 0) < 0) {
        perror("recv");
        return -1;
    }

    return 0;
}

// Function to close the socket
void close_socket() {
    // Close the socket
    close(sockfd);
}

// Main function
int main(int argc, char *argv[]) {
    // Check the arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <ip> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Initialize the socket
    if (init_socket(argv[1], atoi(argv[2])) < 0) {
        return EXIT_FAILURE;
    }

    // Send a request to the server
    char request[BUFSIZE];
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", argv[1]);
    if (send_request(request) < 0) {
        return EXIT_FAILURE;
    }

    // Receive a response from the server
    char buffer[BUFSIZE];
    if (receive_response(buffer) < 0) {
        return EXIT_FAILURE;
    }

    // Print the response
    printf("%s", buffer);

    // Close the socket
    close_socket();

    return EXIT_SUCCESS;
}