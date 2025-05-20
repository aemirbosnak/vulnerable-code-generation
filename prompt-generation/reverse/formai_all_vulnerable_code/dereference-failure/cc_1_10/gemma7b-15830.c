//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INDEX_SIZE 1024

typedef struct IndexEntry {
    char key[MAX_INDEX_SIZE];
    struct IndexEntry* next;
} IndexEntry;

typedef struct IndexList {
    IndexEntry* head;
    IndexEntry* tail;
    int size;
} IndexList;

IndexList* CreateIndexList() {
    IndexList* list = (IndexList*)malloc(sizeof(IndexList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void InsertIndexEntry(IndexList* list, char* key) {
    IndexEntry* newEntry = (IndexEntry*)malloc(sizeof(IndexEntry));
    strcpy(newEntry->key, key);
    newEntry->next = NULL;

    if (list->head == NULL) {
        list->head = newEntry;
        list->tail = newEntry;
    } else {
        list->tail->next = newEntry;
        list->tail = newEntry;
    }

    list->size++;
}

char* FindIndexEntry(IndexList* list, char* key) {
    IndexEntry* currentEntry = list->head;

    while (currentEntry) {
        if (strcmp(currentEntry->key, key) == 0) {
            return currentEntry->key;
        }
        currentEntry = currentEntry->next;
    }

    return NULL;
}

int main() {
    IndexList* list = CreateIndexList();

    InsertIndexEntry(list, "John Doe");
    InsertIndexEntry(list, "Jane Doe");
    InsertIndexEntry(list, "Peter Pan");

    char* foundKey = FindIndexEntry(list, "Jane Doe");

    if (foundKey) {
        printf("Found key: %s\n", foundKey);
    } else {
        printf("Key not found.\n");
    }

    return 0;
}