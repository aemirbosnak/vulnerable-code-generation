//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SERVER "smtp.example.com" // Change to your SMTP server
#define PORT 587                    // Default SMTP port, can vary
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void send_command(int sockfd, const char *cmd) {
    send(sockfd, cmd, strlen(cmd), 0);
    char buffer[BUFFER_SIZE];
    recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    printf("%s", buffer);
}

void send_email(const char *from, const char *to, const char *subject, const char *body) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *host;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    // Resolve SMTP server address
    host = gethostbyname(SERVER);
    if (host == NULL) {
        error("Error resolving host");
    }

    // Set up server address struct
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);
    server_addr.sin_port = htons(PORT);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Error connecting to server");
    }

    char command[BUFFER_SIZE];

    // Read server response
    send_command(sockfd, "EHLO localhost\r\n");

    // Start TLS if needed
    send_command(sockfd, "STARTTLS\r\n");
    
    // NOTE: For this example, we're skipping TLS and authentication for simplicity.
    // In a production client, you should implement proper TLS and authentication.

    snprintf(command, sizeof(command), "MAIL FROM: <%s>\r\n", from);
    send_command(sockfd, command);

    snprintf(command, sizeof(command), "RCPT TO: <%s>\r\n", to);
    send_command(sockfd, command);

    send_command(sockfd, "DATA\r\n");

    // Send email headers and body
    snprintf(command, sizeof(command), "Subject: %s\r\n", subject);
    send(sockfd, command, strlen(command), 0);
    send(sockfd, "\r\n", 2, 0); // Add a blank line after headers
    send(sockfd, body, strlen(body), 0);
    
    // End the DATA section
    send(sockfd, "\r\n.\r\n", 5, 0);
    send_command(sockfd, "QUIT\r\n");

    // Close the socket
    close(sockfd);
}

int main() {
    // Email details
    const char *from = "you@example.com";  // Your email
    const char *to = "recipient@example.com"; // Recipient email
    const char *subject = "Test Email";
    const char *body = "Hello, this is a test email from our SMTP client.";

    // Send the email
    send_email(from, to, subject, body);

    printf("Email sent successfully.\n");
    return 0;
}