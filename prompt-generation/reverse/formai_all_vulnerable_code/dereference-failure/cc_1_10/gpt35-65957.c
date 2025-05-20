//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAXMSG 1024

int main(int argc, char* argv[]) {
    int sockfd, n;
    char send_line[MAXMSG], recv_line[MAXMSG];
    struct sockaddr_in servaddr;

    if (argc != 3) {
        printf("Usage: ./smtp <server_address> <port_number>\n");
        exit(1);
    }

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket error");
        exit(1);
    }

    // initialize server information
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        printf("inet_pton error for %s\n", argv[1]);
        exit(1);
    }

    // connect to the server
    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect error");
        exit(1);
    }

    // read greeting from server
    n = read(sockfd, recv_line, MAXMSG-1);
    recv_line[n] = 0;
    printf("%s\n", recv_line);

    // send EHLO to server
    sprintf(send_line, "EHLO smtp_client\r\n");
    write(sockfd, send_line, strlen(send_line));
    n = read(sockfd, recv_line, MAXMSG-1);
    recv_line[n] = 0;
    printf("%s\n", recv_line);

    // send MAIL FROM command to server
    sprintf(send_line, "MAIL FROM: <test@gmail.com>\r\n");
    write(sockfd, send_line, strlen(send_line));
    n = read(sockfd, recv_line, MAXMSG-1);
    recv_line[n] = 0;
    printf("%s\n", recv_line);

    // send RCPT TO command to server
    sprintf(send_line, "RCPT TO: <friend@yahoo.com>\r\n");
    write(sockfd, send_line, strlen(send_line));
    n = read(sockfd, recv_line, MAXMSG-1);
    recv_line[n] = 0;
    printf("%s\n", recv_line);

    // send DATA command to server
    sprintf(send_line, "DATA\r\n");
    write(sockfd, send_line, strlen(send_line));
    n = read(sockfd, recv_line, MAXMSG-1);
    recv_line[n] = 0;
    printf("%s\n", recv_line);

    // send email body to server
    sprintf(send_line, "Subject: SMTP Client Example\r\n");
    write(sockfd, send_line, strlen(send_line));
    sprintf(send_line, "From: test@gmail.com\r\n");
    write(sockfd, send_line, strlen(send_line));
    sprintf(send_line, "To: friend@yahoo.com\r\n");
    write(sockfd, send_line, strlen(send_line));
    sprintf(send_line, "\r\n");
    write(sockfd, send_line, strlen(send_line));
    sprintf(send_line, "This is an example email sent from an SMTP client program written in C.\r\n");
    write(sockfd, send_line, strlen(send_line));
    sprintf(send_line, ".\r\n");
    write(sockfd, send_line, strlen(send_line));
    n = read(sockfd, recv_line, MAXMSG-1);
    recv_line[n] = 0;
    printf("%s\n", recv_line);

    // send QUIT command to server
    sprintf(send_line, "QUIT\r\n");
    write(sockfd, send_line, strlen(send_line));
    n = read(sockfd, recv_line, MAXMSG-1);
    recv_line[n] = 0;
    printf("%s\n", recv_line);

    // close socket
    close(sockfd);
    exit(0);
}