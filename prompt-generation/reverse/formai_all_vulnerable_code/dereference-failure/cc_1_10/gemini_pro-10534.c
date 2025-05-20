//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: realistic
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// A contact struct to store name and phone number
typedef struct contact {
    char *name;
    char *phone_number;
} contact;

// A phone book struct to store an array of contacts
typedef struct phone_book {
    contact *contacts;
    int num_contacts;
} phone_book;

// Function to create a new phone book
phone_book *create_phone_book() {
    phone_book *book = malloc(sizeof(phone_book));
    book->contacts = NULL;
    book->num_contacts = 0;
    return book;
}

// Function to add a contact to a phone book
void add_contact(phone_book *book, char *name, char *phone_number) {
    // Allocate memory for the new contact
    contact *new_contact = malloc(sizeof(contact));
    new_contact->name = strdup(name);
    new_contact->phone_number = strdup(phone_number);

    // Add the new contact to the phone book
    book->contacts = realloc(book->contacts, sizeof(contact) * (book->num_contacts + 1));
    book->contacts[book->num_contacts] = *new_contact;
    book->num_contacts++;
}

// Function to find a contact in a phone book by name
contact *find_contact_by_name(phone_book *book, char *name) {
    for (int i = 0; i < book->num_contacts; i++) {
        if (strcmp(book->contacts[i].name, name) == 0) {
            return &book->contacts[i];
        }
    }
    return NULL;
}

// Function to print a phone book
void print_phone_book(phone_book *book) {
    for (int i = 0; i < book->num_contacts; i++) {
        printf("%s: %s\n", book->contacts[i].name, book->contacts[i].phone_number);
    }
}

// Function to free the memory allocated for a phone book
void free_phone_book(phone_book *book) {
    for (int i = 0; i < book->num_contacts; i++) {
        free(book->contacts[i].name);
        free(book->contacts[i].phone_number);
    }
    free(book->contacts);
    free(book);
}

int main() {
    // Create a new phone book
    phone_book *book = create_phone_book();

    // Add some contacts to the phone book
    add_contact(book, "John Doe", "555-1212");
    add_contact(book, "Jane Smith", "555-1213");
    add_contact(book, "Bill Jones", "555-1214");

    // Print the phone book
    print_phone_book(book);

    // Find a contact by name
    contact *contact = find_contact_by_name(book, "John Doe");
    if (contact != NULL) {
        printf("Found contact: %s: %s\n", contact->name, contact->phone_number);
    } else {
        printf("Contact not found.\n");
    }

    // Free the memory allocated for the phone book
    free_phone_book(book);

    return 0;
}