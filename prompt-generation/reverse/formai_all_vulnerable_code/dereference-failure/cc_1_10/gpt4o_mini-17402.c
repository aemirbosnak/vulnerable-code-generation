//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define PORT 25 // SMTP port
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void send_command(int sockfd, const char *cmd) {
    char buffer[BUFFER_SIZE];
    send(sockfd, cmd, strlen(cmd), 0);
    recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    printf("%s", buffer);
}

void initialize_email_client(int *sockfd) {
    struct sockaddr_in server_addr;
    *sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (*sockfd < 0) {
        error("Failed to create socket");
    }

    struct hostent *server = gethostbyname("smtp.example.com");
    if (server == NULL) {
        fprintf(stderr, "No such host\n");
        exit(EXIT_FAILURE);
    }

    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(PORT);

    if (connect(*sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Failed to connect to the server");
    }
}

void authenticate(int sockfd, const char *username, const char *password) {
    send_command(sockfd, "HELO localhost\r\n");
    send_command(sockfd, "AUTH LOGIN\r\n");

    char encoded_username[BUFFER_SIZE];
    char encoded_password[BUFFER_SIZE];

    snprintf(encoded_username, sizeof(encoded_username), "%s\r\n", username);
    snprintf(encoded_password, sizeof(encoded_password), "%s\r\n", password);

    send_command(sockfd, encoded_username);
    send_command(sockfd, encoded_password);
}

void send_email(int sockfd, const char *from, const char *to, const char *subject, const char *body) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "MAIL FROM:<%s>\r\n", from);
    send_command(sockfd, command);

    snprintf(command, sizeof(command), "RCPT TO:<%s>\r\n", to);
    send_command(sockfd, command);

    send_command(sockfd, "DATA\r\n");

    snprintf(command, sizeof(command), "Subject: %s\r\nFrom: %s\r\nTo: %s\r\n\r\n%s\r\n.\r\n", subject, from, to, body);
    send_command(sockfd, command);
}

void close_connection(int sockfd) {
    send_command(sockfd, "QUIT\r\n");
    close(sockfd);
}

int main() {
    int sockfd;
    const char *username = "example@gmail.com"; // Provide real email
    const char *password = "your_password"; // Provide real password
    const char *from = "example@gmail.com"; // Provide real email
    const char *to = "recipient@example.com"; // Provide real recipient
    const char *subject = "Hello from C Email Client";
    const char *body = "This is a test email sent from a C program!";

    initialize_email_client(&sockfd);
    authenticate(sockfd, username, password);
    send_email(sockfd, from, to, subject, body);
    close_connection(sockfd);

    printf("Email sent successfully!\n");
    return 0;
}