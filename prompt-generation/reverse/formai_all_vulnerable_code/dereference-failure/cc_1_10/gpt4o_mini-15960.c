//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SMTP_PORT 25
#define POP3_PORT 110
#define BUFFER_SIZE 1024

// Surprise! An email client!
void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void smtp_send_email(const char *smtp_server, const char *from, const char *to, const char *subject, const char *body) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // Prepare to connect to the SMTP server
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        handle_error("Socket creation failed! What a plot twist!");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    if (inet_pton(AF_INET, smtp_server, &server_addr.sin_addr) <= 0) {
        handle_error("Invalid address! Did someone change the SMTP server?");
    }

    // Surprise! Connecting to the SMTP server!
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("Connection failed! Did the mail fairy just disappear?");
    }

    // Read server response
    read(sockfd, buffer, BUFFER_SIZE);
    printf("Server: %s", buffer);

    // SMTP transactions
    snprintf(buffer, sizeof(buffer), "HELO %s\r\n", smtp_server);
    send(sockfd, buffer, strlen(buffer), 0);
    read(sockfd, buffer, BUFFER_SIZE);
    printf("Server: %s", buffer);

    snprintf(buffer, sizeof(buffer), "MAIL FROM:<%s>\r\n", from);
    send(sockfd, buffer, strlen(buffer), 0);
    read(sockfd, buffer, BUFFER_SIZE);
    printf("Server: %s", buffer);

    snprintf(buffer, sizeof(buffer), "RCPT TO:<%s>\r\n", to);
    send(sockfd, buffer, strlen(buffer), 0);
    read(sockfd, buffer, BUFFER_SIZE);
    printf("Server: %s", buffer);

    snprintf(buffer, sizeof(buffer), "DATA\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    read(sockfd, buffer, BUFFER_SIZE);
    printf("Server: %s", buffer);

    snprintf(buffer, sizeof(buffer), "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, body);
    send(sockfd, buffer, strlen(buffer), 0);
    read(sockfd, buffer, BUFFER_SIZE);
    printf("Server: %s", buffer);

    // Closing the connection
    snprintf(buffer, sizeof(buffer), "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    read(sockfd, buffer, BUFFER_SIZE);
    printf("Server: %s", buffer);

    close(sockfd);
    printf("Email sent! 🎉 What a shocking twist!\n");
}

void pop3_fetch_email(const char *pop3_server, const char *username, const char *password) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // Surprise! Attempting to connect to the POP3 server!
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        handle_error("Socket creation failed! Oh no!");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    if (inet_pton(AF_INET, pop3_server, &server_addr.sin_addr) <= 0) {
        handle_error("Invalid address! Where did the emails go?");
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("Connection failed! What a surprise ending!");
    }

    // Read server response
    read(sockfd, buffer, BUFFER_SIZE);
    printf("Server: %s", buffer);

    // Authentication with the POP3 server
    snprintf(buffer, sizeof(buffer), "USER %s\r\n", username);
    send(sockfd, buffer, strlen(buffer), 0);
    read(sockfd, buffer, BUFFER_SIZE);
    printf("Server: %s", buffer);

    snprintf(buffer, sizeof(buffer), "PASS %s\r\n", password);
    send(sockfd, buffer, strlen(buffer), 0);
    read(sockfd, buffer, BUFFER_SIZE);
    printf("Server: %s", buffer);

    // List messages
    send(sockfd, "LIST\r\n", 7, 0);
    read(sockfd, buffer, BUFFER_SIZE);
    printf("Server: %s", buffer);

    // Surprise! Fetch email content!
    send(sockfd, "RETR 1\r\n", 9, 0);
    read(sockfd, buffer, BUFFER_SIZE);
    printf("Email Content: %s", buffer);

    // Closing the connection
    send(sockfd, "QUIT\r\n", 7, 0);
    read(sockfd, buffer, BUFFER_SIZE);
    printf("Server: %s", buffer);

    close(sockfd);
    printf("Emails fetched! 🌟 What an unexpected adventure!\n");
}

int main() {
    const char *smtp_server = "smtp.example.com";
    const char *pop3_server = "pop.example.com";
    const char *from = "you@example.com";
    const char *to = "friend@example.com";
    const char *subject = "Surprising Email!";
    const char *body = "Hello! This is a surprising email from your C email client!";
    const char *username = "you@example.com";
    const char *password = "password"; // Do NOT hard-code passwords in real apps!

    smtp_send_email(smtp_server, from, to, subject, body); // Send an email
    pop3_fetch_email(pop3_server, username, password); // Fetch emails

    return 0;
}