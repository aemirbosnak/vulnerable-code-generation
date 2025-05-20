//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contact {
    char *name;
    char *number;
} contact;

typedef struct node {
    contact *contact;
    struct node *next;
} node;

typedef struct phonebook {
    node *head;
} phonebook;

phonebook *create_phonebook() {
    phonebook *pb = malloc(sizeof(phonebook));
    pb->head = NULL;
    return pb;
}

void add_contact(phonebook *pb, contact *c) {
    node *new_node = malloc(sizeof(node));
    new_node->contact = c;
    new_node->next = pb->head;
    pb->head = new_node;
}

contact *find_contact(phonebook *pb, char *name) {
    node *current = pb->head;
    while (current != NULL) {
        if (strcmp(current->contact->name, name) == 0) {
            return current->contact;
        }
        current = current->next;
    }
    return NULL;
}

void print_phonebook(phonebook *pb) {
    node *current = pb->head;
    while (current != NULL) {
        printf("%s: %s\n", current->contact->name, current->contact->number);
        current = current->next;
    }
}

contact *create_contact(char *name, char *number) {
    contact *c = malloc(sizeof(contact));
    c->name = strdup(name);
    c->number = strdup(number);
    return c;
}

int main() {
    phonebook *pb = create_phonebook();
    add_contact(pb, create_contact("Alice", "123-456-7890"));
    add_contact(pb, create_contact("Bob", "098-765-4321"));
    add_contact(pb, create_contact("Eve", "456-123-7890"));
    add_contact(pb, create_contact("Frank", "321-654-0987"));
    add_contact(pb, create_contact("Grace", "234-567-8901"));

    print_phonebook(pb);

    contact *c = find_contact(pb, "Alice");
    if (c != NULL) {
        printf("Found Alice: %s\n", c->number);
    } else {
        printf("Alice not found.\n");
    }

    return 0;
}