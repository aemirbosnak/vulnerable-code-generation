//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 500

// A contact structure to store a name and phone number
struct contact {
    char name[50];
    char phone[20];
};

// A phone book is an array of contacts
struct phone_book {
    struct contact contacts[MAX_CONTACTS];
    int num_contacts;
};

// Create a new phone book
struct phone_book *create_phone_book() {
    struct phone_book *phone_book = malloc(sizeof(struct phone_book));
    phone_book->num_contacts = 0;
    return phone_book;
}

// Add a new contact to the phone book
void add_contact(struct phone_book *phone_book, char *name, char *phone) {
    // Check if the phone book is full
    if (phone_book->num_contacts >= MAX_CONTACTS) {
        printf("Phone book is full!\n");
        return;
    }

    // Copy the name and phone number into the new contact
    strcpy(phone_book->contacts[phone_book->num_contacts].name, name);
    strcpy(phone_book->contacts[phone_book->num_contacts].phone, phone);

    // Increment the number of contacts
    phone_book->num_contacts++;
}

// Find a contact in the phone book by name
struct contact *find_contact(struct phone_book *phone_book, char *name) {
    // Iterate over the contacts in the phone book
    for (int i = 0; i < phone_book->num_contacts; i++) {
        // Check if the contact's name matches the given name
        if (strcmp(phone_book->contacts[i].name, name) == 0) {
            // Return the contact
            return &phone_book->contacts[i];
        }
    }

    // Return NULL if the contact was not found
    return NULL;
}

// Print the contacts in the phone book
void print_phone_book(struct phone_book *phone_book) {
    // Iterate over the contacts in the phone book
    for (int i = 0; i < phone_book->num_contacts; i++) {
        // Print the contact's name and phone number
        printf("%s: %s\n", phone_book->contacts[i].name, phone_book->contacts[i].phone);
    }
}

// Main function
int main() {
    // Create a new phone book
    struct phone_book *phone_book = create_phone_book();

    // Add some contacts to the phone book
    add_contact(phone_book, "Alice", "555-1212");
    add_contact(phone_book, "Bob", "555-1213");
    add_contact(phone_book, "Carol", "555-1214");

    // Find a contact in the phone book
    struct contact *contact = find_contact(phone_book, "Bob");

    // Print the contact's information
    if (contact != NULL) {
        printf("Name: %s\n", contact->name);
        printf("Phone: %s\n", contact->phone);
    } else {
        printf("Contact not found!\n");
    }

    // Print the entire phone book
    printf("\nPhone Book:\n");
    print_phone_book(phone_book);

    return 0;
}