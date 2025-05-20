//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>
#include <time.h>

#define SMTP_PORT 25
#define BUFFER_SIZE 1024
#define EMAIL_FROM "your_email@example.com"
#define EMAIL_TO "recipient_email@example.com"
#define EMAIL_SUBJECT "Test Email"
#define EMAIL_BODY "This is a test email sent using a C SMTP client."

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    time_t current_time;
    char *date_str;
    char *message;
    int message_size;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    inet_pton(AF_INET, "smtp.example.com", &server_addr.sin_addr);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server: %s\n", strerror(errno));
        exit(1);
    }

    // Send HELO command
    snprintf(buffer, BUFFER_SIZE, "HELO %s\r\n", EMAIL_FROM);
    send(sockfd, buffer, strlen(buffer), 0);

    // Send MAIL FROM command
    snprintf(buffer, BUFFER_SIZE, "MAIL FROM:<%s>\r\n", EMAIL_FROM);
    send(sockfd, buffer, strlen(buffer), 0);

    // Send RCPT TO command
    snprintf(buffer, BUFFER_SIZE, "RCPT TO:<%s>\r\n", EMAIL_TO);
    send(sockfd, buffer, strlen(buffer), 0);

    // Send DATA command
    snprintf(buffer, BUFFER_SIZE, "DATA\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Send email headers
    time(&current_time);
    date_str = ctime(&current_time);
    message_size = snprintf(buffer, BUFFER_SIZE, "From: %s\r\nTo: %s\r\nSubject: %s\r\nDate: %s\r\n\r\n%s", EMAIL_FROM, EMAIL_TO, EMAIL_SUBJECT, date_str, EMAIL_BODY);
    send(sockfd, buffer, message_size, 0);

    // Send end of data command
    snprintf(buffer, BUFFER_SIZE, ".\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Close connection
    close(sockfd);

    printf("Email sent successfully!\n");

    return 0;
}