//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of entries in the phone book
#define MAX_ENTRIES 100

// Define the structure of a phone book entry
typedef struct {
    char *name;
    char *number;
} phone_book_entry;

// Create a new phone book entry
phone_book_entry *new_phone_book_entry(char *name, char *number) {
    phone_book_entry *entry = malloc(sizeof(phone_book_entry));
    entry->name = strdup(name);
    entry->number = strdup(number);
    return entry;
}

// Free a phone book entry
void free_phone_book_entry(phone_book_entry *entry) {
    free(entry->name);
    free(entry->number);
    free(entry);
}

// Add a new entry to the phone book
void add_phone_book_entry(phone_book_entry **phone_book, int *num_entries, char *name, char *number) {
    if (*num_entries >= MAX_ENTRIES) {
        printf("Error: Phone book is full.\n");
        return;
    }
    phone_book[*num_entries] = new_phone_book_entry(name, number);
    (*num_entries)++;
}

// Find a phone book entry by name
phone_book_entry *find_phone_book_entry_by_name(phone_book_entry **phone_book, int num_entries, char *name) {
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phone_book[i]->name, name) == 0) {
            return phone_book[i];
        }
    }
    return NULL;
}

// Find a phone book entry by number
phone_book_entry *find_phone_book_entry_by_number(phone_book_entry **phone_book, int num_entries, char *number) {
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phone_book[i]->number, number) == 0) {
            return phone_book[i];
        }
    }

    return NULL;
}

// Print the phone book
void print_phone_book(phone_book_entry **phone_book, int num_entries) {
    printf("Phone Book:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", phone_book[i]->name, phone_book[i]->number);
    }
}

// Free the phone book
void free_phone_book(phone_book_entry **phone_book, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        free_phone_book_entry(phone_book[i]);
    }
    free(phone_book);
}

int main() {
    // Create a new phone book
    phone_book_entry **phone_book = malloc(sizeof(phone_book_entry *) * MAX_ENTRIES);
    int num_entries = 0;

    // Add some entries to the phone book
    add_phone_book_entry(phone_book, &num_entries, "Alice", "555-1212");
    add_phone_book_entry(phone_book, &num_entries, "Bob", "555-1213");
    add_phone_book_entry(phone_book, &num_entries, "Charlie", "555-1214");

    // Print the phone book
    print_phone_book(phone_book, num_entries);

    // Find an entry in the phone book by name
    phone_book_entry *entry = find_phone_book_entry_by_name(phone_book, num_entries, "Bob");
    if (entry != NULL) {
        printf("Found entry for %s: %s\n", entry->name, entry->number);
    } else {
        printf("Entry not found.\n");
    }

    // Find an entry in the phone book by number
    entry = find_phone_book_entry_by_number(phone_book, num_entries, "555-1214");
    if (entry != NULL) {
        printf("Found entry for %s: %s\n", entry->name, entry->number);
    } else {
        printf("Entry not found.\n");
    }

    // Free the phone book
    free_phone_book(phone_book, num_entries);

    return 0;
}