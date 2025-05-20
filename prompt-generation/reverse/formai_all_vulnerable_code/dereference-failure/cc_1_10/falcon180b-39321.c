//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 15

// Define the structure for each phone book entry
typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} Entry;

// Function to compare two strings (case insensitive)
int strcasecmp(const char* str1, const char* str2) {
    while (tolower(*str1) == tolower(*str2)) {
        str1++;
        str2++;
    }
    return tolower(*str1) - tolower(*str2);
}

// Function to sort the phone book entries alphabetically by name
void sortPhoneBook(Entry entries[], int numEntries) {
    qsort(entries, numEntries, sizeof(Entry), (int(*)(const void*, const void*))strcasecmp);
}

// Function to print the phone book entries
void printPhoneBook(Entry entries[], int numEntries) {
    printf("Phone Book:\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%s: %s\n", entries[i].name, entries[i].number);
    }
}

int main() {
    // Initialize the phone book
    Entry phoneBook[MAX_ENTRIES];
    int numEntries = 0;

    // Read in the phone book entries from a file
    FILE* phoneBookFile = fopen("phonebook.txt", "r");
    if (phoneBookFile == NULL) {
        printf("Error: Could not open phonebook.txt\n");
        return 1;
    }
    char line[MAX_NAME_LENGTH + MAX_NUMBER_LENGTH + 2]; // +2 for newline and null terminator
    while (fgets(line, sizeof(line), phoneBookFile)!= NULL) {
        char* name = strtok(line, ":");
        char* number = strtok(NULL, "\n");
        if (name == NULL || number == NULL) {
            printf("Error: Invalid phone book entry\n");
            return 1;
        }
        strncpy(phoneBook[numEntries].name, name, MAX_NAME_LENGTH);
        strncpy(phoneBook[numEntries].number, number, MAX_NUMBER_LENGTH);
        numEntries++;
    }
    fclose(phoneBookFile);

    // Sort the phone book entries alphabetically by name
    sortPhoneBook(phoneBook, numEntries);

    // Print the phone book entries
    printPhoneBook(phoneBook, numEntries);

    // Search for a name in the phone book
    char searchName[MAX_NAME_LENGTH];
    printf("\nEnter a name to search for: ");
    scanf("%s", searchName);
    int searchResult = -1;
    for (int i = 0; i < numEntries; i++) {
        if (strcasecmp(searchName, phoneBook[i].name) == 0) {
            searchResult = i;
            break;
        }
    }
    if (searchResult == -1) {
        printf("Name not found in phone book\n");
    } else {
        printf("\nName: %s\nNumber: %s\n", phoneBook[searchResult].name, phoneBook[searchResult].number);
    }

    return 0;
}