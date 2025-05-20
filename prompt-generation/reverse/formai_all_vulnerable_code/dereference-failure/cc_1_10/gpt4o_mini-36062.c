//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SMTP_PORT 25
#define BUFFER_SIZE 1024

// Function prototypes
void send_command(int sockfd, const char *cmd);
void receive_response(int sockfd);
void send_email(int sockfd, const char *from, const char *to, const char *subject, const char *body);

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char *smtp_server = "smtp.example.com"; // Replace with your SMTP server
    char *from = "you@example.com"; // Replace with your email
    char *to = "recipient@example.com"; // Replace with recipient's email
    char *subject = "Test Email from C SMTP Client";
    char *body = "Hello, this is a test email sent from C!";

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set server address
    struct hostent *host = gethostbyname(smtp_server);
    if (host == NULL) {
        fprintf(stderr, "Could not resolve hostname\n");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);
    server_addr.sin_port = htons(SMTP_PORT);

    // Connect to the SMTP server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    // Receive initial server response
    receive_response(sockfd);

    // Send HELO command
    send_command(sockfd, "HELO localhost");
    receive_response(sockfd);

    // Send MAIL FROM command
    char mail_from[BUFFER_SIZE];
    snprintf(mail_from, sizeof(mail_from), "MAIL FROM:<%s>", from);
    send_command(sockfd, mail_from);
    receive_response(sockfd);

    // Send RCPT TO command
    char rcpt_to[BUFFER_SIZE];
    snprintf(rcpt_to, sizeof(rcpt_to), "RCPT TO:<%s>", to);
    send_command(sockfd, rcpt_to);
    receive_response(sockfd);

    // Send DATA command
    send_command(sockfd, "DATA");
    receive_response(sockfd);

    // Send email data
    send_email(sockfd, from, to, subject, body);
    
    // End data section
    send_command(sockfd, ".");
    receive_response(sockfd);

    // Send QUIT command
    send_command(sockfd, "QUIT");
    receive_response(sockfd);

    // Close the socket
    close(sockfd);
    return 0;
}

void send_command(int sockfd, const char *cmd) {
    printf("Sending command: %s\n", cmd);
    write(sockfd, cmd, strlen(cmd));
    write(sockfd, "\r\n", 2);
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    read(sockfd, buffer, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0'; // Null-terminate buffer
    printf("Server response: %s\n", buffer);
}

void send_email(int sockfd, const char *from, const char *to, const char *subject, const char *body) {
    char data[BUFFER_SIZE * 2];
    snprintf(data, sizeof(data), "From: %s\r\nTo: %s\r\nSubject: %s\r\n\r\n%s\r\n", from, to, subject, body);
    write(sockfd, data, strlen(data));
}