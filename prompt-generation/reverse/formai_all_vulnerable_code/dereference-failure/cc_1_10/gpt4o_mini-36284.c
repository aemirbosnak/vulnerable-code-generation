//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <ctype.h>

#define SERVER_PORT 25
#define BUFFER_SIZE 1024
#define MAX_EMAIL 256

void clear_buffer(char *buffer, size_t size) {
    for (size_t i = 0; i < size; i++) {
        buffer[i] = '\0';
    }
}

void handle_error(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void send_email(int sockfd, const char *email_from, const char *email_to, const char *subject, const char *body) {
    char buffer[BUFFER_SIZE];
    
    snprintf(buffer, sizeof(buffer), "MAIL FROM:<%s>\r\n", email_from);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, BUFFER_SIZE-1, 0);
    printf("%s", buffer);
    
    snprintf(buffer, sizeof(buffer), "RCPT TO:<%s>\r\n", email_to);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, BUFFER_SIZE-1, 0);
    printf("%s", buffer);
    
    send(sockfd, "DATA\r\n", 6, 0);
    recv(sockfd, buffer, BUFFER_SIZE-1, 0);
    printf("%s", buffer);
    
    snprintf(buffer, sizeof(buffer), "Subject: %s\r\n", subject);
    send(sockfd, buffer, strlen(buffer), 0);
    send(sockfd, body, strlen(body), 0);
    send(sockfd, "\r\n.\r\n", 5, 0); // End of data
    recv(sockfd, buffer, BUFFER_SIZE-1, 0);
    printf("%s", buffer);
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    
    const char *smtp_server = "localhost"; // Change this to your SMTP server address
    const char *email_from = "sender@example.com";
    const char *email_to = "recipient@example.com";
    const char *subject = "Test Email from C Client";
    const char *body = "Hello, this is a test email sent from a simple C email client.";

    clear_buffer(buffer, BUFFER_SIZE);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        handle_error("Socket creation failed");
    }

    // Set up server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, smtp_server, &server_addr.sin_addr);

    // Connect to the SMTP server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("Connection to the server failed");
    }

    // Read server greeting
    recv(sockfd, buffer, BUFFER_SIZE-1, 0);
    printf("Server: %s", buffer);
    
    // Send HELO command
    send(sockfd, "HELO localhost\r\n", 17, 0);
    recv(sockfd, buffer, BUFFER_SIZE-1, 0);
    printf("%s", buffer);
    
    // Sending the email
    send_email(sockfd, email_from, email_to, subject, body);
    
    // Send QUIT command
    send(sockfd, "QUIT\r\n", 6, 0);
    recv(sockfd, buffer, BUFFER_SIZE-1, 0);
    printf("%s", buffer);

    // Close socket
    close(sockfd);
    return 0;
}