//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 256
#define MAX_PHONE_LEN 64

// Declare a struct to store contact information
struct contact {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
};

// Function to print a contact's information
void print_contact(struct contact *contact) {
    printf("Name: %s\nPhone: %s\n", contact->name, contact->phone);
}

// Function to add a new contact
void add_contact(struct contact **contacts, int *num_contacts, char *name, char *phone) {
    struct contact *new_contact = (struct contact *) malloc(sizeof(struct contact));
    strcpy(new_contact->name, name);
    strcpy(new_contact->phone, phone);
    *num_contacts += 1;
    contacts = realloc(contacts, sizeof(struct contact *) * *num_contacts);
    contacts[*num_contacts - 1] = new_contact;
}

// Function to search for a contact
int search_contact(struct contact **contacts, int num_contacts, char *name) {
    int i;
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i]->name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to remove a contact
void remove_contact(struct contact **contacts, int num_contacts, int index) {
    if (index < num_contacts) {
        memmove(contacts + index, contacts + index + 1, (num_contacts - index - 1) * sizeof(struct contact *));
        num_contacts -= 1;
    }
}

int main() {
    // Declare an array of struct contact
    struct contact contacts[10];
    int num_contacts = 0;

    // Add some contacts
    add_contact(&contacts, &num_contacts, "John Doe", "555-1234");
    add_contact(&contacts, &num_contacts, "Jane Doe", "555-5678");
    add_contact(&contacts, &num_contacts, "Bob Smith", "555-9012");

    // Search for a contact
    int index = search_contact(contacts, num_contacts, "Jane Doe");
    if (index != -1) {
        print_contact(&contacts[index]);
    } else {
        printf("Contact not found\n");
    }

    // Remove a contact
    remove_contact(&contacts, num_contacts, 1);

    // Print the updated contact list
    printf("Contacts:\n");
    for (int i = 0; i < num_contacts; i++) {
        print_contact(&contacts[i]);
    }

    return 0;
}