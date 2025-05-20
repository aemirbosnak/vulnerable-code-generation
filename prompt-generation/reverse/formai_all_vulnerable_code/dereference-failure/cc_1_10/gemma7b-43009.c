//Gemma-7B DATASET v1.0 Category: Email Client ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MESSAGES 10

typedef struct Message {
    char *subject;
    char *body;
    struct Message *next;
} Message;

Message *create_message() {
    Message *new_message = malloc(sizeof(Message));
    new_message->subject = malloc(256);
    new_message->body = malloc(256);
    new_message->next = NULL;
    return new_message;
}

void add_message(Message *messages, char *subject, char *body) {
    Message *new_message = create_message();
    strcpy(new_message->subject, subject);
    strcpy(new_message->body, body);
    if (messages) {
        messages->next = new_message;
    } else {
        messages = new_message;
    }
}

void print_messages(Message *messages) {
    while (messages) {
        printf("Subject: %s\n", messages->subject);
        printf("Body: %s\n", messages->body);
        printf("\n");
        messages = messages->next;
    }
}

int main() {
    Message *messages = NULL;
    add_message(messages, "Hello, world!", "This is a message.");
    add_message(messages, "Another message", "This is another message.");
    add_message(messages, "A third message", "This is the third message.");

    print_messages(messages);

    return 0;
}