//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: realistic
#include <stdio.h>
#include <string.h>

// Define a structure to store the digital diary entries
typedef struct Entry {
    char title[20];
    char content[1000];
    struct Entry* next;
} Entry;

// Create a linked list of digital diary entries
Entry* head = NULL;

// Function to add a new entry to the linked list
void addEntry() {
    // Allocate memory for the new entry
    Entry* newEntry = malloc(sizeof(Entry));

    // Get the entry title and content from the user
    printf("Enter the title of the entry: ");
    scanf("%s", newEntry->title);

    printf("Enter the content of the entry: ");
    scanf("%s", newEntry->content);

    // Add the new entry to the linked list
    if (head == NULL) {
        head = newEntry;
    } else {
        head->next = newEntry;
        head = newEntry;
    }
}

// Function to display all entries in the linked list
void displayEntries() {
    // Traverse the linked list and print each entry
    Entry* currentEntry = head;
    while (currentEntry) {
        printf("Title: %s\n", currentEntry->title);
        printf("Content: %s\n", currentEntry->content);
        printf("\n");
        currentEntry = currentEntry->next;
    }
}

// Main function
int main() {
    // Add some entries to the linked list
    addEntry();
    addEntry();
    addEntry();

    // Display all entries in the linked list
    displayEntries();

    return 0;
}