//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SMTP_PORT 587 // Standard port for SMTP
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void send_command(int sockfd, const char *command, char *response) {
    write(sockfd, command, strlen(command));
    write(sockfd, "\r\n", 2);
    read(sockfd, response, BUFFER_SIZE);
}

void smtp_auth(int sockfd, const char *username, const char *password) {
    char response[BUFFER_SIZE];

    // Start the authentication process
    send_command(sockfd, "EHLO smtp.example.com", response);
    printf("%s", response);

    // AUTH LOGIN
    send_command(sockfd, "AUTH LOGIN", response);
    printf("%s", response);

    // Send username
    char encoded_username[BUFFER_SIZE];
    // Base64 encode username (not implemented here for brevity)
    snprintf(encoded_username, BUFFER_SIZE, "encoded_username"); // Placeholder
    send_command(sockfd, encoded_username, response);
    printf("%s", response);

    // Send password
    char encoded_password[BUFFER_SIZE];
    // Base64 encode password (not implemented here for brevity)
    snprintf(encoded_password, BUFFER_SIZE, "encoded_password"); // Placeholder
    send_command(sockfd, encoded_password, response);
    printf("%s", response);
}

void send_email(const char *to, const char *from, const char *subject, const char *body) {
    int sockfd;
    struct sockaddr_in server_addr;
    char response[BUFFER_SIZE];

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error("Socket creation failed");
    }

    // Define server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    struct hostent *host = gethostbyname("smtp.example.com");
    if (host == NULL) {
        error("Failed to resolve hostname");
    }
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection to SMTP server failed");
    }

    // Receive server greeting
    read(sockfd, response, BUFFER_SIZE);
    printf("%s", response);

    // Authenticate
    smtp_auth(sockfd, "your_email@example.com", "your_password");

    // Start mail transaction
    send_command(sockfd, "MAIL FROM:<your_email@example.com>", response);
    printf("%s", response);
    send_command(sockfd, "RCPT TO:<recipient@example.com>", response);
    printf("%s", response);
    send_command(sockfd, "DATA", response);
    printf("%s", response);

    // Send email data
    char email_data[BUFFER_SIZE];
    snprintf(email_data, BUFFER_SIZE, "From: %s\r\nTo: %s\r\nSubject: %s\r\n\r\n%s\r\n.", from, to, subject, body);
    send_command(sockfd, email_data, response);
    printf("%s", response);

    // Quit the SMTP session
    send_command(sockfd, "QUIT", response);
    printf("%s", response);

    // Close the socket
    close(sockfd);
}

int main() {
    const char *to = "recipient@example.com";
    const char *from = "your_email@example.com";
    const char *subject = "Test Email from SMTP Client";
    const char *body = "This is a test email sent from the SMTP Client written in C.";

    send_email(to, from, subject, body);

    return 0;
}