//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: secure
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_NUMBER_LENGTH 20
#define MAX_ENTRIES 100

// Structure to store a single phone book entry
typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone_number[MAX_PHONE_NUMBER_LENGTH];
} phone_book_entry;

// Function to initialize the phone book
void init_phone_book(phone_book_entry** phone_book, int max_entries) {
    int i;
    for (i = 0; i < max_entries; i++) {
        phone_book[i] = malloc(sizeof(phone_book_entry));
        memset(phone_book[i]->name, 0, MAX_NAME_LENGTH);
        memset(phone_book[i]->phone_number, 0, MAX_PHONE_NUMBER_LENGTH);
    }
}

// Function to add a new entry to the phone book
void add_entry(phone_book_entry** phone_book, char* name, char* phone_number) {
    int i;
    for (i = 0; i < MAX_ENTRIES; i++) {
        if (phone_book[i] == NULL) {
            break;
        }
    }
    if (i == MAX_ENTRIES) {
        // Phone book is full, return error
        return;
    }
    strcpy(phone_book[i]->name, name);
    strcpy(phone_book[i]->phone_number, phone_number);
}

// Function to search for an entry in the phone book
phone_book_entry* search_entry(phone_book_entry** phone_book, char* name) {
    int i;
    for (i = 0; i < MAX_ENTRIES; i++) {
        if (strcmp(phone_book[i]->name, name) == 0) {
            return phone_book[i];
        }
    }
    return NULL;
}

// Function to remove an entry from the phone book
void remove_entry(phone_book_entry** phone_book, char* name) {
    int i;
    for (i = 0; i < MAX_ENTRIES; i++) {
        if (strcmp(phone_book[i]->name, name) == 0) {
            free(phone_book[i]);
            phone_book[i] = NULL;
            break;
        }
    }
}

int main() {
    phone_book_entry** phone_book = NULL;
    init_phone_book(&phone_book, MAX_ENTRIES);

    // Add some entries to the phone book
    add_entry(&phone_book, "John Doe", "555-1234");
    add_entry(&phone_book, "Jane Doe", "555-5678");
    add_entry(&phone_book, "Bob Smith", "555-9012");

    // Search for an entry in the phone book
    phone_book_entry* entry = search_entry(&phone_book, "Jane Doe");
    if (entry == NULL) {
        printf("Error: Could not find Jane Doe in the phone book\n");
        return 1;
    }
    printf("Found Jane Doe with phone number 555-5678\n");

    // Remove an entry from the phone book
    remove_entry(&phone_book, "Jane Doe");

    // Print the remaining entries in the phone book
    for (int i = 0; i < MAX_ENTRIES; i++) {
        if (phone_book[i] != NULL) {
            printf("%d: %s %s\n", i, phone_book[i]->name, phone_book[i]->phone_number);
        }
    }

    return 0;
}