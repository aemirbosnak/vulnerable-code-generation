//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <ctype.h>

#define SMTP_PORT 25
#define BUFFER_SIZE 1024

void check_response(int sockfd, const char *expected_response) {
    char buffer[BUFFER_SIZE];
    read(sockfd, buffer, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0'; // Null-terminate the buffer

    if (strncmp(buffer, expected_response, 3) != 0) {
        fprintf(stderr, "Unexpected response: %s\n", buffer);
        exit(EXIT_FAILURE);
    }

    printf("%s", buffer); // Print response for debugging
}

void send_command(int sockfd, const char *command) {
    write(sockfd, command, strlen(command));
    write(sockfd, "\r\n", 2); // SMTP requires CRLF line ending
}

void send_email(const char *server, const char *from, const char *to, const char *subject, const char *body) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    server_addr.sin_addr.s_addr = inet_addr(server);

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Check initial server response
    check_response(sockfd, "220");

    // HELO command
    send_command(sockfd, "HELO localhost");
    check_response(sockfd, "250");

    // MAIL FROM command
    snprintf(buffer, sizeof(buffer), "MAIL FROM: <%s>", from);
    send_command(sockfd, buffer);
    check_response(sockfd, "250");

    // RCPT TO command
    snprintf(buffer, sizeof(buffer), "RCPT TO: <%s>", to);
    send_command(sockfd, buffer);
    check_response(sockfd, "250");

    // DATA command
    send_command(sockfd, "DATA");
    check_response(sockfd, "354");

    // Prepare email content
    snprintf(buffer, sizeof(buffer), "Subject: %s\r\nFrom: %s\r\nTo: %s\r\n\r\n%s\r\n.", subject, from, to, body);
    send_command(sockfd, buffer);
    check_response(sockfd, "250");

    // QUIT command
    send_command(sockfd, "QUIT");
    check_response(sockfd, "221");

    close(sockfd);
    printf("Email sent successfully!\n");
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <smtp_server> <from_email> <to_email> <subject> <body>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *smtp_server = argv[1];
    const char *from_email = argv[2];
    const char *to_email = argv[3];
    const char *subject = argv[4];

    // You can change the body content directly in the code or pass it as another argument
    const char *body = "This is a test email body.";

    send_email(smtp_server, from_email, to_email, subject, body);

    return EXIT_SUCCESS;
}