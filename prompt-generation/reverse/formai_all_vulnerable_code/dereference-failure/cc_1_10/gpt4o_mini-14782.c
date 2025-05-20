//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SMTP_PORT 587
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void send_command(int sockfd, const char *cmd) {
    write(sockfd, cmd, strlen(cmd));
    write(sockfd, "\r\n", 2);
}

void read_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_read = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (bytes_read < 0) {
        error("Error reading response");
    }
    buffer[bytes_read] = '\0';
    printf("Server Response: %s", buffer);
}

int main() {
    const char *smtp_server = "smtp.example.com"; // Replace with your SMTP server
    const char *email_from = "your_email@example.com"; // Sender's email
    const char *email_to = "recipient@example.com"; // Recipient's email
    const char *subject = "Test Email from SMTP Client";
    const char *body = "This is a test email content.";
    
    int sockfd;
    struct sockaddr_in server_addr;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Could not create socket");
    }

    // Setup the server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    inet_pton(AF_INET, smtp_server, &server_addr.sin_addr);

    // Connect to the SMTP server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection failed");
    }

    read_response(sockfd); // Read server greeting

    // EHLO command
    send_command(sockfd, "EHLO localhost");
    read_response(sockfd); // Read response

    // Start TLS (if your server requires it, add logic for STARTTLS here)
    // send_command(sockfd, "STARTTLS");
    // read_response(sockfd);

    // AUTH LOGIN (base64 encoded login)
    send_command(sockfd, "AUTH LOGIN");
    read_response(sockfd);
    
    // Placeholder for base64 encoding the username and password
    // You would typically base64 encode your username and password here.
    // For simplicity, we'll skip that here. Replace "base64_user" and "base64_pass" with actual encoded strings.
    send_command(sockfd, "base64_user"); // Replace with actual base64 encoded username
    read_response(sockfd);
    send_command(sockfd, "base64_pass"); // Replace with actual base64 encoded password
    read_response(sockfd);

    // MAIL FROM
    char mail_from[BUFFER_SIZE];
    snprintf(mail_from, BUFFER_SIZE, "MAIL FROM:<%s>", email_from);
    send_command(sockfd, mail_from);
    read_response(sockfd);

    // RCPT TO
    char rcpt_to[BUFFER_SIZE];
    snprintf(rcpt_to, BUFFER_SIZE, "RCPT TO:<%s>", email_to);
    send_command(sockfd, rcpt_to);
    read_response(sockfd);

    // DATA command
    send_command(sockfd, "DATA");
    read_response(sockfd);

    // Email headers and body
    char email_data[BUFFER_SIZE * 2];
    snprintf(email_data, sizeof(email_data),
             "From: %s\r\n"
             "To: %s\r\n"
             "Subject: %s\r\n"
             "\r\n"
             "%s\r\n"
             ".",
             email_from, email_to, subject, body);

    // Send email content
    send_command(sockfd, email_data);
    read_response(sockfd);

    // Quit command
    send_command(sockfd, "QUIT");
    read_response(sockfd);

    close(sockfd);
    return 0;
}