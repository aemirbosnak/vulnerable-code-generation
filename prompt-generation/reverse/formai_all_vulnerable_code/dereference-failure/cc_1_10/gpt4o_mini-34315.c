//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define PORT 587

// SMTP Commands
const char *HELO_CMD = "HELO localhost\r\n";
const char *MAIL_FROM_CMD = "MAIL FROM:<%s>\r\n";
const char *RCPT_TO_CMD = "RCPT TO:<%s>\r\n";
const char *DATA_CMD = "DATA\r\n";
const char *QUIT_CMD = "QUIT\r\n";

// Configuration structure
typedef struct {
    char smtp_server[256];
    int port;
    char sender_email[256];
    char recipient_email[256];
    char subject[256];
    char body[1024];
} SMTPConfig;

// Function to create socket and connect to the SMTP server
int connect_to_smtp_server(const char *server, int port) {
    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, server, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

// Function to send a command and receive the response
void send_command(int sockfd, const char *cmd) {
    char buffer[BUFFER_SIZE];
    send(sockfd, cmd, strlen(cmd), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);
}

// Function to send email using SMTP protocol
void send_email(SMTPConfig config) {
    int sockfd = connect_to_smtp_server(config.smtp_server, config.port);

    // Read server response
    send_command(sockfd, HELO_CMD);
    
    // MAIL FROM
    char mail_from_cmd[BUFFER_SIZE];
    snprintf(mail_from_cmd, sizeof(mail_from_cmd), MAIL_FROM_CMD, config.sender_email);
    send_command(sockfd, mail_from_cmd);
    
    // RCPT TO
    char rcpt_to_cmd[BUFFER_SIZE];
    snprintf(rcpt_to_cmd, sizeof(rcpt_to_cmd), RCPT_TO_CMD, config.recipient_email);
    send_command(sockfd, rcpt_to_cmd);
    
    // DATA
    send_command(sockfd, DATA_CMD);
    
    // Send email content
    char email_content[BUFFER_SIZE];
    snprintf(email_content, sizeof(email_content), "Subject: %s\r\n\r\n%s\r\n.\r\n", config.subject, config.body);
    send(sockfd, email_content, strlen(email_content), 0);
    
    // Quit
    send_command(sockfd, QUIT_CMD);
    close(sockfd);
}

int main(int argc, char **argv) {
    if (argc < 6) {
        fprintf(stderr, "Usage: %s <SMTP_SERVER> <PORT> <SENDER_EMAIL> <RECIPIENT_EMAIL> <SUBJECT> <BODY>\n", argv[0]);
        return EXIT_FAILURE;
    }

    SMTPConfig config;
    strncpy(config.smtp_server, argv[1], sizeof(config.smtp_server));
    config.port = atoi(argv[2]);
    strncpy(config.sender_email, argv[3], sizeof(config.sender_email));
    strncpy(config.recipient_email, argv[4], sizeof(config.recipient_email));
    strncpy(config.subject, argv[5], sizeof(config.subject));
    strncpy(config.body, argv[6], sizeof(config.body));

    send_email(config);

    return EXIT_SUCCESS;
}