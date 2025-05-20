//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of entries in the phone book
#define MAX_ENTRIES 100

// Define the structure of a phone book entry
typedef struct {
    char *name;
    char *number;
} phone_entry;

// Create a new phone book entry
phone_entry *create_entry(char *name, char *number) {
    phone_entry *entry = malloc(sizeof(phone_entry));
    entry->name = strdup(name);
    entry->number = strdup(number);
    return entry;
}

// Add an entry to the phone book
void add_entry(phone_entry **phone_book, int *num_entries, phone_entry *entry) {
    phone_book[*num_entries] = entry;
    (*num_entries)++;
}

// Find an entry in the phone book by name
phone_entry *find_entry(phone_entry **phone_book, int num_entries, char *name) {
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phone_book[i]->name, name) == 0) {
            return phone_book[i];
        }
    }
    return NULL;
}

// Print the phone book
void print_phone_book(phone_entry **phone_book, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", phone_book[i]->name, phone_book[i]->number);
    }
}

// Free the memory allocated for the phone book
void free_phone_book(phone_entry **phone_book, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        free(phone_book[i]->name);
        free(phone_book[i]->number);
        free(phone_book[i]);
    }
    free(phone_book);
}

// Main function
int main() {
    // Create a new phone book
    phone_entry **phone_book = malloc(sizeof(phone_entry *) * MAX_ENTRIES);
    int num_entries = 0;

    // Add some entries to the phone book
    add_entry(phone_book, &num_entries, create_entry("Alice", "555-1212"));
    add_entry(phone_book, &num_entries, create_entry("Bob", "555-1213"));
    add_entry(phone_book, &num_entries, create_entry("Carol", "555-1214"));

    // Print the phone book
    print_phone_book(phone_book, num_entries);

    // Find an entry in the phone book by name
    phone_entry *entry = find_entry(phone_book, num_entries, "Bob");
    if (entry != NULL) {
        printf("Found entry for Bob: %s\n", entry->number);
    } else {
        printf("No entry found for Bob.\n");
    }

    // Free the memory allocated for the phone book
    free_phone_book(phone_book, num_entries);

    return 0;
}