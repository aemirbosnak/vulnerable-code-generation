//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PHONE_BOOK_SIZE 100
#define MAX_NAME_LENGTH 20
#define MAX_NUMBER_LENGTH 10

// Structure to store phone book entries
typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} phone_book_entry;

// Function to initialize phone book
void init_phone_book(phone_book_entry **phone_book) {
    int i;
    for (i = 0; i < PHONE_BOOK_SIZE; i++) {
        phone_book[i] = malloc(sizeof(phone_book_entry));
        memset(phone_book[i]->name, 0, MAX_NAME_LENGTH);
        memset(phone_book[i]->number, 0, MAX_NUMBER_LENGTH);
    }
}

// Function to add a new entry to the phone book
void add_entry(phone_book_entry **phone_book, char *name, char *number) {
    int i;
    for (i = 0; i < PHONE_BOOK_SIZE; i++) {
        if (strcmp(phone_book[i]->name, name) == 0) {
            // Entry already exists, update the number
            strcpy(phone_book[i]->number, number);
            return;
        }
    }
    // Entry does not exist, add a new one
    phone_book[i] = malloc(sizeof(phone_book_entry));
    strcpy(phone_book[i]->name, name);
    strcpy(phone_book[i]->number, number);
}

// Function to search for an entry in the phone book
phone_book_entry *search_entry(phone_book_entry **phone_book, char *name) {
    int i;
    for (i = 0; i < PHONE_BOOK_SIZE; i++) {
        if (strcmp(phone_book[i]->name, name) == 0) {
            return phone_book[i];
        }
    }
    return NULL;
}

// Function to print the phone book
void print_phone_book(phone_book_entry **phone_book) {
    int i;
    for (i = 0; i < PHONE_BOOK_SIZE; i++) {
        printf("%s %s\n", phone_book[i]->name, phone_book[i]->number);
    }
}

int main() {
    phone_book_entry **phone_book = malloc(sizeof(phone_book_entry *) * PHONE_BOOK_SIZE);
    init_phone_book(phone_book);

    // Add some entries to the phone book
    add_entry(phone_book, "John Doe", "555-1234");
    add_entry(phone_book, "Jane Doe", "555-5678");
    add_entry(phone_book, "Bob Smith", "555-9012");

    // Search for an entry in the phone book
    phone_book_entry *entry = search_entry(phone_book, "Jane Doe");
    if (entry != NULL) {
        printf("Found Jane Doe's number: %s\n", entry->number);
    } else {
        printf("Could not find Jane Doe's number\n");
    }

    // Print the phone book
    print_phone_book(phone_book);

    return 0;
}