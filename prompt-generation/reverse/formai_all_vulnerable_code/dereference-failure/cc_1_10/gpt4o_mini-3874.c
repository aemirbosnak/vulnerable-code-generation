//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SMTP_PORT 25
#define BUFFER_SIZE 1024

void check_response(int sockfd, const char *expected_code) {
    char buffer[BUFFER_SIZE];
    read(sockfd, buffer, sizeof(buffer));
    if (strncmp(buffer, expected_code, 3) != 0) {
        fprintf(stderr, "Error: Unexpected response from server: %s", buffer);
        exit(EXIT_FAILURE);
    }
}

void send_command(int sockfd, const char *command) {
    write(sockfd, command, strlen(command));
    write(sockfd, "\r\n", 2);
}

int main() {
    const char *smtp_server = "smtp.example.com"; // Replace with your SMTP server
    const char *from = "sender@example.com";      // Replace with sender's email
    const char *to = "recipient@example.com";      // Replace with recipient's email
    const char *subject = "Test Email";
    const char *body = "This is a test email sent from my C SMTP client.";

    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    inet_pton(AF_INET, smtp_server, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    check_response(sockfd, "220");

    send_command(sockfd, "HELO localhost");
    check_response(sockfd, "250");

    send_command(sockfd, "MAIL FROM:<sender@example.com>");
    check_response(sockfd, "250");

    send_command(sockfd, "RCPT TO:<recipient@example.com>");
    check_response(sockfd, "250");

    send_command(sockfd, "DATA");
    check_response(sockfd, "354");

    // Sending email header and body
    char email[BUFFER_SIZE];
    snprintf(email, BUFFER_SIZE, "From: %s\r\nTo: %s\r\nSubject: %s\r\n\r\n%s", from, to, subject, body);
    write(sockfd, email, strlen(email));
    write(sockfd, "\r\n.\r\n", 5);
    check_response(sockfd, "250");

    send_command(sockfd, "QUIT");
    check_response(sockfd, "221");

    close(sockfd);
    printf("Email sent successfully!\n");
    return 0;
}