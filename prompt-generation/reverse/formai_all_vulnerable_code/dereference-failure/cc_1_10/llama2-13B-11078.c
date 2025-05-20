//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: invasive
// Invasive Phone Book Program

// This program will invade your privacy and steal your contacts! 😱
// Don't say I didn't warn you...

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define PHONE_BOOK_MAX_NAME_LENGTH 50
#define PHONE_BOOK_MAX_PHONE_NUMBER_LENGTH 20

// Global variables
struct phone_book {
    char name[PHONE_BOOK_MAX_NAME_LENGTH];
    char phone_number[PHONE_BOOK_MAX_PHONE_NUMBER_LENGTH];
};

// Function declarations
void initialize_phone_book(struct phone_book*);
void add_contact(struct phone_book*, const char*, const char*);
void remove_contact(struct phone_book*, const char*);
void print_phone_book(struct phone_book*);

// Program starts here! 💥

int main() {
    // Create a phone book
    struct phone_book phone_book;
    initialize_phone_book(&phone_book);

    // Add some contacts
    add_contact(&phone_book, "John Doe", "555-1234");
    add_contact(&phone_book, "Jane Smith", "555-5678");
    add_contact(&phone_book, "Bob Johnson", "555-9012");

    // Remove some contacts
    remove_contact(&phone_book, "Jane Smith");
    remove_contact(&phone_book, "Bob Johnson");

    // Print the phone book
    print_phone_book(&phone_book);

    return 0;
}

// Functions

void initialize_phone_book(struct phone_book* phone_book) {
    // Initialize the phone book with some default values
    strcpy(phone_book->name, "Default Name");
    strcpy(phone_book->phone_number, "Default Phone Number");
}

void add_contact(struct phone_book* phone_book, const char* name, const char* phone_number) {
    // Add a new contact to the phone book
    strcpy(phone_book->name, name);
    strcpy(phone_book->phone_number, phone_number);
}

void remove_contact(struct phone_book* phone_book, const char* name) {
    // Remove a contact from the phone book
    if (strcmp(phone_book->name, name) == 0) {
        // If the name matches, clear the name and phone number fields
        memset(phone_book->name, 0, PHONE_BOOK_MAX_NAME_LENGTH);
        memset(phone_book->phone_number, 0, PHONE_BOOK_MAX_PHONE_NUMBER_LENGTH);
    }
}

void print_phone_book(struct phone_book* phone_book) {
    // Print the phone book
    printf("Phone Book:\n");
    printf("Name: %s\n", phone_book->name);
    printf("Phone Number: %s\n", phone_book->phone_number);
}