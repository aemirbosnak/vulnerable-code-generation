//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a contact
typedef struct contact {
    char *name;
    char *number;
    struct contact *next;
} contact;

// Create a new contact
contact *create_contact(char *name, char *number) {
    contact *new_contact = (contact *)malloc(sizeof(contact));
    new_contact->name = strdup(name);
    new_contact->number = strdup(number);
    new_contact->next = NULL;
    return new_contact;
}

// Insert a new contact into a phone book
void insert_contact(contact **phone_book, contact *new_contact) {
    if (*phone_book == NULL) {
        *phone_book = new_contact;
    } else {
        contact *current_contact = *phone_book;
        while (current_contact->next != NULL) {
            current_contact = current_contact->next;
        }
        current_contact->next = new_contact;
    }
}

// Search for a contact in a phone book
contact *search_contact(contact *phone_book, char *name) {
    contact *current_contact = phone_book;
    while (current_contact != NULL) {
        if (strcmp(current_contact->name, name) == 0) {
            return current_contact;
        }
        current_contact = current_contact->next;
    }
    return NULL;
}

// Delete a contact from a phone book
void delete_contact(contact **phone_book, char *name) {
    if (*phone_book == NULL) {
        return;
    }

    if (strcmp((*phone_book)->name, name) == 0) {
        contact *temp = *phone_book;
        *phone_book = (*phone_book)->next;
        free(temp);
        return;
    }

    contact *current_contact = *phone_book;
    while (current_contact->next != NULL) {
        if (strcmp(current_contact->next->name, name) == 0) {
            contact *temp = current_contact->next;
            current_contact->next = current_contact->next->next;
            free(temp);
            return;
        }
        current_contact = current_contact->next;
    }
}

// Print the contacts in a phone book
void print_phone_book(contact *phone_book) {
    contact *current_contact = phone_book;
    while (current_contact != NULL) {
        printf("%s: %s\n", current_contact->name, current_contact->number);
        current_contact = current_contact->next;
    }
}

// Free the memory allocated for a phone book
void free_phone_book(contact *phone_book) {
    contact *current_contact = phone_book;
    while (current_contact != NULL) {
        contact *temp = current_contact;
        current_contact = current_contact->next;
        free(temp->name);
        free(temp->number);
        free(temp);
    }
}

// Main function
int main() {
    // Create a new phone book
    contact *phone_book = NULL;

    // Insert some contacts into the phone book
    insert_contact(&phone_book, create_contact("John Doe", "555-123-4567"));
    insert_contact(&phone_book, create_contact("Jane Doe", "555-234-5678"));
    insert_contact(&phone_book, create_contact("Jack Doe", "555-345-6789"));

    // Print the contacts in the phone book
    printf("Phone book:\n");
    print_phone_book(phone_book);

    // Search for a contact in the phone book
    contact *john_doe = search_contact(phone_book, "John Doe");
    if (john_doe != NULL) {
        printf("Found John Doe: %s\n", john_doe->number);
    } else {
        printf("John Doe not found\n");
    }

    // Delete a contact from the phone book
    delete_contact(&phone_book, "Jane Doe");

    // Print the contacts in the phone book
    printf("Phone book after deleting Jane Doe:\n");
    print_phone_book(phone_book);

    // Free the memory allocated for the phone book
    free_phone_book(phone_book);

    return 0;
}