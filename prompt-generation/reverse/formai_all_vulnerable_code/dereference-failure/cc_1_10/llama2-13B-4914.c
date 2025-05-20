//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PHONE_BOOK_SIZE 100

// Structure to store phone book entries
typedef struct phone_book_entry {
    char name[50];
    char number[20];
} phone_book_entry;

// Function to initialize the phone book
void init_phone_book(phone_book_entry** phone_book) {
    int i;
    for (i = 0; i < PHONE_BOOK_SIZE; i++) {
        phone_book[i] = malloc(sizeof(phone_book_entry));
        memset(phone_book[i]->name, 0, 50);
        memset(phone_book[i]->number, 0, 20);
    }
}

// Function to add a new entry to the phone book
void add_entry(phone_book_entry** phone_book, const char* name, const char* number) {
    int i;
    for (i = 0; i < PHONE_BOOK_SIZE; i++) {
        if (strcmp(phone_book[i]->name, name) == 0) {
            // Entry already exists, update the number
            strcpy(phone_book[i]->number, number);
            return;
        }
    }
    // Entry does not exist, allocate a new slot
    phone_book[i] = malloc(sizeof(phone_book_entry));
    strcpy(phone_book[i]->name, name);
    strcpy(phone_book[i]->number, number);
}

// Function to search for an entry in the phone book
phone_book_entry* search_entry(phone_book_entry** phone_book, const char* name) {
    int i;
    for (i = 0; i < PHONE_BOOK_SIZE; i++) {
        if (strcmp(phone_book[i]->name, name) == 0) {
            return phone_book[i];
        }
    }
    return NULL;
}

// Function to remove an entry from the phone book
void remove_entry(phone_book_entry** phone_book, const char* name) {
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
    phone_book_entry** phone_book = malloc(sizeof(phone_book_entry*) * PHONE_BOOK_SIZE);
    init_phone_book(phone_book);

    // Add some entries to the phone book
    add_entry(phone_book, "John Doe", "555-1234");
    add_entry(phone_book, "Jane Doe", "555-5678");
    add_entry(phone_book, "Bob Smith", "555-9012");

    // Search for an entry in the phone book
    phone_book_entry* entry = search_entry(phone_book, "John Doe");
    if (entry != NULL) {
        printf("Found entry for John Doe with number 555-1234\n");
    } else {
        printf("No entry found for John Doe\n");
    }

    // Remove an entry from the phone book
    remove_entry(phone_book, "Jane Doe");

    // Print the remaining entries in the phone book
    for (int i = 0; i < PHONE_BOOK_SIZE; i++) {
        if (phone_book[i] != NULL) {
            printf("%d: %s %s\n", i, phone_book[i]->name, phone_book[i]->number);
        }
    }

    return 0;
}