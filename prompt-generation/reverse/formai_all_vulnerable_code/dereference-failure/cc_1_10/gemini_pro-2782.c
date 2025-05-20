//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a contact
typedef struct Contact {
    char *name;
    char *number;
} Contact;

// Function to create a new contact
Contact *createContact(char *name, char *number) {
    Contact *contact = malloc(sizeof(Contact));
    contact->name = strdup(name);
    contact->number = strdup(number);
    return contact;
}

// Function to compare two contacts
int compareContacts(const void *a, const void *b) {
    const Contact *contact1 = a;
    const Contact *contact2 = b;
    return strcmp(contact1->name, contact2->name);
}

// Function to print a contact
void printContact(Contact *contact) {
    printf("%s: %s\n", contact->name, contact->number);
}

// Main function
int main() {
    // Create an array of contacts
    Contact *contacts[] = {
        createContact("John Doe", "555-1212"),
        createContact("Jane Doe", "555-1213"),
        createContact("John Smith", "555-1214"),
        createContact("Jane Smith", "555-1215"),
    };

    // Sort the contacts by name
    qsort(contacts, 4, sizeof(Contact *), compareContacts);

    // Print the sorted contacts
    for (int i = 0; i < 4; i++) {
        printContact(contacts[i]);
    }

    // Free the allocated memory
    for (int i = 0; i < 4; i++) {
        free(contacts[i]->name);
        free(contacts[i]->number);
        free(contacts[i]);
    }

    return 0;
}