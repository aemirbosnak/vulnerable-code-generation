//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_NUMBER_LENGTH 20
#define MAX_ENTRIES 100

// Structure to store contact information
typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone_number[MAX_PHONE_NUMBER_LENGTH];
} contact_t;

// Function to add a new contact
void add_contact(contact_t *contacts, int *num_contacts, char *name, char *phone_number) {
    // Check if the name is already in the list
    int i;
    for (i = 0; i < *num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Contact already exists with name %s\n", name);
            return;
        }
    }

    // Add the new contact to the end of the list
    contacts[*num_contacts] = (contact_t) { .name = name, .phone_number = phone_number };
    (*num_contacts)++;
}

// Function to search for a contact
int search_contact(contact_t *contacts, int num_contacts, char *name) {
    int i;
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to delete a contact
void delete_contact(contact_t *contacts, int num_contacts, int index) {
    // Check if the index is valid
    assert(index >= 0 && index < num_contacts);

    // Remove the contact at the specified index
    memmove(contacts + index, contacts + index + 1, (num_contacts - index - 1) * sizeof(contact_t));
    num_contacts--;
}

int main() {
    // Initialize the contact list and the number of contacts
    contact_t *contacts = (contact_t *) malloc(MAX_ENTRIES * sizeof(contact_t));
    int num_contacts = 0;

    // Add some test contacts
    add_contact(contacts, &num_contacts, "John Doe", "555-1234");
    add_contact(contacts, &num_contacts, "Jane Smith", "555-5678");
    add_contact(contacts, &num_contacts, "Bob Johnson", "555-9012");

    // Search for a contact
    int index = search_contact(contacts, num_contacts, "Jane Smith");
    if (index >= 0) {
        printf("Found contact %d\n", index);
    } else {
        printf("Contact not found\n");
    }

    // Delete a contact
    delete_contact(contacts, num_contacts, 1);

    // Print the updated contact list
    for (int i = 0; i < num_contacts; i++) {
        printf("%d. %s (%s)\n", i + 1, contacts[i].name, contacts[i].phone_number);
    }

    // Free the memory allocated for the contact list
    free(contacts);

    return 0;
}