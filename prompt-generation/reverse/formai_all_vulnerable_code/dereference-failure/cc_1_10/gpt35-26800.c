//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 256
#define MAX_MESSAGE_SIZE 1024
#define SMTP_PORT 25

int main(int argc, char *argv[]) {
    int sockfd;
    char buffer[MAX_BUFFER_SIZE];
    char message[MAX_MESSAGE_SIZE];

    struct sockaddr_in server_addr;
    struct hostent *server;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error: could not create socket\n");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: no such host\n");
        exit(1);
    }

    memset((char *) &server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(SMTP_PORT);

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "Error: could not connect to server\n");
        exit(1);
    }

    recv(sockfd, buffer, MAX_BUFFER_SIZE - 1, 0);
    printf("%s", buffer);

    sprintf(message, "HELO %s\r\n", argv[1]);
    write(sockfd, message, strlen(message));

    recv(sockfd, buffer, MAX_BUFFER_SIZE - 1, 0);
    printf("%s", buffer);

    sprintf(message, "MAIL FROM:<%s>\r\n", "sender@example.com");
    write(sockfd, message, strlen(message));

    recv(sockfd, buffer, MAX_BUFFER_SIZE - 1, 0);
    printf("%s", buffer);

    sprintf(message, "RCPT TO:<%s>\r\n", "recipient@example.com");
    write(sockfd, message, strlen(message));

    recv(sockfd, buffer, MAX_BUFFER_SIZE - 1, 0);
    printf("%s", buffer);

    sprintf(message, "DATA\r\n");
    write(sockfd, message, strlen(message));

    recv(sockfd, buffer, MAX_BUFFER_SIZE - 1, 0);
    printf("%s", buffer);

    sprintf(message, "Subject: SMTP Client Test\r\n\r\nThis is a test message sent by my SMTP client program.\r\n");
    write(sockfd, message, strlen(message));

    sprintf(message, "\r\n.\r\n");
    write(sockfd, message, strlen(message));

    recv(sockfd, buffer, MAX_BUFFER_SIZE - 1, 0);
    printf("%s", buffer);

    sprintf(message, "QUIT\r\n");
    write(sockfd, message, strlen(message));

    recv(sockfd, buffer, MAX_BUFFER_SIZE - 1, 0);
    printf("%s", buffer);

    close(sockfd);

    return 0;
}