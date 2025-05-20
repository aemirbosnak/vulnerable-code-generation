//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAXLINE 512

int main()
{
    int sockfd, portno, n;
    struct hostent *server;
    struct sockaddr_in serv_addr;
    char buf[MAXLINE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    portno = htons(25);
    server = gethostbyname("smtp.gmail.com");

    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = portno;

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    printf("SMTP client connected\n");

    if (send(sockfd, "HELO mail.example.com\r\n", 18, 0) < 0) {
        perror("ERROR sending HELO command");
        exit(1);
    }

    if (send(sockfd, "MAIL FROM: <sender@example.com>\r\n", 29, 0) < 0) {
        perror("ERROR sending MAIL FROM command");
        exit(1);
    }

    if (send(sockfd, "RCPT TO: recipient@example.com\r\n", 20, 0) < 0) {
        perror("ERROR sending RCPT TO command");
        exit(1);
    }

    if (send(sockfd, "DATA\r\n", 5, 0) < 0) {
        perror("ERROR sending DATA command");
        exit(1);
    }

    n = sprintf(buf, "Subject: Test Email\r\nTo: recipient@example.com\r\nFrom: sender@example.com\r\n\r\nHello, this is a test email.\r\n",
            "sender@example.com", "recipient@example.com");

    if (send(sockfd, buf, n, 0) < 0) {
        perror("ERROR sending email body");
        exit(1);
    }

    if (send(sockfd, ".\r\n", 4, 0) < 0) {
        perror("ERROR sending QUIT command");
        exit(1);
    }

    close(sockfd);

    printf("SMTP client disconnected\n");

    return 0;
}