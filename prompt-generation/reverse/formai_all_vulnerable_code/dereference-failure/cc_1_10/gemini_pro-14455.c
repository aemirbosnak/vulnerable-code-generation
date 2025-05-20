//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a contact
typedef struct Contact {
    char *name;
    char *number;
} Contact;

// Create a new contact
Contact *new_contact(char *name, char *number) {
    Contact *contact = malloc(sizeof(Contact));
    contact->name = strdup(name);
    contact->number = strdup(number);
    return contact;
}

// Free a contact
void free_contact(Contact *contact) {
    free(contact->name);
    free(contact->number);
    free(contact);
}

// Print a contact
void print_contact(Contact *contact) {
    printf("%s: %s\n", contact->name, contact->number);
}

// Compare two contacts
int compare_contacts(const void *a, const void *b) {
    Contact *contact1 = *(Contact **)a;
    Contact *contact2 = *(Contact **)b;
    return strcmp(contact1->name, contact2->name);
}

// Main function
int main() {
    // Create an array of contacts
    Contact *contacts[] = {
        new_contact("Alice", "555-1212"),
        new_contact("Bob", "555-1213"),
        new_contact("Carol", "555-1214"),
        new_contact("Dave", "555-1215"),
        new_contact("Eve", "555-1216"),
    };

    // Sort the contacts
    qsort(contacts, sizeof(contacts) / sizeof(Contact *),
            sizeof(Contact *), compare_contacts);

    // Print the contacts
    printf("Phone Book:\n");
    for (int i = 0; i < sizeof(contacts) / sizeof(Contact *); i++) {
        print_contact(contacts[i]);
    }

    // Free the contacts
    for (int i = 0; i < sizeof(contacts) / sizeof(Contact *); i++) {
        free_contact(contacts[i]);
    }

    return 0;
}