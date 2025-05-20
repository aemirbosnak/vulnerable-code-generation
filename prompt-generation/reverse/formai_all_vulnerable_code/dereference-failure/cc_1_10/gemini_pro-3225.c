//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact {
    char name[20];
    char number[15];
};

struct contact_node {
    struct contact contact;
    struct contact_node *next;
};

struct contact_list {
    struct contact_node *head;
    struct contact_node *tail;
};

void add_contact(struct contact_list *list, struct contact contact) {
    struct contact_node *new_node = (struct contact_node *)malloc(sizeof(struct contact_node));
    new_node->contact = contact;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
}

void print_contacts(struct contact_list *list) {
    struct contact_node *current = list->head;

    while (current != NULL) {
        printf("%s: %s\n", current->contact.name, current->contact.number);
        current = current->next;
    }
}

int main() {
    struct contact_list list;
    list.head = NULL;
    list.tail = NULL;

    add_contact(&list, (struct contact) {"John", "555-123-4567"});
    add_contact(&list, (struct contact) {"Mary", "555-234-5678"});
    add_contact(&list, (struct contact) {"Bob", "555-345-6789"});

    print_contacts(&list);

    return 0;
}