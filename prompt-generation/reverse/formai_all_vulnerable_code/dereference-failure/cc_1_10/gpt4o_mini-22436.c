//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define SMTP_PORT 587
#define BUFFER_SIZE 512

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void send_email(const char *hostname, const char *from, const char *to, const char *subject, const char *message) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    
    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        handle_error("Socket creation failed");
    }

    // Resolve server address
    struct hostent *server = gethostbyname(hostname);
    if (server == NULL) {
        handle_error("Failed to resolve hostname");
    }

    // Configure server address struct
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr_list[0], server->h_length);
    server_addr.sin_port = htons(SMTP_PORT);

    // Connect to server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("Connection to the server failed");
    }

    // Read server response
    read(sockfd, buffer, BUFFER_SIZE);
    printf("%s", buffer);

    // Send EHLO command
    snprintf(buffer, sizeof(buffer), "EHLO localhost\r\n");
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, BUFFER_SIZE);
    printf("%s", buffer);

    // Start TLS (optional, not implemented for simplicity)
    // Normally you'd send STARTTLS and upgrade to secure connection

    // Send MAIL FROM command
    snprintf(buffer, sizeof(buffer), "MAIL FROM:<%s>\r\n", from);
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, BUFFER_SIZE);
    printf("%s", buffer);

    // Send RCPT TO command
    snprintf(buffer, sizeof(buffer), "RCPT TO:<%s>\r\n", to);
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, BUFFER_SIZE);
    printf("%s", buffer);

    // Send DATA command
    snprintf(buffer, sizeof(buffer), "DATA\r\n");
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, BUFFER_SIZE);
    printf("%s", buffer);

    // Prepare the email content
    snprintf(buffer, sizeof(buffer),
             "Subject: %s\r\n"
             "From: %s\r\n"
             "To: %s\r\n"
             "\r\n"
             "%s\r\n"
             ".\r\n", 
             subject, from, to, message);
    
    // Send email content
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, BUFFER_SIZE);
    printf("%s", buffer);

    // Send QUIT command
    snprintf(buffer, sizeof(buffer), "QUIT\r\n");
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, BUFFER_SIZE);
    printf("%s", buffer);

    // Close socket
    close(sockfd);
}

int main() {
    const char *hostname = "smtp.example.com"; // Replace with your SMTP server
    const char *from = "your-email@example.com"; // Replace with your email
    const char *to = "recipient@example.com"; // Replace with recipient's email
    const char *subject = "Test Email";
    const char *message = "Hello, this is a test email sent from a C SMTP client.";

    send_email(hostname, from, to, subject, message);

    return 0;
}