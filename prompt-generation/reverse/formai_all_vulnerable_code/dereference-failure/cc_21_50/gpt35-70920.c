//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXLINE 1024

int main(int argc, char **argv) {
    int sockfd, n;
    char recvline[MAXLINE + 1], sendline[MAXLINE + 1];
    struct sockaddr_in servaddr;
    struct hostent *server;

    if (argc != 4) {
        fprintf(stderr, "usage: %s <hostname> <port> <email_address>\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "error: no such host: %s\n", argv[1]);
        exit(2);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    bcopy((char *) server->h_addr, (char *) &servaddr.sin_addr.s_addr, server->h_length);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "error: cannot create socket\n");
        exit(3);
    }

    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        fprintf(stderr, "error: cannot connect to server\n");
        exit(4);
    }

    // receive greeting message from server
    if ((n = read(sockfd, recvline, MAXLINE)) <= 0) {
        fprintf(stderr, "error: connection closed by server\n");
        exit(5);
    }
    recvline[n] = '\0';
    printf("Received: %s", recvline);

    sprintf(sendline, "HELO %s\r\n", argv[1]);

    // send HELO command
    if (write(sockfd, sendline, strlen(sendline)) < 0) {
        fprintf(stderr, "error: cannot write data to socket\n");
        exit(6);
    }

    // receive server response
    if ((n = read(sockfd, recvline, MAXLINE)) <= 0) {
        fprintf(stderr, "error: connection closed by server\n");
        exit(7);
    }
    recvline[n] = '\0';
    printf("Received: %s", recvline);

    // send MAIL FROM command
    sprintf(sendline, "MAIL FROM: <%s>\r\n", argv[3]);
    if (write(sockfd, sendline, strlen(sendline)) < 0) {
        fprintf(stderr, "error: cannot write data to socket\n");
        exit(8);
    }

    // receive server response
    if ((n = read(sockfd, recvline, MAXLINE)) <= 0) {
        fprintf(stderr, "error: connection closed by server\n");
        exit(9);
    }
    recvline[n] = '\0';
    printf("Received: %s", recvline);

    // send RCPT TO command
    printf("Recipient email address: ");
    if (fgets(sendline, MAXLINE, stdin) == NULL) {
        fprintf(stderr, "error: cannot read from standard input\n");
        exit(10);
    }
    sendline[strlen(sendline) - 1] = '\0';
    sprintf(sendline, "RCPT TO: <%s>\r\n", sendline);
    if (write(sockfd, sendline, strlen(sendline)) < 0) {
        fprintf(stderr, "error: cannot write data to socket\n");
        exit(11);
    }

    // receive server response
    if ((n = read(sockfd, recvline, MAXLINE)) <= 0) {
        fprintf(stderr, "error: connection closed by server\n");
        exit(12);
    }
    recvline[n] = '\0';
    printf("Received: %s", recvline);

    // send DATA command
    sprintf(sendline, "DATA\r\n");
    if (write(sockfd, sendline, strlen(sendline)) < 0) {
        fprintf(stderr, "error: cannot write data to socket\n");
        exit(13);
    }

    // receive server response
    if ((n = read(sockfd, recvline, MAXLINE)) <= 0) {
        fprintf(stderr, "error: connection closed by server\n");
        exit(14);
    }
    recvline[n] = '\0';
    printf("Received: %s", recvline);

    // send email message
    printf("Enter email message, end with <CRLF>.<CRLF>\n");
    while (fgets(sendline, MAXLINE, stdin) != NULL) {
        if (strcmp(sendline, ".\n") == 0) {
            break;
        }
        if (write(sockfd, sendline, strlen(sendline)) < 0) {
            fprintf(stderr, "error: cannot write data to socket\n");
            exit(15);
        }
    }
    sprintf(sendline, "\r\n.\r\n");
    if (write(sockfd, sendline, strlen(sendline)) < 0) {
        fprintf(stderr, "error: cannot write data to socket\n");
        exit(16);
    }

    // receive server response
    if ((n = read(sockfd, recvline, MAXLINE)) <= 0) {
        fprintf(stderr, "error: connection closed by server\n");
        exit(17);
    }
    recvline[n] = '\0';
    printf("Received: %s", recvline);

    // send QUIT command
    sprintf(sendline, "QUIT\r\n");
    if (write(sockfd, sendline, strlen(sendline)) < 0) {
        fprintf(stderr, "error: cannot write data to socket\n");
        exit(18);
    }

    // receive server response
    if ((n = read(sockfd, recvline, MAXLINE)) <= 0) {
        fprintf(stderr, "error: connection closed by server\n");
        exit(19);
    }
    recvline[n] = '\0';
    printf("Received: %s", recvline);

    close(sockfd);

    return 0;
}