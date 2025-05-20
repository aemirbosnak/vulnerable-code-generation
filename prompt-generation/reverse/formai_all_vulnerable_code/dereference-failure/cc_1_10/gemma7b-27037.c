//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store digital diary entries
typedef struct Entry {
    char title[20];
    char content[1000];
    struct Entry* next;
} Entry;

// Function to create a new entry in the digital diary
Entry* createEntry() {
    Entry* newEntry = malloc(sizeof(Entry));
    newEntry->title[0] = '\0';
    newEntry->content[0] = '\0';
    newEntry->next = NULL;
    return newEntry;
}

// Function to add an entry to the digital diary
void addEntry(Entry* head) {
    Entry* newEntry = createEntry();
    printf("Enter the title of your entry: ");
    scanf("%s", newEntry->title);
    printf("Enter the content of your entry: ");
    scanf("%s", newEntry->content);
    if (head == NULL) {
        head = newEntry;
    } else {
        head->next = newEntry;
    }
    head = newEntry;
}

// Function to display all entries in the digital diary
void displayEntries(Entry* head) {
    Entry* currentEntry = head;
    while (currentEntry) {
        printf("Title: %s\n", currentEntry->title);
        printf("Content: %s\n", currentEntry->content);
        printf("\n");
        currentEntry = currentEntry->next;
    }
}

int main() {
    Entry* head = NULL;
    int choice = 0;

    // Loop until the user chooses to quit
    while (choice != 3) {
        printf("Enter 1 to add an entry, 2 to display entries, or 3 to quit: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry(head);
                break;
            case 2:
                displayEntries(head);
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}