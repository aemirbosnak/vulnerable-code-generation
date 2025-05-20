//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the future-proof phone book structure
typedef struct PhoneBookEntry {
    char name[256];
    char number[256];
    struct PhoneBookEntry* next;
} PhoneBookEntry;

// Create a linked list of phone book entries
PhoneBookEntry* head = NULL;

// Function to add a new entry to the phone book
void addEntry(char* name, char* number) {
    PhoneBookEntry* newEntry = (PhoneBookEntry*)malloc(sizeof(PhoneBookEntry));
    strcpy(newEntry->name, name);
    strcpy(newEntry->number, number);
    newEntry->next = NULL;

    if (head == NULL) {
        head = newEntry;
    } else {
        head->next = newEntry;
        head = newEntry;
    }
}

// Function to search for a phone number
char* searchNumber(char* name) {
    PhoneBookEntry* currentEntry = head;

    while (currentEntry) {
        if (strcmp(currentEntry->name, name) == 0) {
            return currentEntry->number;
        }
        currentEntry = currentEntry->next;
    }

    return NULL;
}

int main() {
    // Add some entries to the phone book
    addEntry("John Doe", "555-123-4567");
    addEntry("Jane Doe", "555-234-5678");
    addEntry("Peter Pan", "555-345-6789");

    // Search for a phone number
    char* number = searchNumber("John Doe");

    // Print the phone number
    if (number) {
        printf("Phone number: %s\n", number);
    } else {
        printf("Phone number not found.\n");
    }

    return 0;
}