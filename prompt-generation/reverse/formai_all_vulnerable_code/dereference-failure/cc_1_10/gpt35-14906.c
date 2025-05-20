//FormAI DATASET v1.0 Category: Email Client ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 1024
#define SERVER_PORT 25

void error(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    struct hostent *server;
    char buf[BUF_SIZE];

    if (argc < 3) {
        fprintf(stderr, "Usage: %s hostname message\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    server = gethostbyname(argv[1]);
    if (!server) {
        fprintf(stderr, "Error: no such host %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        error("Error: could not create socket\n");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        error("Error: could not connect to server\n");
    }

    sprintf(buf, "EHLO %s\r\n", argv[1]);
    send(sock, buf, strlen(buf), 0);
    recv(sock, buf, BUF_SIZE, 0);
    printf("%s", buf);

    sprintf(buf, "MAIL FROM: <%s>\r\n", argv[1]);
    send(sock, buf, strlen(buf), 0);
    recv(sock, buf, BUF_SIZE, 0);
    printf("%s", buf);

    sprintf(buf, "RCPT TO: <%s>\r\n", argv[2]);
    send(sock, buf, strlen(buf), 0);
    recv(sock, buf, BUF_SIZE, 0);
    printf("%s", buf);

    sprintf(buf, "DATA\r\n");
    send(sock, buf, strlen(buf), 0);
    recv(sock, buf, BUF_SIZE, 0);
    printf("%s", buf);

    sprintf(buf, "Subject: Test email\r\n\r\nThis is a test email sent using a C email client.\r\n.\r\n");
    send(sock, buf, strlen(buf), 0);
    recv(sock, buf, BUF_SIZE, 0);
    printf("%s", buf);

    sprintf(buf, "QUIT\r\n");
    send(sock, buf, strlen(buf), 0);
    recv(sock, buf, BUF_SIZE, 0);
    printf("%s", buf);

    close(sock);

    return 0;
}