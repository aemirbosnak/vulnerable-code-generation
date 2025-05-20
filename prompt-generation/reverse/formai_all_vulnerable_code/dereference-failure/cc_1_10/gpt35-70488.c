//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>

#define PORT 25
#define BUFFER_SIZE 1024

int main() {
    int sockfd, n;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in serv_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname("smtp.server.com");
    if (server == NULL) {
        perror("ERROR, no such host");
        exit(1);
    }

    bzero((char*)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char*)server->h_addr, (char*)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // send HELO command
    bzero(buffer, BUFFER_SIZE);
    sprintf(buffer, "HELO example.com\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    // send MAIL command
    bzero(buffer, BUFFER_SIZE);
    sprintf(buffer, "MAIL FROM:<sender@example.com>\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    // send RCPT command
    bzero(buffer, BUFFER_SIZE);
    sprintf(buffer, "RCPT TO:<recipient@example.com>\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    // send DATA command
    bzero(buffer, BUFFER_SIZE);
    sprintf(buffer, "DATA\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    // send email message
    bzero(buffer, BUFFER_SIZE);
    sprintf(buffer, "Subject: Test email\r\nFrom: sender@example.com\r\nTo: recipient@example.com\r\n\r\nThis is a test email.\r\n.\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    // send QUIT command
    bzero(buffer, BUFFER_SIZE);
    sprintf(buffer, "QUIT\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    close(sockfd);
    return 0;
}