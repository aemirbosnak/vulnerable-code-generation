//MISTRAL-7B DATASET v1.0 Category: Building a SMTP Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>

#define SMTP_PORT 25
#define BUFFER_SIZE 4096

int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Usage: %s <to_email@example.com> <message.txt>\n", argv[0]);
        return 1;
    }

    const char *to = argv[1];
    const char *message_file = argv[2];

    int sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) {
        perror("inet_pton");
        close(sockfd);
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        close(sockfd);
        return 1;
    }

    printf("Connected to SMTP server\n");

    // EHLO command
    send(sockfd, "HELO localhost\r\n", strlen("HELO localhost\r\n"), 0);

    // MAIL FROM command
    const char *from = "sender@example.com";
    send(sockfd, "MAIL FROM: <", strlen("MAIL FROM: <"), 0);
    send(sockfd, from, strlen(from), 0);
    send(sockfd, ">\r\n", strlen(">\r\n"), 0);

    // RCPT TO command
    send(sockfd, "RCPT TO: <", strlen("RCPT TO: <"), 0);
    send(sockfd, to, strlen(to), 0);
    send(sockfd, ">\r\n", strlen(">\r\n"), 0);

    // Data mode
    send(sockfd, "DATA\r\n", strlen("DATA\r\n"), 0);

    FILE *message_fp = fopen(message_file, "rb");
    if (message_fp == NULL) {
        perror("fopen");
        send(sockfd, "QUIT\r\n", strlen("QUIT\r\n"), 0);
        close(sockfd);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    while ((bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, message_fp)) > 0) {
        send(sockfd, buffer, bytes_read, 0);
    }

    fclose(message_fp);

    // End of data and quit
    send(sockfd, "\r\n.\r\n", strlen("\r\n.\r\n"), 0);
    send(sockfd, "QUIT\r\n", strlen("QUIT\r\n"), 0);

    close(sockfd);

    printf("Email sent successfully\n");

    return 0;
}