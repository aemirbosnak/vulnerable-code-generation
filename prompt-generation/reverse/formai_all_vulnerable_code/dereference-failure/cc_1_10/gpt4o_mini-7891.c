//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SMTP_PORT 587 // Standard port for SMTP
#define BUFFER_SIZE 1024

// Function to communicate with the SMTP server
void smtp_send(int sock, const char *msg) {
    send(sock, msg, strlen(msg), 0);
    char buffer[BUFFER_SIZE];
    recv(sock, buffer, sizeof(buffer), 0);
    printf("%s", buffer);
}

int main() {
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    
    // Server details
    const char *smtp_server = "smtp.example.com"; // Replace with your SMTP server
    const char *username = "your_email@example.com"; // Your email
    const char *password = "your_password"; // Your password
    const char *from = "your_email@example.com"; // From email
    const char *to = "recipient@example.com"; // To email
    const char *subject = "Test Email from SMTP Client";
    
    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return EXIT_FAILURE;
    }

    // Get server by name
    struct hostent *host = gethostbyname(smtp_server);
    if (host == NULL) {
        herror("gethostbyname failed");
        return EXIT_FAILURE;
    }
    
    // Set up server address struct
    memset(&server_addr, 0, sizeof(server_addr)); // Clear memory
    server_addr.sin_family = AF_INET; // IPv4
    server_addr.sin_port = htons(SMTP_PORT); // Port
    memcpy(&server_addr.sin_addr, host->h_addr_list[0], host->h_length); // Copy IP

    // Connect to the SMTP server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to SMTP server failed");
        return EXIT_FAILURE;
    }

    // Read server response
    recv(sock, buffer, sizeof(buffer), 0);
    printf("%s", buffer); // Print server greeting

    // HELO command
    smtp_send(sock, "HELO mail.example.com\r\n"); // Replace with your domain
    // MAIL FROM command
    char mail_from[BUFFER_SIZE];
    snprintf(mail_from, sizeof(mail_from), "MAIL FROM:<%s>\r\n", from);
    smtp_send(sock, mail_from);
    
    // RCPT TO command
    char rcpt_to[BUFFER_SIZE];
    snprintf(rcpt_to, sizeof(rcpt_to), "RCPT TO:<%s>\r\n", to);
    smtp_send(sock, rcpt_to);
    
    // DATA command
    smtp_send(sock, "DATA\r\n");

    // Email body
    char email_body[BUFFER_SIZE];
    snprintf(email_body, sizeof(email_body),
             "Subject: %s\r\n"
             "From: %s\r\n"
             "To: %s\r\n"
             "\r\n"
             "This is a test email sent from a C SMTP client!\r\n"
             ".\r\n", subject, from, to);
    
    smtp_send(sock, email_body); // Send the email body

    // QUIT command
    smtp_send(sock, "QUIT\r\n");

    // Clean up
    close(sock);
    printf("Email sent successfully!\n");
    
    return EXIT_SUCCESS;
}