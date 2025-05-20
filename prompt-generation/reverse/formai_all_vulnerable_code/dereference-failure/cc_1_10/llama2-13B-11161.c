//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PHONE_BOOK_SIZE 100
#define PHONE_NUMBER_LENGTH 10
#define NAME_LENGTH 20

// Structure to store phone book entries
typedef struct {
    char name[NAME_LENGTH];
    char phone_number[PHONE_NUMBER_LENGTH];
} phone_book_entry;

// Function to initialize the phone book
void initialize_phone_book(phone_book_entry** phone_book, int size) {
    for (int i = 0; i < size; i++) {
        phone_book[i] = malloc(sizeof(phone_book_entry));
        memset(phone_book[i]->name, 0, NAME_LENGTH);
        memset(phone_book[i]->phone_number, 0, PHONE_NUMBER_LENGTH);
    }
}

// Function to add a new entry to the phone book
void add_entry_to_phone_book(phone_book_entry** phone_book, char* name, char* phone_number) {
    int i;
    for (i = 0; i < PHONE_BOOK_SIZE; i++) {
        if (strlen(phone_book[i]->name) == 0) {
            strcpy(phone_book[i]->name, name);
            strcpy(phone_book[i]->phone_number, phone_number);
            break;
        }
    }
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

// Function to delete an entry from the phone book
void delete_entry_from_phone_book(phone_book_entry** phone_book, char* name) {
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
    phone_book_entry** phone_book = malloc(sizeof(phone_book_entry*) * PHONE_BOOK_SIZE);
    initialize_phone_book(phone_book, PHONE_BOOK_SIZE);

    // Add some entries to the phone book
    add_entry_to_phone_book(phone_book, "John Doe", "555-1234");
    add_entry_to_phone_book(phone_book, "Jane Smith", "555-5678");
    add_entry_to_phone_book(phone_book, "Bob Johnson", "555-9012");

    // Search for an entry in the phone book
    phone_book_entry* john = search_phone_book(phone_book, "John Doe");
    if (john != NULL) {
        printf("Found John Doe with phone number 555-1234\n");
    } else {
        printf("Did not find John Doe in the phone book\n");
    }

    // Delete an entry from the phone book
    delete_entry_from_phone_book(phone_book, "Jane Smith");

    // Free the phone book memory
    free(phone_book);

    return 0;
}