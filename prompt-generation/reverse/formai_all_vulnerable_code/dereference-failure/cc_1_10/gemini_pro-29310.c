//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a contact
typedef struct contact {
    char name[50];
    char number[20];
} contact;

// Function to create a new contact
contact* create_contact(char* name, char* number) {
    contact* new_contact = (contact*)malloc(sizeof(contact));
    strcpy(new_contact->name, name);
    strcpy(new_contact->number, number);
    return new_contact;
}

// Function to add a contact to the phone book
void add_contact(contact** phone_book, int* num_contacts, char* name, char* number) {
    phone_book[*num_contacts] = create_contact(name, number);
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
    printf("Phone Book:\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("%s: %s\n", phone_book[i]->name, phone_book[i]->number);
    }
}

// Function to free the memory allocated for the phone book
void free_phone_book(contact** phone_book, int num_contacts) {
    for (int i = 0; i < num_contacts; i++) {
        free(phone_book[i]);
    }
    free(phone_book);
}

int main() {
    int num_contacts = 0;
    contact** phone_book = (contact**)malloc(sizeof(contact*) * 100);

    // Add some contacts to the phone book
    add_contact(phone_book, &num_contacts, "John Doe", "555-1234");
    add_contact(phone_book, &num_contacts, "Jane Doe", "555-5678");
    add_contact(phone_book, &num_contacts, "Peter Parker", "555-9876");

    // Search for a contact in the phone book
    contact* contact = search_contact(phone_book, num_contacts, "Peter Parker");

    // Print the contact's information
    if (contact != NULL) {
        printf("Contact found:\n");
        printf("Name: %s\n", contact->name);
        printf("Number: %s\n", contact->number);
    } else {
        printf("Contact not found.\n");
    }

    // Print the phone book
    printf("\n");
    print_phone_book(phone_book, num_contacts);

    // Free the memory allocated for the phone book
    free_phone_book(phone_book, num_contacts);

    return 0;
}