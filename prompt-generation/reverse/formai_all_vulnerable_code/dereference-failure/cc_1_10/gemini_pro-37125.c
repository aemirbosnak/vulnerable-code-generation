//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Entry structure
typedef struct {
    char date[11];
    char time[9];
    char title[51];
    char content[1001];
} Entry;

// Node structure
typedef struct Node {
    Entry entry;
    struct Node *next;
} Node;

// Head of the linked list
Node *head = NULL;

// Add a new entry to the linked list
void addEntry(Entry entry) {
    Node *newEntry = (Node *)malloc(sizeof(Node));
    newEntry->entry = entry;
    newEntry->next = head;
    head = newEntry;
}

// Print all entries in the linked list
void printEntries() {
    Node *current = head;
    while (current != NULL) {
        printf("Date: %s\n", current->entry.date);
        printf("Time: %s\n", current->entry.time);
        printf("Title: %s\n", current->entry.title);
        printf("Content: %s\n\n", current->entry.content);
        current = current->next;
    }
}

// Search for an entry by title
Entry *searchEntry(char *title) {
    Node *current = head;
    while (current != NULL) {
        if (strcmp(current->entry.title, title) == 0) {
            return &current->entry;
        }
        current = current->next;
    }
    return NULL;
}

// Edit an entry by title
void editEntry(char *title) {
    Entry *entry = searchEntry(title);
    if (entry != NULL) {
        printf("Enter new date (YYYY-MM-DD): ");
        scanf("%s", entry->date);
        printf("Enter new time (HH:MM:SS): ");
        scanf("%s", entry->time);
        printf("Enter new title: ");
        scanf("%s", entry->title);
        printf("Enter new content: ");
        scanf("%s", entry->content);
    } else {
        printf("Entry not found!\n");
    }
}

// Delete an entry by title
void deleteEntry(char *title) {
    Node *current = head;
    Node *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->entry.title, title) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Entry not found!\n");
}

// Main function
int main() {
    int choice;
    Entry entry;
    char title[51];

    while (1) {
        // Display menu
        printf("\nDigital Diary\n");
        printf("1. Add a new entry\n");
        printf("2. Print all entries\n");
        printf("3. Search for an entry\n");
        printf("4. Edit an entry\n");
        printf("5. Delete an entry\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Add a new entry
                printf("Enter date (YYYY-MM-DD): ");
                scanf("%s", entry.date);
                printf("Enter time (HH:MM:SS): ");
                scanf("%s", entry.time);
                printf("Enter title: ");
                scanf("%s", entry.title);
                printf("Enter content: ");
                scanf("%s", entry.content);
                addEntry(entry);
                break;
            case 2: // Print all entries
                printEntries();
                break;
            case 3: // Search for an entry
                printf("Enter title: ");
                scanf("%s", title);
                Entry *foundEntry = searchEntry(title);
                if (foundEntry != NULL) {
                    printf("Date: %s\n", foundEntry->date);
                    printf("Time: %s\n", foundEntry->time);
                    printf("Title: %s\n", foundEntry->title);
                    printf("Content: %s\n", foundEntry->content);
                } else {
                    printf("Entry not found!\n");
                }
                break;
            case 4: // Edit an entry
                printf("Enter title: ");
                scanf("%s", title);
                editEntry(title);
                break;
            case 5: // Delete an entry
                printf("Enter title: ");
                scanf("%s", title);
                deleteEntry(title);
                break;
            case 6: // Exit
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}