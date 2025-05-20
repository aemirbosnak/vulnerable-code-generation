//Gemma-7B DATASET v1.0 Category: Email Client ; Style: decentralized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Message {
    char *subject;
    char *body;
    struct Message *next;
} Message;

Message *create_message(char *subject, char *body) {
    Message *new_message = malloc(sizeof(Message));
    new_message->subject = strdup(subject);
    new_message->body = strdup(body);
    new_message->next = NULL;
    return new_message;
}

void add_message(Message *messages, char *subject, char *body) {
    Message *new_message = create_message(subject, body);
    if (messages) {
        messages->next = new_message;
    } else {
        messages = new_message;
    }
}

void print_messages(Message *messages) {
    for (Message *message = messages; message; message = message->next) {
        printf("Subject: %s\n", message->subject);
        printf("Body: %s\n", message->body);
        printf("\n");
    }
}

int main() {
    Message *messages = NULL;

    // Add some messages
    add_message(messages, "Hello, world!", "This is a message.");
    add_message(messages, "How are you?", "I'm doing well, thank you.");
    add_message(messages, "Have a nice day!", "No problem!");

    // Print the messages
    print_messages(messages);

    return 0;
}