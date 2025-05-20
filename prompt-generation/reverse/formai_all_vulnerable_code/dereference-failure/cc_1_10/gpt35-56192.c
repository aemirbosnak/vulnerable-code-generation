//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024
 
int main(int argc, char *argv[]) {
    int sockfd, n;
    char buffer[BUF_SIZE];
    struct sockaddr_in serv_addr;
 
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
 
    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
 
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
 
    // Initialize server address
    memset(&serv_addr, 0, sizeof(serv_addr));
 
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
     
    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
        perror("Invalid address or address not supported");
        exit(EXIT_FAILURE);
    }
 
    // Connect to server
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    } else {
        printf("Connected to server\n");
    }
 
    // Receive message from server
    memset(buffer, 0, sizeof(buffer));
 
    n = read(sockfd, buffer, sizeof(buffer));
 
    if (n < 0) {
        perror("Error while reading from server");
        exit(EXIT_FAILURE);
    } else {
        printf("Message from server: %s\n", buffer);
    }
 
    // Send message to server
    char message[] = "Hello from client";
 
    if (write(sockfd, message, sizeof(message)) < 0) {
        perror("Error while writing to server");
        exit(EXIT_FAILURE);
    } else {
        printf("Message sent to server\n");
    }
 
    // Close socket
    close(sockfd);
     
    return 0;
}