//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_ENTRIES 1024

typedef struct IndexEntry {
    char key[256];
    int data;
    struct IndexEntry* next;
} IndexEntry;

typedef struct IndexManager {
    IndexEntry* head;
    int size;
    struct IndexManager* next;
} IndexManager;

void insertIndexEntry(IndexManager* manager, char* key, int data) {
    IndexEntry* newEntry = malloc(sizeof(IndexEntry));
    strcpy(newEntry->key, key);
    newEntry->data = data;
    newEntry->next = NULL;

    if (manager->head == NULL) {
        manager->head = newEntry;
    } else {
        IndexEntry* currentEntry = manager->head;
        while (currentEntry->next) {
            currentEntry = currentEntry->next;
        }
        currentEntry->next = newEntry;
    }

    manager->size++;
}

int searchIndexEntry(IndexManager* manager, char* key) {
    IndexEntry* currentEntry = manager->head;
    while (currentEntry) {
        if (strcmp(currentEntry->key, key) == 0) {
            return currentEntry->data;
        }
        currentEntry = currentEntry->next;
    }

    return -1;
}

int main() {
    IndexManager* manager = malloc(sizeof(IndexManager));
    manager->head = NULL;
    manager->size = 0;

    insertIndexEntry(manager, "abc", 10);
    insertIndexEntry(manager, "def", 20);
    insertIndexEntry(manager, "ghi", 30);

    int data = searchIndexEntry(manager, "def");

    if (data != -1) {
        printf("Data for key 'def': %d\n", data);
    } else {
        printf("Key not found.\n");
    }

    return 0;
}