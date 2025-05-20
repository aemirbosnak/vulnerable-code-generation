//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a diary entry
typedef struct DiaryEntry {
    char *title;
    char *content;
    struct DiaryEntry *next;
} DiaryEntry;

// Function to insert a new diary entry at the end
void insertEntry(DiaryEntry **head) {
    DiaryEntry *newEntry = malloc(sizeof(DiaryEntry));
    newEntry->title = malloc(20);
    newEntry->content = malloc(200);
    newEntry->next = NULL;

    // Get the title and content of the new entry
    printf("Enter the title of the entry: ");
    scanf("%s", newEntry->title);

    printf("Enter the content of the entry: ");
    scanf("%s", newEntry->content);

    // If the head of the list is NULL, make it the first entry
    if (*head == NULL) {
        *head = newEntry;
    } else {
        (*head)->next = newEntry;
    }
}

// Function to print all diary entries
void printEntries(DiaryEntry *head) {
    while (head) {
        printf("Title: %s\n", head->title);
        printf("Content: %s\n", head->content);
        printf("\n");
        head = head->next;
    }
}

int main() {
    // Create a new diary entry list
    DiaryEntry *head = NULL;

    // Insert some entries
    insertEntry(&head);
    insertEntry(&head);
    insertEntry(&head);

    // Print all entries
    printEntries(head);

    return 0;
}