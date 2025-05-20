//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: surrealist
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to add a new phone number to the phone book
void addPhoneNumber(char* name, char* number) {
    char* newName = (char*)malloc(strlen(name) + 1);
    strcpy(newName, name);
    char* newNumber = (char*)malloc(strlen(number) + 1);
    strcpy(newNumber, number);

    printf("Adding %s (%s) to the phone book...\n", newName, newNumber);

    // Insert the new phone number at the beginning of the phone book
    char* phoneBook = (char*)malloc(sizeof(char) * 100);
    strcpy(phoneBook, "");
    strcat(phoneBook, newNumber);
    strcat(phoneBook, newName);
    strcat(phoneBook, "\n");

    // Print the updated phone book
    printf("Updated phone book:\n");
    printf("%s\n", phoneBook);

    // Free the memory allocated for the new phone number and name
    free(newName);
    free(newNumber);
}

// Function to find a phone number in the phone book
char* findPhoneNumber(char* name) {
    char* phoneBook = (char*)malloc(sizeof(char) * 100);
    strcpy(phoneBook, "");

    char* searchName = (char*)malloc(strlen(name) + 1);
    strcpy(searchName, name);

    char* searchPattern = (char*)malloc(strlen(searchName) + 1);
    strcpy(searchPattern, "\n");

    int searchIndex = 0;
    int searchLength = strlen(searchName);

    while (searchIndex < strlen(phoneBook)) {
        if (strncmp(phoneBook + searchIndex, searchPattern, searchLength) == 0) {
            char* foundName = (char*)malloc(strlen(name) + 1);
            strcpy(foundName, searchName);
            char* foundNumber = (char*)malloc(strlen(phoneBook) + 1);
            strcpy(foundNumber, phoneBook + searchIndex + searchLength);
            printf("Found %s (%s)\n", foundName, foundNumber);
            free(foundName);
            free(foundNumber);
            return phoneBook + searchIndex + searchLength;
        }
        searchIndex++;
    }

    return NULL;
}

int main() {
    // Test the phone book
    addPhoneNumber("Alice", "123-456-7890");
    addPhoneNumber("Bob", "987-654-3210");
    addPhoneNumber("Charlie", "555-555-5555");

    char* phoneNumber = findPhoneNumber("Alice");
    if (phoneNumber!= NULL) {
        printf("Found %s\n", phoneNumber);
    } else {
        printf("Not found\n");
    }

    free(phoneNumber);

    return 0;
}