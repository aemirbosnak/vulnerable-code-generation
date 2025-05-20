//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a phone book entry
struct phone_book_entry {
    char *name;
    char *number;
};

// Create a new phone book entry
struct phone_book_entry *create_phone_book_entry(char *name, char *number) {
    struct phone_book_entry *entry = malloc(sizeof(struct phone_book_entry));
    entry->name = strdup(name);
    entry->number = strdup(number);
    return entry;
}

// Free a phone book entry
void free_phone_book_entry(struct phone_book_entry *entry) {
    free(entry->name);
    free(entry->number);
    free(entry);
}

// Add a phone book entry to a phone book
void add_phone_book_entry(struct phone_book_entry **phone_book, int *size, char *name, char *number) {
    *phone_book = realloc(*phone_book, (*size + 1) * sizeof(struct phone_book_entry));
    (*phone_book)[*size] = *create_phone_book_entry(name, number);
    *size += 1;
}

// Find a phone book entry by name
struct phone_book_entry *find_phone_book_entry_by_name(struct phone_book_entry *phone_book, int size, char *name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            return &phone_book[i];
        }
    }
    return NULL;
}

// Print a phone book
void print_phone_book(struct phone_book_entry *phone_book, int size) {
    for (int i = 0; i < size; i++) {
        printf("%s %s\n", phone_book[i].name, phone_book[i].number);
    }
}

// Free a phone book
void free_phone_book(struct phone_book_entry *phone_book, int size) {
    for (int i = 0; i < size; i++) {
        free_phone_book_entry(&phone_book[i]);
    }
    free(phone_book);
}

int main() {
    // Create a phone book
    struct phone_book_entry *phone_book = NULL;
    int size = 0;

    // Add some entries to the phone book
    add_phone_book_entry(&phone_book, &size, "Alice", "555-1212");
    add_phone_book_entry(&phone_book, &size, "Bob", "555-1213");
    add_phone_book_entry(&phone_book, &size, "Carol", "555-1214");

    // Find an entry in the phone book
    struct phone_book_entry *entry = find_phone_book_entry_by_name(phone_book, size, "Bob");
    if (entry != NULL) {
        printf("Found entry: %s %s\n", entry->name, entry->number);
    } else {
        printf("Entry not found.\n");
    }

    // Print the phone book
    print_phone_book(phone_book, size);

    // Free the phone book
    free_phone_book(phone_book, size);

    return 0;
}