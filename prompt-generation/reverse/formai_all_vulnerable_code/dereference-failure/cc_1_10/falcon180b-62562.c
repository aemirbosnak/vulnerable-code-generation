//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

#define PORT 25
#define MAX_LINE 1024

void die(char *s) {
    perror(s);
    exit(1);
}

int main(int argc, char **argv) {
    if (argc!= 4) {
        fprintf(stderr, "Usage: %s <sender> <recipient> <message>\n", argv[0]);
        exit(1);
    }

    char *sender = argv[1];
    char *recipient = argv[2];
    char *message = argv[3];

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        die("socket");
    }

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    if (inet_pton(AF_INET, "127.0.0.1", &server.sin_addr) <= 0) {
        die("inet_pton");
    }

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        die("connect");
    }

    char *helo = "localhost";
    send(sock, helo, strlen(helo), 0);

    char *mail_from = sender;
    send(sock, mail_from, strlen(mail_from), 0);

    char *rcpt_to = recipient;
    send(sock, rcpt_to, strlen(rcpt_to), 0);

    char *data = "DATA\r\n";
    send(sock, data, strlen(data), 0);

    char line[MAX_LINE];
    snprintf(line, sizeof(line), "Subject: %s\r\n", "Test Email");
    send(sock, line, strlen(line), 0);

    snprintf(line, sizeof(line), "MIME-Version: 1.0\r\n");
    send(sock, line, strlen(line), 0);

    snprintf(line, sizeof(line), "Content-Type: text/plain; charset=UTF-8\r\n");
    send(sock, line, strlen(line), 0);

    snprintf(line, sizeof(line), "Content-Transfer-Encoding: 7bit\r\n\r\n");
    send(sock, line, strlen(line), 0);

    send(sock, message, strlen(message), 0);

    char *dot = ".\r\n";
    send(sock, dot, strlen(dot), 0);

    close(sock);

    return 0;
}