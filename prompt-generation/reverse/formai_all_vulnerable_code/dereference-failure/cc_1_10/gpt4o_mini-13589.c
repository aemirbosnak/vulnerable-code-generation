//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 25
#define SMTP_BUFFER 512

// Function prototypes
int smtp_send_command(int sockfd, const char *cmd);
void send_email(int sockfd, const char *from, const char *to, const char *subject, const char *body);
void close_connection(int sockfd);

int main() {
    int sockfd;
    struct sockaddr_in server_addr;

    // 1. Initialize socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // 2. Define the server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Example: Local server

    // 3. Connect to the SMTP server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to the server failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    
    // 4. Send the EHLO command
    smtp_send_command(sockfd, "EHLO localhost\r\n");

    // 5. Prepare the email details
    const char *from = "sender@example.com";
    const char *to = "receiver@example.com";
    const char *subject = "Test Email";
    const char *body = "Hello, this is a test email from the simple SMTP client.";

    // 6. Send the email
    send_email(sockfd, from, to, subject, body);

    // 7. Quit session
    smtp_send_command(sockfd, "QUIT\r\n");

    // 8. Close the connection
    close_connection(sockfd);

    return 0;
}

// Function to send a command to the SMTP server and print the response
int smtp_send_command(int sockfd, const char *cmd) {
    char buffer[SMTP_BUFFER];

    // 1. Send the command
    write(sockfd, cmd, strlen(cmd));

    // 2. Read the response
    read(sockfd, buffer, sizeof(buffer) - 1);
    buffer[SMTP_BUFFER - 1] = '\0'; // Null-terminate

    // 3. Print the response from the server
    printf("Server response: %s", buffer);
    return 0;
}

// Function to send the email
void send_email(int sockfd, const char *from, const char *to, const char *subject, const char *body) {
    // 1. Specify the sender
    char command[SMTP_BUFFER];
    snprintf(command, sizeof(command), "MAIL FROM:<%s>\r\n", from);
    smtp_send_command(sockfd, command);

    // 2. Specify the recipient
    snprintf(command, sizeof(command), "RCPT TO:<%s>\r\n", to);
    smtp_send_command(sockfd, command);

    // 3. Indicate we want to send data
    smtp_send_command(sockfd, "DATA\r\n");

    // 4. Send the email headers and body
    snprintf(command, sizeof(command),
             "From: %s\r\nTo: %s\r\nSubject: %s\r\n\r\n%s\r\n.\r\n",
             from, to, subject, body);
    smtp_send_command(sockfd, command);
}

// Function to close the socket connection
void close_connection(int sockfd) {
    close(sockfd);
}