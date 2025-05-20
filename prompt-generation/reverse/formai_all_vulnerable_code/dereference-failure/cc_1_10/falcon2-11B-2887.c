//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: funny
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Function to add a new entry to the phone book
void addEntry(char **phoneBook, char *name, char *number) {
    int nameLength = strlen(name);
    int numberLength = strlen(number);

    // Check if the phone book is already full
    if (nameLength + numberLength > 15) {
        printf("Sorry, but we can't fit any more names and numbers into the phone book!\n");
        return;
    }

    // Allocate memory for the new entry
    char *newEntry = (char *)malloc(sizeof(char) * (nameLength + numberLength + 1));
    if (newEntry == NULL) {
        printf("Out of memory!\n");
        return;
    }

    // Copy the name and number into the new entry
    strcpy(newEntry, name);
    strcat(newEntry, " ");
    strcat(newEntry, number);

    // Add the new entry to the phone book
    phoneBook[nameLength + numberLength] = newEntry;
    printf("New entry added: %s %s\n", name, number);
}

// Function to search for an entry in the phone book
int searchEntry(char **phoneBook, char *name, char *number) {
    int nameLength = strlen(name);
    int numberLength = strlen(number);

    // Check if the name or number is empty
    if (nameLength == 0 || numberLength == 0) {
        printf("Please enter a valid name and number to search for!\n");
        return 0;
    }

    // Check if the entry exists in the phone book
    for (int i = 0; i < 16; i++) {
        char *entry = phoneBook[i];
        if (entry == NULL) {
            break;
        }
        if (strncmp(entry, name, nameLength) == 0) {
            if (strncmp(entry + nameLength, number, numberLength) == 0) {
                printf("Found entry: %s %s\n", name, number);
                return 1;
            }
        }
    }

    printf("Entry not found!\n");
    return 0;
}

// Function to print the entire phone book
void printPhoneBook(char **phoneBook, int size) {
    for (int i = 0; i < size; i++) {
        char *entry = phoneBook[i];
        if (entry == NULL) {
            break;
        }
        printf("%s %s\n", entry, entry + strlen(entry));
    }
}

int main() {
    char phoneBook[16][100];
    int size = 0;

    // Prompt the user for a name and number
    char name[100], number[100];
    printf("Enter a name: ");
    fgets(name, 100, stdin);
    printf("Enter a number: ");
    fgets(number, 100, stdin);

    // Add the entry to the phone book
    addEntry(phoneBook, name, number);

    // Print the entire phone book
    printf("Phone Book:\n");
    printPhoneBook(phoneBook, size);

    // Search for an entry in the phone book
    printf("Enter a name and number to search for: ");
    fgets(name, 100, stdin);
    fgets(number, 100, stdin);
    int found = searchEntry(phoneBook, name, number);

    // Print the results of the search
    if (found) {
        printf("Entry found!\n");
    } else {
        printf("Entry not found!\n");
    }

    return 0;
}