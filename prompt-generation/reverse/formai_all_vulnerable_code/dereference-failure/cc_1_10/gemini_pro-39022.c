//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store each contact
struct contact {
    char *name;
    char *number;
    struct contact *next;
};

// Function to create a new contact
struct contact *create_contact(char *name, char *number) {
    struct contact *new_contact = malloc(sizeof(struct contact));
    new_contact->name = strdup(name);
    new_contact->number = strdup(number);
    new_contact->next = NULL;
    return new_contact;
}

// Function to add a contact to the phone book
void add_contact(struct contact **phone_book, struct contact *new_contact) {
    if (*phone_book == NULL) {
        *phone_book = new_contact;
    } else {
        add_contact(&(*phone_book)->next, new_contact);
    }
}

// Function to find a contact in the phone book
struct contact *find_contact(struct contact *phone_book, char *name) {
    if (phone_book == NULL) {
        return NULL;
    } else if (strcmp(phone_book->name, name) == 0) {
        return phone_book;
    } else {
        return find_contact(phone_book->next, name);
    }
}

// Function to print the phone book
void print_phone_book(struct contact *phone_book) {
    if (phone_book == NULL) {
        printf("The phone book is empty.\n");
    } else {
        printf("%s: %s\n", phone_book->name, phone_book->number);
        print_phone_book(phone_book->next);
    }
}

// Function to free the memory allocated for the phone book
void free_phone_book(struct contact *phone_book) {
    if (phone_book == NULL) {
        return;
    } else {
        free_phone_book(phone_book->next);
        free(phone_book->name);
        free(phone_book->number);
        free(phone_book);
    }
}

int main() {
    // Create the phone book
    struct contact *phone_book = NULL;

    // Add some contacts to the phone book
    add_contact(&phone_book, create_contact("John Doe", "555-1212"));
    add_contact(&phone_book, create_contact("Jane Doe", "555-1213"));
    add_contact(&phone_book, create_contact("John Smith", "555-1214"));

    // Print the phone book
    print_phone_book(phone_book);

    // Find a contact in the phone book
    struct contact *contact = find_contact(phone_book, "John Doe");
    if (contact == NULL) {
        printf("Contact not found.\n");
    } else {
        printf("Name: %s\n", contact->name);
        printf("Number: %s\n", contact->number);
    }

    // Free the memory allocated for the phone book
    free_phone_book(phone_book);

    return 0;
}