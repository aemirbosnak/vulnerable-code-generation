//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: intelligent
#include <stdio.h>
#include <string.h>

#define MAX_ENTRIES 10

typedef struct Entry {
    char title[50];
    char content[200];
    struct Entry* next;
} Entry;

Entry* head = NULL;

void addEntry() {
    Entry* newEntry = (Entry*)malloc(sizeof(Entry));
    printf("Enter title: ");
    scanf("%s", newEntry->title);
    printf("Enter content: ");
    scanf("%s", newEntry->content);
    newEntry->next = head;
    head = newEntry;
}

void displayEntries() {
    Entry* currentEntry = head;
    printf("Entries:\n");
    while (currentEntry) {
        printf("Title: %s\n", currentEntry->title);
        printf("Content: %s\n", currentEntry->content);
        printf("\n");
        currentEntry = currentEntry->next;
    }
}

void searchEntries() {
    char searchTerm[50];
    printf("Enter search term: ");
    scanf("%s", searchTerm);
    Entry* currentEntry = head;
    while (currentEntry) {
        if (strstr(currentEntry->title, searchTerm) || strstr(currentEntry->content, searchTerm)) {
            printf("Title: %s\n", currentEntry->title);
            printf("Content: %s\n", currentEntry->content);
            printf("\n");
        }
        currentEntry = currentEntry->next;
    }
}

int main() {
    int choice;

    while (1) {
        printf("1. Add Entry\n");
        printf("2. Display Entries\n");
        printf("3. Search Entries\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                displayEntries();
                break;
            case 3:
                searchEntries();
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}