//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contact {
    char *name;
    char *number;
    struct contact *next;
} contact;

contact *head = NULL;

void add_contact(char *name, char *number) {
    contact *new_contact = malloc(sizeof(contact));
    new_contact->name = malloc(strlen(name) + 1);
    strcpy(new_contact->name, name);
    new_contact->number = malloc(strlen(number) + 1);
    strcpy(new_contact->number, number);
    new_contact->next = head;
    head = new_contact;
}

void print_contacts() {
    contact *current = head;
    while (current != NULL) {
        printf("%s: %s\n", current->name, current->number);
        current = current->next;
    }
}

void search_contacts(char *name) {
    contact *current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("%s: %s\n", current->name, current->number);
            return;
        }
        current = current->next;
    }
    printf("Contact not found.\n");
}

void delete_contact(char *name) {
    contact *current = head;
    contact *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current->name);
            free(current->number);
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Contact not found.\n");
}

int main() {
    add_contact("John Doe", "555-123-4567");
    add_contact("Jane Doe", "555-234-5678");
    add_contact("John Smith", "555-345-6789");
    print_contacts();
    search_contacts("John Doe");
    delete_contact("John Smith");
    print_contacts();
    return 0;
}