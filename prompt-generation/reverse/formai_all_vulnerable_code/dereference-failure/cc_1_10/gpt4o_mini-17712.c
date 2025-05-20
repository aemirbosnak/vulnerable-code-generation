//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdbool.h>

#define SMTP_PORT 25
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int connect_to_smtp_server(const char *server) {
    int sockfd;
    struct sockaddr_in server_addr;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error("Socket creation failed");
    }

    // Set up server address struct
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    
    // Convert server address to binary form
    if (inet_pton(AF_INET, server, &server_addr.sin_addr) <= 0) {
        error("Invalid address or address not supported");
    }

    // Connect to the SMTP server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection to SMTP server failed");
    }

    return sockfd;
}

void send_command(int sockfd, const char *cmd, char *response) {
    write(sockfd, cmd, strlen(cmd));
    write(sockfd, "\r\n", 2);
    read(sockfd, response, BUFFER_SIZE);

    // Print the SMTP server response
    printf("SMTP Server: %s", response);
}

void authenticate(int sockfd, const char *username, const char *password) {
    char cmd[BUFFER_SIZE], response[BUFFER_SIZE];

    // Simple authentication
    sprintf(cmd, "EHLO localhost");
    send_command(sockfd, cmd, response);
    
    // Authentication commands (in real scenarios Base64 encoding would be required)
    sprintf(cmd, "AUTH LOGIN");
    send_command(sockfd, cmd, response);
    
    sprintf(cmd, "%s", username);
    send_command(sockfd, cmd, response);
    
    sprintf(cmd, "%s", password);
    send_command(sockfd, cmd, response);
}

void send_email(int sockfd, const char *from, const char *to, const char *subject, const char *body) {
    char cmd[BUFFER_SIZE], response[BUFFER_SIZE];

    sprintf(cmd, "MAIL FROM:<%s>", from);
    send_command(sockfd, cmd, response);
    
    sprintf(cmd, "RCPT TO:<%s>", to);
    send_command(sockfd, cmd, response);
    
    sprintf(cmd, "DATA");
    send_command(sockfd, cmd, response);
    
    sprintf(cmd, "Subject: %s\r\n\r\n%s\r\n.", subject, body);
    send_command(sockfd, cmd, response);
}

int main(int argc, char *argv[]) {
    if (argc != 6) {
        fprintf(stderr, "Usage: %s <smtp_server> <from> <to> <subject> <body>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *smtp_server = argv[1];
    const char *from = argv[2];
    const char *to = argv[3];
    const char *subject = argv[4];
    const char *body = argv[5];

    int sockfd = connect_to_smtp_server(smtp_server);
    char response[BUFFER_SIZE];

    // Initial greeting from the server
    read(sockfd, response, BUFFER_SIZE);
    printf("SMTP Server: %s", response);

    // Authentication
    authenticate(sockfd, "your_username", "your_password");

    // Sending email
    send_email(sockfd, from, to, subject, body);

    // Close the socket
    close(sockfd);
    return 0;
}