//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define SMTP_PORT 587
#define BUFFER_SIZE 1024

void error(const char* msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void read_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    bzero(buffer, BUFFER_SIZE);
    if (read(sockfd, buffer, BUFFER_SIZE - 1) <= 0) {
        error("Failed to read response from server");
    }
    printf("Server: %s", buffer);
}

void send_command(int sockfd, const char* cmd) {
    write(sockfd, cmd, strlen(cmd));
    printf("Client: %s", cmd);
    read_response(sockfd);
}

void paranoid_smtp_client(const char* email, const char* password, const char* to_email, const char* subject, const char* body) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *host;

    host = gethostbyname("smtp.gmail.com");
    if (host == NULL) {
        error("Failed to resolve SMTP server");
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Cannot open socket");
    }

    bzero((char*)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char*)host->h_addr, (char*)&server_addr.sin_addr.s_addr, host->h_length);
    server_addr.sin_port = htons(SMTP_PORT);
    
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection failed");
    }

    read_response(sockfd); // Read server greeting

    // HELO command
    send_command(sockfd, "EHLO localhost\r\n");

    // Start TLS
    send_command(sockfd, "STARTTLS\r\n");

    // Here we would normally initiate SSL/TLS handshake
    // However, for the purpose of paranoia, let's skip to authentication

    // Authenticate
    char auth_cmd[BUFFER_SIZE];
    snprintf(auth_cmd, BUFFER_SIZE, "AUTH LOGIN\r\n");
    send_command(sockfd, auth_cmd);

    // Send username
    char username[BUFFER_SIZE];
    snprintf(username, BUFFER_SIZE, "%s\r\n", email);
    send_command(sockfd, username);

    // Send password
    char pass[BUFFER_SIZE];
    snprintf(pass, BUFFER_SIZE, "%s\r\n", password);
    send_command(sockfd, pass);

    // Send MAIL FROM
    char mail_from[BUFFER_SIZE];
    snprintf(mail_from, BUFFER_SIZE, "MAIL FROM:<%s>\r\n", email);
    send_command(sockfd, mail_from);
    
    // Send RCPT TO
    char rcpt_to[BUFFER_SIZE];
    snprintf(rcpt_to, BUFFER_SIZE, "RCPT TO:<%s>\r\n", to_email);
    send_command(sockfd, rcpt_to);
    
    // Send DATA command
    send_command(sockfd, "DATA\r\n");

    // Send email headers and body
    char data[BUFFER_SIZE * 2];
    snprintf(data, sizeof(data), "Subject: %s\r\nTo: %s\r\n\r\n%s\r\n.\r\n", subject, to_email, body);
    send_command(sockfd, data);

    // Quit
    send_command(sockfd, "QUIT\r\n");

    close(sockfd);
}

int main() {
    const char* email = "your_email@gmail.com";       // Enter your email
    const char* password = "your_password";            // Enter your password
    const char* to_email = "recipient@example.com";    // Recipient's email
    const char* subject = "Paranoid SMTP Test";        // Email subject
    const char* body = "This is a paranoid email test."; // Email body

    paranoid_smtp_client(email, password, to_email, subject, body);

    return 0;
}