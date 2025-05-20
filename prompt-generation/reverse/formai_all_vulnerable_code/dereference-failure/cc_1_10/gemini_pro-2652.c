//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAX_BUF 1024

struct mail_msg {
    char sender[100];
    char recipient[100];
    char subject[100];
    char body[MAX_BUF];
};

void send_mail(int sockfd, struct mail_msg *msg) {
    char buf[MAX_BUF];
    sprintf(buf, "MAIL FROM: %s\r\n", msg->sender);
    send(sockfd, buf, strlen(buf), 0);

    sprintf(buf, "RCPT TO: %s\r\n", msg->recipient);
    send(sockfd, buf, strlen(buf), 0);

    sprintf(buf, "DATA\r\n");
    send(sockfd, buf, strlen(buf), 0);

    sprintf(buf, "Subject: %s\r\n", msg->subject);
    send(sockfd, buf, strlen(buf), 0);

    sprintf(buf, "%s\r\n", msg->body);
    send(sockfd, buf, strlen(buf), 0);

    sprintf(buf, ".\r\n");
    send(sockfd, buf, strlen(buf), 0);

    recv(sockfd, buf, MAX_BUF, 0);
    printf("%s", buf);
}

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in servaddr;

    if (argc != 5) {
        printf("Usage: %s <server_ip> <server_port> <sender> <recipient>\n", argv[0]);
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        return 1;
    }

    char buf[MAX_BUF];
    recv(sockfd, buf, MAX_BUF, 0);
    printf("%s", buf);

    struct mail_msg msg;
    strcpy(msg.sender, argv[3]);
    strcpy(msg.recipient, argv[4]);
    strcpy(msg.subject, "Test Email");
    strcpy(msg.body, "This is a test email.\n");

    send_mail(sockfd, &msg);

    close(sockfd);

    return 0;
}