//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SMTP_PORT 587
#define BUFFER_SIZE 1024

void send_command(int sockfd, const char *cmd, char *response) {
    send(sockfd, cmd, strlen(cmd), 0);
    recv(sockfd, response, BUFFER_SIZE - 1, 0);
}

void smtp_send_email(const char *smtp_server, const char *username, const char *password, 
                      const char *from, const char *to, const char *subject, const char *body) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Resolve SMTP server address
    struct hostent *host = gethostbyname(smtp_server);
    if (host == NULL) {
        perror("Failed to resolve host");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);

    // Connect to SMTP server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to the SMTP server failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Read server response
    recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    printf("%s", buffer);

    // Say HELO
    send_command(sockfd, "HELO localhost\r\n", buffer);
    printf("%s", buffer);

    // Start TLS if needed or skip if using plain
    // send_command(sockfd, "STARTTLS\r\n", buffer);
    // printf("%s", buffer);

    // Authenticate
    send_command(sockfd, "AUTH LOGIN\r\n", buffer);
    printf("%s", buffer);

    // Username
    char encoded_username[BUFFER_SIZE];
    snprintf(encoded_username, sizeof(encoded_username), "%s\r\n", username);
    send_command(sockfd, encoded_username, buffer);
    printf("%s", buffer);

    // Password
    char encoded_password[BUFFER_SIZE];
    snprintf(encoded_password, sizeof(encoded_password), "%s\r\n", password);
    send_command(sockfd, encoded_password, buffer);
    printf("%s", buffer);

    // Set sender
    char sender_command[BUFFER_SIZE];
    snprintf(sender_command, sizeof(sender_command), "MAIL FROM:<%s>\r\n", from);
    send_command(sockfd, sender_command, buffer);
    printf("%s", buffer);

    // Set recipient
    char recipient_command[BUFFER_SIZE];
    snprintf(recipient_command, sizeof(recipient_command), "RCPT TO:<%s>\r\n", to);
    send_command(sockfd, recipient_command, buffer);
    printf("%s", buffer);

    // Start data
    send_command(sockfd, "DATA\r\n", buffer);
    printf("%s", buffer);

    // Send email content
    char email_message[BUFFER_SIZE];
    snprintf(email_message, sizeof(email_message), "Subject: %s\r\nFrom: %s\r\nTo: %s\r\n\r\n%s\r\n.\r\n",
             subject, from, to, body);
    send_command(sockfd, email_message, buffer);
    printf("%s", buffer);

    // Quit
    send_command(sockfd, "QUIT\r\n", buffer);
    printf("%s", buffer);

    // Close socket
    close(sockfd);
}

int main() {
    const char *smtp_server = "smtp.example.com";
    const char *username = "your_username";
    const char *password = "your_password";
    const char *from = "sender@example.com";
    const char *to = "recipient@example.com";
    const char *subject = "Test Email";
    const char *body = "This is a test email sent from a simple SMTP client in C.";

    smtp_send_email(smtp_server, username, password, from, to, subject, body);

    return 0;
}