//FormAI DATASET v1.0 Category: Digital Diary ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000

// Entry struct
typedef struct Entry {
    char* date;
    char* title;
    char* body;
} Entry;

// Global entry array
Entry entries[MAX_ENTRIES];
int entryCount = 0;

// Function to print all entries
void printEntries() {
    for(int i = 0; i < entryCount; i++) {
        printf("Date: %s\nTitle: %s\nBody: %s\n\n", entries[i].date, entries[i].title, entries[i].body);
    }
}

// Function to add a new entry
void addEntry() {
    // Check if there is space for another entry
    if(entryCount >= MAX_ENTRIES) {
        printf("Diary is full!\n");
        return;
    }

    // Allocate memory for new entry
    Entry* newEntry = malloc(sizeof(Entry));

    // Prompt user to enter date, title and body
    printf("Enter date (MM/DD/YYYY format): ");
    char date[11];
    scanf("%s", date);
    newEntry->date = strdup(date);

    printf("Enter title: ");
    char title[100];
    scanf(" %[^\n]s", title);
    newEntry->title = strdup(title);

    printf("Enter body: ");
    char body[1000];
    scanf(" %[^\n]s", body);
    newEntry->body = strdup(body);

    // Add entry to array and increment count
    entries[entryCount++] = *newEntry;
}

// Function to remove an entry by index
void removeEntry(int index) {
    // Check if index is valid
    if(index < 0 || index >= entryCount) {
        printf("Invalid index!\n");
        return;
    }

    // Free memory for entry
    free(entries[index].date);
    free(entries[index].title);
    free(entries[index].body);

    // Shift all entries after the removed entry to the left
    for(int i = index; i < entryCount - 1; i++) {
        entries[i] = entries[i+1];
    }

    // Decrement entry count
    entryCount--;
}

int main() {
    printf("Welcome to your Digital Diary!\n");
    printf("-----------------------------\n");

    // Menu loop
    while(1) {
        printf("Choose an option:\n");
        printf("1. View all entries\n");
        printf("2. Add a new entry\n");
        printf("3. Remove an entry\n");
        printf("4. Exit\n");

        // Get user input
        int choice;
        scanf("%d", &choice);

        // Perform corresponding action
        switch(choice) {
            case 1:
                printf("All entries:\n");
                printEntries();
                break;
            case 2:
                addEntry();
                break;
            case 3:
                printf("Enter index of entry to remove: ");
                int index;
                scanf("%d", &index);
                removeEntry(index);
                break;
            case 4:
                printf("Exiting diary...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
                break;
        }

        printf("\n");
    }
}