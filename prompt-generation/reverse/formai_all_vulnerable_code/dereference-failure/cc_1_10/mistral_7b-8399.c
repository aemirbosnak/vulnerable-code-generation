//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LIST_SIZE 1000
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

typedef struct Subscriber {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    struct Subscriber *next;
} Subscriber;

typedef struct Mailbox {
    char name[MAX_NAME_LENGTH];
    Subscriber *subscribers;
    int num_subscribers;
    struct Mailbox *next;
} Mailbox;

Mailbox *mailboxes = NULL;

void create_mailbox(char *name) {
    Mailbox *new_mailbox = (Mailbox *) malloc(sizeof(Mailbox));
    strcpy(new_mailbox->name, name);
    new_mailbox->subscribers = NULL;
    new_mailbox->num_subscribers = 0;
    new_mailbox->next = mailboxes;
    mailboxes = new_mailbox;
}

bool add_subscriber(char *name, char *email, char *mailbox_name) {
    Mailbox *current_mailbox = mailboxes;
    while (current_mailbox != NULL) {
        if (strcmp(current_mailbox->name, mailbox_name) == 0) {
            Subscriber *new_subscriber = (Subscriber *) malloc(sizeof(Subscriber));
            strcpy(new_subscriber->name, name);
            strcpy(new_subscriber->email, email);
            new_subscriber->next = current_mailbox->subscribers;
            current_mailbox->subscribers = new_subscriber;
            current_mailbox->num_subscribers++;
            return true;
        }
        current_mailbox = current_mailbox->next;
    }
    printf("Mailbox %s not found.\n", mailbox_name);
    return false;
}

void print_mailbox(Mailbox *mailbox) {
    Subscriber *current_subscriber = mailbox->subscribers;
    printf("%s:\n", mailbox->name);
    while (current_subscriber != NULL) {
        printf("%s (%s)\n", current_subscriber->name, current_subscriber->email);
        current_subscriber = current_subscriber->next;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <mailbox_name>\n", argv[0]);
        return 1;
    }

    create_mailbox(argv[1]);

    add_subscriber("Alice", "alice@example.com", argv[1]);
    add_subscriber("Bob", "bob@example.com", argv[1]);

    Mailbox *current_mailbox = mailboxes;
    while (current_mailbox != NULL) {
        if (strcmp(current_mailbox->name, argv[1]) == 0) {
            print_mailbox(current_mailbox);
            break;
        }
        current_mailbox = current_mailbox->next;
    }

    return 0;
}