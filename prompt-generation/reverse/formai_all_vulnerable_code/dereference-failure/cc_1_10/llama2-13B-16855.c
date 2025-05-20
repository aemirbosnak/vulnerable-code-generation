//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define SMTP_PORT 25
#define MAX_LENGTH 256

struct email {
    char *from;
    char *to;
    char *subject;
    char *message;
};

struct server {
    char *host;
    int port;
};

int main(int argc, char *argv[]) {
    struct server server;
    struct email email;

    if (argc < 4) {
        printf("Usage: %s <host> <port> <from> <to> <subject> <message>\n", argv[0]);
        return 1;
    }

    server.host = argv[1];
    server.port = atoi(argv[2]);

    email.from = argv[3];
    email.to = argv[4];
    email.subject = argv[5];
    email.message = argv[6];

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket creation failed");
        return 1;
    }

    // Connect to the server
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server.port);
    inet_pton(AF_INET, server.host, &server_addr.sin_addr);
    connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));

    // Send email
    char buffer[MAX_LENGTH];
    snprintf(buffer, MAX_LENGTH, "HELO %s\r\n", email.from);
    send(sock, buffer, strlen(buffer), 0);

    snprintf(buffer, MAX_LENGTH, "MAIL FROM:<%s>\r\n", email.from);
    send(sock, buffer, strlen(buffer), 0);

    snprintf(buffer, MAX_LENGTH, "RCPT TO:<%s>\r\n", email.to);
    send(sock, buffer, strlen(buffer), 0);

    snprintf(buffer, MAX_LENGTH, "DATA\r\n");
    send(sock, buffer, strlen(buffer), 0);

    // Send email message
    char *message = email.message;
    while (*message != '\0') {
        char c = *message;
        if (c == '\n') {
            send(sock, "\r\n", 2, 0);
        } else {
            send(sock, &c, 1, 0);
        }
        message++;
    }

    snprintf(buffer, MAX_LENGTH, "\r\n.\r\n");
    send(sock, buffer, strlen(buffer), 0);

    close(sock);

    return 0;
}