//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define SMTP_PORT 587

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void send_command(int sockfd, const char *cmd, const char *response) {
    char buffer[BUFFER_SIZE];
    
    // Send command to the SMTP server
    write(sockfd, cmd, strlen(cmd));
    write(sockfd, "\r\n", 2);
    
    // Receive server response
    read(sockfd, buffer, BUFFER_SIZE - 1);
    printf("%s", buffer);
    if (strncmp(buffer, response, 3) != 0) {
        fprintf(stderr, "Error: Unexpected server response\n");
        exit(1);
    }
}

void send_email(const char *smtp_server, const char *from, const char *to, const char *subject, const char *body) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    
    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) error("Error opening socket");

    // Set up server address struct
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    server_addr.sin_addr.s_addr = inet_addr(smtp_server);
    
    // Connect to the SMTP server
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0)
        error("Error connecting to SMTP server");

    // Read server greeting
    read(sockfd, buffer, BUFFER_SIZE - 1);
    printf("%s", buffer);

    // Send HELO command
    send_command(sockfd, "EHLO localhost", "250");
    
    // Authenticate (to be implemented: for simplicity's sake, it's omitted here)
    
    // Send MAIL FROM command
    snprintf(buffer, sizeof(buffer), "MAIL FROM:<%s>", from);
    send_command(sockfd, buffer, "250");
    
    // Send RCPT TO command
    snprintf(buffer, sizeof(buffer), "RCPT TO:<%s>", to);
    send_command(sockfd, buffer, "250");

    // Send DATA command
    send_command(sockfd, "DATA", "354");
    
    // Prepare email content
    snprintf(buffer, sizeof(buffer),
             "From: %s\r\n"
             "To: %s\r\n"
             "Subject: %s\r\n"
             "\r\n"
             "%s\r\n"
             ".\r\n", from, to, subject, body);
    
    // Send email content
    write(sockfd, buffer, strlen(buffer));
    
    // Read server response after sending email
    read(sockfd, buffer, BUFFER_SIZE - 1);
    printf("%s", buffer);
    
    // Send QUIT command
    send_command(sockfd, "QUIT", "221");
    
    // Clean up
    close(sockfd);
}

int main() {
    const char *smtp_server = "smtp.yourmailserver.com";   // Modify as needed
    const char *from = "your_email@example.com";          // Modify as needed
    const char *to = "recipient@example.com";              // Modify as needed
    const char *subject = "Test Email";
    const char *body = "This is a test email sent from a simple C Email Client.";

    send_email(smtp_server, from, to, subject, body);
    return 0;
}