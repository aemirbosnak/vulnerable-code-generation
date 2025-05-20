//GEMINI-pro DATASET v1.0 Category: Intrusion detection system ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// Global variables
int sockfd;
struct sockaddr_in servaddr;

// Function to create a socket and connect to the server
int connect_to_server(char *ip, int port) {
    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return -1;
    }

    // Set the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    if (inet_pton(AF_INET, ip, &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        return -1;
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("connect");
        return -1;
    }

    return 0;
}

// Function to send data to the server
int send_data(char *data) {
    // Send the data
    int n = send(sockfd, data, strlen(data), 0);
    if (n == -1) {
        perror("send");
        return -1;
    }

    return 0;
}

// Function to receive data from the server
int receive_data(char *buf) {
    // Receive the data
    int n = recv(sockfd, buf, 1024, 0);
    if (n == -1) {
        perror("recv");
        return -1;
    }

    return 0;
}

// Main function
int main(int argc, char *argv[]) {
    // Check the arguments
    if (argc != 3) {
        printf("Usage: %s <ip> <port>\n", argv[0]);
        return -1;
    }

    // Connect to the server
    if (connect_to_server(argv[1], atoi(argv[2])) == -1) {
        return -1;
    }

    // Send a message to the server
    if (send_data("Hello world!") == -1) {
        return -1;
    }

    // Receive a message from the server
    char buf[1024];
    if (receive_data(buf) == -1) {
        return -1;
    }

    // Print the message from the server
    printf("%s\n", buf);

    // Close the socket
    close(sockfd);

    return 0;
}