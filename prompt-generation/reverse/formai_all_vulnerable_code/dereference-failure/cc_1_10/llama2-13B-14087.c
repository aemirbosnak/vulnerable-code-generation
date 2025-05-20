//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PHONE_BOOK_SIZE 100
#define MAX_NAME_LENGTH 20
#define MAX_PHONE_NUMBER_LENGTH 15

// Structure to store phone book entries
typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone_number[MAX_PHONE_NUMBER_LENGTH];
} phone_book_entry;

// Function to initialize the phone book
void initialize_phone_book(phone_book_entry** phone_book, int size) {
    int i;
    for (i = 0; i < size; i++) {
        phone_book[i] = (phone_book_entry*) malloc(sizeof(phone_book_entry));
        memset(phone_book[i]->name, 0, MAX_NAME_LENGTH);
        memset(phone_book[i]->phone_number, 0, MAX_PHONE_NUMBER_LENGTH);
    }
}

// Function to add a new entry to the phone book
void add_entry_to_phone_book(phone_book_entry** phone_book, char* name, char* phone_number) {
    int i;
    for (i = 0; i < PHONE_BOOK_SIZE; i++) {
        if (strcmp(phone_book[i]->name, name) == 0) {
            // Entry already exists, update the phone number
            strcpy(phone_book[i]->phone_number, phone_number);
            return;
        }
    }
    // Entry does not exist, add a new one
    phone_book[i] = (phone_book_entry*) malloc(sizeof(phone_book_entry));
    strcpy(phone_book[i]->name, name);
    strcpy(phone_book[i]->phone_number, phone_number);
}

// Function to search the phone book for a specific name
phone_book_entry* search_phone_book(phone_book_entry** phone_book, char* name) {
    int i;
    for (i = 0; i < PHONE_BOOK_SIZE; i++) {
        if (strcmp(phone_book[i]->name, name) == 0) {
            return phone_book[i];
        }
    }
    return NULL;
}

// Function to print the phone book
void print_phone_book(phone_book_entry** phone_book) {
    int i;
    for (i = 0; i < PHONE_BOOK_SIZE; i++) {
        printf("%s %s\n", phone_book[i]->name, phone_book[i]->phone_number);
    }
}

int main() {
    phone_book_entry** phone_book = (phone_book_entry**) malloc(sizeof(phone_book_entry*) * PHONE_BOOK_SIZE);
    initialize_phone_book(phone_book, PHONE_BOOK_SIZE);

    // Add some entries to the phone book
    add_entry_to_phone_book(phone_book, "John Doe", "555-1234");
    add_entry_to_phone_book(phone_book, "Jane Doe", "555-5678");
    add_entry_to_phone_book(phone_book, "Bob Smith", "555-9012");

    // Search the phone book for a specific name
    phone_book_entry* john = search_phone_book(phone_book, "John Doe");
    if (john != NULL) {
        printf("John Doe's phone number is %s\n", john->phone_number);
    } else {
        printf("No such name in the phone book\n");
    }

    // Print the entire phone book
    print_phone_book(phone_book);

    return 0;
}