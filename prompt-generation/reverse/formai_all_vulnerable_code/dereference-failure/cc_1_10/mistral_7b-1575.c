//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Subscriber {
    char name[50];
    char email[100];
    struct Subscriber *next;
} Subscriber;

typedef struct MailingList {
    Subscriber *head;
    int num_subscribers;
} MailingList;

void print_list(MailingList *list) {
    printf("Subscribers in the mailing list:\n");
    Subscriber *current = list->head;

    while (current != NULL) {
        printf("%s (%s)\n", current->name, current->email);
        current = current->next;
    }
}

void add_subscriber(MailingList *list, char *name, char *email) {
    Subscriber *new_subscriber = (Subscriber *)malloc(sizeof(Subscriber));

    strcpy(new_subscriber->name, name);
    strcpy(new_subscriber->email, email);
    new_subscriber->next = list->head;

    list->head = new_subscriber;
    list->num_subscribers++;
}

void remove_subscriber(MailingList *list, char *email) {
    Subscriber *current = list->head;
    Subscriber *previous = NULL;

    while (current != NULL && strcmp(current->email, email) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Email not found in the mailing list.\n");
        return;
    }

    if (previous == NULL) {
        list->head = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
    list->num_subscribers--;
}

void list_introspection(MailingList *list) {
    printf("Mailing List Information:\n");
    printf("Number of subscribers: %d\n", list->num_subscribers);
}

int main() {
    MailingList list = {NULL, 0};

    add_subscriber(&list, "John Doe", "john.doe@example.com");
    add_subscriber(&list, "Jane Doe", "jane.doe@example.com");

    print_list(&list);
    list_introspection(&list);

    remove_subscriber(&list, "jane.doe@example.com");
    print_list(&list);
    list_introspection(&list);

    return 0;
}