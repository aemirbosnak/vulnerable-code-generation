//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A contact in the phone book has a name and a phone number
typedef struct Contact {
    char *name;
    char *number;
} Contact;

// The phone book is an array of contacts
typedef struct PhoneBook {
    Contact *contacts;
    int num_contacts;
} PhoneBook;

// Create a new phone book
PhoneBook *create_phone_book() {
    PhoneBook *phone_book = malloc(sizeof(PhoneBook));
    phone_book->contacts = NULL;
    phone_book->num_contacts = 0;
    return phone_book;
}

// Add a new contact to the phone book
void add_contact(PhoneBook *phone_book, char *name, char *number) {
    // Allocate memory for the new contact
    Contact *new_contact = malloc(sizeof(Contact));
    new_contact->name = strdup(name);
    new_contact->number = strdup(number);

    // Add the new contact to the phone book
    phone_book->contacts = realloc(phone_book->contacts, (phone_book->num_contacts + 1) * sizeof(Contact));
    phone_book->contacts[phone_book->num_contacts] = *new_contact;
    phone_book->num_contacts++;

    // Free the memory allocated for the new contact's name and number
    free(new_contact);
}

// Find a contact in the phone book by name
Contact *find_contact(PhoneBook *phone_book, char *name) {
    for (int i = 0; i < phone_book->num_contacts; i++) {
        if (strcmp(phone_book->contacts[i].name, name) == 0) {
            return &phone_book->contacts[i];
        }
    }
    return NULL;
}

// Print the phone book
void print_phone_book(PhoneBook *phone_book) {
    for (int i = 0; i < phone_book->num_contacts; i++) {
        printf("%s: %s\n", phone_book->contacts[i].name, phone_book->contacts[i].number);
    }
}

// Free the memory allocated for the phone book
void free_phone_book(PhoneBook *phone_book) {
    for (int i = 0; i < phone_book->num_contacts; i++) {
        free(phone_book->contacts[i].name);
        free(phone_book->contacts[i].number);
    }
    free(phone_book->contacts);
    free(phone_book);
}

int main() {
    // Create a new phone book
    PhoneBook *phone_book = create_phone_book();

    // Add some contacts to the phone book
    add_contact(phone_book, "Alice", "555-1212");
    add_contact(phone_book, "Bob", "555-1213");
    add_contact(phone_book, "Charlie", "555-1214");

    // Find a contact in the phone book by name
    Contact *charlie = find_contact(phone_book, "Charlie");

    // Print the phone book
    print_phone_book(phone_book);

    // Free the memory allocated for the phone book
    free_phone_book(phone_book);

    return 0;
}