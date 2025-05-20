//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of entries
#define MAX_ENTRIES 10

// Define the structure of an entry
typedef struct Entry {
    char title[50];
    char content[500];
    struct Entry* next;
} Entry;

// Create a linked list of entries
Entry* head = NULL;

// Function to add an entry to the linked list
void addEntry(char* title, char* content) {
    // Allocate memory for the new entry
    Entry* newEntry = malloc(sizeof(Entry));

    // Copy the title and content of the new entry
    strcpy(newEntry->title, title);
    strcpy(newEntry->content, content);

    // If the linked list is empty, make the new entry the head
    if (head == NULL) {
        head = newEntry;
    } else {
        // Traverse the linked list until the last entry is reached
        Entry* currentEntry = head;
        while (currentEntry->next) {
            currentEntry = currentEntry->next;
        }

        // Add the new entry to the end of the linked list
        currentEntry->next = newEntry;
    }
}

int main() {
    // Add some entries to the linked list
    addEntry("My first entry", "This is my first entry.");
    addEntry("My second entry", "This is my second entry.");
    addEntry("My third entry", "This is my third entry.");

    // Print the entries in the linked list
    Entry* currentEntry = head;
    while (currentEntry) {
        printf("Title: %s\n", currentEntry->title);
        printf("Content: %s\n", currentEntry->content);
        printf("\n");
        currentEntry = currentEntry->next;
    }

    return 0;
}