//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_BUFFER 1024

void send_command(int sockfd, const char *cmd, char *response) {
    send(sockfd, cmd, strlen(cmd), 0);
    recv(sockfd, response, MAX_BUFFER, 0);
}

void smtp_client(const char *smtp_server, int port, const char *from, const char *to, const char *subject, const char *body) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[MAX_BUFFER];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Define server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, smtp_server, &server_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        exit(EXIT_FAILURE);
    }

    // Connect to SMTP server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to SMTP server failed");
        exit(EXIT_FAILURE);
    }

    // Receive server greeting
    recv(sockfd, buffer, MAX_BUFFER, 0);
    printf("Server: %s", buffer);

    // HELO Command
    send_command(sockfd, "HELO localhost\r\n", buffer);
    printf("Server: %s", buffer);

    // MAIL FROM Command
    char mail_from_cmd[MAX_BUFFER];
    snprintf(mail_from_cmd, sizeof(mail_from_cmd), "MAIL FROM:<%s>\r\n", from);
    send_command(sockfd, mail_from_cmd, buffer);
    printf("Server: %s", buffer);

    // RCPT TO Command
    char rcpt_to_cmd[MAX_BUFFER];
    snprintf(rcpt_to_cmd, sizeof(rcpt_to_cmd), "RCPT TO:<%s>\r\n", to);
    send_command(sockfd, rcpt_to_cmd, buffer);
    printf("Server: %s", buffer);

    // DATA Command
    send_command(sockfd, "DATA\r\n", buffer);
    printf("Server: %s", buffer);

    // Email Content
    char email[MAX_BUFFER];
    snprintf(email, sizeof(email), "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, body);
    send_command(sockfd, email, buffer);
    printf("Server: %s", buffer);

    // QUIT Command
    send_command(sockfd, "QUIT\r\n", buffer);
    printf("Server: %s", buffer);

    // Close the socket
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 6) {
        fprintf(stderr, "Usage: %s <smtp_server> <port> <from> <to> <subject> <body>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *smtp_server = argv[1];
    int port = atoi(argv[2]);
    const char *from = argv[3];
    const char *to = argv[4];
    const char *subject = argv[5];
    const char *body = argv[6];

    smtp_client(smtp_server, port, from, to, subject, body);

    return 0;
}