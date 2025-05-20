//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: light-weight
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

// SMTP default port
#define SMTP_PORT 25

// Function to send command and read response from the server
void send_command(int sock, const char *cmd, char *response, size_t resp_len) {
    send(sock, cmd, strlen(cmd), 0);
    recv(sock, response, resp_len, 0);
}

// Function to create and connect to the SMTP server
int connect_to_server(const char *server_ip) {
    int sock;
    struct sockaddr_in server_addr;

    // Creating socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Setting up server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    // Connecting to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    return sock;
}

// Function to send an email
void send_email(int sock, const char *from, const char *to, const char *subject, const char *body) {
    char response[1024];

    // SMTP handshake
    send_command(sock, "EHLO localhost\r\n", response, sizeof(response));
    printf("Server Response: %s", response);

    // Mail from
    char mail_from[256];
    snprintf(mail_from, sizeof(mail_from), "MAIL FROM:<%s>\r\n", from);
    send_command(sock, mail_from, response, sizeof(response));
    printf("Server Response: %s", response);

    // Recipient
    char rcpt_to[256];
    snprintf(rcpt_to, sizeof(rcpt_to), "RCPT TO:<%s>\r\n", to);
    send_command(sock, rcpt_to, response, sizeof(response));
    printf("Server Response: %s", response);

    // Data
    send_command(sock, "DATA\r\n", response, sizeof(response));
    printf("Server Response: %s", response);

    // Create email message
    char email[1024];
    snprintf(email, sizeof(email),
             "From: %s\r\n"
             "To: %s\r\n"
             "Subject: %s\r\n"
             "\r\n"
             "%s\r\n"
             ".\r\n", from, to, subject, body);

    // Send the email
    send_command(sock, email, response, sizeof(response));
    printf("Server Response: %s", response);

    // Quit
    send_command(sock, "QUIT\r\n", response, sizeof(response));
    printf("Server Response: %s", response);
}

int main() {
    const char *server_ip = "127.0.0.1"; // SMTP server address
    const char *from = "sender@example.com";
    const char *to = "recipient@example.com";
    const char *subject = "Test Email";
    const char *body = "Hello, this is a test email from C SMTP Client.";

    // Connecting to the SMTP server
    int sock = connect_to_server(server_ip);

    // Sending an email
    send_email(sock, from, to, subject, body);

    // Closing the socket
    close(sock);
    return 0;
}