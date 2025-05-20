//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SMTP_PORT 587
#define POP3_PORT 110
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void send_email(const char *smtp_server, const char *from, const char *to, const char *subject, const char *body) {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error("Socket creation failed");
    }

    // Set up server address struct
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    inet_pton(AF_INET, smtp_server, &server_addr.sin_addr);

    // Connect to SMTP server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection to SMTP server failed");
    }

    // Read server response
    read(sock, buffer, sizeof(buffer));
    printf("Server: %s", buffer);

    // Send HELO command
    snprintf(buffer, sizeof(buffer), "HELO %s\r\n", "localhost");
    send(sock, buffer, strlen(buffer), 0);
    read(sock, buffer, sizeof(buffer));
    printf("Server: %s", buffer);

    // Send MAIL FROM command
    snprintf(buffer, sizeof(buffer), "MAIL FROM:<%s>\r\n", from);
    send(sock, buffer, strlen(buffer), 0);
    read(sock, buffer, sizeof(buffer));
    printf("Server: %s", buffer);

    // Send RCPT TO command
    snprintf(buffer, sizeof(buffer), "RCPT TO:<%s>\r\n", to);
    send(sock, buffer, strlen(buffer), 0);
    read(sock, buffer, sizeof(buffer));
    printf("Server: %s", buffer);

    // Send DATA command
    send(sock, "DATA\r\n", strlen("DATA\r\n"), 0);
    read(sock, buffer, sizeof(buffer));
    printf("Server: %s", buffer);

    // Send email content
    snprintf(buffer, sizeof(buffer), "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, body);
    send(sock, buffer, strlen(buffer), 0);
    read(sock, buffer, sizeof(buffer));
    printf("Server: %s", buffer);

    // Send QUIT command
    send(sock, "QUIT\r\n", strlen("QUIT\r\n"), 0);
    read(sock, buffer, sizeof(buffer));
    printf("Server: %s", buffer);

    close(sock);
}

void receive_email(const char *pop3_server, const char *username, const char *password) {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error("Socket creation failed");
    }

    // Set up server address struct
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    inet_pton(AF_INET, pop3_server, &server_addr.sin_addr);

    // Connect to POP3 server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection to POP3 server failed");
    }

    // Read server response
    read(sock, buffer, sizeof(buffer));
    printf("Server: %s", buffer);

    // Send USER command
    snprintf(buffer, sizeof(buffer), "USER %s\r\n", username);
    send(sock, buffer, strlen(buffer), 0);
    read(sock, buffer, sizeof(buffer));
    printf("Server: %s", buffer);

    // Send PASS command
    snprintf(buffer, sizeof(buffer), "PASS %s\r\n", password);
    send(sock, buffer, strlen(buffer), 0);
    read(sock, buffer, sizeof(buffer));
    printf("Server: %s", buffer);

    // Send LIST command
    send(sock, "LIST\r\n", strlen("LIST\r\n"), 0);
    read(sock, buffer, sizeof(buffer));
    printf("Messages:\n%s", buffer);

    // Send QUIT command
    send(sock, "QUIT\r\n", strlen("QUIT\r\n"), 0);
    read(sock, buffer, sizeof(buffer));
    printf("Server: %s", buffer);

    close(sock);
}

int main(int argc, char *argv[]) {
    if (argc < 7) {
        fprintf(stderr, "Usage: %s <smtp_server> <from_email> <to_email> <subject> <body> <pop3_server> <username> <password>\n", argv[0]);
        exit(1);
    }

    // Send email
    send_email(argv[1], argv[2], argv[3], argv[4], argv[5]);

    // Receive email
    receive_email(argv[6], argv[7], argv[8]);

    return 0;
}