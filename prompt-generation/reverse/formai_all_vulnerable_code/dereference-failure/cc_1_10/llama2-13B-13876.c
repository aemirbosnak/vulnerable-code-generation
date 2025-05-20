//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define PHONE_BOOK_SIZE 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_NUMBER_LENGTH 20

// Structure to store a phone book entry
typedef struct {
    char name[MAX_NAME_LENGTH];
    char phoneNumber[MAX_PHONE_NUMBER_LENGTH];
} phone_book_entry_t;

// Function to initialize the phone book
void init_phone_book(phone_book_entry_t** phone_book) {
    int i;
    for (i = 0; i < PHONE_BOOK_SIZE; i++) {
        phone_book[i] = malloc(sizeof(phone_book_entry_t));
        memset(phone_book[i]->name, 0, MAX_NAME_LENGTH);
        memset(phone_book[i]->phoneNumber, 0, MAX_PHONE_NUMBER_LENGTH);
    }
}

// Function to add a new entry to the phone book
void add_entry(phone_book_entry_t** phone_book, const char* name, const char* phoneNumber) {
    int i;
    for (i = 0; i < PHONE_BOOK_SIZE; i++) {
        if (strcmp(phone_book[i]->name, name) == 0) {
            // Entry already exists, do nothing
            return;
        }
    }
    // Entry does not exist, add it
    strcpy(phone_book[i]->name, name);
    strcpy(phone_book[i]->phoneNumber, phoneNumber);
}

// Function to search for an entry in the phone book
phone_book_entry_t* search_entry(phone_book_entry_t** phone_book, const char* name) {
    int i;
    for (i = 0; i < PHONE_BOOK_SIZE; i++) {
        if (strcmp(phone_book[i]->name, name) == 0) {
            return phone_book[i];
        }
    }
    return NULL;
}

// Function to delete an entry from the phone book
void delete_entry(phone_book_entry_t** phone_book, const char* name) {
    int i;
    for (i = 0; i < PHONE_BOOK_SIZE; i++) {
        if (strcmp(phone_book[i]->name, name) == 0) {
            // Found the entry, delete it
            free(phone_book[i]);
            phone_book[i] = NULL;
            break;
        }
    }
}

int main() {
    // Initialize the phone book
    phone_book_entry_t** phone_book = malloc(sizeof(phone_book_entry_t*) * PHONE_BOOK_SIZE);
    init_phone_book(phone_book);

    // Add some entries to the phone book
    add_entry(phone_book, "John Doe", "555-1234");
    add_entry(phone_book, "Jane Doe", "555-5678");
    add_entry(phone_book, "Bob Smith", "555-9012");

    // Search for an entry in the phone book
    phone_book_entry_t* entry = search_entry(phone_book, "Jane Doe");
    if (entry != NULL) {
        printf("Found Jane Doe's phone number: %s\n", entry->phoneNumber);
    } else {
        printf("No such entry in the phone book\n");
    }

    // Delete an entry from the phone book
    delete_entry(phone_book, "John Doe");

    // Print the remaining entries in the phone book
    for (int i = 0; i < PHONE_BOOK_SIZE; i++) {
        if (phone_book[i] != NULL) {
            printf("%d: %s %s\n", i, phone_book[i]->name, phone_book[i]->phoneNumber);
        }
    }

    return 0;
}