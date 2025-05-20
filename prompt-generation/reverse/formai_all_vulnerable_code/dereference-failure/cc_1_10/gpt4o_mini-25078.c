//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SMTP_PORT 587
#define BUFFER_SIZE 1024

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void smtp_send(int sockfd, const char *msg) {
    if (send(sockfd, msg, strlen(msg), 0) < 0) {
        handle_error("Send failed");
    }
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_received < 0) {
        handle_error("Receive failed");
    }
    buffer[bytes_received] = '\0';
    printf("%s", buffer);
}

void smtp_auth_login(int sockfd, const char *username, const char *password) {
    smtp_send(sockfd, "EHLO localhost\r\n");
    smtp_send(sockfd, "AUTH LOGIN\r\n");
    char encoded_username[BUFFER_SIZE];
    char encoded_password[BUFFER_SIZE];

    // Base64 encode username
    snprintf(encoded_username, sizeof(encoded_username), "%s\r\n", username);
    smtp_send(sockfd, encoded_username);

    // Base64 encode password
    snprintf(encoded_password, sizeof(encoded_password), "%s\r\n", password);
    smtp_send(sockfd, encoded_password);
}

void smtp_send_email(int sockfd, const char *from, const char *to, const char *subject, const char *body) {
    smtp_send(sockfd, "MAIL FROM:<");
    smtp_send(sockfd, from);
    smtp_send(sockfd, ">\r\n");
    
    smtp_send(sockfd, "RCPT TO:<");
    smtp_send(sockfd, to);
    smtp_send(sockfd, ">\r\n");

    smtp_send(sockfd, "DATA\r\n");
    
    char data[BUFFER_SIZE];
    snprintf(data, sizeof(data), "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, body);
    smtp_send(sockfd, data);
}

int main() {
    const char *smtp_server = "smtp.example.com"; // Replace with your SMTP server
    const char *username = "user@example.com"; // Your email username
    const char *password = "your_password"; // Your email password
    const char *from = "user@example.com"; // Your email
    const char *to = "recipient@example.com"; // Recipient email
    const char *subject = "Test Email";
    const char *body = "Hello, this is a test email from the C SMTP client.";

    int sockfd;
    struct hostent *server;
    struct sockaddr_in serv_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        handle_error("Unable to create socket");
    }

    server = gethostbyname(smtp_server);
    if (server == NULL) {
        fprintf(stderr, "No such host: %s\n", smtp_server);
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(SMTP_PORT);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        handle_error("Unable to connect");
    }

    smtp_send(sockfd, "HELO localhost\r\n");

    smtp_auth_login(sockfd, username, password);
    smtp_send_email(sockfd, from, to, subject, body);

    smtp_send(sockfd, "QUIT\r\n");

    close(sockfd);
    printf("Email sent successfully!\n");

    return EXIT_SUCCESS;
}