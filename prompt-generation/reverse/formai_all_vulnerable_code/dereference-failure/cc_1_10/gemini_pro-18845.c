//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Entry structure
struct phone_entry {
    char name[32];
    char number[16];
};

// Phone book structure
struct phone_book {
    int size;
    struct phone_entry *entries;
};

// Create a new phone book
struct phone_book *create_phone_book(int size) {
    struct phone_book *book = malloc(sizeof(struct phone_book));
    book->size = size;
    book->entries = malloc(sizeof(struct phone_entry) * size);
    return book;
}

// Add an entry to the phone book
void add_entry(struct phone_book *book, char *name, char *number) {
    strcpy(book->entries[book->size].name, name);
    strcpy(book->entries[book->size++].number, number);
}

// Get an entry from the phone book
struct phone_entry *get_entry(struct phone_book *book, char *name) {
    for (int i = 0; i < book->size; i++) {
        if (strcmp(book->entries[i].name, name) == 0) {
            return &book->entries[i];
        }
    }
    return NULL;
}

// Print the phone book
void print_phone_book(struct phone_book *book) {
    for (int i = 0; i < book->size; i++) {
        printf("%s: %s\n", book->entries[i].name, book->entries[i].number);
    }
}

// Free the phone book
void free_phone_book(struct phone_book *book) {
    free(book->entries);
    free(book);
}

// Main function
int main() {
    // Create a new phone book
    struct phone_book *book = create_phone_book(100);

    // Add some entries to the phone book
    add_entry(book, "Alice", "123-456-7890");
    add_entry(book, "Bob", "234-567-8901");
    add_entry(book, "Charlie", "345-678-9012");

    // Get an entry from the phone book
    struct phone_entry *entry = get_entry(book, "Alice");

    // Print the phone book
    print_phone_book(book);

    // Free the phone book
    free_phone_book(book);

    return 0;
}