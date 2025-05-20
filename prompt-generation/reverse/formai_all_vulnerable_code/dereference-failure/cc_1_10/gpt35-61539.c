//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: ./smtp <ip> <port>\n");
        exit(EXIT_FAILURE);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;

    inet_pton(AF_INET, argv[1], &server.sin_addr);
    server.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    recv(sockfd, buffer, BUFFER_SIZE, 0); // Receive message from server
    printf("%s\n", buffer);

    // Send HELO
    char *helo = "HELO me\r\n";
    send(sockfd, helo, strlen(helo), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s\n", buffer);

    // Send MAIL FROM
    char *mail_from = "MAIL FROM:<sender@example.com>\r\n";
    send(sockfd, mail_from, strlen(mail_from), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s\n", buffer);

    // Send RCPT TO
    char *rcpt_to = "RCPT TO:<receiver@example.com>\r\n";
    send(sockfd, rcpt_to, strlen(rcpt_to), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s\n", buffer);

    // Send DATA
    char *data = "DATA\r\n";
    send(sockfd, data, strlen(data), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s\n", buffer);

    // Send message body
    char *message = "From: sender@example.com\r\n"
                    "To: receiver@example.com\r\n"
                    "Subject: SMTP Client Example\r\n\r\n"
                    "Hello World!\r\n.\r\n";
    send(sockfd, message, strlen(message), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s\n", buffer);

    // Send QUIT
    char *quit = "QUIT\r\n";
    send(sockfd, quit, strlen(quit), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s\n", buffer);

    close(sockfd);
    return 0;
}