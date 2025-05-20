//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_SIZE 100

typedef struct IndexEntry {
    char key[MAX_INDEX_SIZE];
    struct IndexEntry* next;
} IndexEntry;

IndexEntry* insertIndexEntry(IndexEntry* head, char key) {
    IndexEntry* newEntry = malloc(sizeof(IndexEntry));
    strcpy(newEntry->key, key);
    newEntry->next = NULL;

    if (head == NULL) {
        head = newEntry;
    } else {
        IndexEntry* current = head;
        IndexEntry* previous = NULL;
        while (current) {
            if (strcmp(current->key, key) == 0) {
                return NULL;
            } else if (previous == NULL) {
                previous = current;
            }
            current = current->next;
        }
        previous->next = newEntry;
    }

    return head;
}

int main() {
    IndexEntry* index = NULL;
    insertIndexEntry(index, "John Doe");
    insertIndexEntry(index, "Jane Doe");
    insertIndexEntry(index, "Jack Doe");
    insertIndexEntry(index, "Jill Doe");

    IndexEntry* current = index;
    while (current) {
        printf("%s\n", current->key);
        current = current->next;
    }

    return 0;
}