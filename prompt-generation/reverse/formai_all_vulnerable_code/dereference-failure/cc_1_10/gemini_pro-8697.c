//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a contact
typedef struct contact {
    char name[50];
    char phone_number[20];
} contact;

// Function to create a new contact
contact* create_contact(char* name, char* phone_number) {
    contact* new_contact = (contact*)malloc(sizeof(contact));
    strcpy(new_contact->name, name);
    strcpy(new_contact->phone_number, phone_number);
    return new_contact;
}

// Function to add a contact to the phone book
void add_contact(contact** phone_book, int* num_contacts, contact* new_contact) {
    phone_book[*num_contacts] = new_contact;
    (*num_contacts)++;
}

// Function to search for a contact in the phone book
contact* search_contact(contact** phone_book, int num_contacts, char* name) {
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(phone_book[i]->name, name) == 0) {
            return phone_book[i];
        }
    }
    return NULL;
}

// Function to print the phone book
void print_phone_book(contact** phone_book, int num_contacts) {
    for (int i = 0; i < num_contacts; i++) {
        printf("%s: %s\n", phone_book[i]->name, phone_book[i]->phone_number);
    }
}

// Main function
int main() {
    // Create a phone book
    contact** phone_book = (contact**)malloc(sizeof(contact*) * 100);
    int num_contacts = 0;

    // Add some contacts to the phone book
    add_contact(phone_book, &num_contacts, create_contact("John Doe", "555-123-4567"));
    add_contact(phone_book, &num_contacts, create_contact("Jane Smith", "555-234-5678"));
    add_contact(phone_book, &num_contacts, create_contact("Bill Jones", "555-345-6789"));

    // Print the phone book
    print_phone_book(phone_book, num_contacts);

    // Search for a contact
    contact* contact = search_contact(phone_book, num_contacts, "Jane Smith");
    if (contact != NULL) {
        printf("Found contact: %s: %s\n", contact->name, contact->phone_number);
    } else {
        printf("Contact not found.\n");
    }

    // Free the memory allocated for the phone book
    for (int i = 0; i < num_contacts; i++) {
        free(phone_book[i]);
    }
    free(phone_book);

    return 0;
}