//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char name[50];
    char number[20];
    struct node *next;
} node_t;

void addContact(node_t **head, char *name, char *number) {
    node_t *newContact = (node_t *)malloc(sizeof(node_t));
    strcpy(newContact->name, name);
    strcpy(newContact->number, number);
    newContact->next = NULL;

    if (*head == NULL) {
        *head = newContact;
    } else {
        node_t *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newContact;
    }
}

void searchContact(node_t *head, char *name) {
    while (head != NULL) {
        if (strcmp(head->name, name) == 0) {
            printf("Name: %s\nNumber: %s\n", head->name, head->number);
            return;
        }
        head = head->next;
    }

    printf("Contact not found.\n");
}

void deleteContact(node_t **head, char *name) {
    node_t *current = *head;
    node_t *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                *head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }

        previous = current;
        current = current->next;
    }

    printf("Contact not found.\n");
}

void printContacts(node_t *head) {
    while (head != NULL) {
        printf("Name: %s\nNumber: %s\n\n", head->name, head->number);
        head = head->next;
    }
}

int main() {
    node_t *head = NULL;

    // Add some contacts
    addContact(&head, "Alice", "123-456-7890");
    addContact(&head, "Bob", "234-567-8901");
    addContact(&head, "Carol", "345-678-9012");

    // Search for a contact
    searchContact(head, "Alice");

    // Delete a contact
    deleteContact(&head, "Bob");

    // Print all contacts
    printContacts(head);

    return 0;
}