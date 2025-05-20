//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: retro
// Retro Phone Book v1.0
// Compiled on 03/27/22

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define phone book structure
typedef struct {
    char name[50];  // Name of the person
    char number[20]; // Phone number
} phonebook;

// Define phone book array
phonebook phoneBook[10];

// Function to add a new entry to the phone book
void addEntry(char *name, char *number) {
    int i;
    for (i = 0; i < 10; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            printf("Error: Duplicate entry found for %s\n", name);
            return;
        }
    }
    strcpy(phoneBook[i].name, name);
    strcpy(phoneBook[i].number, number);
    i++;
}

// Function to search for a phone number
int searchNumber(char *number) {
    int i;
    for (i = 0; i < 10; i++) {
        if (strcmp(phoneBook[i].number, number) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to display the phone book
void displayPhoneBook() {
    int i;
    for (i = 0; i < 10; i++) {
        printf("%d: %s %s\n", i, phoneBook[i].name, phoneBook[i].number);
    }
}

int main() {
    // Add some entries to the phone book
    addEntry("John Doe", "555-1234");
    addEntry("Jane Doe", "555-5678");
    addEntry("Bob Smith", "555-9012");

    // Search for a phone number
    int found = searchNumber("555-5678");
    if (found != -1) {
        printf("Found %s %s\n", phoneBook[found].name, phoneBook[found].number);
    } else {
        printf("Not found\n");
    }

    // Display the phone book
    displayPhoneBook();

    return 0;
}