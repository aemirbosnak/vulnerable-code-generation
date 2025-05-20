//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SMTP_PORT 587
#define BUFFER_SIZE 1024

void send_command(int sock, const char *cmd) {
    send(sock, cmd, strlen(cmd), 0);
    char buffer[BUFFER_SIZE];
    recv(sock, buffer, sizeof(buffer) - 1, 0);
    printf("Server: %s", buffer);
}

void authenticate(int sock, const char *username, const char *password) {
    char base64_username[BUFFER_SIZE];
    char base64_password[BUFFER_SIZE];
    
    // Base64 encoding the username and password
    snprintf(base64_username, sizeof(base64_username), "AUTH LOGIN\r\n");
    send_command(sock, base64_username);
    send_command(sock, username);
    send_command(sock, password);
}

void smtp_send(int sock, const char *from, const char *to, const char *subject, const char *body) {
    char buffer[BUFFER_SIZE];
    
    snprintf(buffer, sizeof(buffer), "MAIL FROM:<%s>\r\n", from);
    send_command(sock, buffer);
    
    snprintf(buffer, sizeof(buffer), "RCPT TO:<%s>\r\n", to);
    send_command(sock, buffer);
    
    send_command(sock, "DATA\r\n");
    
    snprintf(buffer, sizeof(buffer), "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, body);
    send(sock, buffer, strlen(buffer), 0);
    
    char response[BUFFER_SIZE];
    recv(sock, response, sizeof(response) - 1, 0);
    printf("Server: %s", response);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <smtp_server> <username> <password> <to_email>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *smtp_server = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];
    const char *to_email = argv[4];

    int sock;
    struct sockaddr_in server_addr;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    server_addr.sin_addr.s_addr = inet_addr(smtp_server);

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to SMTP server failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    // Read server greeting
    char buffer[BUFFER_SIZE];
    recv(sock, buffer, sizeof(buffer) - 1, 0);
    printf("Server: %s", buffer);

    // STARTTLS or EHLO could be added for an actual implementation, but omitted for brevity

    authenticate(sock, username, password);

    // Specify email details
    const char *from_email = username;
    const char *subject = "Hello from SMTP Client";
    const char *body = "This is a test email sent from a simple SMTP client written in C.";

    smtp_send(sock, from_email, to_email, subject, body);
    
    // Finalize and quit
    send_command(sock, "QUIT\r\n");

    close(sock);
    return 0;
}