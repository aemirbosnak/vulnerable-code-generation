//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SMTP_PORT 587
#define BUFFER_SIZE 1024

void send_email(const char *smtp_server, const char *from, const char *to, const char *subject, const char *body) {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return;
    }

    // Set up server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    server_addr.sin_addr.s_addr = inet_addr(smtp_server);

    // Connect to SMTP server
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(sock);
        return;
    }

    // Read server response
    read(sock, buffer, BUFFER_SIZE);
    printf("Server: %s", buffer);

    // Say hello to the server
    write(sock, "HELO client\r\n", strlen("HELO client\r\n"));
    read(sock, buffer, BUFFER_SIZE);
    printf("Server: %s", buffer);

    // Send the sender's email
    snprintf(buffer, sizeof(buffer), "MAIL FROM: <%s>\r\n", from);
    write(sock, buffer, strlen(buffer));
    read(sock, buffer, BUFFER_SIZE);
    printf("Server: %s", buffer);

    // Send the recipient's email
    snprintf(buffer, sizeof(buffer), "RCPT TO: <%s>\r\n", to);
    write(sock, buffer, strlen(buffer));
    read(sock, buffer, BUFFER_SIZE);
    printf("Server: %s", buffer);

    // Initiate the data transfer
    write(sock, "DATA\r\n", strlen("DATA\r\n"));
    read(sock, buffer, BUFFER_SIZE);
    printf("Server: %s", buffer);

    // Send the email headers and body
    snprintf(buffer, sizeof(buffer), "Subject: %s\r\nFrom: %s\r\nTo: %s\r\n\r\n%s\r\n.\r\n", subject, from, to, body);
    write(sock, buffer, strlen(buffer));
    read(sock, buffer, BUFFER_SIZE);
    printf("Server: %s", buffer);

    // Close the connection
    write(sock, "QUIT\r\n", strlen("QUIT\r\n"));
    read(sock, buffer, BUFFER_SIZE);
    printf("Server: %s", buffer);

    // Cleanup
    close(sock);
}

int main() {
    const char *smtp_server = "smtp.example.com"; // Replace with your SMTP server
    const char *from = "you@example.com";          // Replace with sender email
    const char *to = "recipient@example.com";      // Replace with recipient email
    const char *subject = "Test Email from C Client";
    const char *body = "Hello,\nThis is a test email sent from a C email client example.\nBest regards,\nC Team";

    send_email(smtp_server, from, to, subject, body);

    return 0;
}