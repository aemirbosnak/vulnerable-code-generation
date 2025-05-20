//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

int main() {
    int sockfd;
    struct sockaddr_in serveraddr;
    struct hostent *host;

    char *server = "smtp.example.com";
    int port = 25;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    host = gethostbyname(server);

    if (host == NULL) {
        printf("Error resolving host\n");
        exit(1);
    }

    memset(&serveraddr, 0, sizeof(struct sockaddr_in));

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(port);
    serveraddr.sin_addr.s_addr = *(long *)host->h_addr;

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(struct sockaddr_in)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    char *helo = "HELO example.com\r\n";
    char *mailfrom = "MAIL FROM: <sender@example.com>\r\n";
    char *rcptto = "RCPT TO: <recipient@example.com>\r\n";
    char *data = "DATA\r\n";
    char *message = "Subject: Test Message\r\n\r\nThis is a test message.\r\n.\r\n";
    char *quit = "QUIT\r\n";

    send(sockfd, helo, strlen(helo), 0);
    send(sockfd, mailfrom, strlen(mailfrom), 0);
    send(sockfd, rcptto, strlen(rcptto), 0);
    send(sockfd, data, strlen(data), 0);
    send(sockfd, message, strlen(message), 0);
    send(sockfd, quit, strlen(quit), 0);

    close(sockfd);

    return 0;
}