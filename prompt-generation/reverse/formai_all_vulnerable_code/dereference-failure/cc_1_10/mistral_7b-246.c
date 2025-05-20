//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char number[20];
} Contact;

typedef struct Node {
    Contact data;
    struct Node* next;
} Node;

Node* create_node(Contact contact) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = contact;
    new_node->next = NULL;
    return new_node;
}

void add_contact(Node** head_ref, Contact contact) {
    Node* new_node = create_node(contact);

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    Node* last = *head_ref;
    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    return;
}

void display_contacts(Node* node) {
    while (node != NULL) {
        printf("\nName: %s\nNumber: %s", node->data.name, node->data.number);
        node = node->next;
    }
}

int search_contact(Node* head, char name[50]) {
    Node* current = head;

    while (current != NULL) {
        if (strcmp(current->data.name, name) == 0)
            return 1;

        current = current->next;
    }

    return 0;
}

void delete_contact(Node** head_ref, char name[50]) {
    Node* current = *head_ref, *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->data.name, name) == 0) {
            if (previous == NULL) {
                *head_ref = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }

        previous = current;
        current = current->next;
    }

    printf("Contact not found!\n");
}

int main() {
    Node* head = NULL;

    add_contact(&head, (Contact){"John Doe", "555-1234"});
    add_contact(&head, (Contact){"Jane Doe", "555-5678"});
    add_contact(&head, (Contact){"Bob Smith", "555-9012"});

    display_contacts(head);

    if (search_contact(head, "Jane Doe"))
        printf("\nContact found!");

    delete_contact(&head, "Bob Smith");

    display_contacts(head);

    return 0;
}