//MISTRAL-7B DATASET v1.0 Category: Building a POP3 Client ; Style: rigorous
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define SERVER_PORT 110
#define MAX_BUFFER_SIZE 4096
#define USER_AGENT "MyPOP3Client/1.0"

void die(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char **argv) {
    int sockfd;
    struct sockaddr_in serv_addr;
    char buffer[MAX_BUFFER_SIZE];
    ssize_t read_size;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <username> <password>\n", argv[0]);
        exit(1);
    }

    // Initialize socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        die("socket");
    }

    // Set up the server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);

    // Convert IPv4 address from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        die("Invalid address/ Address not supported");
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        die("Connection failed");
    }

    // Send USER command
    send(sockfd, "USER ", 5, 0);
    send(sockfd, argv[1], strlen(argv[1]), 0);
    send(sockfd, "\r\n", 2, 0);

    // Receive and print server response
    read_size = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
    if (read_size > 0) {
        printf("Server response: %.*s\n", (int)read_size, buffer);
    }

    // Send PASS command
    send(sockfd, "PASS ", 5, 0);
    send(sockfd, argv[2], strlen(argv[2]), 0);
    send(sockfd, "\r\n", 2, 0);

    // Receive and print server response
    read_size = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
    if (read_size > 0) {
        printf("Server response: %.*s\n", (int)read_size, buffer);
    }

    // Send STAT command
    send(sockfd, "STAT\r\n", 5, 0);

    // Receive and print server response
    read_size = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
    if (read_size > 0) {
        printf("Server response: %.*s\n", (int)read_size, buffer);
    }

    // Send RETR command for the first message
    send(sockfd, "RETR 1\r\n", 7, 0);

    // Receive and print message data
    while ((read_size = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0)) > 0) {
        printf("Message data: %.*s\n", (int)read_size, buffer);
    }

    // Close the connection
    close(sockfd);

    return 0;
}