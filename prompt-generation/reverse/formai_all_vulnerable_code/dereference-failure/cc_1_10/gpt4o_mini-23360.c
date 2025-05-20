//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SMTP_PORT 25
#define BUFFER_SIZE 1024

void send_command(int sockfd, const char *command, char *response) {
    write(sockfd, command, strlen(command));
    write(sockfd, "\r\n", 2);
    read(sockfd, response, BUFFER_SIZE);
}

void smtp_auth(int sockfd) {
    char response[BUFFER_SIZE];
    
    send_command(sockfd, "EHLO localhost", response);
    printf("%s", response);
    
    // You can add authentication commands here if needed
}

void send_email(int sockfd, const char *from, const char *to, const char *subject, const char *body) {
    char response[BUFFER_SIZE];

    // Set sender
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "MAIL FROM: <%s>", from);
    send_command(sockfd, command, response);
    
    // Set recipient
    snprintf(command, sizeof(command), "RCPT TO: <%s>", to);
    send_command(sockfd, command, response);

    // Start the DATA section
    send_command(sockfd, "DATA", response);

    // Send email content
    snprintf(command, sizeof(command), "Subject: %s\r\n\r\n%s\r\n.", subject, body);
    send_command(sockfd, command, response);
    
    // End the email message
    send_command(sockfd, "QUIT", response);
}

int main() {
    const char *smtp_server = "127.0.0.1"; // Change to your SMTP server IP
    const char *from = "example@domain.com"; // Change to your From address
    const char *to = "recipient@domain.com"; // Change to your To address
    const char *subject = "Test Email";
    const char *body = "This is a test email sent from a minimal SMTP client.\n";

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return EXIT_FAILURE;
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SMTP_PORT);
    server_address.sin_addr.s_addr = inet_addr(smtp_server);

    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Connection to SMTP server failed");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Start communication with the SMTP server
    char response[BUFFER_SIZE];
    read(sockfd, response, BUFFER_SIZE);
    printf("%s", response);

    // Authenticate and send email
    smtp_auth(sockfd);
    send_email(sockfd, from, to, subject, body);

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}