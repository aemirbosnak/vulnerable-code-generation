//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main() {
    struct addrinfo *server_info;
    int sockfd;
    char buffer[BUFFER_SIZE];
    char *username = "your_username";
    char *password = "your_password";
    char *to = "recipient@example.com";
    char *subject = "Test Email";
    char *body = "This is a test email sent using SMTP client in C.";
    char *message = NULL;
    int message_length = 0;
    int bytes_sent;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    // Get server information
    memset(&server_info, 0, sizeof(struct addrinfo));
    server_info->ai_family = AF_INET;
    server_info->ai_socktype = SOCK_STREAM;
    getaddrinfo("smtp.example.com", "587", &server_info, NULL);

    // Connect to the server
    if (connect(sockfd, server_info->ai_addr, server_info->ai_addrlen) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    // Send SMTP commands
    send(sockfd, "EHLO your_hostname\r\n", strlen("EHLO your_hostname\r\n"), 0);
    send(sockfd, "AUTH LOGIN\r\n", strlen("AUTH LOGIN\r\n"), 0);
    send(sockfd, username, strlen(username), 0);
    send(sockfd, "\r\n", 2, 0);
    send(sockfd, password, strlen(password), 0);
    send(sockfd, "\r\n", 2, 0);

    // Create message
    message_length = strlen(subject) + strlen(body) + strlen("\r\n.\r\n") + strlen(to) + strlen("\r\n");
    message = malloc(message_length + 1);
    if (message == NULL) {
        printf("Error allocating memory\n");
        return 1;
    }
    strcat(message, "To: ");
    strcat(message, to);
    strcat(message, "\r\n");
    strcat(message, "Subject: ");
    strcat(message, subject);
    strcat(message, "\r\n");
    strcat(message, "\r\n");
    strcat(message, body);
    strcat(message, "\r\n.\r\n");

    // Send message
    bytes_sent = send(sockfd, message, message_length, 0);
    if (bytes_sent == -1) {
        printf("Error sending message\n");
        return 1;
    }

    printf("Message sent successfully\n");
    close(sockfd);
    return 0;
}