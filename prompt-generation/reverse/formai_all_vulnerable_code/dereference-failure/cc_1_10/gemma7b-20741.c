//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define MAX_INDEX_SIZE 10

typedef struct IndexEntry {
    char data[MAX_INDEX_SIZE];
    struct IndexEntry* next;
} IndexEntry;

IndexEntry* insertIndexEntry(IndexEntry* head, char data[]) {
    IndexEntry* newEntry = (IndexEntry*)malloc(sizeof(IndexEntry));
    newEntry->next = NULL;
    strcpy(newEntry->data, data);

    if (head == NULL) {
        head = newEntry;
    } else {
        head->next = newEntry;
    }

    return head;
}

void searchIndex(IndexEntry* head, char data[]) {
    IndexEntry* currentEntry = head;

    while (currentEntry) {
        if (strcmp(currentEntry->data, data) == 0) {
            printf("Data found: %s\n", currentEntry->data);
            return;
        }

        currentEntry = currentEntry->next;
    }

    printf("Data not found.\n");
}

int main() {
    IndexEntry* head = NULL;

    insertIndexEntry(head, "John Doe");
    insertIndexEntry(head, "Jane Doe");
    insertIndexEntry(head, "Peter Pan");

    searchIndex(head, "Jane Doe");

    return 0;
}