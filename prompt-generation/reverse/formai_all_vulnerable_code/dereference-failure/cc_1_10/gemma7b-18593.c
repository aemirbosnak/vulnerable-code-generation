//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: realistic
#include <stdio.h>
#include <string.h>

// Define the maximum number of entries
#define MAX_ENTRIES 10

// Define the structure of an entry
typedef struct Entry {
    char title[50];
    char content[200];
    struct Entry* next;
} Entry;

// Create a linked list of entries
Entry* head = NULL;

// Function to add an entry to the linked list
void addEntry(char* title, char* content) {
    Entry* newEntry = malloc(sizeof(Entry));

    strcpy(newEntry->title, title);
    strcpy(newEntry->content, content);

    if (head == NULL) {
        head = newEntry;
    } else {
        head->next = newEntry;
        head = newEntry;
    }
}

// Function to display all entries
void displayEntries() {
    Entry* currentEntry = head;

    while (currentEntry) {
        printf("Title: %s\n", currentEntry->title);
        printf("Content: %s\n", currentEntry->content);
        printf("\n");
        currentEntry = currentEntry->next;
    }
}

int main() {
    // Add some entries
    addEntry("My First Entry", "This is my first entry.");
    addEntry("My Second Entry", "This is my second entry.");
    addEntry("My Third Entry", "This is my third entry.");

    // Display all entries
    displayEntries();

    return 0;
}