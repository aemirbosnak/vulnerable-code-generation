//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 1024
#define PORT 25
#define SERVER "smtp.example.com"

int main() {
    int sockfd;
    struct sockaddr_in serv_addr;
    char send_buffer[BUF_SIZE];
    char recv_buffer[BUF_SIZE];
    int n, m;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Could not create socket: %s\n", strerror(errno));
        exit(1);
    }

    // Initialize server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER, &serv_addr.sin_addr);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Could not connect to server: %s\n", strerror(errno));
        exit(1);
    }

    // Send HELO command
    strcpy(send_buffer, "HELO example.com\r\n");
    n = send(sockfd, send_buffer, strlen(send_buffer), 0);
    if (n < 0) {
        printf("Could not send HELO command: %s\n", strerror(errno));
        exit(1);
    }

    // Send MAIL FROM command
    strcpy(send_buffer, "MAIL FROM: <sender@example.com>\r\n");
    n = send(sockfd, send_buffer, strlen(send_buffer), 0);
    if (n < 0) {
        printf("Could not send MAIL FROM command: %s\n", strerror(errno));
        exit(1);
    }

    // Send RCPT TO command
    strcpy(send_buffer, "RCPT TO: <recipient@example.com>\r\n");
    n = send(sockfd, send_buffer, strlen(send_buffer), 0);
    if (n < 0) {
        printf("Could not send RCPT TO command: %s\n", strerror(errno));
        exit(1);
    }

    // Send DATA command
    strcpy(send_buffer, "DATA\r\n");
    n = send(sockfd, send_buffer, strlen(send_buffer), 0);
    if (n < 0) {
        printf("Could not send DATA command: %s\n", strerror(errno));
        exit(1);
    }

    // Send email content
    strcpy(send_buffer, "Subject: Test Email\r\n");
    n = send(sockfd, send_buffer, strlen(send_buffer), 0);
    if (n < 0) {
        printf("Could not send email content: %s\n", strerror(errno));
        exit(1);
    }

    strcpy(send_buffer, "\r\n");
    n = send(sockfd, send_buffer, strlen(send_buffer), 0);
    if (n < 0) {
        printf("Could not send email content: %s\n", strerror(errno));
        exit(1);
    }

    // Receive server response
    m = recv(sockfd, recv_buffer, BUF_SIZE, 0);
    if (m < 0) {
        printf("Could not receive server response: %s\n", strerror(errno));
        exit(1);
    }

    printf("Server response: %s\n", recv_buffer);

    // Close socket
    close(sockfd);

    return 0;
}