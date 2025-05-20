//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SERVER "smtp.example.com"
#define PORT 587
#define BUFFER_SIZE 1024

// Function to send a command to the SMTP server and receive the response
int smtp_send_command(int sockfd, const char *command) {
    char buffer[BUFFER_SIZE];
    if (send(sockfd, command, strlen(command), 0) < 0) {
        perror("send failed");
        return -1;
    }
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("Server: %s", buffer);
    return 0;
}

// Function to authenticate with the SMTP server
int smtp_authenticate(int sockfd, const char *username, const char *password) {
    char command[BUFFER_SIZE];
    
    // Start SMTP conversation
    smtp_send_command(sockfd, "EHLO localhost\r\n");
    
    // Authorization
    smtp_send_command(sockfd, "AUTH LOGIN\r\n");
    
    // Send base64 encoded username
    snprintf(command, sizeof(command), "%s\r\n", "encoded_username"); // Placeholder for base64 username
    smtp_send_command(sockfd, command);
    
    // Send base64 encoded password
    snprintf(command, sizeof(command), "%s\r\n", "encoded_password"); // Placeholder for base64 password
    smtp_send_command(sockfd, command);
    
    return 0;
}

// Function to send an email
int smtp_send_email(int sockfd, const char *from, const char *to, const char *subject, const char *body) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "MAIL FROM:<%s>\r\n", from);
    smtp_send_command(sockfd, command);
    
    snprintf(command, sizeof(command), "RCPT TO:<%s>\r\n", to);
    smtp_send_command(sockfd, command);
    
    smtp_send_command(sockfd, "DATA\r\n");
    
    snprintf(command, sizeof(command), "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, body);
    smtp_send_command(sockfd, command);
    
    return 0;
}

// Main SMTP client function
int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *host;

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return -1;
    }

    // Define server properties
    host = gethostbyname(SERVER);
    if (host == NULL) {
        fprintf(stderr, "Could not find host\n");
        return -1;
    }
    
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);

    // Connect to the SMTP server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        return -1;
    }

    // SMTP Authentication
    smtp_authenticate(sockfd, "your_username@example.com", "your_password");

    // Sending Email
    smtp_send_email(sockfd, "your_username@example.com", "recipient@example.com", "Test Subject", "This is a test email body.");

    // Close the socket
    close(sockfd);
    
    return 0;
}