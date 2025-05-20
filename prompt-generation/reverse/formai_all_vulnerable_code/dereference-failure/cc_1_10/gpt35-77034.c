//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAXLINE 1024

int main(int argc, char *argv[]) {
    int sockfd, n, port = 25;
    struct sockaddr_in servaddr;
    char buffer[MAXLINE], resp[MAXLINE], mail_from[MAXLINE], rcpt_to[MAXLINE], subject[MAXLINE], msg[MAXLINE];
    
    if(argc < 2) {
        printf("Usage: smtpclient [mail server] [port]\n");
        exit(1);
    }
    if(argc == 3) port = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);

    inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

    if(connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Unable to connect to server");
        exit(1);
    }

    n = recv(sockfd, resp, MAXLINE, 0);
    resp[n] = '\0';
    printf("%s\n", resp);
    bzero(buffer, MAXLINE);

    sprintf(buffer, "EHLO localhost\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    n = recv(sockfd, resp, MAXLINE, 0);
    resp[n] = '\0';
    printf("%s\n", resp);
    bzero(buffer, MAXLINE);

    printf("Enter your email address: ");
    fgets(mail_from, MAXLINE, stdin);
    mail_from[strlen(mail_from) - 1] = '\0';

    printf("Enter recipient email address: ");
    fgets(rcpt_to, MAXLINE, stdin);
    rcpt_to[strlen(rcpt_to) - 1] = '\0';

    printf("Enter message subject: ");
    fgets(subject, MAXLINE, stdin);
    subject[strlen(subject) - 1] = '\0';

    printf("Enter message body:\n");
    fgets(msg, MAXLINE, stdin);
    msg[strlen(msg) - 1] = '\0';

    sprintf(buffer, "MAIL FROM: <%s>\r\n", mail_from);
    send(sockfd, buffer, strlen(buffer), 0);
    n = recv(sockfd, resp, MAXLINE, 0);
    resp[n] = '\0';
    printf("%s\n", resp);
    bzero(buffer, MAXLINE);

    sprintf(buffer, "RCPT TO: <%s>\r\n", rcpt_to);
    send(sockfd, buffer, strlen(buffer), 0);
    n = recv(sockfd, resp, MAXLINE, 0);
    resp[n] = '\0';
    printf("%s\n", resp);
    bzero(buffer, MAXLINE);

    sprintf(buffer, "DATA\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    n = recv(sockfd, resp, MAXLINE, 0);
    resp[n] = '\0';
    printf("%s\n", resp);
    bzero(buffer, MAXLINE);

    sprintf(buffer, "From: <%s>\r\nTo: <%s>\r\nSubject: %s\r\n\r\n%s\r\n.\r\n", mail_from, rcpt_to, subject, msg);
    send(sockfd, buffer, strlen(buffer), 0);
    n = recv(sockfd, resp, MAXLINE, 0);
    resp[n] = '\0';
    printf("%s\n", resp);
    bzero(buffer, MAXLINE);

    sprintf(buffer, "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    n = recv(sockfd, resp, MAXLINE, 0);
    resp[n] = '\0';
    printf("%s\n", resp);
    bzero(buffer, MAXLINE);

    close(sockfd);
    return 0;
}