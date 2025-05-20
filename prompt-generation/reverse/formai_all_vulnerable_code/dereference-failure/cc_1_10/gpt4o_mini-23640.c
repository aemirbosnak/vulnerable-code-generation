//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

void send_command(int sockfd, const char *cmd) {
    write(sockfd, cmd, strlen(cmd));
    write(sockfd, "\r\n", 2);
}

void read_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received = read(sockfd, buffer, sizeof(buffer) - 1);
    if (bytes_received > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }
}

int main() {
    const char *smtp_server = "smtp.example.com";  // Change to your SMTP server
    const char *email_from = "your_email@example.com"; // Change to your email
    const char *email_to = "recipient@example.com"; // Change to recipient email
    const char *subject = "Test Email from SMTP Client";
    const char *body = "This is a test email sent from a simple SMTP client.";
    
    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(587); // Change port if necessary
    inet_pton(AF_INET, smtp_server, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to SMTP server failed");
        close(sockfd);
        return 1;
    }

    read_response(sockfd);
    send_command(sockfd, "HELO localhost");
    read_response(sockfd);

    send_command(sockfd, "MAIL FROM:<your_email@example.com>");
    read_response(sockfd);
    
    send_command(sockfd, "RCPT TO:<recipient@example.com>");
    read_response(sockfd);
    
    send_command(sockfd, "DATA");
    read_response(sockfd);
    
    char email_message[BUFFER_SIZE];
    snprintf(email_message, sizeof(email_message),
             "From: %s\r\nTo: %s\r\nSubject: %s\r\n\r\n%s\r\n.\r\n",
             email_from, email_to, subject, body);
    send_command(sockfd, email_message);
    read_response(sockfd);
    
    send_command(sockfd, "QUIT");
    read_response(sockfd);
    
    close(sockfd);
    printf("Email sent successfully!\n");
    return 0;
}