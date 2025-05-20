//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store contact information
typedef struct {
    char name[50];    // Name of the contact
    char number[20];  // Phone number of the contact
    char email[50];   // Email address of the contact
} contact;

// Function to insert a new contact
void insert_contact(contact *contacts, int *num_contacts, char *name, char *number, char *email) {
    int i;

    // Check if the contact already exists
    for (i = 0; i < *num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Contact already exists. Skipping...\n");
            return;
        }
    }

    // If the contact does not exist, insert it
    contacts[*num_contacts] = (contact) {
        .name = name,
        .number = number,
        .email = email
    };
    (*num_contacts)++;
}

// Function to search for a contact
contact *search_contact(contact *contacts, int num_contacts, char *name) {
    int i;

    for (i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            return &contacts[i];
        }
    }

    return NULL;
}

// Function to display all contacts
void display_contacts(contact *contacts, int num_contacts) {
    int i;

    printf("Contacts:\n");
    for (i = 0; i < num_contacts; i++) {
        printf("Name: %s\n", contacts[i].name);
        printf("Number: %s\n", contacts[i].number);
        printf("Email: %s\n", contacts[i].email);
    }
}

int main() {
    // Initialize the phone book
    contact *contacts = (contact *)calloc(10, sizeof(contact));
    int num_contacts = 0;

    // Insert some contacts
    insert_contact(contacts, &num_contacts, "John Doe", "555-1234", "johndoe@example.com");
    insert_contact(contacts, &num_contacts, "Jane Smith", "555-5678", "janesmith@example.com");
    insert_contact(contacts, &num_contacts, "Bob Brown", "555-9012", "bob brown@example.com");

    // Search for a contact
    contact *found_contact = search_contact(contacts, num_contacts, "Jane Smith");
    if (found_contact != NULL) {
        printf("Found contact: %s\n", found_contact->name);
    } else {
        printf("No contact found\n");
    }

    // Display all contacts
    display_contacts(contacts, num_contacts);

    // Free the memory
    free(contacts);

    return 0;
}