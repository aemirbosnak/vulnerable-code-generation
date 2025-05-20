//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAX_BUF_SIZE 1024

void send_mail(int sockfd, char *from, char *to, char *subject, char *body);

int main()
{
    int sockfd;
    char buf[MAX_BUF_SIZE];
    char from[MAX_BUF_SIZE], to[MAX_BUF_SIZE], subject[MAX_BUF_SIZE], body[MAX_BUF_SIZE];

    struct hostent *he;
    struct sockaddr_in server_addr;

    printf("Enter SMTP server hostname: ");
    gets(buf);

    if ((he = gethostbyname(buf)) == NULL) {
        perror("gethostbyname(): ");
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket(): ");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(25); 
    server_addr.sin_addr = *((struct in_addr *)he->h_addr);
    memset(&(server_addr.sin_zero), '\0', 8);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1) {
        perror("connect(): ");
        exit(1);
    }

    printf("Enter mail from: ");
    gets(from);

    printf("Enter mail to: ");
    gets(to);

    printf("Enter mail subject: ");
    gets(subject);

    printf("Enter mail body: ");
    gets(body);

    send_mail(sockfd, from, to, subject, body);

    close(sockfd);

    return 0;
}

void send_mail(int sockfd, char *from, char *to, char *subject, char *body)
{
    char buf[MAX_BUF_SIZE];
    int numbytes;

    recv(sockfd, buf, MAX_BUF_SIZE, 0);
    if (strncmp(buf, "220", 3) != 0) {
        printf("SMTP server error: %s\n", buf);
        exit(1);
    }

    snprintf(buf, sizeof(buf), "HELO localhost\r\n");
    send(sockfd, buf, strlen(buf), 0);
    recv(sockfd, buf, MAX_BUF_SIZE, 0);
    if (strncmp(buf, "250", 3) != 0) {
        printf("SMTP server error: %s\n", buf);
        exit(1);
    }

    snprintf(buf, sizeof(buf), "MAIL FROM:<%s>\r\n", from);
    send(sockfd, buf, strlen(buf), 0);
    recv(sockfd, buf, MAX_BUF_SIZE, 0);
    if (strncmp(buf, "250", 3) != 0) {
        printf("SMTP server error: %s\n", buf);
        exit(1);
    }

    snprintf(buf, sizeof(buf), "RCPT TO:<%s>\r\n", to);
    send(sockfd, buf, strlen(buf), 0);
    recv(sockfd, buf, MAX_BUF_SIZE, 0);
    if (strncmp(buf, "250", 3) != 0) {
        printf("SMTP server error: %s\n", buf);
        exit(1);
    }

    snprintf(buf, sizeof(buf), "DATA\r\n");
    send(sockfd, buf, strlen(buf), 0);
    recv(sockfd, buf, MAX_BUF_SIZE, 0);
    if (strncmp(buf, "354", 3) != 0) {
        printf("SMTP server error: %s\n", buf);
        exit(1);
    }

    snprintf(buf, sizeof(buf), "Subject: %s\r\n", subject);
    send(sockfd, buf, strlen(buf), 0);

    snprintf(buf, sizeof(buf), "From: <%s>\r\n", from);
    send(sockfd, buf, strlen(buf), 0);

    snprintf(buf, sizeof(buf), "To: <%s>\r\n", to);
    send(sockfd, buf, strlen(buf), 0);

    send(sockfd, "\r\n", strlen("\r\n"), 0);

    send(sockfd, body, strlen(body), 0);

    send(sockfd, "\r\n.\r\n", strlen("\r\n.\r\n"), 0);
    recv(sockfd, buf, MAX_BUF_SIZE, 0);
    if (strncmp(buf, "250", 3) != 0) {
        printf("SMTP server error: %s\n", buf);
        exit(1);
    }

    snprintf(buf, sizeof(buf), "QUIT\r\n");
    send(sockfd, buf, strlen(buf), 0);
    recv(sockfd, buf, MAX_BUF_SIZE, 0);
    if (strncmp(buf, "221", 3) != 0) {
        printf("SMTP server error: %s\n", buf);
        exit(1);
    }
}