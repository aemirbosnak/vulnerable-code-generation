//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define EMAIL_SERVER "mail.example.com"
#define EMAIL_PORT 25

#define MAX_LENGTH 512

struct email {
    char *from;
    char *to;
    char *subject;
    char *message;
};

struct email_server {
    int sock;
    struct sockaddr_in server_addr;
};

void init_email_server(struct email_server *es) {
    es->sock = socket(AF_INET, SOCK_STREAM, 0);
    memset(&es->server_addr, 0, sizeof(es->server_addr));
    es->server_addr.sin_family = AF_INET;
    es->server_addr.sin_port = htons(EMAIL_PORT);
    inet_pton(AF_INET, EMAIL_SERVER, &es->server_addr.sin_addr);
}

void send_email(struct email_server *es, struct email *email) {
    char *message = email->message;
    int len = strlen(message);
    send(es->sock, message, len, 0);
}

void recv_email(struct email_server *es, struct email *email) {
    char buffer[MAX_LENGTH];
    recv(es->sock, buffer, MAX_LENGTH, 0);
    email->message = buffer;
}

int main() {
    struct email_server es;
    struct email email;

    init_email_server(&es);

    printf("Welcome to the Email Client!\n");

    while (1) {
        printf("Enter sender: ");
        fgets(email.from, MAX_LENGTH, stdin);
        printf("Enter recipient: ");
        fgets(email.to, MAX_LENGTH, stdin);
        printf("Enter subject: ");
        fgets(email.subject, MAX_LENGTH, stdin);
        printf("Enter message: ");
        fgets(email.message, MAX_LENGTH, stdin);

        send_email(&es, &email);

        recv_email(&es, &email);

        printf("Received email from %s with subject %s and message %s\n",
            email.from, email.subject, email.message);
    }

    close(es.sock);

    return 0;
}