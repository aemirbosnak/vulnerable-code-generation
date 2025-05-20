//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// Structure to store a contact
typedef struct {
    char *name;
    char *email;
} contact;

// Function to allocate memory for a contact
contact *alloc_contact(void) {
    contact *c = (contact *)malloc(sizeof(contact));
    c->name = (char *)malloc(20 * sizeof(char));
    c->email = (char *)malloc(50 * sizeof(char));
    return c;
}

// Function to free memory for a contact
void free_contact(contact *c) {
    free(c->name);
    free(c->email);
    free(c);
}

// Function to add a contact to the address book
void add_contact(contact **contacts, int *num_contacts, const char *name, const char *email) {
    contact *new_contact = alloc_contact();
    new_contact->name = name;
    new_contact->email = email;
    // Safe version of arrays
    if (*num_contacts == 0) {
        *contacts = new_contact;
    } else {
        contact **new_contacts = realloc(*contacts, (size_t)(*num_contacts + 1) * sizeof(contact *));
        assert(new_contacts != NULL);
        new_contacts[*num_contacts] = new_contact;
        *contacts = new_contacts;
    }
    (*num_contacts)++;
}

// Function to remove a contact from the address book
void remove_contact(contact **contacts, int *num_contacts, int index) {
    assert(index < *num_contacts);
    contact *contact_to_remove = contacts[index];
    free_contact(contact_to_remove);
    // Safe version of arrays
    if (index == 0) {
        contacts[0] = NULL;
    } else {
        memmove(contacts + index, contacts + index + 1, (size_t)(*num_contacts - index));
    }
    (*num_contacts)--;
}

// Function to search for a contact in the address book
int contains_contact(contact **contacts, int num_contacts, const char *name) {
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i]->name, name) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    contact *contacts = NULL;
    int num_contacts = 0;

    // Add some contacts
    add_contact(&contacts, &num_contacts, "John Doe", "johndoe@example.com");
    add_contact(&contacts, &num_contacts, "Jane Doe", "janedoe@example.com");
    add_contact(&contacts, &num_contacts, "Bob Smith", "bobsmith@example.com");

    // Remove a contact
    remove_contact(&contacts, &num_contacts, 1);

    // Search for a contact
    if (contains_contact(&contacts, num_contacts, "Jane Doe")) {
        printf("Contact found\n");
    } else {
        printf("Contact not found\n");
    }

    // Free memory
    free_contact(contacts);

    return 0;
}