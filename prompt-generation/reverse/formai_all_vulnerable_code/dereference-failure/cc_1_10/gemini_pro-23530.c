//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structure to store a contact
struct Contact {
    char *name;
    char *number;
};

// Function to create a new contact
struct Contact *createContact(char *name, char *number) {
    struct Contact *contact = malloc(sizeof(struct Contact));
    contact->name = strdup(name);
    contact->number = strdup(number);
    return contact;
}

// Function to print a contact
void printContact(struct Contact *contact) {
    printf("%s: %s\n", contact->name, contact->number);
}

// Function to free the memory allocated for a contact
void freeContact(struct Contact *contact) {
    free(contact->name);
    free(contact->number);
    free(contact);
}

// Main function
int main() {
    // Create a phone book
    struct Contact *phoneBook[100];

    // Add some contacts to the phone book
    phoneBook[0] = createContact("Alice", "555-123-4567");
    phoneBook[1] = createContact("Bob", "555-234-5678");
    phoneBook[2] = createContact("Carol", "555-345-6789");

    // Print the phone book
    for (int i = 0; i < 3; i++) {
        printContact(phoneBook[i]);
    }

    // Free the memory allocated for the phone book
    for (int i = 0; i < 3; i++) {
        freeContact(phoneBook[i]);
    }

    return 0;
}