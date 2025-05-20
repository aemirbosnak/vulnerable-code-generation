//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SMTP_SERVER "smtp.gmail.com"
#define SMTP_PORT 587

void check_email_response(int sockfd);
void send_smtp_command(int sockfd, const char *cmd);
void smtp_client(const char *from_address, const char *to_address, const char *subject, const char *message);

int main() {
    const char *from = "your_email@gmail.com";
    const char *to = "recipient_email@example.com";
    const char *subject = "A Creative SMTP Test";
    const char *message = "Hello there!\n\nThis is a creative SMTP test message from your friendly SMTP client.";

    smtp_client(from, to, subject, message);
    return 0;
}

void smtp_client(const char *from_address, const char *to_address, const char *subject, const char *message) {
    int sockfd;
    struct sockaddr_in server_addr;

    // Create the socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    if (inet_pton(AF_INET, SMTP_SERVER, &server_addr.sin_addr) <= 0) {
        perror("Invalid address or address not supported");
        exit(EXIT_FAILURE);
    }

    // Connect to the SMTP server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to the server failed");
        exit(EXIT_FAILURE);
    }

    check_email_response(sockfd);

    // Start the SMTP conversation
    send_smtp_command(sockfd, "EHLO localhost");
    send_smtp_command(sockfd, "MAIL FROM:<your_email@gmail.com>");
    send_smtp_command(sockfd, "RCPT TO:<recipient_email@example.com>");
    send_smtp_command(sockfd, "DATA");

    // Sending email headers
    char email[512];
    snprintf(email, sizeof(email),
             "From: %s\r\n"
             "To: %s\r\n"
             "Subject: %s\r\n"
             "\r\n"
             "%s\r\n"
             ".\r\n", 
             from_address, to_address, subject, message);

    // Send email data
    send(sockfd, email, strlen(email), 0);
    check_email_response(sockfd);

    // End the session
    send_smtp_command(sockfd, "QUIT");

    close(sockfd);
}

void check_email_response(int sockfd) {
    char buffer[1024] = {0};
    read(sockfd, buffer, sizeof(buffer) - 1);
    printf("Server: %s", buffer);
}

void send_smtp_command(int sockfd, const char *cmd) {
    send(sockfd, cmd, strlen(cmd), 0);
    send(sockfd, "\r\n", 2, 0);
    check_email_response(sockfd);
}