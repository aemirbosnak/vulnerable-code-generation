//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The maximum number of contacts allowed in the phone book
#define MAX_CONTACTS 50

// The maximum length of a name or phone number
#define MAX_NAME_LENGTH 32

// A contact in the phone book
typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone_number[MAX_NAME_LENGTH];
} contact;

// The phone book
contact phone_book[MAX_CONTACTS];

// The number of contacts in the phone book
int num_contacts = 0;

// Add a new contact to the phone book
void add_contact(char *name, char *phone_number) {
    // Check if the phone book is full
    if (num_contacts == MAX_CONTACTS) {
        printf("The phone book is full. Cannot add new contact.\n");
        return;
    }

    // Copy the name and phone number into the new contact
    strcpy(phone_book[num_contacts].name, name);
    strcpy(phone_book[num_contacts].phone_number, phone_number);

    // Increment the number of contacts
    num_contacts++;
}

// Search for a contact in the phone book by name
contact *search_contact_by_name(char *name) {
    // Iterate over the contacts
    for (int i = 0; i < num_contacts; i++) {
        // Check if the name matches the search term
        if (strcmp(phone_book[i].name, name) == 0) {
            // Return the contact if it is found
            return &phone_book[i];
        }
    }

    // Return NULL if the contact is not found
    return NULL;
}

// Search for a contact in the phone book by phone number
contact *search_contact_by_phone_number(char *phone_number) {
    // Iterate over the contacts
    for (int i = 0; i < num_contacts; i++) {
        // Check if the phone number matches the search term
        if (strcmp(phone_book[i].phone_number, phone_number) == 0) {
            // Return the contact if it is found
            return &phone_book[i];
        }
    }

    // Return NULL if the contact is not found
    return NULL;
}

// Print all the contacts in the phone book
void print_phone_book() {
    // Iterate over the contacts
    for (int i = 0; i < num_contacts; i++) {
        // Print the contact's name and phone number
        printf("%s: %s\n", phone_book[i].name, phone_book[i].phone_number);
    }
}

// Get the user's input
char *get_user_input(char *prompt) {
    // Allocate memory for the user's input
    char *input = malloc(MAX_NAME_LENGTH * sizeof(char));

    // Prompt the user for input
    printf("%s: ", prompt);

    // Read the user's input
    scanf("%s", input);

    // Return the user's input
    return input;
}

// Main function
int main() {
    // Add some contacts to the phone book
    add_contact("John Doe", "555-1212");
    add_contact("Jane Doe", "555-1213");
    add_contact("Bill Smith", "555-1214");
    add_contact("Mary Johnson", "555-1215");
    add_contact("Tom Jones", "555-1216");

    // Print the phone book
    print_phone_book();

    // Get the user's input
    char *name = get_user_input("Enter a name to search for:");
    char *phone_number = get_user_input("Enter a phone number to search for:");

    // Search for the contact by name
    contact *contact_by_name = search_contact_by_name(name);

    // Search for the contact by phone number
    contact *contact_by_phone_number = search_contact_by_phone_number(phone_number);

    // Check if the user entered a valid name
    if (!contact_by_name) {
        printf("No contact found with the name '%s'.\n", name);
    } else {
        // Print the contact's name and phone number
        printf("Contact found: %s: %s\n", contact_by_name->name, contact_by_name->phone_number);
    }

    // Check if the user entered a valid phone number
    if (!contact_by_phone_number) {
        printf("No contact found with the phone number '%s'.\n", phone_number);
    } else {
        // Print the contact's name and phone number
        printf("Contact found: %s: %s\n", contact_by_phone_number->name, contact_by_phone_number->phone_number);
    }

    // Free the memory allocated for the user's input
    free(name);
    free(phone_number);

    return 0;
}