//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024  // Buffer size for communication
#define SMTP_PORT 587     // Common port for SMTP submission

// Function to send command and read response from the server
void send_command(int sockfd, const char *cmd, char *response) {
    write(sockfd, cmd, strlen(cmd));
    write(sockfd, "\r\n", 2);
    read(sockfd, response, BUFFER_SIZE);
}

// Function to connect to the SMTP server
int connect_to_smtp(const char *smtp_server) {
    int sockfd;
    struct sockaddr_in server_addr;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up the server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    inet_pton(AF_INET, smtp_server, &server_addr.sin_addr);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to the SMTP server failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

void send_email(int sockfd, const char *from, const char *to, const char *subject, const char *body) {
    char buffer[BUFFER_SIZE];

    // HELO command
    send_command(sockfd, "HELO localhost", buffer);
    printf("Server: %s", buffer);

    // AUTH LOGIN (You would implement proper authentication here)
    send_command(sockfd, "AUTH LOGIN", buffer);
    printf("Server: %s", buffer);

    // Send sender email
    char cmd[BUFFER_SIZE];
    snprintf(cmd, sizeof(cmd), "MAIL FROM:<%s>", from);
    send_command(sockfd, cmd, buffer);
    printf("Server: %s", buffer);

    // Send recipient email
    snprintf(cmd, sizeof(cmd), "RCPT TO:<%s>", to);
    send_command(sockfd, cmd, buffer);
    printf("Server: %s", buffer);

    // Data command
    send_command(sockfd, "DATA", buffer);
    printf("Server: %s", buffer);

    // Message
    snprintf(cmd, sizeof(cmd),
            "From: <%s>\r\n"
            "To: <%s>\r\n"
            "Subject: %s\r\n\r\n"
            "%s\r\n.\r\n", from, to, subject, body);
    send_command(sockfd, cmd, buffer);
    printf("Server: %s", buffer);

    // Quit command
    send_command(sockfd, "QUIT", buffer);
    printf("Server: %s", buffer);
}

int main() {
    const char *smtp_server = "smtp.example.com";  // Replace with your SMTP server
    const char *from = "your-email@example.com";    // Sender's email
    const char *to = "recipient@example.com";        // Recipient's email
    const char *subject = "Test Email";
    const char *body = "This is a test email sent from a C program.";

    int sockfd = connect_to_smtp(smtp_server);
    send_email(sockfd, from, to, subject, body);
    close(sockfd);

    return 0;
}