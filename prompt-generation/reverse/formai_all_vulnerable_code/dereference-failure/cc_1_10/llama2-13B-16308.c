//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a contact
typedef struct {
    char name[50];
    char number[20];
    char email[50];
} contact;

// Function to create a new contact
contact create_contact(char *name, char *number, char *email) {
    contact c;
    strcpy(c.name, name);
    strcpy(c.number, number);
    strcpy(c.email, email);
    return c;
}

// Function to search for a contact by name
contact *search_contact(contact *contacts, int num_contacts, char *name) {
    int i;
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            return &contacts[i];
        }
    }
    return NULL;
}

// Function to add a contact to the phone book
void add_contact(contact *contacts, int *num_contacts, char *name, char *number, char *email) {
    int i;
    for (i = 0; i < *num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            // Contact already exists, update the information
            strcpy(contacts[i].number, number);
            strcpy(contacts[i].email, email);
            return;
        }
    }
    // Contact does not exist, add a new one
    contacts[*num_contacts] = create_contact(name, number, email);
    (*num_contacts)++;
}

// Function to remove a contact from the phone book
void remove_contact(contact *contacts, int *num_contacts, char *name) {
    int i;
    for (i = 0; i < *num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            // Found the contact to remove
            memmove(&contacts[i], &contacts[i+1], (*num_contacts - i - 1) * sizeof(contact));
            (*num_contacts)--;
            return;
        }
    }
}

int main() {
    // Initialize phone book with empty array and 0 contacts
    contact *contacts = NULL;
    int num_contacts = 0;

    // Add some contacts to the phone book
    add_contact(contacts, &num_contacts, "John Doe", "555-1234", "johndoe@example.com");
    add_contact(contacts, &num_contacts, "Jane Doe", "555-5678", "janedoe@example.com");
    add_contact(contacts, &num_contacts, "Bob Smith", "555-9012", "bobsmith@example.com");

    // Search for a contact by name
    contact *found_contact = search_contact(contacts, num_contacts, "Jane Doe");
    if (found_contact != NULL) {
        printf("Found contact: %s %s %s\n", found_contact->name, found_contact->number, found_contact->email);
    } else {
        printf("No contact found\n");
    }

    // Remove a contact from the phone book
    remove_contact(contacts, &num_contacts, "John Doe");

    // Print the updated phone book
    for (int i = 0; i < num_contacts; i++) {
        printf("%d: %s %s %s\n", i, contacts[i].name, contacts[i].number, contacts[i].email);
    }

    return 0;
}