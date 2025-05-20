//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of entries in the phone book
#define MAX_ENTRIES 100

// Define the structure of a phone book entry
typedef struct {
    char name[50];
    char number[20];
} PhoneBookEntry;

// Create a new phone book entry
PhoneBookEntry* create_entry(char* name, char* number) {
    PhoneBookEntry* entry = malloc(sizeof(PhoneBookEntry));
    strcpy(entry->name, name);
    strcpy(entry->number, number);
    return entry;
}

// Add an entry to the phone book
void add_entry(PhoneBookEntry** phone_book, int* num_entries, PhoneBookEntry* entry) {
    phone_book[*num_entries] = entry;
    (*num_entries)++;
}

// Search for an entry in the phone book by name
PhoneBookEntry* search_by_name(PhoneBookEntry** phone_book, int num_entries, char* name) {
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phone_book[i]->name, name) == 0) {
            return phone_book[i];
        }
    }
    return NULL;
}

// Search for an entry in the phone book by number
PhoneBookEntry* search_by_number(PhoneBookEntry** phone_book, int num_entries, char* number) {
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phone_book[i]->number, number) == 0) {
            return phone_book[i];
        }
    }
    return NULL;
}

// Print the phone book
void print_phone_book(PhoneBookEntry** phone_book, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", phone_book[i]->name, phone_book[i]->number);
    }
}

// Main function
int main() {
    // Create an empty phone book
    PhoneBookEntry* phone_book[MAX_ENTRIES];
    int num_entries = 0;

    // Add some entries to the phone book
    add_entry(phone_book, &num_entries, create_entry("John Doe", "555-1212"));
    add_entry(phone_book, &num_entries, create_entry("Jane Smith", "555-1213"));
    add_entry(phone_book, &num_entries, create_entry("Bill Jones", "555-1214"));

    // Print the phone book
    printf("Phone Book:\n");
    print_phone_book(phone_book, num_entries);

    // Search for an entry by name
    PhoneBookEntry* entry = search_by_name(phone_book, num_entries, "John Doe");
    if (entry != NULL) {
        printf("Found entry for John Doe: %s\n", entry->number);
    } else {
        printf("Entry for John Doe not found\n");
    }

    // Search for an entry by number
    entry = search_by_number(phone_book, num_entries, "555-1213");
    if (entry != NULL) {
        printf("Found entry for 555-1213: %s\n", entry->name);
    } else {
        printf("Entry for 555-1213 not found\n");
    }

    return 0;
}