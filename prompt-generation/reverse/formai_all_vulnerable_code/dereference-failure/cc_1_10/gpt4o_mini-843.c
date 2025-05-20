//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SMTP_PORT 587
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void send_command(int sockfd, const char *command) {
    write(sockfd, command, strlen(command));
    write(sockfd, "\r\n", 2);
}

void read_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_read = read(sockfd, buffer, sizeof(buffer) - 1);
    if (bytes_read < 0) error("Error reading from socket");
    buffer[bytes_read] = '\0';
    printf("%s", buffer);
}

void smtp_auth(int sockfd, const char *username, const char *password) {
    char command[BUFFER_SIZE];

    // Send EHLO command
    send_command(sockfd, "EHLO localhost");
    read_response(sockfd);
    
    // Begin authentication
    send_command(sockfd, "AUTH LOGIN");
    read_response(sockfd);
    
    // Send username and password (Base64 encoded)
    snprintf(command, sizeof(command), "%s", username); // Assume Base64 encoded
    send_command(sockfd, command);
    read_response(sockfd);
    
    snprintf(command, sizeof(command), "%s", password); // Assume Base64 encoded
    send_command(sockfd, command);
    read_response(sockfd);
}

void send_email(int sockfd, const char *from, const char *to, const char *subject, const char *body) {
    char command[BUFFER_SIZE];

    // Set 'MAIL FROM'
    snprintf(command, sizeof(command), "MAIL FROM:<%s>", from);
    send_command(sockfd, command);
    read_response(sockfd);
    
    // Set 'RCPT TO'
    snprintf(command, sizeof(command), "RCPT TO:<%s>", to);
    send_command(sockfd, command);
    read_response(sockfd);
    
    // Set 'DATA'
    send_command(sockfd, "DATA");
    read_response(sockfd);
    
    // Send the email data
    snprintf(command, sizeof(command), "Subject: %s\r\n\r\n%s\r\n.", subject, body);
    send_command(sockfd, command);
    read_response(sockfd);
    
    // End of message
    send_command(sockfd, "QUIT");
    read_response(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc < 6) {
        fprintf(stderr, "Usage: %s <smtp_server> <username> <password> <from_email> <to_email> <subject> <body>\n", argv[0]);
        return 1;
    }

    const char *smtp_server = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];
    const char *from_email = argv[4];
    const char *to_email = argv[5];
    const char *subject = argv[6];
    const char *body = argv[7];
    
    int sockfd;
    struct sockaddr_in server_addr;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) error("Error opening socket");

    // Define server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    server_addr.sin_addr.s_addr = inet_addr(smtp_server);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) 
        error("Error connecting");

    // Read server response
    read_response(sockfd);

    // Authenticate
    smtp_auth(sockfd, username, password);

    // Send email
    send_email(sockfd, from_email, to_email, subject, body);
    
    // Clean up
    close(sockfd);
    return 0;
}