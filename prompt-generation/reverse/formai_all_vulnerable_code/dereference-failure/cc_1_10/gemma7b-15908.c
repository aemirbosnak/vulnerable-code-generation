//Gemma-7B DATASET v1.0 Category: Email Client ; Style: mathematical
#include <stdio.h>
#include <string.h>

#define MAX_MSG_SIZE 1024

typedef struct Message {
    char *subject;
    char *from;
    char *to;
    char *body;
    int size;
} Message;

Message *create_message() {
    Message *message = malloc(sizeof(Message));
    message->subject = malloc(MAX_MSG_SIZE);
    message->from = malloc(MAX_MSG_SIZE);
    message->to = malloc(MAX_MSG_SIZE);
    message->body = malloc(MAX_MSG_SIZE);
    message->size = 0;
    return message;
}

void add_message_part(Message *message, char *part, int part_size) {
    message->size += part_size;
    memcpy(message->body + message->size - part_size, part, part_size);
}

int main() {
    Message *message = create_message();
    add_message_part(message, "Subject: Hello, world!", 22);
    add_message_part(message, "From: me@example.com", 29);
    add_message_part(message, "To: you@example.com", 25);
    add_message_part(message, "Hello, world!", 13);

    printf("Subject: %s\n", message->subject);
    printf("From: %s\n", message->from);
    printf("To: %s\n", message->to);
    printf("Body: %s\n", message->body);

    printf("Total size: %d bytes\n", message->size);

    free(message->subject);
    free(message->from);
    free(message->to);
    free(message->body);
    free(message);

    return 0;
}