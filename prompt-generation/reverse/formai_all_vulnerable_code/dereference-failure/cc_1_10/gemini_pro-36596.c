//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the contact structure
typedef struct contact {
    char name[50];
    char number[20];
    char email[50];
} contact;

// Define the phone book structure
typedef struct phone_book {
    int num_contacts;
    contact *contacts;
} phone_book;

// Create a new phone book
phone_book *create_phone_book() {
    phone_book *pb = malloc(sizeof(phone_book));
    pb->num_contacts = 0;
    pb->contacts = NULL;
    return pb;
}

// Add a contact to the phone book
void add_contact(phone_book *pb, char *name, char *number, char *email) {
    // Reallocate memory for the contacts array if necessary
    if (pb->num_contacts == 0) {
        pb->contacts = malloc(sizeof(contact));
    } else {
        pb->contacts = realloc(pb->contacts, (pb->num_contacts + 1) * sizeof(contact));
    }

    // Add the new contact to the array
    strcpy(pb->contacts[pb->num_contacts].name, name);
    strcpy(pb->contacts[pb->num_contacts].number, number);
    strcpy(pb->contacts[pb->num_contacts].email, email);

    // Increment the number of contacts
    pb->num_contacts++;
}

// Find a contact in the phone book
contact *find_contact(phone_book *pb, char *name) {
    for (int i = 0; i < pb->num_contacts; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            return &pb->contacts[i];
        }
    }

    return NULL;
}

// Print the phone book
void print_phone_book(phone_book *pb) {
    for (int i = 0; i < pb->num_contacts; i++) {
        printf("%s\n", pb->contacts[i].name);
        printf("%s\n", pb->contacts[i].number);
        printf("%s\n\n", pb->contacts[i].email);
    }
}

// Free the memory allocated for the phone book
void free_phone_book(phone_book *pb) {
    free(pb->contacts);
    free(pb);
}

// Main function
int main() {
    // Create a new phone book
    phone_book *pb = create_phone_book();

    // Add some contacts to the phone book
    add_contact(pb, "John Doe", "555-1212", "john.doe@example.com");
    add_contact(pb, "Jane Doe", "555-1213", "jane.doe@example.com");
    add_contact(pb, "John Smith", "555-1214", "john.smith@example.com");

    // Print the phone book
    printf("Phone Book:\n");
    print_phone_book(pb);

    // Find a contact in the phone book
    contact *contact = find_contact(pb, "Jane Doe");

    // Print the contact's information
    printf("Contact Information:\n");
    printf("Name: %s\n", contact->name);
    printf("Number: %s\n", contact->number);
    printf("Email: %s\n", contact->email);

    // Free the memory allocated for the phone book
    free_phone_book(pb);

    return 0;
}