//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mailing_list_entry {
    char name[100];
    char email[100];
    char message[1000];
    struct mailing_list_entry *next;
};

struct mailing_list {
    struct mailing_list_entry *head;
    struct mailing_list_entry *tail;
};

void add_entry(struct mailing_list *ml, char *name, char *email, char *message) {
    struct mailing_list_entry *new_entry = malloc(sizeof(struct mailing_list_entry));
    if (new_entry == NULL) {
        printf("Memory allocation error\n");
        return;
    }

    strcpy(new_entry->name, name);
    strcpy(new_entry->email, email);
    strcpy(new_entry->message, message);

    if (ml->head == NULL) {
        ml->head = new_entry;
        ml->tail = new_entry;
    } else {
        ml->tail->next = new_entry;
        ml->tail = new_entry;
    }
}

void display_list(struct mailing_list *ml) {
    struct mailing_list_entry *curr = ml->head;
    while (curr!= NULL) {
        printf("%s - %s\n", curr->name, curr->email);
        curr = curr->next;
    }
}

int main() {
    struct mailing_list ml;
    ml.head = NULL;
    ml.tail = NULL;

    add_entry(&ml, "John Doe", "john.doe@example.com", "Hello, this is a message.");
    add_entry(&ml, "Jane Doe", "jane.doe@example.com", "Hi there, this is another message.");

    display_list(&ml);

    return 0;
}