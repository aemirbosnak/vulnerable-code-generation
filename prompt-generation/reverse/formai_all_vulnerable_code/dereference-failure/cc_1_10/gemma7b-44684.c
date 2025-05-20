//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: detailed
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1024

typedef struct Entry {
    char title[MAX_SIZE];
    char content[MAX_SIZE];
    struct Entry* next;
} Entry;

Entry* createEntry() {
    Entry* newEntry = (Entry*)malloc(sizeof(Entry));
    newEntry->title[0] = '\0';
    newEntry->content[0] = '\0';
    newEntry->next = NULL;
    return newEntry;
}

void addEntry(Entry* head, char* title, char* content) {
    Entry* newEntry = createEntry();
    strcpy(newEntry->title, title);
    strcpy(newEntry->content, content);

    if (head == NULL) {
        head = newEntry;
    } else {
        head->next = newEntry;
    }
    head = newEntry;
}

void printEntries(Entry* head) {
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

    addEntry(head, "My First Entry", "This is my first entry.");
    addEntry(head, "My Second Entry", "This is my second entry.");
    addEntry(head, "My Third Entry", "This is my third entry.");

    printEntries(head);

    return 0;
}