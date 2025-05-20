//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a contact
typedef struct Contact {
    char *name;
    char *phone_number;
} Contact;

// Create a new contact
Contact *create_contact(char *name, char *phone_number) {
    Contact *contact = malloc(sizeof(Contact));
    contact->name = strdup(name);
    contact->phone_number = strdup(phone_number);
    return contact;
}

// Free the memory allocated for a contact
void free_contact(Contact *contact) {
    free(contact->name);
    free(contact->phone_number);
    free(contact);
}

// Print a contact
void print_contact(Contact *contact) {
    printf("%s: %s\n", contact->name, contact->phone_number);
}

// Create a new phone book
typedef struct PhoneBook {
    Contact **contacts;
    int num_contacts;
} PhoneBook;

// Create a new phone book
PhoneBook *create_phone_book() {
    PhoneBook *phone_book = malloc(sizeof(PhoneBook));
    phone_book->contacts = malloc(sizeof(Contact *) * 10);
    phone_book->num_contacts = 0;
    return phone_book;
}

// Free the memory allocated for a phone book
void free_phone_book(PhoneBook *phone_book) {
    for (int i = 0; i < phone_book->num_contacts; i++) {
        free_contact(phone_book->contacts[i]);
    }
    free(phone_book->contacts);
    free(phone_book);
}

// Add a contact to a phone book
void add_contact(PhoneBook *phone_book, Contact *contact) {
    if (phone_book->num_contacts == 10) {
        phone_book->contacts = realloc(phone_book->contacts, sizeof(Contact *) * 20);
    }
    phone_book->contacts[phone_book->num_contacts] = contact;
    phone_book->num_contacts++;
}

// Find a contact in a phone book by name
Contact *find_contact_by_name(PhoneBook *phone_book, char *name) {
    for (int i = 0; i < phone_book->num_contacts; i++) {
        if (strcmp(phone_book->contacts[i]->name, name) == 0) {
            return phone_book->contacts[i];
        }
    }
    return NULL;
}

// Find a contact in a phone book by phone number
Contact *find_contact_by_phone_number(PhoneBook *phone_book, char *phone_number) {
    for (int i = 0; i < phone_book->num_contacts; i++) {
        if (strcmp(phone_book->contacts[i]->phone_number, phone_number) == 0) {
            return phone_book->contacts[i];
        }
    }
    return NULL;
}

// Print all contacts in a phone book
void print_phone_book(PhoneBook *phone_book) {
    for (int i = 0; i < phone_book->num_contacts; i++) {
        print_contact(phone_book->contacts[i]);
    }
}

int main() {
    // Create a new phone book
    PhoneBook *phone_book = create_phone_book();

    // Add some contacts to the phone book
    add_contact(phone_book, create_contact("John Doe", "555-1212"));
    add_contact(phone_book, create_contact("Jane Doe", "555-1213"));
    add_contact(phone_book, create_contact("John Smith", "555-1214"));
    add_contact(phone_book, create_contact("Jane Smith", "555-1215"));

    // Print all contacts in the phone book
    print_phone_book(phone_book);

    // Find a contact in the phone book by name
    Contact *contact = find_contact_by_name(phone_book, "John Doe");
    if (contact != NULL) {
        printf("Found contact: %s\n", contact->name);
    } else {
        printf("Contact not found.\n");
    }

    // Free the memory allocated for the phone book
    free_phone_book(phone_book);

    return 0;
}