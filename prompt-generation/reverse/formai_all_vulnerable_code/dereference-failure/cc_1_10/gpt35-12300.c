//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define SMTP_PORT "25"
#define MAX_BUF_SIZE 1024

int main(int argc, char **argv) {
    int sock_fd;
    struct addrinfo hints, *res;
    int conn;
    char buf[MAX_BUF_SIZE] = {0};

    if (argc < 3) {
        printf("Usage: ./smtp_client [server] [from] [to] [subject]\n");
        return 1;
    }

    // Get server address info
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(argv[1], SMTP_PORT, &hints, &res) != 0) {
        perror("getaddrinfo");
        return 1;
    }

    // Create socket
    sock_fd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sock_fd < 0) {
        perror("socket");
        return 1;
    }

    // Connect to server
    conn = connect(sock_fd, res->ai_addr, res->ai_addrlen);
    if (conn < 0) {
        perror("connect");
        return 1;
    }

    // Receive greeting
    recv(sock_fd, buf, MAX_BUF_SIZE, 0);
    printf("%s", buf);

    // Send EHLO
    sprintf(buf, "EHLO %s\r\n", argv[1]);
    send(sock_fd, buf, strlen(buf), 0);
    recv(sock_fd, buf, MAX_BUF_SIZE, 0);
    printf("%s", buf);

    // Send MAIL FROM
    sprintf(buf, "MAIL FROM: <%s>\r\n", argv[2]);
    send(sock_fd, buf, strlen(buf), 0);
    recv(sock_fd, buf, MAX_BUF_SIZE, 0);
    printf("%s", buf);

    // Send RCPT TO
    sprintf(buf, "RCPT TO: <%s>\r\n", argv[3]);
    send(sock_fd, buf, strlen(buf), 0);
    recv(sock_fd, buf, MAX_BUF_SIZE, 0);
    printf("%s", buf);

    // Send DATA
    sprintf(buf, "DATA\r\n");
    send(sock_fd, buf, strlen(buf), 0);
    recv(sock_fd, buf, MAX_BUF_SIZE, 0);
    printf("%s", buf);

    // Send email content
    sprintf(buf, "From: %s\r\n", argv[2]);
    send(sock_fd, buf, strlen(buf), 0);

    sprintf(buf, "To: %s\r\n", argv[3]);
    send(sock_fd, buf, strlen(buf), 0);

    sprintf(buf, "Subject: %s\r\n", argv[4]);
    send(sock_fd, buf, strlen(buf), 0);

    sprintf(buf, "\r\n");
    send(sock_fd, buf, strlen(buf), 0);

    sprintf(buf, "Hello, this is a test email.\r\n");
    send(sock_fd, buf, strlen(buf), 0);

    sprintf(buf, ".\r\n");
    send(sock_fd, buf, strlen(buf), 0);
    recv(sock_fd, buf, MAX_BUF_SIZE, 0);
    printf("%s", buf);

    // Send QUIT
    sprintf(buf, "QUIT\r\n");
    send(sock_fd, buf, strlen(buf), 0);
    recv(sock_fd, buf, MAX_BUF_SIZE, 0);
    printf("%s", buf);

    // Close socket
    close(sock_fd);

    return 0;
}