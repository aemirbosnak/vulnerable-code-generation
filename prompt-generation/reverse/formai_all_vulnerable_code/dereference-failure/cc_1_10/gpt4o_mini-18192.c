//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdbool.h>

#define MAX_EMAIL_LENGTH 256
#define MAX_SUBJECT_LENGTH 128
#define MAX_BODY_LENGTH 1024
#define MAX_RECIPIENTS 10
#define SMTP_PORT 587
#define BUFFER_SIZE 2048

void error_exit(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

bool send_email(const char *server, const char *from, const char *to[], int to_count, const char *subject, const char *body) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *host;
    char buffer[BUFFER_SIZE];
    char command[BUFFER_SIZE];

    // Get host by server name
    host = gethostbyname(server);
    if (host == NULL) {
        fprintf(stderr, "Could not resolve hostname %s\n", server);
        return false;
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error_exit("Error opening socket");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);

    // Connect to the SMTP server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error_exit("Error connecting to server");
    }

    // Read server initial reply
    read(sockfd, buffer, sizeof(buffer) - 1);
    printf("Server: %s", buffer);

    // HELO
    sprintf(command, "HELO localhost\r\n");
    send(sockfd, command, strlen(command), 0);
    read(sockfd, buffer, sizeof(buffer) - 1);
    printf("Server: %s", buffer);

    // AUTH LOGIN (simulated – adjust for your real credentials)
    sprintf(command, "AUTH LOGIN\r\n");
    send(sockfd, command, strlen(command), 0);
    read(sockfd, buffer, sizeof(buffer) - 1);
    printf("Server: %s", buffer);

    // Send sender address
    sprintf(command, "%s\r\n", from);
    send(sockfd, command, strlen(command), 0);
    read(sockfd, buffer, sizeof(buffer) - 1);
    printf("Server: %s", buffer);

    // Send recipient addresses
    for (int i = 0; i < to_count; i++) {
        sprintf(command, "RCPT TO: %s\r\n", to[i]);
        send(sockfd, command, strlen(command), 0);
        read(sockfd, buffer, sizeof(buffer) - 1);
        printf("Server: %s", buffer);
    }

    // Send DATA command
    send(sockfd, "DATA\r\n", 7, 0);
    read(sockfd, buffer, sizeof(buffer) - 1);
    printf("Server: %s", buffer);

    // Construct email headers and body
    sprintf(command, "From: %s\r\n", from);
    send(sockfd, command, strlen(command), 0);
    for (int i = 0; i < to_count; i++) {
        sprintf(command, "To: %s\r\n", to[i]);
        send(sockfd, command, strlen(command), 0);
    }
    sprintf(command, "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, body);
    send(sockfd, command, strlen(command), 0);
    read(sockfd, buffer, sizeof(buffer) - 1);
    printf("Server: %s", buffer);

    // Quit the session
    send(sockfd, "QUIT\r\n", 7, 0);
    read(sockfd, buffer, sizeof(buffer) - 1);
    printf("Server: %s", buffer);

    close(sockfd);
    return true;
}

int main() {
    char *smtp_server = "smtp.example.com";
    char sender[MAX_EMAIL_LENGTH] = "sender@example.com";
    char *recipients[MAX_RECIPIENTS] = {
        "recipient1@example.com",
        "recipient2@example.com"
    };
    int recipient_count = 2;
    char subject[MAX_SUBJECT_LENGTH] = "Test Email";
    char body[MAX_BODY_LENGTH] = "Hello, this is a test email sent from a C email client.";

    if (send_email(smtp_server, sender, recipients, recipient_count, subject, body)) {
        printf("Email sent successfully!\n");
    } else {
        printf("Failed to send email.\n");
    }

    return 0;
}