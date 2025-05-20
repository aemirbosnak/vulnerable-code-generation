//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store diary entries
typedef struct DiaryEntry {
    char *title;
    char *entry;
    struct DiaryEntry *next;
} DiaryEntry;

// Function to insert a new entry into the diary
void insertEntry(DiaryEntry **head, char *title, char *entry) {
    DiaryEntry *newEntry = malloc(sizeof(DiaryEntry));
    newEntry->title = strdup(title);
    newEntry->entry = strdup(entry);
    newEntry->next = NULL;

    if (*head == NULL) {
        *head = newEntry;
    } else {
        (*head)->next = newEntry;
    }
}

// Function to read an entry from the diary
char *readEntry(DiaryEntry *head, char *title) {
    while (head) {
        if (strcmp(head->title, title) == 0) {
            return head->entry;
        }
        head = head->next;
    }

    return NULL;
}

int main() {
    DiaryEntry *head = NULL;

    // Insert some entries into the diary
    insertEntry(&head, "My First Entry", "This is my first entry into the diary.");
    insertEntry(&head, "My Second Entry", "This is my second entry into the diary.");
    insertEntry(&head, "My Third Entry", "This is my third entry into the diary.");

    // Read an entry from the diary
    char *entry = readEntry(head, "My Second Entry");

    // Print the entry
    if (entry) {
        printf("%s\n", entry);
    } else {
        printf("Entry not found.\n");
    }

    return 0;
}