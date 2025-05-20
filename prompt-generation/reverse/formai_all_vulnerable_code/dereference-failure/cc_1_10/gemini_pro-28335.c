//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char **argv) {
    if (argc < 4) {
        printf("Usage: smtp_client <host> <port> <sender> <recipient> <subject> <message>\n");
        return 1;
    }

    char *host = argv[1];
    int port = atoi(argv[2]);
    char *sender = argv[3];
    char *recipient = argv[4];
    char *subject = argv[5];
    char *message = argv[6];

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(host);
    addr.sin_port = htons(port);

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("connect");
        return 1;
    }

    char buf[1024];

    recv(sock, buf, sizeof(buf), 0);

    sprintf(buf, "EHLO %s\r\n", host);
    send(sock, buf, strlen(buf), 0);

    recv(sock, buf, sizeof(buf), 0);

    sprintf(buf, "MAIL FROM: <%s>\r\n", sender);
    send(sock, buf, strlen(buf), 0);

    recv(sock, buf, sizeof(buf), 0);

    sprintf(buf, "RCPT TO: <%s>\r\n", recipient);
    send(sock, buf, strlen(buf), 0);

    recv(sock, buf, sizeof(buf), 0);

    sprintf(buf, "DATA\r\n");
    send(sock, buf, strlen(buf), 0);

    recv(sock, buf, sizeof(buf), 0);

    sprintf(buf, "From: <%s>\r\n", sender);
    send(sock, buf, strlen(buf), 0);

    sprintf(buf, "To: <%s>\r\n", recipient);
    send(sock, buf, strlen(buf), 0);

    sprintf(buf, "Subject: %s\r\n", subject);
    send(sock, buf, strlen(buf), 0);

    sprintf(buf, "%s\r\n", message);
    send(sock, buf, strlen(buf), 0);

    recv(sock, buf, sizeof(buf), 0);

    sprintf(buf, ".\r\n");
    send(sock, buf, strlen(buf), 0);

    recv(sock, buf, sizeof(buf), 0);

    sprintf(buf, "QUIT\r\n");
    send(sock, buf, strlen(buf), 0);

    recv(sock, buf, sizeof(buf), 0);

    close(sock);

    return 0;
}