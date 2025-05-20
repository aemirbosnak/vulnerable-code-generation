//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define PHONE_BOOK_SIZE 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_NUMBER_LENGTH 20

// Structure to store phone book entries
typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone_number[MAX_PHONE_NUMBER_LENGTH];
} phone_book_entry;

// Function to initialize phone book
void init_phone_book(phone_book_entry** phone_book, int capacity) {
    int i;

    for (i = 0; i < capacity; i++) {
        phone_book[i] = malloc(sizeof(phone_book_entry));
        memset(phone_book[i]->name, 0, MAX_NAME_LENGTH);
        memset(phone_book[i]->phone_number, 0, MAX_PHONE_NUMBER_LENGTH);
    }
}

// Function to add a new entry to the phone book
void add_entry_to_phone_book(phone_book_entry** phone_book, char* name, char* phone_number) {
    int i;

    for (i = 0; i < PHONE_BOOK_SIZE; i++) {
        if (phone_book[i] == NULL) {
            break;
        }
    }

    if (i == PHONE_BOOK_SIZE) {
        printf("Phone book is full. Cannot add new entry.\n");
        return;
    }

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
            break;
        }
    }
}

int main() {
    phone_book_entry* phone_book;
    int capacity = PHONE_BOOK_SIZE;

    // Initialize phone book
    init_phone_book(&phone_book, capacity);

    // Add some entries to the phone book
    add_entry_to_phone_book(&phone_book, "John Doe", "555-1234");
    add_entry_to_phone_book(&phone_book, "Jane Doe", "555-5678");
    add_entry_to_phone_book(&phone_book, "Bob Smith", "555-9012");

    // Search for an entry in the phone book
    phone_book_entry* entry = search_phone_book(&phone_book, "Jane Doe");
    if (entry != NULL) {
        printf("Found entry for Jane Doe with phone number 555-5678\n");
    } else {
        printf("No entry found for Jane Doe\n");
    }

    // Remove an entry from the phone book
    remove_entry_from_phone_book(&phone_book, "John Doe");

    return 0;
}