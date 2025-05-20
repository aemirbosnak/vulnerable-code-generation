//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: irregular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_MAILBOX_SIZE 1024
#define MAX_MESSAGE_SIZE 512

typedef struct mailbox {
    char *subject;
    char *body;
    struct mailbox *next;
} mailbox_t;

typedef struct mailserver {
    int sock;
    struct sockaddr_in server_addr;
    mailbox_t *mailboxes;
} mailserver_t;

void init_mailserver(mailserver_t *server, int port) {
    server->sock = socket(AF_INET, SOCK_STREAM, 0);
    memset(&server->server_addr, 0, sizeof(server->server_addr));
    server->server_addr.sin_family = AF_INET;
    server->server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server->server_addr.sin_port = htons(port);
    bind(server->sock, (struct sockaddr *)&server->server_addr, sizeof(server->server_addr));
    listen(server->sock, 3);
}

void handle_connection(mailserver_t *server, int client_sock) {
    char buffer[1024];
    int bytes_read;
    mailbox_t *mailbox;

    while (1) {
        bytes_read = recv(client_sock, buffer, 1024, 0);
        if (bytes_read <= 0) {
            break;
        }
        buffer[bytes_read] = '\0';
        mailbox = malloc(sizeof(mailbox_t));
        mailbox->subject = strtok(buffer, " ");
        mailbox->body = strtok(NULL, " ");
        mailbox->next = server->mailboxes;
        server->mailboxes = mailbox;
    }
}

void send_mail(mailserver_t *server, mailbox_t *mailbox) {
    char *message = malloc(MAX_MESSAGE_SIZE);
    int bytes_written;

    message[0] = 'H';
    message[1] = 'E';
    message[2] = 'L';
    message[3] = 'L';
    message[4] = 'O';
    message[5] = '!';
    strcat(message, mailbox->subject);
    strcat(message, " ");
    strcat(message, mailbox->body);
    strcat(message, "\n");

    bytes_written = send(server->sock, message, strlen(message), 0);
    free(message);
}

int main() {
    mailserver_t server;
    init_mailserver(&server, 1025);

    while (1) {
        handle_connection(&server, accept(server.sock, NULL, NULL));
    }

    return 0;
}