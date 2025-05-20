//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contact {
    char name[50];
    char phone[20];
    struct contact *next;
} contact;

contact *head = NULL;

void add_contact(char *name, char *phone) {
    contact *new_contact = malloc(sizeof(contact));
    strcpy(new_contact->name, name);
    strcpy(new_contact->phone, phone);
    new_contact->next = NULL;

    if (head == NULL) {
        head = new_contact;
    } else {
        contact *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_contact;
    }
}

void print_contacts() {
    contact *current = head;
    while (current != NULL) {
        printf("%s: %s\n", current->name, current->phone);
        current = current->next;
    }
}

void search_contact(char *name) {
    contact *current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("%s: %s\n", current->name, current->phone);
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
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Contact not found.\n");
}

int main() {
    add_contact("John Doe", "555-1212");
    add_contact("Jane Doe", "555-1213");
    add_contact("Peter Jones", "555-1214");

    print_contacts();

    search_contact("Jane Doe");

    delete_contact("Peter Jones");

    print_contacts();

    return 0;
}