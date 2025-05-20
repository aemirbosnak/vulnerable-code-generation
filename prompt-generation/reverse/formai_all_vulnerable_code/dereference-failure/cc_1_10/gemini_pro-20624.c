//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct contact {
    char name[256];
    char phone_number[16];
    struct contact *next;
};

struct contact *head = NULL;

void add_contact(char *name, char *phone_number) {
    struct contact *new_contact = malloc(sizeof(struct contact));
    strcpy(new_contact->name, name);
    strcpy(new_contact->phone_number, phone_number);
    new_contact->next = head;
    head = new_contact;
}

void print_contacts() {
    struct contact *current = head;
    while (current != NULL) {
        printf("%s: %s\n", current->name, current->phone_number);
        current = current->next;
    }
}

void search_contact(char *name) {
    struct contact *current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("Found contact: %s (%s)\n", current->name, current->phone_number);
            return;
        }
        current = current->next;
    }
    printf("Contact not found.\n");
}

int main() {
    add_contact("John Doe", "555-1212");
    add_contact("Jane Smith", "555-1213");
    add_contact("Bob Jones", "555-1214");

    print_contacts();

    search_contact("John Doe");
    search_contact("Jane Smith");
    search_contact("Bob Jones");
    search_contact("Alice Baker");

    return 0;
}