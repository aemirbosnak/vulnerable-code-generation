//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SMTP_PORT 25
#define BUFFER_SIZE 1024

// Configuration structure
typedef struct {
    char *smtp_server;
    char *from_email;
    char *to_email;
    char *subject;
    char *body;
} SMTPConfig;

// Function to send data to the server and receive the response
int send_data(int sockfd, const char *data) {
    send(sockfd, data, strlen(data), 0);
    char buffer[BUFFER_SIZE];
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);
    return 0;
}

// Function to build the email and send it using SMTP
void send_email(SMTPConfig *config) {
    int sockfd;
    struct sockaddr_in server_addr;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Setup server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    server_addr.sin_addr.s_addr = inet_addr(config->smtp_server);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to SMTP server failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // SMTP communication
    send_data(sockfd, "HELO localhost\r\n");
    send_data(sockfd, "MAIL FROM: ");
    send_data(sockfd, config->from_email);
    send_data(sockfd, "\r\n");
    send_data(sockfd, "RCPT TO: ");
    send_data(sockfd, config->to_email);
    send_data(sockfd, "\r\n");
    send_data(sockfd, "DATA\r\n");
    send_data(sockfd, "Subject: ");
    send_data(sockfd, config->subject);
    send_data(sockfd, "\r\n");
    send_data(sockfd, "\r\n");
    send_data(sockfd, config->body);
    send_data(sockfd, "\r\n.\r\n");
    send_data(sockfd, "QUIT\r\n");

    // Close the socket
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 6) {
        fprintf(stderr, "Usage: %s <SMTP server> <From email> <To email> <Subject> <Body>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    SMTPConfig config;
    config.smtp_server = argv[1];
    config.from_email = argv[2];
    config.to_email = argv[3];
    config.subject = argv[4];
    config.body = argv[5];

    send_email(&config);

    return 0;
}