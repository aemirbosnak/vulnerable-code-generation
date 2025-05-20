//FormAI DATASET v1.0 Category: Phone Book ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PhoneBookEntry {
    char name[100];
    char number[20];
} PhoneBookEntry;

void addEntry(PhoneBookEntry** phoneBook, int* numEntries);
void searchEntry(PhoneBookEntry* phoneBook, int numEntries);

int main() {
    printf("Welcome to the Surreal Phone Book Program\n");

    int numEntries = 0;
    PhoneBookEntry* phoneBook = NULL;

    while (1) {
        printf("\nPlease choose an option:\n");
        printf("1. Add an entry to the phone book\n");
        printf("2. Search for an entry in the phone book\n");
        printf("3. Exit the program\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry(&phoneBook, &numEntries);
                break;
            case 2:
                searchEntry(phoneBook, numEntries);
                break;
            case 3:
                printf("\nExiting the Surreal Phone Book Program. Goodbye!\n");
                return 0;
            default:
                printf("\nInvalid option. Please select again.\n");
                break;
        }
    }

    return 0;
}

void addEntry(PhoneBookEntry** phoneBook, int* numEntries) {
    printf("\nAdding a Surreal Entry to the Phone Book\n");

    *numEntries = *numEntries + 1;
    *phoneBook = realloc(*phoneBook, (*numEntries) * sizeof(PhoneBookEntry));
    PhoneBookEntry newEntry;

    printf("\nEnter the name:");
    scanf("%s", newEntry.name);
    printf("\nEnter the number:");
    scanf("%s", newEntry.number);

    (*phoneBook)[*numEntries - 1] = newEntry;

    printf("\nSurreal Entry added to Phone Book successfully!\n");
}

void searchEntry(PhoneBookEntry* phoneBook, int numEntries) {
    printf("\nSearching for a Surreal Entry in Phone Book\n");

    char searchTerm[100];
    printf("\nEnter the name to search for:");
    scanf("%s", searchTerm);

    for (int i = 0; i < numEntries; i++) {
        if (strcmp(phoneBook[i].name, searchTerm) == 0) {
            printf("\nSurreal Entry found!\n");
            printf("Name: %s\n", phoneBook[i].name);
            printf("Number: %s\n", phoneBook[i].number);
            return;
        }
    }

    printf("\nCould not find any Entry with given name. Please try again!\n");
}