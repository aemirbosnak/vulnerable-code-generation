//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUFFER 1024

int main(int argc, char **argv) {
    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[MAX_BUFFER];

    // Check command line arguments
    if (argc != 3) {
        printf("Usage: %s <ip_address> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        printf("Invalid address/ Address not supported\n");
        exit(EXIT_FAILURE);
    }
    
    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("connection failed");
        exit(EXIT_FAILURE);
    }
    
    // Send email message
    sprintf(buffer, "HELO example.com\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    sprintf(buffer, "MAIL FROM: <sender@example.com>\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    sprintf(buffer, "RCPT TO: <recipient@example.com>\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    sprintf(buffer, "DATA\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    sprintf(buffer, "Subject: Test email\r\n\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    sprintf(buffer, "This is a test email.\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    sprintf(buffer, ".\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    sprintf(buffer, "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    
    // Close socket
    close(sockfd);
    
    return 0;
}