//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to add a contact to the phone book
void addContact(char *name, char *phoneNumber) {
    char *newEntry = (char *)malloc(sizeof(char) * (strlen(name) + strlen(phoneNumber) + 1));
    strcpy(newEntry, name);
    strcat(newEntry, " | ");
    strcat(newEntry, phoneNumber);
    char *entry = (char *)malloc(sizeof(char) * (strlen(name) + strlen(phoneNumber) + 1));
    strcpy(entry, name);
    strcat(entry, " | ");
    strcat(entry, phoneNumber);
    char *existingEntries = (char *)malloc(sizeof(char) * 100);
    char *newEntryPointer = newEntry;
    char *existingEntriesPointer = existingEntries;
    while (*existingEntriesPointer) {
        if (strcmp(newEntryPointer, existingEntriesPointer) == 0) {
            free(entry);
            return;
        }
        existingEntriesPointer++;
    }
    strcat(existingEntries, newEntry);
    free(newEntry);
}

// Function to search for a contact in the phone book
char *searchContact(char *name) {
    char *existingEntries = (char *)malloc(sizeof(char) * 100);
    char *entry = (char *)malloc(sizeof(char) * (strlen(name) + strlen(name) + 1));
    strcpy(entry, name);
    strcat(entry, " | ");
    strcat(entry, name);
    char *entryPointer = entry;
    char *existingEntriesPointer = existingEntries;
    while (*existingEntriesPointer) {
        if (strcmp(entryPointer, existingEntriesPointer) == 0) {
            return existingEntries;
        }
        existingEntriesPointer++;
    }
    return NULL;
}

// Function to print all contacts in the phone book
void printContacts() {
    char *existingEntries = (char *)malloc(sizeof(char) * 100);
    char *entry = (char *)malloc(sizeof(char) * 100);
    char *entryPointer = entry;
    char *existingEntriesPointer = existingEntries;
    while (*existingEntriesPointer) {
        printf("%s | %s\n", entryPointer, existingEntriesPointer);
        entryPointer = entry;
        existingEntriesPointer++;
    }
}

int main() {
    char *existingEntries = (char *)malloc(sizeof(char) * 100);
    char *entry = (char *)malloc(sizeof(char) * 100);
    char *entryPointer = entry;
    char *existingEntriesPointer = existingEntries;
    while (*existingEntriesPointer) {
        printf("%s | %s\n", entryPointer, existingEntriesPointer);
        entryPointer = entry;
        existingEntriesPointer++;
    }
    addContact("John Smith", "123-456-7890");
    addContact("Jane Doe", "987-654-3210");
    addContact("Mike Johnson", "555-123-4567");
    printf("Search for 'John Smith': %s\n", searchContact("John Smith"));
    printf("Search for 'Jane Doe': %s\n", searchContact("Jane Doe"));
    printf("Search for 'Mike Johnson': %s\n", searchContact("Mike Johnson"));
    printContacts();
    return 0;
}