//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct subscriber {
    char *name;
    char *email;
    struct subscriber *next;
};

struct mailing_list {
    struct subscriber *head;
    struct subscriber *tail;
};

void add_subscriber(struct mailing_list *list, char *name, char *email) {
    struct subscriber *new_subscriber = malloc(sizeof(struct subscriber));
    new_subscriber->name = malloc(strlen(name) + 1);
    strcpy(new_subscriber->name, name);
    new_subscriber->email = malloc(strlen(email) + 1);
    strcpy(new_subscriber->email, email);
    new_subscriber->next = NULL;

    if (list->head == NULL) {
        list->head = new_subscriber;
        list->tail = new_subscriber;
    } else {
        list->tail->next = new_subscriber;
        list->tail = new_subscriber;
    }
}

void send_email(struct mailing_list *list, char *subject, char *body) {
    struct subscriber *current = list->head;

    while (current != NULL) {
        printf("Sending email to %s <%s>\n", current->name, current->email);
        // ...send the email...
        current = current->next;
    }
}

int main() {
    struct mailing_list list;
    list.head = NULL;
    list.tail = NULL;

    add_subscriber(&list, "Alice", "alice@example.com");
    add_subscriber(&list, "Bob", "bob@example.com");
    add_subscriber(&list, "Carol", "carol@example.com");

    send_email(&list, "Hello", "This is a test email.");

    return 0;
}