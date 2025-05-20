//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_NUMBER_LENGTH 20

// Structure to store a contact
typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone_number[MAX_PHONE_NUMBER_LENGTH];
} contact;

// Function to insert a new contact
void insert(contact *contacts, int *num_contacts, char *name, char *phone_number) {
    int i;
    for (i = 0; i < *num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            // Contact already exists, do nothing
            return;
        }
    }
    // Insert the new contact
    contacts[*num_contacts] = (contact) {
        .name = name,
        .phone_number = phone_number
    };
    (*num_contacts)++;
}

// Function to search for a contact
contact *search(contact *contacts, int num_contacts, char *name) {
    int i;
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            return &contacts[i];
        }
    }
    return NULL;
}

// Function to delete a contact
void delete(contact *contacts, int *num_contacts, char *name) {
    int i;
    for (i = 0; i < *num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            // Found the contact to delete
            memmove(&contacts[i], &contacts[i+1], (*num_contacts - i - 1) * sizeof(contact));
            (*num_contacts)--;
            break;
        }
    }
}

int main() {
    // Initialize the phone book
    contact *contacts = malloc(10 * sizeof(contact));
    int num_contacts = 0;

    // Insert some contacts
    insert(contacts, &num_contacts, "John Doe", "555-1234");
    insert(contacts, &num_contacts, "Jane Doe", "555-5678");
    insert(contacts, &num_contacts, "Bob Smith", "555-9012");

    // Search for a contact
    contact *found = search(contacts, num_contacts, "Jane Doe");
    if (found != NULL) {
        printf("Found contact: %s %s\n", found->name, found->phone_number);
    } else {
        printf("Contact not found\n");
    }

    // Delete a contact
    delete(contacts, &num_contacts, "Bob Smith");

    // Print the updated phone book
    for (int i = 0; i < num_contacts; i++) {
        printf("%d. %s %s\n", i + 1, contacts[i].name, contacts[i].phone_number);
    }

    free(contacts);
    return 0;
}