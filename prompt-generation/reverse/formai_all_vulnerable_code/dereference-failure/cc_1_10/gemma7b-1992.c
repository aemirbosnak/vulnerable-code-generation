//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of entries in the diary
#define MAX_ENTRIES 10

// Define the structure of an entry
typedef struct Entry {
    char *title;
    char *content;
    struct Entry *next;
} Entry;

// Function to create a new entry
Entry *createEntry() {
    Entry *newEntry = malloc(sizeof(Entry));
    newEntry->title = malloc(20 * sizeof(char));
    newEntry->content = malloc(200 * sizeof(char));
    newEntry->next = NULL;

    return newEntry;
}

// Function to add an entry to the diary
void addEntry(Entry *entries, Entry *newEntry) {
    if (entries == NULL) {
        entries = newEntry;
    } else {
        entries->next = newEntry;
        entries = newEntry;
    }
}

// Function to read an entry from the diary
void readEntry(Entry *entries) {
    Entry *currentEntry = entries;

    while (currentEntry) {
        printf("Title: %s\n", currentEntry->title);
        printf("Content: %s\n", currentEntry->content);
        printf("\n");

        currentEntry = currentEntry->next;
    }
}

int main() {
    Entry *entries = NULL;

    // Create a new entry
    Entry *newEntry = createEntry();
    newEntry->title = "My First Entry";
    newEntry->content = "This is my first entry in the diary.";

    // Add the entry to the diary
    addEntry(entries, newEntry);

    // Create a new entry
    newEntry = createEntry();
    newEntry->title = "My Second Entry";
    newEntry->content = "This is my second entry in the diary.";

    // Add the entry to the diary
    addEntry(entries, newEntry);

    // Read the entries from the diary
    readEntry(entries);

    return 0;
}