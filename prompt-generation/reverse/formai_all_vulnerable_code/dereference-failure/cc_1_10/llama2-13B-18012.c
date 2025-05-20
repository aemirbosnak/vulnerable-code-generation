//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SMTP_PORT 25
#define MAX_MESSAGE_LENGTH 512

struct email {
    char *from;
    char *to;
    char *subject;
    char *message;
};

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <from> <to> <subject> <message>\n", argv[0]);
        return 1;
    }

    struct email email;
    email.from = argv[1];
    email.to = argv[2];
    email.subject = argv[3];
    email.message = argv[4];

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return 1;
    }

    char send_buffer[MAX_MESSAGE_LENGTH];
    char recv_buffer[MAX_MESSAGE_LENGTH];

    // Send email
    sprintf(send_buffer, "HELO client.local\r\n");
    send(sock, send_buffer, strlen(send_buffer), 0);
    sprintf(send_buffer, "MAIL FROM:<%s>\r\n", email.from);
    send(sock, send_buffer, strlen(send_buffer), 0);
    sprintf(send_buffer, "RCPT TO:<%s>\r\n", email.to);
    send(sock, send_buffer, strlen(send_buffer), 0);
    sprintf(send_buffer, "DATA\r\n");
    send(sock, send_buffer, strlen(send_buffer), 0);
    send(sock, email.message, strlen(email.message), 0);
    sprintf(send_buffer, "QUIT\r\n");
    send(sock, send_buffer, strlen(send_buffer), 0);

    // Receive email
    recv(sock, recv_buffer, MAX_MESSAGE_LENGTH, 0);
    printf("Received email from server:\n%s\n", recv_buffer);

    close(sock);
    return 0;
}