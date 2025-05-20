//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SMTP_PORT 587
#define BUFFER_SIZE 1024

void send_command(int sockfd, const char *cmd, char *response) {
    write(sockfd, cmd, strlen(cmd));
    write(sockfd, "\r\n", 2);
    read(sockfd, response, BUFFER_SIZE - 1);
}

void init_smtp(int sockfd) {
    char response[BUFFER_SIZE];
    send_command(sockfd, "EHLO localhost", response);
    printf("%s", response);
}

void close_connection(int sockfd) {
    char response[BUFFER_SIZE];
    send_command(sockfd, "QUIT", response);
    printf("%s", response);
    close(sockfd);
}

void send_email(int sockfd, const char *from, const char *to, const char *subject, const char *body) {
    char response[BUFFER_SIZE];

    // Set sender
    char cmd[BUFFER_SIZE];
    snprintf(cmd, sizeof(cmd), "MAIL FROM:<%s>", from);
    send_command(sockfd, cmd, response);
    printf("%s", response);

    // Set recipient
    snprintf(cmd, sizeof(cmd), "RCPT TO:<%s>", to);
    send_command(sockfd, cmd, response);
    printf("%s", response);

    // Start the data section
    send_command(sockfd, "DATA", response);
    printf("%s", response);

    // Send the email body
    snprintf(cmd, sizeof(cmd), "Subject: %s\r\n\r\n%s\r\n.", subject, body);
    send_command(sockfd, cmd, response);
    printf("%s", response);
}

int main() {
    // Establishing the connection to the SMTP server
    struct sockaddr_in server_addr;
    struct hostent *host;

    const char *smtp_server = "smtp.example.com"; // Change this to your SMTP server
    const char *from = "your_email@example.com"; // Change this to the sender's email
    const char *to = "recipient@example.com"; // Change this to the recipient's email
    const char *subject = "Greetings from C SMTP Client";
    const char *body = "Hello! This is a test email sent from a C program.";

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return EXIT_FAILURE;
    }

    host = gethostbyname(smtp_server);
    if (host == NULL) {
        perror("Could not resolve host");
        return EXIT_FAILURE;
    }

    // Populate server address struct
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);
    server_addr.sin_port = htons(SMTP_PORT);

    // Connect to the SMTP server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to SMTP server failed");
        return EXIT_FAILURE;
    }

    // SMTP Protocol Initialization
    init_smtp(sockfd);

    // Send email
    send_email(sockfd, from, to, subject, body);

    // Cleanly close the connection
    close_connection(sockfd);

    return EXIT_SUCCESS;
}