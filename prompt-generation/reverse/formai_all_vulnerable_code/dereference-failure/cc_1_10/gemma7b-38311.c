//Gemma-7B DATASET v1.0 Category: Email Client ; Style: multivariable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MSG_SIZE 1024

typedef struct Message {
    char *subject;
    char *sender;
    char *recipient;
    char *body;
    struct Message *next;
} Message;

Message *addMessage(Message *head) {
    Message *newMessage = malloc(sizeof(Message));
    newMessage->subject = malloc(MAX_MSG_SIZE);
    newMessage->sender = malloc(MAX_MSG_SIZE);
    newMessage->recipient = malloc(MAX_MSG_SIZE);
    newMessage->body = malloc(MAX_MSG_SIZE);
    newMessage->next = NULL;

    head = newMessage;

    return head;
}

void printMessages(Message *head) {
    Message *currentMessage = head;
    while (currentMessage) {
        printf("Subject: %s\n", currentMessage->subject);
        printf("From: %s\n", currentMessage->sender);
        printf("To: %s\n", currentMessage->recipient);
        printf("Body: %s\n", currentMessage->body);
        printf("\n");
        currentMessage = currentMessage->next;
    }
}

int main() {
    Message *head = NULL;

    addMessage(head);
    addMessage(head);
    addMessage(head);

    printMessages(head);

    return 0;
}