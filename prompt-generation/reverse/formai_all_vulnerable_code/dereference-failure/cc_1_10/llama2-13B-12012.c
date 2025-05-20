//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// Phone book structure
typedef struct {
    char *name;
    char *phone;
    struct phone_book *next;
} phone_book_t;

// Function to create a new phone book
phone_book_t *new_phone_book() {
    phone_book_t *pb = malloc(sizeof(phone_book_t));
    pb->name = NULL;
    pb->phone = NULL;
    pb->next = NULL;
    return pb;
}

// Function to add a new entry to the phone book
void add_entry(phone_book_t **phone_book, char *name, char *phone) {
    phone_book_t *new_entry = malloc(sizeof(phone_book_t));
    new_entry->name = name;
    new_entry->phone = phone;
    new_entry->next = *phone_book;
    *phone_book = new_entry;
}

// Function to search for a phone number in the phone book
phone_book_t *search_phone(phone_book_t *phone_book, char *phone) {
    phone_book_t *current = phone_book;
    while (current != NULL) {
        if (strcmp(current->phone, phone) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to print the phone book
void print_phone_book(phone_book_t *phone_book) {
    while (phone_book != NULL) {
        printf("%s %s\n", phone_book->name, phone_book->phone);
        phone_book = phone_book->next;
    }
}

int main() {
    phone_book_t *phone_book = new_phone_book();

    // Add some entries to the phone book
    add_entry(&phone_book, "John Doe", "555-1234");
    add_entry(&phone_book, "Jane Doe", "555-5678");
    add_entry(&phone_book, "Bob Smith", "555-9012");

    // Search for a phone number
    phone_book_t *found = search_phone(phone_book, "555-5678");
    if (found != NULL) {
        printf("Found phone number %s\n", found->phone);
    } else {
        printf("Phone number not found\n");
    }

    // Print the phone book
    print_phone_book(phone_book);

    return 0;
}