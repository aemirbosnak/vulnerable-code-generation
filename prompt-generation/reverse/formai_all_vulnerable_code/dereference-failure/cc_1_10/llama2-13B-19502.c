//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the phone book structure
typedef struct {
    char name[50];    // Name of the contact
    char number[20];   // Phone number of the contact
    int age;         // Age of the contact
    char address[100]; // Address of the contact
} contact_t;

// Define a function to add a new contact
void add_contact(contact_t **phone_book, int *num_contacts, const char *name, const char *number, int age, const char *address) {
    contact_t *new_contact = (contact_t *)malloc(sizeof(contact_t));
    strcpy(new_contact->name, name);
    strcpy(new_contact->number, number);
    new_contact->age = age;
    strcpy(new_contact->address, address);
    *num_contacts += 1;
    phone_book = (contact_t **)realloc(phone_book, sizeof(contact_t *) * *num_contacts);
    phone_book[*num_contacts - 1] = new_contact;
}

// Define a function to search for a contact
int search_contact(contact_t **phone_book, int num_contacts, const char *name) {
    int i;
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(phone_book[i]->name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// Define a function to delete a contact
void delete_contact(contact_t **phone_book, int num_contacts, int index) {
    if (index < num_contacts) {
        free(phone_book[index]);
        memmove(phone_book + index, phone_book + index + 1, sizeof(contact_t *) * (num_contacts - index - 1));
        num_contacts -= 1;
    }
}

// Define the main function
int main() {
    // Create an empty phone book
    contact_t *phone_book[10];
    int num_contacts = 0;

    // Add some contacts
    add_contact(phone_book, &num_contacts, "John Doe", "555-1234", 35, "123 Main St");
    add_contact(phone_book, &num_contacts, "Jane Doe", "555-5678", 27, "456 Elm St");
    add_contact(phone_book, &num_contacts, "Bob Smith", "555-9012", 42, "789 Oak St");

    // Search for a contact
    int index = search_contact(phone_book, num_contacts, "Jane Doe");
    if (index != -1) {
        printf("Found Jane Doe at index %d\n", index);
    } else {
        printf("Not found\n");
    }

    // Delete a contact
    delete_contact(phone_book, num_contacts, 1);

    // Print the phone book
    for (int i = 0; i < num_contacts; i++) {
        printf("%d: %s %s %d %s\n", i, phone_book[i]->name, phone_book[i]->number, phone_book[i]->age, phone_book[i]->address);
    }

    return 0;
}