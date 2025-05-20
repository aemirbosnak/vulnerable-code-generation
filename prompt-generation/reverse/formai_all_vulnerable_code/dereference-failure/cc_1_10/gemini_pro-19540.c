//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of contacts in the phone book
#define MAX_CONTACTS 100

// Define the structure of a contact
typedef struct contact {
    char *name;
    char *number;
} contact;

// Define the phone book as an array of contacts
contact phone_book[MAX_CONTACTS];

// Initialize the phone book with some sample data
void initialize_phone_book() {
    strcpy(phone_book[0].name, "John Doe");
    strcpy(phone_book[0].number, "555-1212");
    strcpy(phone_book[1].name, "Jane Smith");
    strcpy(phone_book[1].number, "555-1213");
    strcpy(phone_book[2].name, "Bill Jones");
    strcpy(phone_book[2].number, "555-1214");
}

// Print the phone book
void print_phone_book() {
    for (int i = 0; i < MAX_CONTACTS; i++) {
        if (phone_book[i].name != NULL) {
            printf("%s: %s\n", phone_book[i].name, phone_book[i].number);
        }
    }
}

// Add a contact to the phone book
void add_contact(char *name, char *number) {
    for (int i = 0; i < MAX_CONTACTS; i++) {
        if (phone_book[i].name == NULL) {
            phone_book[i].name = malloc(strlen(name) + 1);
            strcpy(phone_book[i].name, name);
            phone_book[i].number = malloc(strlen(number) + 1);
            strcpy(phone_book[i].number, number);
            return;
        }
    }
    printf("Phone book is full.\n");
}

// Delete a contact from the phone book
void delete_contact(char *name) {
    for (int i = 0; i < MAX_CONTACTS; i++) {
        if (phone_book[i].name != NULL && strcmp(phone_book[i].name, name) == 0) {
            free(phone_book[i].name);
            free(phone_book[i].number);
            phone_book[i].name = NULL;
            phone_book[i].number = NULL;
            return;
        }
    }
    printf("Contact not found.\n");
}

// Search for a contact in the phone book
char *search_contact(char *name) {
    for (int i = 0; i < MAX_CONTACTS; i++) {
        if (phone_book[i].name != NULL && strcmp(phone_book[i].name, name) == 0) {
            return phone_book[i].number;
        }
    }
    return NULL;
}

// Main function
int main() {
    // Initialize the phone book
    initialize_phone_book();

    // Print the phone book
    printf("Phone Book:\n");
    print_phone_book();

    // Add a contact
    add_contact("Bob Smith", "555-1215");

    // Print the phone book
    printf("Phone Book (after adding Bob Smith):\n");
    print_phone_book();

    // Delete a contact
    delete_contact("Jane Smith");

    // Print the phone book
    printf("Phone Book (after deleting Jane Smith):\n");
    print_phone_book();

    // Search for a contact
    char *number = search_contact("Bob Smith");
    if (number != NULL) {
        printf("Bob Smith's number: %s\n", number);
    } else {
        printf("Contact not found.\n");
    }

    return 0;
}