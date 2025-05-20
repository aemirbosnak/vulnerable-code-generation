//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/tcp.h>
#include <unistd.h>

#define PORT 25

int main() {
    int sockfd, ret, n;
    struct sockaddr_in serv_addr;
    char buf[256];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = inet_addr("localhost");

    ret = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (ret < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    printf("Connected to SMTP server.\n");

    ret = send(sockfd, "EHLO localhost\r\n", 12, 0);
    if (ret < 0) {
        perror("ERROR sending EHLO command");
        exit(1);
    }

    ret = send(sockfd, "MAIL FROM: test@example.com\r\n", 24, 0);
    if (ret < 0) {
        perror("ERROR sending MAIL FROM command");
        exit(1);
    }

    ret = send(sockfd, "RCPT TO: test@example.com\r\n", 24, 0);
    if (ret < 0) {
        perror("ERROR sending RCPT TO command");
        exit(1);
    }

    ret = send(sockfd, "DATA\r\n", 7, 0);
    if (ret < 0) {
        perror("ERROR sending DATA command");
        exit(1);
    }

    sprintf(buf, "Subject: Test email\r\n\r\nThis is a test email.\r\n.\r\n.\r\n.\r\n.\r\n.\r\n.\r\n");
    ret = send(sockfd, buf, strlen(buf), 0);
    if (ret < 0) {
        perror("ERROR sending email message");
        exit(1);
    }

    ret = send(sockfd, ".\r\n", 3, 0);
    if (ret < 0) {
        perror("ERROR sending end of message");
        exit(1);
    }

    ret = send(sockfd, "QUIT\r\n", 8, 0);
    if (ret < 0) {
        perror("ERROR sending QUIT command");
        exit(1);
    }

    close(sockfd);
    return 0;
}