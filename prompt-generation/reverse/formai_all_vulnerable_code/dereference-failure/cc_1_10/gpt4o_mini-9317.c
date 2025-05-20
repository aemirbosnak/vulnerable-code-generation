//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define SMTP_SERVER "smtp.example.com"
#define SMTP_PORT 25
#define BUFFER_SIZE 1024

void send_command(int sock, const char *command) {
    send(sock, command, strlen(command), 0);
    send(sock, "\r\n", 2, 0);
}

void receive_response(int sock, char *buffer) {
    int size = recv(sock, buffer, BUFFER_SIZE - 1, 0);
    if (size > 0) {
        buffer[size] = '\0';
        printf("Server: %s", buffer);
    }
}

void smtp_client(const char *email_from, const char *email_to, const char *subject, const char *message) {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // Socket Creation
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket Creation Failed");
        exit(EXIT_FAILURE);
    }

    // Server Configuration
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    server_addr.sin_addr.s_addr = inet_addr("192.168.1.1"); // Replace with actual SMTP Server IP

    // Connect to SMTP Server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to Server Failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    // Receiving Greeting
    receive_response(sock, buffer);

    // Send HELO Command
    send_command(sock, "HELO localhost");
    receive_response(sock, buffer);
    
    // Send MAIL FROM Command
    char mail_from[BUFFER_SIZE];
    snprintf(mail_from, BUFFER_SIZE, "MAIL FROM:<%s>", email_from);
    send_command(sock, mail_from);
    receive_response(sock, buffer);
    
    // Send RCPT TO Command
    char rcpt_to[BUFFER_SIZE];
    snprintf(rcpt_to, BUFFER_SIZE, "RCPT TO:<%s>", email_to);
    send_command(sock, rcpt_to);
    receive_response(sock, buffer);
    
    // Send DATA Command
    send_command(sock, "DATA");
    receive_response(sock, buffer);
    
    // Send Email Headers and Body
    char email[BUFFER_SIZE * 2];
    snprintf(email, BUFFER_SIZE * 2, "Subject: %s\r\nFrom: %s\r\nTo: %s\r\n\r\n%s\r\n.", subject, email_from, email_to, message);
    send(sock, email, strlen(email), 0);
    
    // Send Message Termination
    send_command(sock, ".");
    receive_response(sock, buffer);
    
    // Send QUIT Command
    send_command(sock, "QUIT");
    receive_response(sock, buffer);
    
    // Socket Closure
    close(sock);
    printf("Email sent successfully!\n");
}

int main() {
    const char *from = "sender@example.com";
    const char *to = "receiver@example.com";
    const char *subject = "Test Email";
    const char *body = "Hello, this is a test email sent from a C SMTP client.";

    smtp_client(from, to, subject, body);
    
    return 0;
}