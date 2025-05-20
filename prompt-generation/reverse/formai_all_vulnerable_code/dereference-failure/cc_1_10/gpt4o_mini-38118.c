//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAXLINE 1024

// Function to send and receive messages
void send_recv(int sockfd, const char *msg, char *response) {
    send(sockfd, msg, strlen(msg), 0);
    recv(sockfd, response, MAXLINE, 0);
    printf("Server: %s", response);
}

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in servaddr;
    char sendline[MAXLINE], recvline[MAXLINE];
    char user[50], pass[50];
    const char *hostname = "mail.example.com"; // Change to your POP3 server

    // Check if username and password are provided
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    strcpy(user, argv[1]);
    strcpy(pass, argv[2]);

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set server address
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(110); // POP3 port
    servaddr.sin_addr.s_addr = inet_addr("192.0.2.1"); // Replace with your server's IP

    // Connect to the POP3 server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Connection to server failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Receive server greeting
    recv(sockfd, recvline, MAXLINE, 0);
    printf("Server: %s", recvline);

    // Send USER command
    snprintf(sendline, sizeof(sendline), "USER %s\r\n", user);
    send_recv(sockfd, sendline, recvline);

    // Send PASS command
    snprintf(sendline, sizeof(sendline), "PASS %s\r\n", pass);
    send_recv(sockfd, sendline, recvline);

    // Send STAT command to get message count
    snprintf(sendline, sizeof(sendline), "STAT\r\n");
    send_recv(sockfd, sendline, recvline);

    // Send LIST command to get message list
    snprintf(sendline, sizeof(sendline), "LIST\r\n");
    send_recv(sockfd, sendline, recvline);

    // Sending RETR command to get a specific message, assuming message 1
    snprintf(sendline, sizeof(sendline), "RETR 1\r\n");
    send_recv(sockfd, sendline, recvline);

    // Send QUIT command to close the connection
    snprintf(sendline, sizeof(sendline), "QUIT\r\n");
    send_recv(sockfd, sendline, recvline);

    close(sockfd);
    return 0;
}