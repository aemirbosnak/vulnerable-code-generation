//Gemma-7B DATASET v1.0 Category: Email Client ; Style: visionary
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Mailbox {
    char *name;
    struct Mailbox *next;
    int num_messages;
    struct Message **messages;
} Mailbox;

typedef struct Message {
    char *subject;
    char *body;
    struct Message *next;
} Message;

Mailbox *mailbox_new(char *name) {
    Mailbox *mailbox = malloc(sizeof(Mailbox));
    mailbox->name = strdup(name);
    mailbox->next = NULL;
    mailbox->num_messages = 0;
    mailbox->messages = NULL;
    return mailbox;
}

Message *message_new(char *subject, char *body) {
    Message *message = malloc(sizeof(Message));
    message->subject = strdup(subject);
    message->body = strdup(body);
    message->next = NULL;
    return message;
}

void mailbox_add_message(Mailbox *mailbox, Message *message) {
    mailbox->messages = realloc(mailbox->messages, (mailbox->num_messages + 1) * sizeof(Message *));
    mailbox->messages[mailbox->num_messages++] = message;
}

void mailbox_print_messages(Mailbox *mailbox) {
    for (int i = 0; i < mailbox->num_messages; i++) {
        printf("Subject: %s\n", mailbox->messages[i]->subject);
        printf("Body: %s\n", mailbox->messages[i]->body);
        printf("\n");
    }
}

int main() {
    Mailbox *mailbox = mailbox_new("john.doe@example.com");

    message_new("Hello, world!", "This is my first email.");
    mailbox_add_message(mailbox, message_new("Greetings, friend!", "How are you?"));

    mailbox_print_messages(mailbox);

    return 0;
}