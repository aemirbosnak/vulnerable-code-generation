//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <assert.h>

#define PHONE_BOOK_SIZE 100
#define NAME_MAX_LENGTH 25
#define PHONE_MAX_LENGTH 20

// Structure to store phone book entries
typedef struct {
    char name[NAME_MAX_LENGTH];
    char phone[PHONE_MAX_LENGTH];
} phone_book_entry;

// Function to initialize phone book
void initialize_phone_book(phone_book_entry** phone_book, int size) {
    for (int i = 0; i < size; i++) {
        phone_book[i] = malloc(sizeof(phone_book_entry));
        memset(phone_book[i]->name, 0, NAME_MAX_LENGTH);
        memset(phone_book[i]->phone, 0, PHONE_MAX_LENGTH);
    }
}

// Function to add a new entry to the phone book
void add_entry_to_phone_book(phone_book_entry** phone_book, const char* name, const char* phone) {
    int i;
    for (i = 0; i < PHONE_BOOK_SIZE; i++) {
        if (strcmp(phone_book[i]->name, name) == 0) {
            // Entry already exists, update the phone number
            strcpy(phone_book[i]->phone, phone);
            return;
        }
    }
    // Entry does not exist, add a new one
    phone_book[i] = malloc(sizeof(phone_book_entry));
    strcpy(phone_book[i]->name, name);
    strcpy(phone_book[i]->phone, phone);
}

// Function to search for an entry in the phone book
phone_book_entry* search_phone_book(phone_book_entry** phone_book, const char* name) {
    int i;
    for (i = 0; i < PHONE_BOOK_SIZE; i++) {
        if (strcmp(phone_book[i]->name, name) == 0) {
            return phone_book[i];
        }
    }
    return NULL;
}

// Function to delete an entry from the phone book
void delete_entry_from_phone_book(phone_book_entry** phone_book, const char* name) {
    int i;
    for (i = 0; i < PHONE_BOOK_SIZE; i++) {
        if (strcmp(phone_book[i]->name, name) == 0) {
            // Found the entry, free the memory
            free(phone_book[i]);
            phone_book[i] = NULL;
            return;
        }
    }
}

int main() {
    phone_book_entry** phone_book = malloc(PHONE_BOOK_SIZE * sizeof(phone_book_entry*));
    initialize_phone_book(phone_book, PHONE_BOOK_SIZE);

    // Add some entries to the phone book
    add_entry_to_phone_book(phone_book, "John Doe", "555-1234");
    add_entry_to_phone_book(phone_book, "Jane Doe", "555-5678");
    add_entry_to_phone_book(phone_book, "Bob Smith", "555-9012");

    // Search for an entry in the phone book
    phone_book_entry* entry = search_phone_book(phone_book, "John Doe");
    if (entry != NULL) {
        printf("Found John Doe's phone number: %s\n", entry->phone);
    } else {
        printf("Could not find John Doe's phone number\n");
    }

    // Delete an entry from the phone book
    delete_entry_from_phone_book(phone_book, "Jane Doe");

    return 0;
}