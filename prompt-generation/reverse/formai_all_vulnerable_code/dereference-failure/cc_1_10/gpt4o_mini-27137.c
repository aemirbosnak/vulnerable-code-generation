//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_EMAIL_LENGTH 256
#define MAX_SUBJECT_LENGTH 128
#define MAX_BODY_LENGTH 1024
#define MAX_RECIPIENTS 10
#define SMTP_PORT 587
#define BUFFER_SIZE 1024

void send_email(const char *smtp_server, const char *from, const char *recipients[], int recipient_count, const char *subject, const char *body) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int i;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    inet_pton(AF_INET, smtp_server, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to SMTP server failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Receive greeting from server
    read(sockfd, buffer, sizeof(buffer));
    printf("Server: %s", buffer);

    // Send EHLO command
    sprintf(buffer, "EHLO localhost\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    read(sockfd, buffer, sizeof(buffer));
    printf("Server: %s", buffer);
    
    // Send MAIL FROM command
    sprintf(buffer, "MAIL FROM:<%s>\r\n", from);
    send(sockfd, buffer, strlen(buffer), 0);
    read(sockfd, buffer, sizeof(buffer));
    printf("Server: %s", buffer);

    // Send RCPT TO commands
    for (i = 0; i < recipient_count; i++) {
        sprintf(buffer, "RCPT TO:<%s>\r\n", recipients[i]);
        send(sockfd, buffer, strlen(buffer), 0);
        read(sockfd, buffer, sizeof(buffer));
        printf("Server: %s", buffer);
    }

    // Send DATA command
    send(sockfd, "DATA\r\n", 6, 0);
    read(sockfd, buffer, sizeof(buffer));
    printf("Server: %s", buffer);

    // Send email headers and body
    sprintf(buffer, "Subject: %s\r\n", subject);
    send(sockfd, buffer, strlen(buffer), 0);
    sprintf(buffer, "From: %s\r\n", from);
    send(sockfd, buffer, strlen(buffer), 0);
    sprintf(buffer, "To: ");
    send(sockfd, buffer, strlen(buffer), 0);
    for (i = 0; i < recipient_count; i++) {
        sprintf(buffer, "<%s>", recipients[i]);
        send(sockfd, buffer, strlen(buffer), (i == recipient_count - 1) ? 0 : 1);
        if (i < recipient_count - 1) {
            send(sockfd, ", ", 2, 0);
        }
    }
    send(sockfd, "\r\n\r\n", 4, 0);
    
    // Send email body
    send(sockfd, body, strlen(body), 0);
    send(sockfd, "\r\n.\r\n", 5, 0);  // End of message
    read(sockfd, buffer, sizeof(buffer));
    printf("Server: %s", buffer);

    // Send QUIT command
    send(sockfd, "QUIT\r\n", 7, 0);
    read(sockfd, buffer, sizeof(buffer));
    printf("Server: %s", buffer);

    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc < 5) {
        printf("Usage: %s <smtp_server> <from_email> <subject> <body> <recipient1> <recipient2> ...\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *smtp_server = argv[1];
    const char *from_email = argv[2];
    const char *subject = argv[3];
    const char *body = argv[4];
    const char **recipients = (const char **)malloc((argc - 5) * sizeof(char *));
    int recipient_count = argc - 5;

    for (int i = 0; i < recipient_count; i++) {
        recipients[i] = argv[i + 5];
    }

    send_email(smtp_server, from_email, recipients, recipient_count, subject, body);

    free(recipients);
    return EXIT_SUCCESS;
}