//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contact {
    char *name;
    char *number;
} contact;

// Creates a new contact with the given name and number.
contact *create_contact(char *name, char *number) {
    contact *new_contact = malloc(sizeof(contact));
    new_contact->name = strdup(name);
    new_contact->number = strdup(number);
    return new_contact;
}

// Frees the memory allocated for the given contact.
void destroy_contact(contact *contact) {
    free(contact->name);
    free(contact->number);
    free(contact);
}

// Prints the contact's name and number to the console.
void print_contact(contact *contact) {
    printf("%s: %s\n", contact->name, contact->number);
}

// Adds the given contact to the phone book.
void add_contact(contact **phone_book, int *num_contacts, contact *new_contact) {
    phone_book[*num_contacts] = new_contact;
    *num_contacts = *num_contacts + 1;
}

// Removes the contact at the given index from the phone book.
void remove_contact(contact **phone_book, int *num_contacts, int index) {
    for (int i = index; i < *num_contacts - 1; i++) {
        phone_book[i] = phone_book[i + 1];
    }
    *num_contacts = *num_contacts - 1;
}

// Finds the contact with the given name in the phone book.
contact *find_contact(contact **phone_book, int num_contacts, char *name) {
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(phone_book[i]->name, name) == 0) {
            return phone_book[i];
        }
    }
    return NULL;
}

// Prints the entire phone book to the console.
void print_phone_book(contact **phone_book, int num_contacts) {
    printf("Contacts:\n");
    for (int i = 0; i < num_contacts; i++) {
        print_contact(phone_book[i]);
    }
}

int main() {
    // Create an empty phone book.
    contact **phone_book = malloc(0 * sizeof(contact *));
    int num_contacts = 0;

    // Add some contacts to the phone book.
    add_contact(&phone_book, &num_contacts, create_contact("Alice", "123-456-7890"));
    add_contact(&phone_book, &num_contacts, create_contact("Bob", "098-765-4321"));
    add_contact(&phone_book, &num_contacts, create_contact("Charlie", "111-222-3333"));

    // Print the phone book to the console.
    print_phone_book(phone_book, num_contacts);

    // Find a contact in the phone book.
    contact *alice = find_contact(phone_book, num_contacts, "Alice");

    // Print the contact's information to the console.
    if (alice != NULL) {
        printf("Found Alice:\n");
        print_contact(alice);
    } else {
        printf("Alice not found.\n");
    }

    // Remove a contact from the phone book.
    remove_contact(&phone_book, &num_contacts, 1);

    // Print the phone book to the console again.
    print_phone_book(phone_book, num_contacts);

    // Free the memory allocated for the phone book.
    for (int i = 0; i < num_contacts; i++) {
        destroy_contact(phone_book[i]);
    }
    free(phone_book);

    return 0;
}