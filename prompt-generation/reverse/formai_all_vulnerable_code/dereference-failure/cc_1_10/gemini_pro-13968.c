//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store contact information
typedef struct contact {
    char *name;
    char *phone_number;
} contact;

// Function to create a new contact
contact *create_contact(char *name, char *phone_number) {
    contact *new_contact = malloc(sizeof(contact));
    new_contact->name = strdup(name);
    new_contact->phone_number = strdup(phone_number);
    return new_contact;
}

// Function to add a new contact to the phone book
void add_contact(contact *phone_book[], int *num_contacts, contact *new_contact) {
    phone_book[*num_contacts] = new_contact;
    (*num_contacts)++;
}

// Function to search for a contact in the phone book
contact *search_contact(contact *phone_book[], int num_contacts, char *name) {
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(phone_book[i]->name, name) == 0) {
            return phone_book[i];
        }
    }
    return NULL;
}

// Function to print the phone book
void print_phone_book(contact *phone_book[], int num_contacts) {
    for (int i = 0; i < num_contacts; i++) {
        printf("%s: %s\n", phone_book[i]->name, phone_book[i]->phone_number);
    }
}

// Function to free the memory allocated for a contact
void free_contact(contact *contact) {
    free(contact->name);
    free(contact->phone_number);
    free(contact);
}

// Function to free the memory allocated for the phone book
void free_phone_book(contact *phone_book[], int num_contacts) {
    for (int i = 0; i < num_contacts; i++) {
        free_contact(phone_book[i]);
    }
    free(phone_book);
}

int main() {
    // Create a phone book
    contact *phone_book[100];
    int num_contacts = 0;

    // Add some contacts to the phone book
    add_contact(phone_book, &num_contacts, create_contact("John Smith", "555-1212"));
    add_contact(phone_book, &num_contacts, create_contact("Jane Doe", "555-1213"));
    add_contact(phone_book, &num_contacts, create_contact("Bill Jones", "555-1214"));

    // Print the phone book
    print_phone_book(phone_book, num_contacts);

    // Search for a contact in the phone book
    contact *contact = search_contact(phone_book, num_contacts, "John Smith");
    if (contact != NULL) {
        printf("Found contact: %s: %s\n", contact->name, contact->phone_number);
    } else {
        printf("Contact not found.\n");
    }

    // Free the memory allocated for the phone book
    free_phone_book(phone_book, num_contacts);

    return 0;
}