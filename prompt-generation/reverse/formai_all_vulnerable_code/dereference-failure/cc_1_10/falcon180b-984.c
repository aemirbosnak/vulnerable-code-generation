//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <time.h>

#define MAX_BUF_LEN 1024
#define SERVER_PORT 25
#define SERVER_ADDR "smtp.gmail.com"

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in server_addr;
    char send_buf[MAX_BUF_LEN], recv_buf[MAX_BUF_LEN];
    time_t current_time;

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    // set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_ADDR);

    // connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // send EHLO command
    sprintf(send_buf, "EHLO %s\r\n", argv[1]);
    send(sockfd, send_buf, strlen(send_buf), 0);

    // send MAIL FROM command
    sprintf(send_buf, "MAIL FROM:<%s>\r\n", argv[1]);
    send(sockfd, send_buf, strlen(send_buf), 0);

    // send RCPT TO command
    sprintf(send_buf, "RCPT TO:<%s>\r\n", argv[2]);
    send(sockfd, send_buf, strlen(send_buf), 0);

    // send DATA command
    sprintf(send_buf, "DATA\r\n");
    send(sockfd, send_buf, strlen(send_buf), 0);

    // send message body
    sprintf(send_buf, "Subject: Test Message\r\n\r\nHello, this is a test message.\r\n");
    send(sockfd, send_buf, strlen(send_buf), 0);

    // send quit command
    sprintf(send_buf, "QUIT\r\n");
    send(sockfd, send_buf, strlen(send_buf), 0);

    // receive server response
    n = recv(sockfd, recv_buf, MAX_BUF_LEN, 0);
    while (n > 0) {
        printf("%s", recv_buf);
        n = recv(sockfd, recv_buf, MAX_BUF_LEN, 0);
    }

    // close socket
    close(sockfd);

    return 0;
}