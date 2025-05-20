//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include <math.h>

// Definition of a phone book entry
typedef struct {
    char name[50];  // Name of the person
    char phone[20]; // Phone number of the person
} phone_entry_t;

// Definition of a phone book
typedef struct {
    int count;      // Number of entries in the phone book
    phone_entry_t entries[100]; // Array of phone book entries
} phone_book_t;

// Function to add a new entry to the phone book
void add_entry(phone_book_t* book, const char* name, const char* phone) {
    int i; // Loop counter

    // Check if the phone book is full
    if (book->count >= 100) {
        printf("Phone book is full, cannot add more entries\n");
        return;
    }

    // Find an empty slot in the phone book
    for (i = 0; i < 100; i++) {
        if (book->entries[i].name[0] == '\0') {
            break;
        }
    }

    // If no empty slot was found, reallocate the phone book
    if (i == 100) {
        phone_book_t* new_book = realloc(book, (i + 1) * sizeof(phone_entry_t));
        assert(new_book != NULL);
        book = new_book;
    }

    // Add the new entry to the phone book
    strcpy(book->entries[i].name, name);
    strcpy(book->entries[i].phone, phone);
    book->count++;
}

// Function to search for a specific entry in the phone book
phone_entry_t* search_entry(phone_book_t* book, const char* name) {
    int i; // Loop counter

    for (i = 0; i < book->count; i++) {
        if (strcmp(book->entries[i].name, name) == 0) {
            return &book->entries[i];
        }
    }

    return NULL;
}

int main() {
    phone_book_t* book = malloc(sizeof(phone_book_t));
    assert(book != NULL);

    // Add some entries to the phone book
    add_entry(book, "John Doe", "555-1234");
    add_entry(book, "Jane Doe", "555-5678");
    add_entry(book, "Bob Smith", "555-9012");

    // Search for an entry in the phone book
    phone_entry_t* entry = search_entry(book, "Jane Doe");
    if (entry != NULL) {
        printf("Found entry for Jane Doe with phone number %s\n", entry->phone);
    } else {
        printf("No entry found for Jane Doe\n");
    }

    return 0;
}