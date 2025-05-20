//Gemma-7B DATASET v1.0 Category: Email Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char data[MAX_BUFFER_SIZE];
    struct Node* next;
} Node;

typedef struct Mailbox {
    Node* head;
    Node* tail;
} Mailbox;

Mailbox* create_mailbox() {
    Mailbox* mailbox = malloc(sizeof(Mailbox));
    mailbox->head = NULL;
    mailbox->tail = NULL;
    return mailbox;
}

void add_mail(Mailbox* mailbox, char* mail) {
    Node* new_node = malloc(sizeof(Node));
    strcpy(new_node->data, mail);
    new_node->next = NULL;

    if (mailbox->head == NULL) {
        mailbox->head = new_node;
        mailbox->tail = new_node;
    } else {
        mailbox->tail->next = new_node;
        mailbox->tail = new_node;
    }
}

char* read_mail(Mailbox* mailbox) {
    if (mailbox->head == NULL) {
        return NULL;
    }

    return mailbox->head->data;
}

int main() {
    Mailbox* mailbox = create_mailbox();

    add_mail(mailbox, "Hello, world!");
    add_mail(mailbox, "This is a message.");

    char* mail = read_mail(mailbox);

    if (mail) {
        printf("%s\n", mail);
    } else {
        printf("No mail available.\n");
    }

    return 0;
}