//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>

#define SMTP_PORT 25

int main() {
    int sockfd, rc;
    struct sockaddr_in server_addr;
    char buffer[1024];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Get the server address
    struct hostent *server = gethostbyname("smtp.example.com");
    if (server == NULL) {
        fprintf(stderr, "Could not resolve hostname: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Fill in the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr_list[0], server->h_length);

    // Connect to the server
    rc = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (rc == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Send the HELO command
    rc = send(sockfd, "HELO example.com\r\n", strlen("HELO example.com\r\n"), 0);
    if (rc == -1) {
        perror("send HELO");
        exit(EXIT_FAILURE);
    }

    // Receive the server response
    rc = recv(sockfd, buffer, sizeof(buffer), 0);
    if (rc == -1) {
        perror("recv HELO");
        exit(EXIT_FAILURE);
    }

    // Check the server response
    if (strncmp(buffer, "250", 3) != 0) {
        fprintf(stderr, "Error: %s\n", buffer);
        exit(EXIT_FAILURE);
    }

    // Send the MAIL FROM command
    rc = send(sockfd, "MAIL FROM: <sender@example.com>\r\n", strlen("MAIL FROM: <sender@example.com>\r\n"), 0);
    if (rc == -1) {
        perror("send MAIL FROM");
        exit(EXIT_FAILURE);
    }

    // Receive the server response
    rc = recv(sockfd, buffer, sizeof(buffer), 0);
    if (rc == -1) {
        perror("recv MAIL FROM");
        exit(EXIT_FAILURE);
    }

    // Check the server response
    if (strncmp(buffer, "250", 3) != 0) {
        fprintf(stderr, "Error: %s\n", buffer);
        exit(EXIT_FAILURE);
    }

    // Send the RCPT TO command
    rc = send(sockfd, "RCPT TO: <recipient@example.com>\r\n", strlen("RCPT TO: <recipient@example.com>\r\n"), 0);
    if (rc == -1) {
        perror("send RCPT TO");
        exit(EXIT_FAILURE);
    }

    // Receive the server response
    rc = recv(sockfd, buffer, sizeof(buffer), 0);
    if (rc == -1) {
        perror("recv RCPT TO");
        exit(EXIT_FAILURE);
    }

    // Check the server response
    if (strncmp(buffer, "250", 3) != 0) {
        fprintf(stderr, "Error: %s\n", buffer);
        exit(EXIT_FAILURE);
    }

    // Send the DATA command
    rc = send(sockfd, "DATA\r\n", strlen("DATA\r\n"), 0);
    if (rc == -1) {
        perror("send DATA");
        exit(EXIT_FAILURE);
    }

    // Receive the server response
    rc = recv(sockfd, buffer, sizeof(buffer), 0);
    if (rc == -1) {
        perror("recv DATA");
        exit(EXIT_FAILURE);
    }

    // Check the server response
    if (strncmp(buffer, "354", 3) != 0) {
        fprintf(stderr, "Error: %s\n", buffer);
        exit(EXIT_FAILURE);
    }

    // Send the email message
    rc = send(sockfd, "From: sender@example.com\r\n", strlen("From: sender@example.com\r\n"), 0);
    if (rc == -1) {
        perror("send From");
        exit(EXIT_FAILURE);
    }

    rc = send(sockfd, "To: recipient@example.com\r\n", strlen("To: recipient@example.com\r\n"), 0);
    if (rc == -1) {
        perror("send To");
        exit(EXIT_FAILURE);
    }

    rc = send(sockfd, "Subject: Test email\r\n", strlen("Subject: Test email\r\n"), 0);
    if (rc == -1) {
        perror("send Subject");
        exit(EXIT_FAILURE);
    }

    rc = send(sockfd, "\r\n", strlen("\r\n"), 0);
    if (rc == -1) {
        perror("send newline");
        exit(EXIT_FAILURE);
    }

    rc = send(sockfd, "This is a test email.\r\n", strlen("This is a test email.\r\n"), 0);
    if (rc == -1) {
        perror("send email body");
        exit(EXIT_FAILURE);
    }

    rc = send(sockfd, ".\r\n", strlen(".\r\n"), 0);
    if (rc == -1) {
        perror("send end of message");
        exit(EXIT_FAILURE);
    }

    // Receive the server response
    rc = recv(sockfd, buffer, sizeof(buffer), 0);
    if (rc == -1) {
        perror("recv end of message");
        exit(EXIT_FAILURE);
    }

    // Check the server response
    if (strncmp(buffer, "250", 3) != 0) {
        fprintf(stderr, "Error: %s\n", buffer);
        exit(EXIT_FAILURE);
    }

    // Send the QUIT command
    rc = send(sockfd, "QUIT\r\n", strlen("QUIT\r\n"), 0);
    if (rc == -1) {
        perror("send QUIT");
        exit(EXIT_FAILURE);
    }

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}