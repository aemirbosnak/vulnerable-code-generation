//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 32
#define MAX_NUM_LEN 16
#define MAX_NUM_ENTRIES 100

// Entry contains a name and a phone number
typedef struct Entry {
    char name[MAX_NAME_LEN];
    char number[MAX_NUM_LEN];
} Entry;

// Phone book contains an array of entries
typedef struct PhoneBook {
    Entry entries[MAX_NUM_ENTRIES];
    int num_entries;
} PhoneBook;

// Create a new phone book
PhoneBook *new_phone_book() {
    PhoneBook *phone_book = malloc(sizeof(PhoneBook));
    phone_book->num_entries = 0;
    return phone_book;
}

// Add an entry to the phone book
void add_entry(PhoneBook *phone_book, char *name, char *number) {
    if (phone_book->num_entries == MAX_NUM_ENTRIES) {
        printf("Phone book is full!\n");
        return;
    }

    strcpy(phone_book->entries[phone_book->num_entries].name, name);
    strcpy(phone_book->entries[phone_book->num_entries].number, number);
    phone_book->num_entries++;
}

// Find an entry in the phone book by name
Entry *find_entry_by_name(PhoneBook *phone_book, char *name) {
    for (int i = 0; i < phone_book->num_entries; i++) {
        if (strcmp(phone_book->entries[i].name, name) == 0) {
            return &phone_book->entries[i];
        }
    }

    return NULL;
}

// Find an entry in the phone book by number
Entry *find_entry_by_number(PhoneBook *phone_book, char *number) {
    for (int i = 0; i < phone_book->num_entries; i++) {
        if (strcmp(phone_book->entries[i].number, number) == 0) {
            return &phone_book->entries[i];
        }
    }

    return NULL;
}

// Print the phone book
void print_phone_book(PhoneBook *phone_book) {
    for (int i = 0; i < phone_book->num_entries; i++) {
        printf("%s: %s\n", phone_book->entries[i].name, phone_book->entries[i].number);
    }
}

// Free the phone book
void free_phone_book(PhoneBook *phone_book) {
    free(phone_book);
}

int main() {
    // Create a new phone book
    PhoneBook *phone_book = new_phone_book();

    // Add some entries to the phone book
    add_entry(phone_book, "Alice", "555-1212");
    add_entry(phone_book, "Bob", "555-1213");
    add_entry(phone_book, "Charlie", "555-1214");

    // Print the phone book
    print_phone_book(phone_book);

    // Find an entry in the phone book by name
    Entry *entry = find_entry_by_name(phone_book, "Alice");
    if (entry != NULL) {
        printf("Found entry for %s: %s\n", entry->name, entry->number);
    } else {
        printf("Entry for %s not found\n", "Alice");
    }

    // Find an entry in the phone book by number
    entry = find_entry_by_number(phone_book, "555-1214");
    if (entry != NULL) {
        printf("Found entry for %s: %s\n", entry->name, entry->number);
    } else {
        printf("Entry for %s not found\n", "555-1214");
    }

    // Free the phone book
    free_phone_book(phone_book);

    return 0;
}