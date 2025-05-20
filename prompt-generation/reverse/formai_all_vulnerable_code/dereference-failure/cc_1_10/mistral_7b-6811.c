//MISTRAL-7B DATASET v1.0 Category: Building a SMTP Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>

#define SERVER_PORT 25
#define BUFFER_SIZE 1024

void die(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <server_ip> <email_address>\n", argv[0]);
        exit(1);
    }

    const char *server_ip = argv[1];
    const char *email_address = argv[2];

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        die("socket: can't allocate socket");

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        die("connect: can't connect to server");

    // EHLO command
    write(sockfd, "HELO ", 4);
    write(sockfd, server_ip, strlen(server_ip));
    write(sockfd, "\r\n", 2);

    // Mail From command
    write(sockfd, "MAIL FROM: <", 11);
    write(sockfd, email_address, strlen(email_address));
    write(sockfd, ">\r\n", 3);

    // Rcpt To command
    write(sockfd, "RCPT TO: <", 9);
    write(sockfd, "recipient@example.com", strlen("recipient@example.com"));
    write(sockfd, ">\r\n", 3);

    // Data command
    write(sockfd, "DATA\r\n", 4);

    // Send email content
    char subject[] = "Test Email from SMTP Client";
    char message[] = "This is a test email sent using an SMTP client.";

    // Set up headers
    char header[BUFFER_SIZE];
    snprintf(header, BUFFER_SIZE, "From: %s\r\nSubject: %s\r\n\r\n", email_address, subject);

    // Send email content with headers
    write(sockfd, header, strlen(header));
    write(sockfd, message, strlen(message));

    // Quit command
    write(sockfd, "\r\n.\r\nQUIT\r\n", 7);

    close(sockfd);
    return 0;
}