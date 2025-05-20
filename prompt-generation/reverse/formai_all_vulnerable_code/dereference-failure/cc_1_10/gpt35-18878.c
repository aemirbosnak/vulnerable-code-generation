//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 25
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    char buffer[BUFFER_SIZE];
    char *hostname;
    struct sockaddr_in servaddr;

    if(argc != 2) {
        perror("Usage: ./client <hostname>");
        exit(EXIT_FAILURE);
    }

    hostname = argv[1];

    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);

    if(inet_pton(AF_INET, hostname, &servaddr.sin_addr) <= 0) {
        perror("Invalid hostname");
        exit(EXIT_FAILURE);
    }

    if(connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Connection error");
        exit(EXIT_FAILURE);
    }

    // Read server response
    n = read(sockfd, buffer, BUFFER_SIZE);
    buffer[n] = '\0';
    printf("Server: %s", buffer);

    // Send HELO message
    char helo_command[100];
    sprintf(helo_command, "HELO %s\r\n", hostname);
    write(sockfd, helo_command, strlen(helo_command));
    n = read(sockfd, buffer, BUFFER_SIZE);
    buffer[n] = '\0';
    printf("Server: %s", buffer);

    // Send MAIL FROM message
    char mail_from_command[100] = "MAIL FROM: <sender@example.com>\r\n";
    write(sockfd, mail_from_command, strlen(mail_from_command));
    n = read(sockfd, buffer, BUFFER_SIZE);
    buffer[n] = '\0';
    printf("Server: %s", buffer);

    // Send RCPT TO message
    char rcpt_to_command[100] = "RCPT TO: <recipient@example.com>\r\n";
    write(sockfd, rcpt_to_command, strlen(rcpt_to_command));
    n = read(sockfd, buffer, BUFFER_SIZE);
    buffer[n] = '\0';
    printf("Server: %s", buffer);

    // Send DATA message
    char data_command[100] = "DATA\r\n";
    write(sockfd, data_command, strlen(data_command));
    n = read(sockfd, buffer, BUFFER_SIZE);
    buffer[n] = '\0';
    printf("Server: %s", buffer);

    // Send email body
    char email_body[200] = "Subject: Test email\r\n\r\nThis is a test email from my SMTP client.\r\n.\r\n";
    write(sockfd, email_body, strlen(email_body));
    n = read(sockfd, buffer, BUFFER_SIZE);
    buffer[n] = '\0';
    printf("Server: %s", buffer);

    // Send QUIT message
    char quit_command[100] = "QUIT\r\n";
    write(sockfd, quit_command, strlen(quit_command));
    n = read(sockfd, buffer, BUFFER_SIZE);
    buffer[n] = '\0';
    printf("Server: %s", buffer);

    close(sockfd);
    return 0;
}