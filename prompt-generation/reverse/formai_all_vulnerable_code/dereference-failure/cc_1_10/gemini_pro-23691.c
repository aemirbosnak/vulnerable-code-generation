//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact {
    char name[50];
    char phone[20];
    struct contact *next;
};

struct contact *head = NULL;
struct contact *tail = NULL;

void add_contact(char *name, char *phone) {
    struct contact *new_contact = malloc(sizeof(struct contact));
    strcpy(new_contact->name, name);
    strcpy(new_contact->phone, phone);
    new_contact->next = NULL;

    if (head == NULL) {
        head = new_contact;
        tail = new_contact;
    } else {
        tail->next = new_contact;
        tail = new_contact;
    }
}

void print_contacts() {
    struct contact *current = head;

    while (current != NULL) {
        printf("%s: %s\n", current->name, current->phone);
        current = current->next;
    }
}

void search_contact(char *name) {
    struct contact *current = head;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("%s: %s\n", current->name, current->phone);
            return;
        }
        current = current->next;
    }

    printf("Contact not found.\n");
}

int main() {
    add_contact("John Doe", "555-123-4567");
    add_contact("Jane Smith", "555-234-5678");
    add_contact("Bill Jones", "555-345-6789");

    print_contacts();

    search_contact("John Doe");
    search_contact("Mary Johnson");

    return 0;
}