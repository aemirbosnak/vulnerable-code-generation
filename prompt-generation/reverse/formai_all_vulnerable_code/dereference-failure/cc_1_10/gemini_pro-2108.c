//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a contact
typedef struct contact {
    char *name;
    char *number;
} contact;

// Function to create a new contact
contact *create_contact(char *name, char *number) {
    contact *new_contact = malloc(sizeof(contact));
    new_contact->name = strdup(name);
    new_contact->number = strdup(number);
    return new_contact;
}

// Function to add a contact to the phone book
void add_contact(contact **phone_book, int *num_contacts, contact *new_contact) {
    *phone_book = realloc(*phone_book, (*num_contacts + 1) * sizeof(contact));
    (*phone_book)[*num_contacts] = *new_contact;
    (*num_contacts)++;
}

// Function to search for a contact by name
contact *find_contact_by_name(contact *phone_book, int num_contacts, char *name) {
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            return &phone_book[i];
        }
    }
    return NULL;
}

// Function to print the phone book
void print_phone_book(contact *phone_book, int num_contacts) {
    for (int i = 0; i < num_contacts; i++) {
        printf("%s: %s\n", phone_book[i].name, phone_book[i].number);
    }
}

// Function to free the memory allocated for a contact
void free_contact(contact *contact) {
    free(contact->name);
    free(contact->number);
    free(contact);
}

// Function to free the memory allocated for the phone book
void free_phone_book(contact **phone_book, int num_contacts) {
    for (int i = 0; i < num_contacts; i++) {
        free_contact(&(*phone_book)[i]);
    }
    free(*phone_book);
}

int main() {
    // Create an empty phone book
    contact *phone_book = NULL;
    int num_contacts = 0;

    // Add some contacts to the phone book
    contact *c1 = create_contact("Alice", "555-1212");
    add_contact(&phone_book, &num_contacts, c1);

    contact *c2 = create_contact("Bob", "555-1213");
    add_contact(&phone_book, &num_contacts, c2);

    contact *c3 = create_contact("Carol", "555-1214");
    add_contact(&phone_book, &num_contacts, c3);

    // Print the phone book
    print_phone_book(phone_book, num_contacts);

    // Search for a contact by name
    contact *found_contact = find_contact_by_name(phone_book, num_contacts, "Bob");
    if (found_contact != NULL) {
        printf("Found contact: %s\n", found_contact->number);
    } else {
        printf("Contact not found.\n");
    }

    // Free the memory allocated for the phone book
    free_phone_book(&phone_book, num_contacts);

    return 0;
}