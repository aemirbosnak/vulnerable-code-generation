//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

void sendCommand(int sockfd, const char *command, const char *expected_response) {
    char buffer[BUFFER_SIZE];
    
    // Send command
    send(sockfd, command, strlen(command), 0);
    printf("Sent: %s", command);
    
    // Receive response
    recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    buffer[BUFFER_SIZE - 1] = '\0';  // Null-terminate the buffer
    printf("Received: %s", buffer);
    
    // Checking for expected response
    if (strstr(buffer, expected_response) == NULL) {
        fprintf(stderr, "Unexpected response from server!\n");
        exit(EXIT_FAILURE);
    }
}

int main() {
    // SMTP server details
    const char *smtp_server = "smtp.example.com";
    const int smtp_port = 587;
    const char *email_from = "you@example.com";
    const char *email_to = "recipient@example.com";
    const char *email_subject = "Test Email from C SMTP Client!";
    const char *email_body = "Hello,\n\nThis is a test email sent from a C SMTP Client.\n\nBest regards,\nC Programmer";

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    // Resolve SMTP server address
    struct hostent *server = gethostbyname(smtp_server);
    if (server == NULL) {
        fprintf(stderr, "No such host: %s\n", smtp_server);
        exit(EXIT_FAILURE);
    }

    // Setup server address struct
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(smtp_port);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr_list[0], server->h_length);

    // Connect to the SMTP server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection to SMTP server failed");
        exit(EXIT_FAILURE);
    }
    
    // Greeting
    sendCommand(sockfd, "EHLO localhost\r\n", "250");

    // Start TLS
    sendCommand(sockfd, "STARTTLS\r\n", "220");

    // For simplicity, we're not implementing TLS; please use a proper library for production code

    // Authenticate (for servers requiring authentication)
    // sendCommand(sockfd, "AUTH LOGIN\r\n", "334");
    // sendCommand(sockfd, "<Base64_encoded_username>\r\n", "334");
    // sendCommand(sockfd, "<Base64_encoded_password>\r\n", "235");

    // Specify sender
    char buffer[BUFFER_SIZE];
    snprintf(buffer, sizeof(buffer), "MAIL FROM: <%s>\r\n", email_from);
    sendCommand(sockfd, buffer, "250");

    // Specify recipient
    snprintf(buffer, sizeof(buffer), "RCPT TO: <%s>\r\n", email_to);
    sendCommand(sockfd, buffer, "250");

    // Start mail data
    sendCommand(sockfd, "DATA\r\n", "354");

    // Send email content
    snprintf(buffer, sizeof(buffer), "Subject: %s\r\n\r\n%s\r\n.\r\n", email_subject, email_body);
    sendCommand(sockfd, buffer, "250");

    // Close the connection
    sendCommand(sockfd, "QUIT\r\n", "221");

    // Close socket
    close(sockfd);
    printf("Email sent successfully!\n");

    return 0;
}