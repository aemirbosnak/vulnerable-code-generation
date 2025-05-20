//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 256
#define SERVER_PORT 25
#define SERVER_ADDRESS "smtp.example.com"

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int n;

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    // set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_ADDRESS, &server_addr.sin_addr);

    // connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // send HELO command
    sprintf(buffer, "HELO client.example.com\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // send MAIL FROM command
    sprintf(buffer, "MAIL FROM: sender@example.com\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // send RCPT TO command
    sprintf(buffer, "RCPT TO: recipient@example.com\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // send DATA command
    sprintf(buffer, "DATA\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // send message body
    sprintf(buffer, "Subject: Test Message\r\n\r\nThis is a test message.\r\n.\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // send QUIT command
    sprintf(buffer, "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // close socket
    close(sockfd);

    return 0;
}