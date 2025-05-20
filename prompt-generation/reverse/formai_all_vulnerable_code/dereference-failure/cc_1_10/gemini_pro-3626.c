//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: imaginative
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Constants
#define MAX_CONTACTS 100
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20

// Contact structure
typedef struct Contact {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} Contact;

// Phone book structure
typedef struct PhoneBook {
    Contact contacts[MAX_CONTACTS];
    int num_contacts;
} PhoneBook;

// Function to create a new phone book
PhoneBook *create_phone_book() {
    PhoneBook *phone_book = malloc(sizeof(PhoneBook));
    phone_book->num_contacts = 0;
    return phone_book;
}

// Function to add a contact to a phone book
void add_contact(PhoneBook *phone_book, char *name, char *number) {
    Contact *contact = &phone_book->contacts[phone_book->num_contacts++];
    strcpy(contact->name, name);
    strcpy(contact->number, number);
}

// Function to search for a contact in a phone book by name
Contact *find_contact_by_name(PhoneBook *phone_book, char *name) {
    for (int i = 0; i < phone_book->num_contacts; i++) {
        Contact *contact = &phone_book->contacts[i];
        if (strcmp(contact->name, name) == 0) {
            return contact;
        }
    }
    return NULL;
}

// Function to print a phone book
void print_phone_book(PhoneBook *phone_book) {
    for (int i = 0; i < phone_book->num_contacts; i++) {
        Contact *contact = &phone_book->contacts[i];
        printf("%s: %s\n", contact->name, contact->number);
    }
}

// Function to free the memory allocated for a phone book
void free_phone_book(PhoneBook *phone_book) {
    free(phone_book);
}

// Main function
int main() {
    // Create a new phone book
    PhoneBook *phone_book = create_phone_book();

    // Add some contacts to the phone book
    add_contact(phone_book, "John Doe", "123-456-7890");
    add_contact(phone_book, "Jane Doe", "123-456-7891");
    add_contact(phone_book, "John Smith", "123-456-7892");

    // Print the phone book
    print_phone_book(phone_book);

    // Search for a contact in the phone book by name
    Contact *contact = find_contact_by_name(phone_book, "John Doe");
    if (contact != NULL) {
        printf("Found contact: %s: %s\n", contact->name, contact->number);
    } else {
        printf("Contact not found.\n");
    }

    // Free the memory allocated for the phone book
    free_phone_book(phone_book);

    return 0;
}