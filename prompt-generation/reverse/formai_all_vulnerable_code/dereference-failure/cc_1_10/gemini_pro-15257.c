//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a single contact
typedef struct contact {
    char name[50];
    char phone_number[20];
} contact;

// Structure to store the phone book
typedef struct phone_book {
    int num_contacts;
    contact *contacts;
} phone_book;

// Function to create a new phone book
phone_book *create_phone_book() {
    phone_book *pb = malloc(sizeof(phone_book));
    pb->num_contacts = 0;
    pb->contacts = NULL;
    return pb;
}

// Function to add a new contact to the phone book
void add_contact(phone_book *pb, char *name, char *phone_number) {
    pb->contacts = realloc(pb->contacts, (pb->num_contacts + 1) * sizeof(contact));
    strcpy(pb->contacts[pb->num_contacts].name, name);
    strcpy(pb->contacts[pb->num_contacts].phone_number, phone_number);
    pb->num_contacts++;
}

// Function to search for a contact in the phone book
contact *search_contact(phone_book *pb, char *name) {
    for (int i = 0; i < pb->num_contacts; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            return &pb->contacts[i];
        }
    }
    return NULL;
}

// Function to print the phone book
void print_phone_book(phone_book *pb) {
    for (int i = 0; i < pb->num_contacts; i++) {
        printf("%s: %s\n", pb->contacts[i].name, pb->contacts[i].phone_number);
    }
}

// Function to free the memory allocated for the phone book
void free_phone_book(phone_book *pb) {
    free(pb->contacts);
    free(pb);
}

// Main function
int main() {
    // Create a new phone book
    phone_book *pb = create_phone_book();

    // Add some contacts to the phone book
    add_contact(pb, "John Doe", "555-123-4567");
    add_contact(pb, "Jane Doe", "555-234-5678");
    add_contact(pb, "Bob Smith", "555-345-6789");

    // Print the phone book
    print_phone_book(pb);

    // Search for a contact in the phone book
    contact *contact = search_contact(pb, "John Doe");

    // Print the contact information
    printf("Name: %s\nPhone number: %s\n", contact->name, contact->phone_number);

    // Free the memory allocated for the phone book
    free_phone_book(pb);

    return 0;
}