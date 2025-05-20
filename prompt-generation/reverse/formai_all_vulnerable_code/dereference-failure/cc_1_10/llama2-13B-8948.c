//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define PHONE_BOOK_MAX_ENTRIES 100
#define PHONE_NUMBER_MAX_LENGTH 20

// Structure to store phone book entries
typedef struct {
    char name[50]; // Name of the contact
    char phone_number[PHONE_NUMBER_MAX_LENGTH]; // Phone number of the contact
    bool is_favorite; // Flag to indicate if the contact is a favorite
} phone_book_entry;

// Function to initialize the phone book
void init_phone_book(phone_book_entry** phone_book, int max_entries) {
    int i;

    for (i = 0; i < max_entries; i++) {
        phone_book[i] = malloc(sizeof(phone_book_entry));
        memset(phone_book[i], 0, sizeof(phone_book_entry));
    }
}

// Function to add a new entry to the phone book
void add_entry_to_phone_book(phone_book_entry** phone_book, const char* name, const char* phone_number) {
    int i;

    for (i = 0; i < PHONE_BOOK_MAX_ENTRIES; i++) {
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
    phone_book[i]->is_favorite = false;
}

// Function to search for a specific entry in the phone book
phone_book_entry* search_phone_book(phone_book_entry** phone_book, const char* name) {
    int i;

    for (i = 0; i < PHONE_BOOK_MAX_ENTRIES; i++) {
        if (strcmp(phone_book[i]->name, name) == 0) {
            return phone_book[i];
        }
    }

    return NULL;
}

// Function to mark an entry as a favorite
void mark_entry_as_favorite(phone_book_entry** phone_book, int index) {
    phone_book[index]->is_favorite = true;
}

// Function to check if an entry is a favorite
bool is_entry_a_favorite(phone_book_entry** phone_book, int index) {
    return phone_book[index]->is_favorite;
}

// Function to print the phone book
void print_phone_book(phone_book_entry** phone_book) {
    int i;

    for (i = 0; i < PHONE_BOOK_MAX_ENTRIES; i++) {
        if (phone_book[i]) {
            printf("%d - %s (%s)\n", i, phone_book[i]->name, phone_book[i]->phone_number);
        }
    }
}

int main() {
    phone_book_entry** phone_book = NULL;
    int num_entries = 0;

    // Initialize the phone book
    init_phone_book(&phone_book, PHONE_BOOK_MAX_ENTRIES);

    // Add some entries to the phone book
    add_entry_to_phone_book(phone_book, "John Doe", "555-1234");
    add_entry_to_phone_book(phone_book, "Jane Doe", "555-5678");
    add_entry_to_phone_book(phone_book, "Bob Smith", "555-9012");

    // Search for an entry in the phone book
    phone_book_entry* john = search_phone_book(phone_book, "John Doe");
    if (john) {
        printf("Found John Doe's phone number: %s\n", john->phone_number);
    } else {
        printf("No such entry in the phone book\n");
    }

    // Mark an entry as a favorite
    mark_entry_as_favorite(phone_book, 1);

    // Check if an entry is a favorite
    if (is_entry_a_favorite(phone_book, 1)) {
        printf("Jane Doe is a favorite\n");
    } else {
        printf("Jane Doe is not a favorite\n");
    }

    // Print the phone book
    print_phone_book(phone_book);

    return 0;
}