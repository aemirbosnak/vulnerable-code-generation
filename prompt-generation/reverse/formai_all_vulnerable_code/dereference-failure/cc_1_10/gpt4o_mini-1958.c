//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 25 // SMTP Port for email sending
#define BUFFER_SIZE 1024

void die(const char *message) {
    perror(message);
    exit(1);
}

void send_email(const char *smtp_server, const char *from, const char *to, const char *subject, const char *body) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        die("Failed to create socket");
    }

    // Get SMTP server IP
    struct hostent *host = gethostbyname(smtp_server);
    if (!host) {
        die("Failed to get hostname");
    }

    // Set up server address struct
    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    bcopy((char *)host->h_addr, (char *)&server_addr.sin_addr.s_addr, host->h_length);

    // Connect to SMTP server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        die("Failed to connect to server");
    }

    // Read server greeting
    read(sockfd, buffer, sizeof(buffer));
    printf("%s", buffer);

    // Send HELO command
    snprintf(buffer, sizeof(buffer), "HELO %s\r\n", smtp_server);
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, sizeof(buffer));
    printf("%s", buffer);

    // Send MAIL FROM command
    snprintf(buffer, sizeof(buffer), "MAIL FROM:<%s>\r\n", from);
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, sizeof(buffer));
    printf("%s", buffer);

    // Send RCPT TO command
    snprintf(buffer, sizeof(buffer), "RCPT TO:<%s>\r\n", to);
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, sizeof(buffer));
    printf("%s", buffer);

    // Send DATA command
    write(sockfd, "DATA\r\n", 6);
    read(sockfd, buffer, sizeof(buffer));
    printf("%s", buffer);

    // Send email header and body
    snprintf(buffer, sizeof(buffer), "Subject: %s\r\nFrom: %s\r\nTo: %s\r\n\r\n%s\r\n.\r\n", subject, from, to, body);
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, sizeof(buffer));
    printf("%s", buffer);

    // Send QUIT command
    write(sockfd, "QUIT\r\n", 6);
    read(sockfd, buffer, sizeof(buffer));
    printf("%s", buffer);

    // Close socket
    close(sockfd);
}

int main() {
    const char *smtp_server = "smtp.example.com"; // Replace with your SMTP server
    const char *from = "sender@example.com";       // Replace with your email
    const char *to = "recipient@example.com";       // Replace with recipient email
    const char *subject = "Test Email from C Client";
    const char *body = "This is a test email sent from a C email client!\n";

    printf("Attempting to send email...\n");
    send_email(smtp_server, from, to, subject, body);
    printf("Email sent successfully!\n");

    return 0;
}