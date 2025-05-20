//FormAI DATASET v1.0 Category: Phone Book ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a phone book entry
typedef struct PhoneBookEntry {
    char name[50];
    char phone_number[15];
} PhoneBookEntry;

// Function to add a new entry to the phone book
void addEntry(PhoneBookEntry* phoneBook, int* numEntries) {
    PhoneBookEntry newEntry;
    // Prompt the user for the name and phone number
    printf("Enter the name: ");
    fgets(newEntry.name, 50, stdin);
    printf("Enter the phone number: ");
    fgets(newEntry.phone_number, 15, stdin);
    // Add the entry to the phone book
    phoneBook[*numEntries] = newEntry;
    (*numEntries)++;
    printf("Entry added successfully!\n");
}

// Function to search for an entry in the phone book
void searchEntry(PhoneBookEntry* phoneBook, int numEntries) {
    char name[50];
    printf("Enter the name to search for: ");
    fgets(name, 50, stdin);
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            printf("Phone number: %s\n", phoneBook[i].phone_number);
            return;
        }
    }
    printf("Entry not found.\n");
}

// Function to print all entries in the phone book
void printEntries(PhoneBookEntry* phoneBook, int numEntries) {
    printf("Entries:\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%s - %s", phoneBook[i].name, phoneBook[i].phone_number);
    }
}

int main() {
    PhoneBookEntry* phoneBook = malloc(sizeof(PhoneBookEntry) * 100);
    int numEntries = 0;
    while (1) {
        // Prompt the user for an action
        printf("What would you like to do?\n");
        printf("1. Add an entry\n");
        printf("2. Search for an entry\n");
        printf("3. Print all entries\n");
        printf("4. Exit\n");
        char choice[5];
        fgets(choice, 5, stdin);
        // Respond to the user's choice
        if (strcmp(choice, "1\n") == 0) {
            addEntry(phoneBook, &numEntries);
        }
        else if (strcmp(choice, "2\n") == 0) {
            searchEntry(phoneBook, numEntries);
        }
        else if (strcmp(choice, "3\n") == 0) {
            printEntries(phoneBook, numEntries);
        }
        else if (strcmp(choice, "4\n") == 0) {
            break;
        }
        else {
            printf("Invalid choice.\n");
        }
    }
    free(phoneBook);
    return 0;
}