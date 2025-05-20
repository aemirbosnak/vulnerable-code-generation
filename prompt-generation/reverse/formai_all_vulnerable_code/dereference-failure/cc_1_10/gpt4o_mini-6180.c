//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SMTP_PORT 25
#define MAX_BUFFER 1024

void send_command(int sockfd, const char *cmd, const char *response_check) {
    char buffer[MAX_BUFFER];
    send(sockfd, cmd, strlen(cmd), 0);
    recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    
    if (strstr(buffer, response_check) == NULL) {
        fprintf(stderr, "Error: Unexpected response: %s\n", buffer);
        exit(EXIT_FAILURE);
    }
}

void smtp_auth(int sockfd, const char *username, const char *password) {
    char cmd[MAX_BUFFER];

    snprintf(cmd, sizeof(cmd), "EHLO localhost\r\n");
    send_command(sockfd, cmd, "250");

    snprintf(cmd, sizeof(cmd), "AUTH LOGIN\r\n");
    send_command(sockfd, cmd, "334");

    // Send encoded username
    snprintf(cmd, sizeof(cmd), "%s\r\n", username);
    send_command(sockfd, cmd, "334");

    // Send encoded password
    snprintf(cmd, sizeof(cmd), "%s\r\n", password);
    send_command(sockfd, cmd, "235");
}

void send_email(int sockfd, const char *from, const char *to, const char *subject, const char *body) {
    char cmd[MAX_BUFFER];

    snprintf(cmd, sizeof(cmd), "MAIL FROM: <%s>\r\n", from);
    send_command(sockfd, cmd, "250");

    snprintf(cmd, sizeof(cmd), "RCPT TO: <%s>\r\n", to);
    send_command(sockfd, cmd, "250");

    snprintf(cmd, sizeof(cmd), "DATA\r\n");
    send_command(sockfd, cmd, "354");

    // Sending email headers and body
    snprintf(cmd, sizeof(cmd), "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, body);
    send(sockfd, cmd, strlen(cmd), 0);
    
    recv(sockfd, cmd, sizeof(cmd) - 1, 0);
    if (strstr(cmd, "250") == NULL) {
        fprintf(stderr, "Error: Failed to send email: %s\n", cmd);
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 6) {
        fprintf(stderr, "Usage: %s <smtp_server> <username> <password> <from> <to>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *smtp_server = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];
    const char *from = argv[4];
    const char *to = argv[5];

    struct sockaddr_in server_address;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Could not create socket");
        return EXIT_FAILURE;
    }

    struct hostent *host = gethostbyname(smtp_server);
    if (host == NULL) {
        fprintf(stderr, "Could not resolve hostname: %s\n", smtp_server);
        close(sockfd);
        return EXIT_FAILURE;
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SMTP_PORT);
    memcpy(&server_address.sin_addr.s_addr, host->h_addr, host->h_length);

    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Could not connect to server");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Read the server's greeting
    char buffer[MAX_BUFFER];
    recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    printf("Server response: %s\n", buffer);

    // Authenticate
    smtp_auth(sockfd, username, password);

    // Sending email content
    const char *subject = "Test Email";
    const char *body = "This is a test email sent from a C program!";
    send_email(sockfd, from, to, subject, body);

    snprintf(buffer, sizeof(buffer), "QUIT\r\n");
    send_command(sockfd, buffer, "221");

    // Clean up
    close(sockfd);
    printf("Email sent successfully!\n");
    return EXIT_SUCCESS;
}