//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 25  // Default SMTP port
#define BUFFER_SIZE 1024

void send_command(int sockfd, const char *cmd, char *response) {
    write(sockfd, cmd, strlen(cmd));
    write(sockfd, "\r\n", 2);
    read(sockfd, response, BUFFER_SIZE);
    printf("Server Response: %s", response);
}

void smtp_client(const char *smtp_server, const char *from, const char *to, const char *subject, const char *body) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // Surprise! Time to create a socket!
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Oh no! Socket creation failed!");
        exit(EXIT_FAILURE);
    }
    printf("Socket created! Ready to connect...\n");

    // Surprise again with an address struct!
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(smtp_server);

    // Wow! Let's connect to the server!
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Whoa! Connection to the SMTP server failed!");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    printf("Connected to SMTP server %s!\n", smtp_server);

    // Gasp! We might actually send some mail now!
    read(sockfd, buffer, BUFFER_SIZE);  // Ignore the initial greeting
    printf("%s", buffer);

    // HELO Command
    send_command(sockfd, "EHLO localhost", buffer);

    // AUTH LOGIN (This example does not implement authentication for simplicity)
    // send_command(sockfd, "AUTH LOGIN", buffer);

    // MAIL FROM Command
    char mail_from_cmd[BUFFER_SIZE];
    snprintf(mail_from_cmd, sizeof(mail_from_cmd), "MAIL FROM:<%s>", from);
    send_command(sockfd, mail_from_cmd, buffer);

    // RCPT TO Command
    char rcpt_to_cmd[BUFFER_SIZE];
    snprintf(rcpt_to_cmd, sizeof(rcpt_to_cmd), "RCPT TO:<%s>", to);
    send_command(sockfd, rcpt_to_cmd, buffer);

    // DATA Command
    send_command(sockfd, "DATA", buffer);

    // Prepare message
    char message[BUFFER_SIZE];
    snprintf(message, sizeof(message),
        "From: %s\r\n"
        "To: %s\r\n"
        "Subject: %s\r\n"
        "\r\n"
        "%s\r\n"
        ".",
        from, to, subject, body);

    // Surprise! Sending the message!
    write(sockfd, message, strlen(message));
    printf("Mail sent! Let's wait for the server to react...\n");
    read(sockfd, buffer, BUFFER_SIZE);
    printf("%s", buffer);

    // QUIT Command
    send_command(sockfd, "QUIT", buffer);

    // Close the socket
    close(sockfd);
    printf("Socket closed! What an adventure!\n");
}

int main() {
    printf("Welcome to the SMTP Client Surprise!\n");

    const char *smtp_server = "smtp.example.com";  // Replace with a valid SMTP server
    const char *from = "you@example.com";           // Replace with valid sender email
    const char *to = "friend@example.com";           // Replace with valid recipient email
    const char *subject = "Surprise Email";
    const char *body = "This is a surprise email sent from a C SMTP client!\n";

    smtp_client(smtp_server, from, to, subject, body);
    printf("Goodbye! Hope you enjoyed the SMTP surprise!\n");

    return 0;
}