//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: expert-level
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
PhoneBookEntry* createEntry(char* name, char* number) {
    PhoneBookEntry* entry = malloc(sizeof(PhoneBookEntry));
    strcpy(entry->name, name);
    strcpy(entry->number, number);
    return entry;
}

// Add an entry to the phone book
void addEntry(PhoneBookEntry* phoneBook[], int* numEntries, PhoneBookEntry* entry) {
    phoneBook[*numEntries] = entry;
    (*numEntries)++;
}

// Search for an entry in the phone book by name
PhoneBookEntry* searchByName(PhoneBookEntry* phoneBook[], int numEntries, char* name) {
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(phoneBook[i]->name, name) == 0) {
            return phoneBook[i];
        }
    }
    return NULL;
}

// Search for an entry in the phone book by number
PhoneBookEntry* searchByNumber(PhoneBookEntry* phoneBook[], int numEntries, char* number) {
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(phoneBook[i]->number, number) == 0) {
            return phoneBook[i];
        }
    }
    return NULL;
}

// Print the phone book
void printPhoneBook(PhoneBookEntry* phoneBook[], int numEntries) {
    printf("Phone Book:\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%s: %s\n", phoneBook[i]->name, phoneBook[i]->number);
    }
}

// Free the memory allocated for the phone book
void freePhoneBook(PhoneBookEntry* phoneBook[], int numEntries) {
    for (int i = 0; i < numEntries; i++) {
        free(phoneBook[i]);
    }
}

// Main function
int main() {
    // Initialize the phone book
    PhoneBookEntry* phoneBook[MAX_ENTRIES];
    int numEntries = 0;

    // Add some entries to the phone book
    addEntry(phoneBook, &numEntries, createEntry("John Doe", "555-1212"));
    addEntry(phoneBook, &numEntries, createEntry("Jane Smith", "555-1213"));
    addEntry(phoneBook, &numEntries, createEntry("Bill Jones", "555-1214"));

    // Print the phone book
    printPhoneBook(phoneBook, numEntries);

    // Search for an entry by name
    PhoneBookEntry* entry = searchByName(phoneBook, numEntries, "John Doe");
    if (entry != NULL) {
        printf("Found entry: %s: %s\n", entry->name, entry->number);
    } else {
        printf("Entry not found.\n");
    }

    // Search for an entry by number
    entry = searchByNumber(phoneBook, numEntries, "555-1213");
    if (entry != NULL) {
        printf("Found entry: %s: %s\n", entry->name, entry->number);
    } else {
        printf("Entry not found.\n");
    }

    // Free the memory allocated for the phone book
    freePhoneBook(phoneBook, numEntries);

    return 0;
}