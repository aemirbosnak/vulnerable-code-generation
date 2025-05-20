//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of contacts
#define MAX_CONTACTS 100

// Define the contact structure
typedef struct {
    char name[50];
    char phone_number[20];
    char email[50];
} contact;

// Define the phone book structure
typedef struct {
    contact contacts[MAX_CONTACTS];
    int num_contacts;
} phone_book;

// Create a new phone book
phone_book* create_phone_book() {
    phone_book* pb = malloc(sizeof(phone_book));
    pb->num_contacts = 0;
    return pb;
}

// Add a new contact to the phone book
void add_contact(phone_book* pb, contact* c) {
    if (pb->num_contacts < MAX_CONTACTS) {
        pb->contacts[pb->num_contacts] = *c;
        pb->num_contacts++;
    }
}

// Search for a contact in the phone book by name
contact* search_contact(phone_book* pb, char* name) {
    for (int i = 0; i < pb->num_contacts; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            return &pb->contacts[i];
        }
    }
    return NULL;
}

// Print the contacts in the phone book
void print_contacts(phone_book* pb) {
    for (int i = 0; i < pb->num_contacts; i++) {
        printf("%s: %s (%s)\n", pb->contacts[i].name, pb->contacts[i].phone_number, pb->contacts[i].email);
    }
}

// Free the memory allocated for the phone book
void free_phone_book(phone_book* pb) {
    free(pb);
}

// Main function
int main() {
    // Create a new phone book
    phone_book* pb = create_phone_book();

    // Add some contacts to the phone book
    contact c1 = {"John Doe", "555-1212", "johndoe@example.com"};
    add_contact(pb, &c1);
    contact c2 = {"Jane Doe", "555-1213", "janedoe@example.com"};
    add_contact(pb, &c2);
    contact c3 = {"John Smith", "555-1214", "johnsmith@example.com"};
    add_contact(pb, &c3);

    // Search for a contact in the phone book
    contact* c = search_contact(pb, "Jane Doe");
    if (c != NULL) {
        printf("Found contact: %s: %s (%s)\n", c->name, c->phone_number, c->email);
    } else {
        printf("Contact not found.\n");
    }

    // Print the contacts in the phone book
    printf("Contacts:\n");
    print_contacts(pb);

    // Free the memory allocated for the phone book
    free_phone_book(pb);

    return 0;
}