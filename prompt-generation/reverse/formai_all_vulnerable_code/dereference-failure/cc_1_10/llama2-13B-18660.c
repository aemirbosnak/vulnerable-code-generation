//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PHONE_BOOK_SIZE 100

// Structure to store phone book entries
struct phone_entry {
    char name[50];
    char number[20];
};

// Function to insert a new entry into the phone book
void insert_entry(struct phone_entry *phone_book, int size, char *name, char *number) {
    int i;

    // Check if the phone book is full
    if (size == PHONE_BOOK_SIZE) {
        printf("Phone book is full! cannot insert new entry\n");
        return;
    }

    // Find an empty slot in the phone book
    for (i = 0; i < size; i++) {
        if (phone_book[i].name[0] == '\0') {
            break;
        }
    }

    // If no empty slot found, reallocate the phone book
    if (i == size) {
        int new_size = size * 2;
        struct phone_entry *new_phone_book = realloc(phone_book, new_size * sizeof(struct phone_entry));
        if (new_phone_book == NULL) {
            printf("Failed to reallocate phone book\n");
            return;
        }
        phone_book = new_phone_book;
        size = new_size;
    }

    // Insert the new entry
    strcpy(phone_book[i].name, name);
    strcpy(phone_book[i].number, number);
}

// Function to search for a phone number in the phone book
struct phone_entry *search_entry(struct phone_entry *phone_book, int size, char *number) {
    int i;

    for (i = 0; i < size; i++) {
        if (strcmp(phone_book[i].number, number) == 0) {
            return &phone_book[i];
        }
    }

    return NULL;
}

// Function to delete a phone number from the phone book
void delete_entry(struct phone_entry *phone_book, int size, char *number) {
    int i;

    for (i = 0; i < size; i++) {
        if (strcmp(phone_book[i].number, number) == 0) {
            // Found the entry to be deleted
            memset(phone_book[i].name, 0, 50);
            memset(phone_book[i].number, 0, 20);
            break;
        }
    }
}

int main() {
    struct phone_entry phone_book[PHONE_BOOK_SIZE];
    int size = 0;

    // Insert some test entries
    insert_entry(phone_book, size, "John Doe", "555-1234");
    insert_entry(phone_book, size, "Jane Doe", "555-5678");
    insert_entry(phone_book, size, "Bob Smith", "555-9012");

    // Search for a phone number
    struct phone_entry *entry = search_entry(phone_book, size, "555-5678");
    if (entry != NULL) {
        printf("Found phone number %s\n", entry->number);
    } else {
        printf("Phone number not found\n");
    }

    // Delete a phone number
    delete_entry(phone_book, size, "555-5678");

    return 0;
}