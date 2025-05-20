//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a phone book entry
typedef struct {
    char *name;
    char *number;
} PhoneBookEntry;

// Define the maximum number of entries in the phone book
#define MAX_ENTRIES 100

// Create a new phone book entry
PhoneBookEntry *new_entry(char *name, char *number) {
    PhoneBookEntry *entry = malloc(sizeof(PhoneBookEntry));
    entry->name = strdup(name);
    entry->number = strdup(number);
    return entry;
}

// Add an entry to the phone book
void add_entry(PhoneBookEntry *entries[], int *num_entries, PhoneBookEntry *entry) {
    if (*num_entries >= MAX_ENTRIES) {
        printf("Phone book is full!\n");
        return;
    }
    entries[*num_entries] = entry;
    (*num_entries)++;
}

// Find an entry in the phone book by name
PhoneBookEntry *find_entry(PhoneBookEntry *entries[], int num_entries, char *name) {
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i]->name, name) == 0) {
            return entries[i];
        }
    }
    return NULL;
}

// Print the phone book
void print_phone_book(PhoneBookEntry *entries[], int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", entries[i]->name, entries[i]->number);
    }
}

// Free the memory allocated for the phone book
void free_phone_book(PhoneBookEntry *entries[], int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        free(entries[i]->name);
        free(entries[i]->number);
        free(entries[i]);
    }
}

// Main function
int main() {
    // Create an array of phone book entries
    PhoneBookEntry *entries[MAX_ENTRIES];

    // Initialize the number of entries in the phone book
    int num_entries = 0;

    // Add some entries to the phone book
    add_entry(entries, &num_entries, new_entry("John Doe", "555-1212"));
    add_entry(entries, &num_entries, new_entry("Jane Doe", "555-1213"));
    add_entry(entries, &num_entries, new_entry("John Smith", "555-1214"));

    // Find an entry in the phone book
    PhoneBookEntry *entry = find_entry(entries, num_entries, "John Doe");
    if (entry != NULL) {
        printf("Found entry for John Doe: %s\n", entry->number);
    } else {
        printf("Entry for John Doe not found\n");
    }

    // Print the phone book
    printf("Phone book:\n");
    print_phone_book(entries, num_entries);

    // Free the memory allocated for the phone book
    free_phone_book(entries, num_entries);

    return 0;
}