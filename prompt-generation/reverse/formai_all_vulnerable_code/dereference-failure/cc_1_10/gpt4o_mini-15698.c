//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>

#define MAXLINE 1024
#define PORT 587 // SMTP port
#define SMTP_SERVER "smtp.example.com" // Use a valid SMTP server

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void send_email(const char *recipient, const char *subject, const char *body) {
    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[MAXLINE];

    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error("Socket creation failed");
    }

    // Filling server information
    servaddr.sin_family = AF_INET; // IPv4
    servaddr.sin_port = htons(PORT); // SMTP port
    if (inet_pton(AF_INET, SMTP_SERVER, &servaddr.sin_addr) <= 0) {
        error("Invalid address or address not supported");
    }

    // Connecting to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        error("Connection to the server failed");
    }

    // Read welcome message
    read(sockfd, buffer, sizeof(buffer));
    printf("Server: %s", buffer);

    // Send EHLO command
    send(sockfd, "EHLO localhost\r\n", strlen("EHLO localhost\r\n"), 0);
    read(sockfd, buffer, sizeof(buffer));
    printf("Server: %s", buffer);

    // Sending MAIL FROM command
    char from_command[100];
    sprintf(from_command, "MAIL FROM:<you@example.com>\r\n"); 
    send(sockfd, from_command, strlen(from_command), 0);
    read(sockfd, buffer, sizeof(buffer));
    printf("Server: %s", buffer);

    // Sending RCPT TO command
    char rcpt_command[100];
    sprintf(rcpt_command, "RCPT TO:<%s>\r\n", recipient);
    send(sockfd, rcpt_command, strlen(rcpt_command), 0);
    read(sockfd, buffer, sizeof(buffer));
    printf("Server: %s", buffer);

    // Sending DATA command
    send(sockfd, "DATA\r\n", strlen("DATA\r\n"), 0);
    read(sockfd, buffer, sizeof(buffer));
    printf("Server: %s", buffer);

    // Sending email headers and body
    char email[MAXLINE];
    sprintf(email, "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, body);
    send(sockfd, email, strlen(email), 0);
    read(sockfd, buffer, sizeof(buffer));
    printf("Server: %s", buffer);

    // Sending QUIT command
    send(sockfd, "QUIT\r\n", strlen("QUIT\r\n"), 0);
    read(sockfd, buffer, sizeof(buffer));
    printf("Server: %s", buffer);

    // Close the socket
    close(sockfd);
}

int main(int argc, char *argv[]) {
    // We didn’t check for command line arguments, oh wow!
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <recipient> <subject> <body>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // The moment of truth! Let’s send that email!
    printf("Sending email...\n");
    send_email(argv[1], argv[2], argv[3]);
    printf("Email sent successfully! Unbelievable!\n");

    return 0;
}