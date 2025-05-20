//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>

#define MAX_MESSAGE_SIZE 1024

// Global variables
int sockfd;
struct sockaddr_in server;
char message[MAX_MESSAGE_SIZE];

// Function to send email
void send_email(void) {
    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    
    // Set up the server address
    server.sin_family = AF_INET;
    server.sin_port = htons(25);
    server.sin_addr.s_addr = inet_addr("localhost");
    
    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }
    
    // Send email
    printf("Enter the email message: ");
    fgets(message, MAX_MESSAGE_SIZE, stdin);
    
    // Send email
    send(sockfd, message, strlen(message), 0);
    printf("Email sent!\n");
    
    // Close the socket
    close(sockfd);
}

// Function to receive email
void receive_email(void) {
    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    
    // Set up the server address
    server.sin_family = AF_INET;
    server.sin_port = htons(25);
    server.sin_addr.s_addr = inet_addr("localhost");
    
    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }
    
    // Receive email
    printf("Enter the email message: ");
    fgets(message, MAX_MESSAGE_SIZE, stdin);
    
    // Send email
    send(sockfd, message, strlen(message), 0);
    printf("Email received!\n");
    
    // Close the socket
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s [send|receive]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    if (!strcmp(argv[1], "send")) {
        send_email();
    } else if (!strcmp(argv[1], "receive")) {
        receive_email();
    } else {
        printf("Unknown command: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    
    return 0;
}