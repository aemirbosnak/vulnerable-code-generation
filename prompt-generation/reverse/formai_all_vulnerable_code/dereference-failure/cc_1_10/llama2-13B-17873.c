//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_MAILBOX_SIZE 1024 * 1024 * 5
#define MAX_MESSAGE_SIZE 1024 * 1024 * 2

struct mailbox {
    char *name;
    char *email;
    char *message;
    struct mailbox *next;
};

struct mailserver {
    int sock;
    struct sockaddr_in server_addr;
    struct mailbox *mailboxes;
};

void init_mailserver(struct mailserver *ms) {
    ms->sock = socket(AF_INET, SOCK_STREAM, 0);
    memset(&ms->server_addr, 0, sizeof(ms->server_addr));
    ms->server_addr.sin_family = AF_INET;
    ms->server_addr.sin_port = htons(25);
    ms->mailboxes = NULL;
}

void add_mailbox(struct mailserver *ms, char *name, char *email) {
    struct mailbox *mb = malloc(sizeof(struct mailbox));
    mb->name = name;
    mb->email = email;
    mb->message = NULL;
    mb->next = ms->mailboxes;
    ms->mailboxes = mb;
}

void send_mail(struct mailserver *ms, char *to, char *subject, char *message) {
    struct mailbox *mb = malloc(sizeof(struct mailbox));
    mb->name = to;
    mb->email = "root";
    mb->message = message;
    mb->next = NULL;
    ms->mailboxes = mb;
    sendto(ms->sock, (void *)mb, sizeof(struct mailbox), 0,
           (struct sockaddr *)&ms->server_addr, sizeof(ms->server_addr));
}

void recv_mail(struct mailserver *ms) {
    struct mailbox *mb = malloc(sizeof(struct mailbox));
    recvfrom(ms->sock, (void *)mb, sizeof(struct mailbox), 0,
             (struct sockaddr *)&ms->server_addr, sizeof(ms->server_addr));
    printf("Received mail from %s <%s>\n", mb->name, mb->email);
    if (mb->message) {
        printf("Message: %s\n", mb->message);
    }
    free(mb);
}

int main() {
    struct mailserver ms;
    init_mailserver(&ms);

    // Add mailboxes
    add_mailbox(&ms, "John Doe", "johndoe@example.com");
    add_mailbox(&ms, "Jane Doe", "janedoe@example.com");

    // Send mail
    send_mail(&ms, "Jane Doe", "Test Subject", "Hello Jane!");

    // Recv mail
    recv_mail(&ms);

    // Cleanup
    close(ms.sock);
    return 0;
}