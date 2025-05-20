//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAXLINE 1024
#define PORT 587  // Port for SMTP
#define SERVER "smtp.example.com"  // Change to your SMTP server

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void send_email(int sock, const char *email_content) {
    send(sock, email_content, strlen(email_content), 0);
}

int main() {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[MAXLINE];
    const char *username = "your_email@example.com";  // Change to your email
    const char *password = "your_password";            // Change to your password
    const char *to = "recipient@example.com";          // Change to recipient email
    const char *subject = "Test Email from C Client";
    const char *body = "This is a test email.";

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        error("Error in creating socket");
    }
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("192.0.2.1");  // Use actual SMTP server IP or hostname

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection to server failed");
    }

    // Receive server response
    read(sock, buffer, MAXLINE);
    printf("Server: %s", buffer);
    
    // Send HELO command
    send_email(sock, "HELO localhost\r\n");
    read(sock, buffer, MAXLINE);
    printf("Server: %s", buffer);

    // Authenticate
    send_email(sock, "AUTH LOGIN\r\n");
    read(sock, buffer, MAXLINE);
    printf("Server: %s", buffer);

    // Send encoded username
    send_email(sock, "base64_encoded_username\r\n"); // Replace with base64 encoded username
    read(sock, buffer, MAXLINE);
    printf("Server: %s", buffer);

    // Send encoded password
    send_email(sock, "base64_encoded_password\r\n"); // Replace with base64 encoded password
    read(sock, buffer, MAXLINE);
    printf("Server: %s", buffer);

    // Mail From
    char mail_from[MAXLINE];
    snprintf(mail_from, sizeof(mail_from), "MAIL FROM:<%s>\r\n", username);
    send_email(sock, mail_from);
    read(sock, buffer, MAXLINE);
    printf("Server: %s", buffer);
    
    // RCPT TO
    char rcpt_to[MAXLINE];
    snprintf(rcpt_to, sizeof(rcpt_to), "RCPT TO:<%s>\r\n", to);
    send_email(sock, rcpt_to);
    read(sock, buffer, MAXLINE);
    printf("Server: %s", buffer);

    // DATA
    send_email(sock, "DATA\r\n");
    read(sock, buffer, MAXLINE);
    printf("Server: %s", buffer);

    // Email content
    char email[MAXLINE * 10];  // Adjust size as necessary
    snprintf(email, sizeof(email),
             "Subject: %s\r\n"
             "To: %s\r\n"
             "From: %s\r\n"
             "\r\n"
             "%s\r\n"
             ".\r\n", subject, to, username, body);
    
    send_email(sock, email);
    read(sock, buffer, MAXLINE);
    printf("Server: %s", buffer);
    
    // QUIT
    send_email(sock, "QUIT\r\n");
    read(sock, buffer, MAXLINE);
    printf("Server: %s", buffer);

    close(sock);
    return 0;
}