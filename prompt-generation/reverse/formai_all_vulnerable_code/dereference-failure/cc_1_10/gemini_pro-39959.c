//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a phone book entry
typedef struct PhoneBookEntry {
    char *name;
    char *number;
} PhoneBookEntry;

// Define the structure of the phone book
typedef struct PhoneBook {
    PhoneBookEntry *entries;
    int numEntries;
} PhoneBook;

// Create a new phone book
PhoneBook *createPhoneBook() {
    PhoneBook *phoneBook = malloc(sizeof(PhoneBook));
    phoneBook->entries = NULL;
    phoneBook->numEntries = 0;
    return phoneBook;
}

// Add an entry to the phone book
void addEntry(PhoneBook *phoneBook, char *name, char *number) {
    // Allocate memory for the new entry
    PhoneBookEntry *entry = malloc(sizeof(PhoneBookEntry));
    entry->name = malloc(strlen(name) + 1);
    entry->number = malloc(strlen(number) + 1);

    // Copy the name and number into the new entry
    strcpy(entry->name, name);
    strcpy(entry->number, number);

    // Add the new entry to the phone book
    phoneBook->entries = realloc(phoneBook->entries, (phoneBook->numEntries + 1) * sizeof(PhoneBookEntry));
    phoneBook->entries[phoneBook->numEntries] = *entry;
    phoneBook->numEntries++;
}

// Find an entry in the phone book by name
PhoneBookEntry *findEntryByName(PhoneBook *phoneBook, char *name) {
    for (int i = 0; i < phoneBook->numEntries; i++) {
        if (strcmp(phoneBook->entries[i].name, name) == 0) {
            return &phoneBook->entries[i];
        }
    }
    return NULL;
}

// Find an entry in the phone book by number
PhoneBookEntry *findEntryByNumber(PhoneBook *phoneBook, char *number) {
    for (int i = 0; i < phoneBook->numEntries; i++) {
        if (strcmp(phoneBook->entries[i].number, number) == 0) {
            return &phoneBook->entries[i];
        }
    }
    return NULL;
}

// Print the phone book
void printPhoneBook(PhoneBook *phoneBook) {
    for (int i = 0; i < phoneBook->numEntries; i++) {
        printf("%s: %s\n", phoneBook->entries[i].name, phoneBook->entries[i].number);
    }
}

// Free the memory allocated for the phone book
void freePhoneBook(PhoneBook *phoneBook) {
    for (int i = 0; i < phoneBook->numEntries; i++) {
        free(phoneBook->entries[i].name);
        free(phoneBook->entries[i].number);
    }
    free(phoneBook->entries);
    free(phoneBook);
}

// Main function
int main() {
    // Create a new phone book
    PhoneBook *phoneBook = createPhoneBook();

    // Add some entries to the phone book
    addEntry(phoneBook, "John Doe", "555-1212");
    addEntry(phoneBook, "Jane Doe", "555-1213");
    addEntry(phoneBook, "Bob Smith", "555-1214");

    // Print the phone book
    printPhoneBook(phoneBook);

    // Find an entry in the phone book by name
    PhoneBookEntry *entry = findEntryByName(phoneBook, "John Doe");
    if (entry != NULL) {
        printf("Found entry: %s: %s\n", entry->name, entry->number);
    } else {
        printf("Entry not found.\n");
    }

    // Find an entry in the phone book by number
    entry = findEntryByNumber(phoneBook, "555-1214");
    if (entry != NULL) {
        printf("Found entry: %s: %s\n", entry->name, entry->number);
    } else {
        printf("Entry not found.\n");
    }

    // Free the memory allocated for the phone book
    freePhoneBook(phoneBook);

    return 0;
}