//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SMTP_PORT 587
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int create_socket(const char *hostname) {
    struct sockaddr_in server_address;
    struct hostent *server;

    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        return -1;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Opening socket");
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    memcpy(&server_address.sin_addr.s_addr, server->h_addr, server->h_length);
    server_address.sin_port = htons(SMTP_PORT);

    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        error("Connecting");
    }
    return sockfd;
}

void send_command(int sockfd, const char *cmd) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    sprintf(buffer, "%s\r\n", cmd);
    send(sockfd, buffer, strlen(buffer), 0);
    
    memset(buffer, 0, BUFFER_SIZE);
    recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    printf("Server: %s", buffer);
}

void send_email(int sockfd, const char *from, const char *to, const char *subject, const char *body) {
    // Send EHLO command
    send_command(sockfd, "EHLO localhost");

    // Start TLS
    send_command(sockfd, "STARTTLS");
    
    // Here we would need to implement TLS, 
    // skipping for simplicity
    // TLS would be set up before sending AUTH command

    // Authenticate (Base64 Encoding required)
    // Just a placeholder for real username and password handling
    const char *username = "your_email@example.com";
    const char *password = "your_password";
    char auth[BUFFER_SIZE];
    sprintf(auth, "AUTH LOGIN\r\n");
    send_command(sockfd, auth);
    send_command(sockfd, username);
    send_command(sockfd, password);
    
    // Send the email content
    send_command(sockfd, "MAIL FROM:<your_email@example.com>");
    send_command(sockfd, "RCPT TO:<recipient@example.com>");
    send_command(sockfd, "DATA");

    // Email Content
    char email[BUFFER_SIZE];
    sprintf(email, "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, body);
    send_command(sockfd, email);

    // Send QUIT command
    send_command(sockfd, "QUIT");
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <from> <to> <subject> <body>\n", argv[0]);
        exit(1);
    }

    const char *from = argv[1];
    const char *to = argv[2];
    const char *subject = argv[3];
    const char *body = argv[4];

    // Create SMTP socket connection
    int sockfd = create_socket("smtp.example.com");

    // Send the email
    send_email(sockfd, from, to, subject, body);

    // Close the socket
    close(sockfd);
    return 0;
}