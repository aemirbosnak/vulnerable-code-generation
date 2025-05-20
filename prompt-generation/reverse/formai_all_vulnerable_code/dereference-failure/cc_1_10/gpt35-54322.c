//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAXLINE 1024

int main(int argc, char **argv)
{
    int sockfd, n;
    char recvline[MAXLINE + 1];
    struct sockaddr_in servaddr;
    char *hostname = "smtp.gmail.com";
    char *port = "587";
    char *username = "your_email@gmail.com";
    char *password = "your_password";
    char *from = "your_email@gmail.com";
    char *to = "recipient@example.com";
    char *subject = "Test Email";
    char *body = "This is a test email.";

    char *auth_msg = "AUTH LOGIN\r\n";
    char *user_msg = (char *)malloc(strlen(username) + 3);
    strcpy(user_msg, username);
    strcat(user_msg, "\r\n");
    char *pass_msg = (char *)malloc(strlen(password) + 3);
    strcpy(pass_msg, password);
    strcat(pass_msg, "\r\n");

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(port));
    inet_pton(AF_INET, hostname, &servaddr.sin_addr);

    char *helo_msg = "HELO smtp.gmail.com\r\n";
    char *mail_msg = (char *)malloc(strlen(from) + 12);
    strcpy(mail_msg, "MAIL FROM:<");
    strcat(mail_msg, from);
    strcat(mail_msg, ">\r\n");
    char *rcpt_msg = (char *)malloc(strlen(to) + 10);
    strcpy(rcpt_msg, "RCPT TO:<");
    strcat(rcpt_msg, to);
    strcat(rcpt_msg, ">\r\n");
    char *data_msg = "DATA\r\n";
    char *subject_msg = (char *)malloc(strlen(subject) + 11);
    strcpy(subject_msg, "Subject: ");
    strcat(subject_msg, subject);
    strcat(subject_msg, "\r\n");
    char *body_msg = (char *)malloc(strlen(body) + 5);
    strcpy(body_msg, body);
    strcat(body_msg, "\r\n.\r\n");

    connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    n = read(sockfd, recvline, MAXLINE);
    printf("%s", recvline);

    // authenticate
    write(sockfd, auth_msg, strlen(auth_msg));
    n = read(sockfd, recvline, MAXLINE);
    printf("%s", recvline);
    write(sockfd, user_msg, strlen(user_msg));
    n = read(sockfd, recvline, MAXLINE);
    printf("%s", recvline);
    write(sockfd, pass_msg, strlen(pass_msg));
    n = read(sockfd, recvline, MAXLINE);
    printf("%s", recvline);

    // send email
    write(sockfd, helo_msg, strlen(helo_msg));
    n = read(sockfd, recvline, MAXLINE);
    printf("%s", recvline);
    write(sockfd, mail_msg, strlen(mail_msg));
    n = read(sockfd, recvline, MAXLINE);
    printf("%s", recvline);
    write(sockfd, rcpt_msg, strlen(rcpt_msg));
    n = read(sockfd, recvline, MAXLINE);
    printf("%s", recvline);
    write(sockfd, data_msg, strlen(data_msg));
    n = read(sockfd, recvline, MAXLINE);
    printf("%s", recvline);
    write(sockfd, subject_msg, strlen(subject_msg));
    write(sockfd, body_msg, strlen(body_msg));
    n = read(sockfd, recvline, MAXLINE);
    printf("%s", recvline);

    close(sockfd);
    return 0;
}