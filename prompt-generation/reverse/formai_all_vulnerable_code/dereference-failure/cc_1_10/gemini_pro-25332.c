//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: introspective
/*
 * Behold, the introspective phone book!
 *
 * This program is designed to be a living, breathing example of how to
 * manage a phone book using introspection.
 *
 * It leverages the power of reflection to dynamically inspect its own
 * structure and behavior, providing a level of self-awareness that
 * is rarely seen in the programming world.
 *
 * So, without further ado, prepare to be amazed as we delve into the
 * introspective realm of phone book management.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The maximum number of contacts that can be stored in the phone book.
#define MAX_CONTACTS    100

// The structure of a contact in the phone book.
typedef struct contact {
    char    *name;
    char    *number;
} contact_t;

// The phone book itself, an array of contacts.
contact_t phone_book[MAX_CONTACTS];

// The number of contacts currently stored in the phone book.
int num_contacts = 0;

// The function to add a new contact to the phone book.
void add_contact(char *name, char *number) {
    // Check if the phone book is full.
    if (num_contacts == MAX_CONTACTS) {
        printf("Error: The phone book is full.\n");
        return;
    }

    // Allocate memory for the new contact.
    phone_book[num_contacts].name    = malloc(strlen(name)    + 1);
    phone_book[num_contacts].number   = malloc(strlen(number)   + 1);

    // Copy the name and number into the new contact.
    strcpy(phone_book[num_contacts].name, name);
    strcpy(phone_book[num_contacts].number, number);

    // Increment the number of contacts.
    num_contacts++;
}

// The function to find a contact in the phone book.
contact_t *find_contact(char *name) {
    // Iterate over the contacts in the phone book.
    for (int i = 0; i < num_contacts; i++) {
        // Compare the name of the contact with the given name.
        if (strcmp(phone_book[i].name, name) == 0) {
            // Return the contact if found.
            return &phone_book[i];
        }
    }

    // Return NULL if the contact is not found.
    return NULL;
}

// The function to delete a contact from the phone book.
void delete_contact(char *name) {
    // Find the contact in the phone book.
    contact_t *contact = find_contact(name);

    // Check if the contact was found.
    if (contact == NULL) {
        printf("Error: Contact not found.\n");
        return;
    }

    // Free the memory allocated for the contact.
    free(contact->name);
    free(contact->number);

    // Shift the contacts after the deleted contact to fill the gap.
    for (int i = contact - phone_book; i < num_contacts - 1; i++) {
        phone_book[i] = phone_book[i + 1];
    }

    // Decrement the number of contacts.
    num_contacts--;
}

// The function to print the phone book.
void print_phone_book() {
    // Iterate over the contacts in the phone book.
    for (int i = 0; i < num_contacts; i++) {
        // Print the name and number of the contact.
        printf("%s: %s\n", phone_book[i].name, phone_book[i].number);
    }
}

// The main function.
int main() {
    // Add some contacts to the phone book.
    add_contact("John Doe", "555-1212");
    add_contact("Jane Doe", "555-1213");
    add_contact("Peter Parker", "555-1214");
    add_contact("Mary Jane", "555-1215");

    // Print the phone book.
    print_phone_book();

    // Find a contact in the phone book.
    contact_t *contact = find_contact("Peter Parker");

    // Print the contact's name and number.
    printf("Found contact: %s, %s\n", contact->name, contact->number);

    // Delete the contact from the phone book.
    delete_contact("Peter Parker");

    // Print the phone book again.
    print_phone_book();

    return 0;
}