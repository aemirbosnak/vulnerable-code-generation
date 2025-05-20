//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: decentralized
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_LINE 1024

int main(int argc, char *argv[])
{
    int sockfd, port;
    char *hostname, *username, *password, *to, *subject, *body;
    struct sockaddr_in serveraddr;

    if (argc != 8) {
        fprintf(stderr, "Usage: %s hostname port username password to subject body\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    hostname = argv[1];
    port = atoi(argv[2]);
    username = argv[3];
    password = argv[4];
    to = argv[5];
    subject = argv[6];
    body = argv[7];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(port);
    if (inet_pton(AF_INET, hostname, &serveraddr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_LINE];
    sprintf(buffer, "EHLO %s\r\n", hostname);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, MAX_LINE, 0);

    sprintf(buffer, "AUTH LOGIN\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, MAX_LINE, 0);

    sprintf(buffer, "%s\r\n", username);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, MAX_LINE, 0);

    sprintf(buffer, "%s\r\n", password);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, MAX_LINE, 0);

    sprintf(buffer, "MAIL FROM: <%s>\r\n", username);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, MAX_LINE, 0);

    sprintf(buffer, "RCPT TO: <%s>\r\n", to);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, MAX_LINE, 0);

    sprintf(buffer, "DATA\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, MAX_LINE, 0);

    sprintf(buffer, "Subject: %s\r\n", subject);
    send(sockfd, buffer, strlen(buffer), 0);

    sprintf(buffer, "Content-Type: text/plain; charset=UTF-8\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    send(sockfd, "\r\n", 2, 0);
    send(sockfd, body, strlen(body), 0);

    send(sockfd, "\r\n.\r\n", 5, 0);
    recv(sockfd, buffer, MAX_LINE, 0);

    sprintf(buffer, "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, MAX_LINE, 0);

    close(sockfd);

    return 0;
}