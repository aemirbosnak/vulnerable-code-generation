//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: Alan Touring
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024

void error_handling(char *message) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in serv_addr;
    char buf[BUF_SIZE];
    int str_len;

    if (argc != 3) {
        printf("Usage: %s <ip> <port>\n", argv[0]);
        exit(1);
    }

    sock = socket(PF_INET, SOCK_STREAM, 0);
    if (sock == -1)
        error_handling("socket() error");

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == -1)
        error_handling("connect() error");

    printf("[INFO] Connected to SMTP server\n");

    // HELO
    sprintf(buf, "HELO myserver.com\r\n");
    write(sock, buf, strlen(buf));
    memset(buf, 0, BUF_SIZE);
    read(sock, buf, BUF_SIZE);
    printf("[INFO] SMTP Server: %s\n", buf);

    // MAIL FROM
    sprintf(buf, "MAIL FROM: <myemail@gmail.com>\r\n");
    write(sock, buf, strlen(buf));
    memset(buf, 0, BUF_SIZE);
    read(sock, buf, BUF_SIZE);
    printf("[INFO] SMTP Server: %s\n", buf);

    // RCPT TO
    sprintf(buf, "RCPT TO: <john@example.com>\r\n");
    write(sock, buf, strlen(buf));
    memset(buf, 0, BUF_SIZE);
    read(sock, buf, BUF_SIZE);
    printf("[INFO] SMTP Server: %s\n", buf);

    // DATA
    sprintf(buf, "DATA\r\n");
    write(sock, buf, strlen(buf));
    memset(buf, 0, BUF_SIZE);
    read(sock, buf, BUF_SIZE);
    printf("[INFO] SMTP Server: %s\n", buf);

    // Message body
    sprintf(buf, "Subject: My Test Email\r\nTo: john@example.com\r\n\r\nHello John,\r\nThis is a test email sent using SMTP client.\r\nThank you,\r\nMyClient_team");
    write(sock, buf, strlen(buf));
    memset(buf, 0, BUF_SIZE);
    read(sock, buf, BUF_SIZE);
    printf("[INFO] SMTP Server: %s\n", buf);

    // QUIT
    sprintf(buf, "QUIT\r\n");
    write(sock, buf, strlen(buf));
    memset(buf, 0, BUF_SIZE);
    read(sock, buf, BUF_SIZE);
    printf("[INFO] SMTP Server: %s\n", buf);

    close(sock);
    printf("[INFO] Disconnected from SMTP server\n");

    return 0;
}