//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define PHONE_BOOK_SIZE 100
#define MAX_NAME_LENGTH 20
#define MAX_PHONE_NUMBER_LENGTH 15

// Structure to hold a phone book entry
typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone_number[MAX_PHONE_NUMBER_LENGTH];
} phone_book_entry;

// Function to initialize the phone book
void init_phone_book(phone_book_entry **phone_book, int size) {
    int i;
    for (i = 0; i < size; i++) {
        phone_book[i] = malloc(sizeof(phone_book_entry));
        memset(phone_book[i]->name, 0, MAX_NAME_LENGTH);
        memset(phone_book[i]->phone_number, 0, MAX_PHONE_NUMBER_LENGTH);
    }
}

// Function to add a new entry to the phone book
void add_entry(phone_book_entry **phone_book, char *name, char *phone_number) {
    int i;
    for (i = 0; i < PHONE_BOOK_SIZE; i++) {
        if (strlen(name) < MAX_NAME_LENGTH && strlen(phone_number) < MAX_PHONE_NUMBER_LENGTH) {
            strcpy(phone_book[i]->name, name);
            strcpy(phone_book[i]->phone_number, phone_number);
            break;
        }
    }
}

// Function to search for an entry in the phone book
phone_book_entry *search_entry(phone_book_entry **phone_book, char *name) {
    int i;
    for (i = 0; i < PHONE_BOOK_SIZE; i++) {
        if (strcmp(name, phone_book[i]->name) == 0) {
            return phone_book[i];
        }
    }
    return NULL;
}

// Function to delete an entry from the phone book
void delete_entry(phone_book_entry **phone_book, char *name) {
    int i;
    for (i = 0; i < PHONE_BOOK_SIZE; i++) {
        if (strcmp(name, phone_book[i]->name) == 0) {
            free(phone_book[i]);
            break;
        }
    }
}

int main() {
    phone_book_entry *phone_book = malloc(sizeof(phone_book_entry) * PHONE_BOOK_SIZE);
    init_phone_book(phone_book, PHONE_BOOK_SIZE);

    add_entry(phone_book, "John Doe", "555-1234");
    add_entry(phone_book, "Jane Doe", "555-5678");
    add_entry(phone_book, "Bob Smith", "555-9012");

    // Search for an entry
    phone_book_entry *entry = search_entry(phone_book, "John Doe");
    if (entry != NULL) {
        printf("Found John Doe with phone number 555-1234\n");
    } else {
        printf("No such entry found\n");
    }

    // Delete an entry
    delete_entry(phone_book, "John Doe");

    return 0;
}