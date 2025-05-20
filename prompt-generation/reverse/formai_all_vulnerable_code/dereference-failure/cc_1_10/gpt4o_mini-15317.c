//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SMTP_PORT 587
#define BUFFER_SIZE 1024

// Function prototypes
void handle_error(const char *msg);
void send_email(const char *server, const char *from, const char *to, const char *subject, const char *body);
void smtp_connect(int *sockfd, const char *server);
void smtp_send_command(int sockfd, const char *command);
void smtp_receive_response(int sockfd, char *response, size_t length);

int main() {
    const char *smtp_server = "smtp.example.com";
    const char *from_email = "sender@example.com";
    const char *to_email = "recipient@example.com";
    const char *subject = "Test Email";
    const char *body = "Hello,\n\nThis is a test email sent using a simple SMTP client written in C.\n\nBest,\nYour SMTP Client";

    send_email(smtp_server, from_email, to_email, subject, body);
    return 0;
}

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void send_email(const char *server, const char *from, const char *to, const char *subject, const char *body) {
    int sockfd;
    char response[BUFFER_SIZE];

    smtp_connect(&sockfd, server);

    smtp_send_command(sockfd, "HELO localhost");
    smtp_receive_response(sockfd, response, sizeof(response));

    smtp_send_command(sockfd, "MAIL FROM:");
    smtp_send_command(sockfd, from);
    smtp_receive_response(sockfd, response, sizeof(response));

    smtp_send_command(sockfd, "RCPT TO:");
    smtp_send_command(sockfd, to);
    smtp_receive_response(sockfd, response, sizeof(response));

    smtp_send_command(sockfd, "DATA");
    smtp_receive_response(sockfd, response, sizeof(response));

    char message[BUFFER_SIZE];
    snprintf(message, sizeof(message), "Subject: %s\r\nFrom: %s\r\nTo: %s\r\n\r\n%s\r\n.", subject, from, to, body);
    smtp_send_command(sockfd, message);
    smtp_receive_response(sockfd, response, sizeof(response));

    smtp_send_command(sockfd, "QUIT");
    smtp_receive_response(sockfd, response, sizeof(response));

    close(sockfd);
}

void smtp_connect(int *sockfd, const char *server) {
    struct sockaddr_in server_addr;

    *sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (*sockfd < 0) {
        handle_error("Unable to create socket");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    if (inet_pton(AF_INET, server, &server_addr.sin_addr) <= 0) {
        handle_error("Invalid address or address not supported");
    }

    if (connect(*sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("Connection failed");
    }

    char response[BUFFER_SIZE];
    smtp_receive_response(*sockfd, response, sizeof(response));
}

void smtp_send_command(int sockfd, const char *command) {
    char command_buffer[BUFFER_SIZE];
    snprintf(command_buffer, sizeof(command_buffer), "%s\r\n", command);
    write(sockfd, command_buffer, strlen(command_buffer));
}

void smtp_receive_response(int sockfd, char *response, size_t length) {
    read(sockfd, response, length);
    printf("SMTP Response: %s", response);
}