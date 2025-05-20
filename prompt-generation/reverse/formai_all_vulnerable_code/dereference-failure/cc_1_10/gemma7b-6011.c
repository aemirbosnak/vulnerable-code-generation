//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store phone book entries
typedef struct phoneBookEntry {
    char name[50];
    char number[20];
    struct phoneBookEntry* next;
} phoneBookEntry;

// Create a linked list to store phone book entries
phoneBookEntry* head = NULL;

// Function to add a new entry to the phone book
void addEntry(char* name, char* number) {
    phoneBookEntry* newEntry = (phoneBookEntry*)malloc(sizeof(phoneBookEntry));
    strcpy(newEntry->name, name);
    strcpy(newEntry->number, number);
    newEntry->next = NULL;

    if (head == NULL) {
        head = newEntry;
    } else {
        phoneBookEntry* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newEntry;
    }
}

// Function to search for a phone book entry
phoneBookEntry* searchEntry(char* name) {
    phoneBookEntry* temp = head;
    while (temp) {
        if (strcmp(temp->name, name) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to print all phone book entries
void printEntries() {
    phoneBookEntry* temp = head;
    while (temp) {
        printf("%s - %s\n", temp->name, temp->number);
        temp = temp->next;
    }
}

int main() {
    // Add some entries to the phone book
    addEntry("John Doe", "123-456-7890");
    addEntry("Jane Doe", "456-789-0123");
    addEntry("Peter Pan", "555-123-4567");

    // Search for an entry
    phoneBookEntry* entry = searchEntry("John Doe");
    if (entry) {
        printf("Name: %s\n", entry->name);
        printf("Number: %s\n", entry->number);
    } else {
        printf("Entry not found.\n");
    }

    // Print all entries
    printEntries();

    return 0;
}