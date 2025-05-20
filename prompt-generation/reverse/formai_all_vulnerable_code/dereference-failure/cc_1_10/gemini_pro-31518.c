//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structure to store a contact
typedef struct Contact {
    char *name;
    char *phone;
} Contact;

// Array to store all contacts
Contact *contacts[100];

// Function to add a new contact
void add_contact(char *name, char *phone) {
    for (int i = 0; i < 100; i++) {
        if (contacts[i] == NULL) {
            contacts[i] = malloc(sizeof(Contact));
            contacts[i]->name = strdup(name);
            contacts[i]->phone = strdup(phone);
            break;
        }
    }
}

// Function to search for a contact by name
Contact *search_contact(char *name) {
    for (int i = 0; i < 100; i++) {
        if (contacts[i] != NULL && strcmp(contacts[i]->name, name) == 0) {
            return contacts[i];
        }
    }

    return NULL;
}

// Function to print all contacts
void print_contacts() {
    for (int i = 0; i < 100; i++) {
        if (contacts[i] != NULL) {
            printf("%s: %s\n", contacts[i]->name, contacts[i]->phone);
        }
    }
}

// Main function
int main() {
    // Add some dummy contacts to the phone book
    add_contact("John Doe", "123-456-7890");
    add_contact("Jane Doe", "987-654-3210");

    // Search for a contact by name
    Contact *contact = search_contact("John Doe");
    if (contact != NULL) {
        printf("Found contact: %s (%s)\n", contact->name, contact->phone);
    } else {
        printf("Contact not found\n");
    }

    // Print all contacts
    printf("All contacts:\n");
    print_contacts();

    return 0;
}