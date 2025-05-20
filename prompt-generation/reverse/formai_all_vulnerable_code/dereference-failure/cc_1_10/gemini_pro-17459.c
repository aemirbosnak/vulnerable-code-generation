//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Entry {
    char *title;
    char *content;
    struct Entry *next;
} Entry;

Entry *head = NULL;

void addEntry(char *title, char *content) {
    Entry *newEntry = malloc(sizeof(Entry));
    newEntry->title = malloc(strlen(title) + 1);
    strcpy(newEntry->title, title);
    newEntry->content = malloc(strlen(content) + 1);
    strcpy(newEntry->content, content);
    newEntry->next = NULL;

    if (head == NULL) {
        head = newEntry;
    } else {
        Entry *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newEntry;
    }
}

void printEntry(Entry *entry) {
    printf("Title: %s\n", entry->title);
    printf("Content: %s\n", entry->content);
}

void printAllEntries() {
    Entry *current = head;
    while (current != NULL) {
        printEntry(current);
        current = current->next;
    }
}

void deleteEntry(char *title) {
    Entry *current = head;
    Entry *prev = NULL;
    while (current != NULL) {
        if (strcmp(current->title, title) == 0) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current->title);
            free(current->content);
            free(current);
            break;
        }
        prev = current;
        current = current->next;
    }
}

int main() {
    addEntry("My First Entry", "This is my first entry in my digital diary.");
    addEntry("My Second Entry", "This is my second entry in my digital diary.");
    addEntry("My Third Entry", "This is my third entry in my digital diary.");

    printAllEntries();

    deleteEntry("My Second Entry");

    printAllEntries();

    return 0;
}