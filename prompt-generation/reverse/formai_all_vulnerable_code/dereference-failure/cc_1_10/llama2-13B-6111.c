//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_MAILBOX_SIZE 1024
#define MAX_MESSAGE_SIZE 512

struct mailbox {
    char *name;
    char *email;
    char *message;
    struct mailbox *next;
};

struct server_info {
    int sock;
    struct sockaddr_in server_addr;
};

void init_mailbox(struct mailbox **head_ptr) {
    struct mailbox *head = (struct mailbox *)malloc(sizeof(struct mailbox));
    head->name = "Root";
    head->email = "root@example.com";
    head->message = NULL;
    head->next = NULL;
    *head_ptr = head;
}

void add_mailbox(struct mailbox **head_ptr, char *name, char *email, char *message) {
    struct mailbox *new_box = (struct mailbox *)malloc(sizeof(struct mailbox));
    new_box->name = name;
    new_box->email = email;
    new_box->message = message;
    new_box->next = *head_ptr;
    *head_ptr = new_box;
}

void send_email(int sock, struct mailbox *head) {
    struct mailbox *current = head;
    char buffer[MAX_MESSAGE_SIZE];
    char *message = buffer;
    int len = 0;

    while (current != NULL) {
        len += snprintf(message, MAX_MESSAGE_SIZE - len, "%s <%s>: %s\n", current->name, current->email, current->message);
        message += len;
        len = 0;
        current = current->next;
    }

    send(sock, message, strlen(message), 0);
}

int main(int argc, char *argv[]) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct server_info server;
    struct mailbox *head;

    if (argc < 2) {
        printf("Usage: %s <server_ip>\n", argv[0]);
        return 1;
    }

    server.sock = sock;
    server.server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &server.server_addr.sin_addr);
    server.server_addr.sin_port = htons(25);

    init_mailbox(&head);

    while (1) {
        char buffer[1024];
        int len = recv(sock, buffer, 1024, 0);

        if (len == 0) {
            break;
        }

        char *message = buffer;
        char *token = strtok(message, "\n");

        while (token != NULL) {
            char *name = token;
            char *email = strtok(NULL, ":");
            char *message = strtok(NULL, "\n");

            add_mailbox(&head, name, email, message);
            token = strtok(NULL, "\n");
        }

        send_email(sock, head);
    }

    close(sock);
    return 0;
}