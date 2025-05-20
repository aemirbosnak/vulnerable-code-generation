//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PHONE_BOOK_SIZE 100
#define MAX_NAME_LENGTH 25
#define MAX_PHONE_NUMBER_LENGTH 15

// Structure to store a phone book entry
typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone_number[MAX_PHONE_NUMBER_LENGTH];
} phone_book_entry;

// Function to initialize the phone book
void initialize_phone_book(phone_book_entry** phone_book, int size) {
    int i;
    for (i = 0; i < size; i++) {
        phone_book[i] = malloc(sizeof(phone_book_entry));
        memset(phone_book[i], 0, sizeof(phone_book_entry));
    }
}

// Function to add a new entry to the phone book
void add_entry_to_phone_book(phone_book_entry** phone_book, char* name, char* phone_number) {
    int i;
    for (i = 0; i < PHONE_BOOK_SIZE; i++) {
        if (strcmp(phone_book[i]->name, name) == 0) {
            // Entry already exists, update the phone number
            strcpy(phone_book[i]->phone_number, phone_number);
            return;
        }
    }
    // Entry does not exist, add a new one
    phone_book[i] = malloc(sizeof(phone_book_entry));
    strcpy(phone_book[i]->name, name);
    strcpy(phone_book[i]->phone_number, phone_number);
}

// Function to search for an entry in the phone book
phone_book_entry* search_phone_book(phone_book_entry** phone_book, char* name) {
    int i;
    for (i = 0; i < PHONE_BOOK_SIZE; i++) {
        if (strcmp(phone_book[i]->name, name) == 0) {
            return phone_book[i];
        }
    }
    return NULL;
}

// Function to remove an entry from the phone book
void remove_entry_from_phone_book(phone_book_entry** phone_book, char* name) {
    int i;
    for (i = 0; i < PHONE_BOOK_SIZE; i++) {
        if (strcmp(phone_book[i]->name, name) == 0) {
            free(phone_book[i]);
            phone_book[i] = NULL;
            return;
        }
    }
}

int main() {
    // Initialize the phone book
    phone_book_entry** phone_book = malloc(sizeof(phone_book_entry*) * PHONE_BOOK_SIZE);
    initialize_phone_book(phone_book, PHONE_BOOK_SIZE);

    // Add some entries to the phone book
    add_entry_to_phone_book(phone_book, "John Doe", "555-1234");
    add_entry_to_phone_book(phone_book, "Jane Doe", "555-5678");
    add_entry_to_phone_book(phone_book, "Bob Smith", "555-9012");

    // Search for an entry in the phone book
    phone_book_entry* entry = search_phone_book(phone_book, "John Doe");
    if (entry != NULL) {
        printf("Found entry for John Doe with phone number 555-1234\n");
    } else {
        printf("No entry found for John Doe\n");
    }

    // Remove an entry from the phone book
    remove_entry_from_phone_book(phone_book, "Jane Doe");

    // Free the phone book memory
    free(phone_book);

    return 0;
}