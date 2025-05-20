//Gemma-7B DATASET v1.0 Category: Email Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MSG_SIZE 1024

typedef struct Message {
    char *subject;
    char *from;
    char *to;
    char *body;
    int size;
} Message;

Message *createMessage() {
    Message *msg = malloc(sizeof(Message));
    msg->subject = malloc(MAX_MSG_SIZE);
    msg->from = malloc(MAX_MSG_SIZE);
    msg->to = malloc(MAX_MSG_SIZE);
    msg->body = malloc(MAX_MSG_SIZE);
    msg->size = 0;
    return msg;
}

void freeMessage(Message *msg) {
    free(msg->subject);
    free(msg->from);
    free(msg->to);
    free(msg->body);
    free(msg);
}

int main() {
    Message *msg = createMessage();

    // Set message details
    msg->subject = "Test Subject";
    msg->from = "sender@example.com";
    msg->to = "recipient@example.com";
    msg->body = "This is a test message.";

    // Increase message size
    msg->size = 50;

    // Print message details
    printf("Subject: %s\n", msg->subject);
    printf("From: %s\n", msg->from);
    printf("To: %s\n", msg->to);
    printf("Body: %s\n", msg->body);
    printf("Size: %d\n", msg->size);

    // Free message memory
    freeMessage(msg);

    return 0;
}