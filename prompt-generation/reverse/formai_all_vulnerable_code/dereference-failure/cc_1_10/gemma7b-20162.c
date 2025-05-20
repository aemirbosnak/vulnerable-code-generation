//Gemma-7B DATASET v1.0 Category: Email Client ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MSG_SIZE 1024

typedef struct Message {
    char *subject;
    char *from;
    char *to;
    char *body;
} Message;

Message *create_message() {
    Message *msg = malloc(sizeof(Message));
    msg->subject = malloc(MAX_MSG_SIZE);
    msg->from = malloc(MAX_MSG_SIZE);
    msg->to = malloc(MAX_MSG_SIZE);
    msg->body = malloc(MAX_MSG_SIZE);
    return msg;
}

void free_message(Message *msg) {
    free(msg->subject);
    free(msg->from);
    free(msg->to);
    free(msg->body);
    free(msg);
}

int main() {
    Message *msg = create_message();

    // Set message details
    msg->subject = "Hello, world!";
    msg->from = "john.doe@example.com";
    msg->to = "jane.doe@example.com";
    msg->body = "This is a message body.";

    // Print message details
    printf("Subject: %s\n", msg->subject);
    printf("From: %s\n", msg->from);
    printf("To: %s\n", msg->to);
    printf("Body: %s\n", msg->body);

    // Free the message
    free_message(msg);

    return 0;
}