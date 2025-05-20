//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_MAILBOX_SIZE 1024
#define MAX_MESSAGE_SIZE 10240

typedef struct {
    char *subject;
    char *body;
    char *from;
    char *to;
} mail_t;

void parse_mailbox(char *mailbox) {
    char *subject, *body, *from, *to;
    char *token;

    subject = strtok(mailbox, ",");
    body = strtok(NULL, ",");
    from = strtok(NULL, ",");
    to = strtok(NULL, ",");

    printf("Subject: %s\n", subject);
    printf("Body: %s\n", body);
    printf("From: %s\n", from);
    printf("To: %s\n", to);
}

int send_mail(mail_t *mail) {
    int sock, port;
    struct sockaddr_in server_addr;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket() failed");
        exit(1);
    }

    port = 25;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect() failed");
        exit(1);
    }

    send(sock, mail->body, strlen(mail->body), 0);
    send(sock, "\r\n.", 3, 0);

    close(sock);
    return 0;
}

int main(void) {
    char mailbox[MAX_MAILBOX_SIZE];
    char message[MAX_MESSAGE_SIZE];

    printf("Welcome to the email client!\n");

    while (1) {
        printf("Enter a mailbox (e.g. user@example.com): ");
        fgets(mailbox, MAX_MAILBOX_SIZE, stdin);

        parse_mailbox(mailbox);

        printf("Enter a message (e.g. Hello, world!): ");
        fgets(message, MAX_MESSAGE_SIZE, stdin);

        mail_t *mail = malloc(sizeof(mail_t));
        mail->subject = strdup(mailbox);
        mail->body = strdup(message);
        mail->from = "you@example.com";
        mail->to = mailbox;

        send_mail(mail);

        free(mail);
    }

    return 0;
}