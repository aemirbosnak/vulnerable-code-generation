//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_INDEX_SIZE 100

typedef struct IndexEntry {
    char key[MAX_INDEX_SIZE];
    struct IndexEntry* next;
} IndexEntry;

IndexEntry* createIndexEntry(char* key) {
    IndexEntry* newEntry = (IndexEntry*)malloc(sizeof(IndexEntry));
    strcpy(newEntry->key, key);
    newEntry->next = NULL;
    return newEntry;
}

void insertIndexEntry(IndexEntry* head, char* key) {
    IndexEntry* newEntry = createIndexEntry(key);
    if (head == NULL) {
        head = newEntry;
    } else {
        IndexEntry* currentEntry = head;
        while (currentEntry->next != NULL) {
            currentEntry = currentEntry->next;
        }
        currentEntry->next = newEntry;
    }
}

void searchIndexEntry(IndexEntry* head, char* key) {
    IndexEntry* currentEntry = head;
    while (currentEntry) {
        if (strcmp(currentEntry->key, key) == 0) {
            printf("Key found: %s\n", currentEntry->key);
            return;
        }
        currentEntry = currentEntry->next;
    }
    printf("Key not found: %s\n", key);
}

int main() {
    IndexEntry* head = NULL;
    insertIndexEntry(head, "a");
    insertIndexEntry(head, "b");
    insertIndexEntry(head, "c");
    insertIndexEntry(head, "d");
    searchIndexEntry(head, "b");
    searchIndexEntry(head, "f");
    return 0;
}