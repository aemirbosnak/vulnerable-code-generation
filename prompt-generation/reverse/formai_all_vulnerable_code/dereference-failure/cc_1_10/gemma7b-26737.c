//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255
#define MAX_INDEX_ENTRIES 100

typedef struct IndexEntry {
    char name[MAX_NAME_LENGTH];
    int index;
    struct IndexEntry* next;
} IndexEntry;

IndexEntry* createIndexEntry(char* name, int index) {
    IndexEntry* entry = malloc(sizeof(IndexEntry));
    strcpy(entry->name, name);
    entry->index = index;
    entry->next = NULL;
    return entry;
}

void insertIndexEntry(IndexEntry* head, char* name, int index) {
    IndexEntry* newEntry = createIndexEntry(name, index);
    if (head == NULL) {
        head = newEntry;
    } else {
        IndexEntry* current = head;
        IndexEntry* previous = NULL;
        while (current) {
            if (strcmp(current->name, name) == 0) {
                return;
            } else if (previous == NULL) {
                previous = current;
            }
            current = current->next;
        }
        previous->next = newEntry;
    }
}

int searchIndexEntry(IndexEntry* head, char* name) {
    IndexEntry* current = head;
    while (current) {
        if (strcmp(current->name, name) == 0) {
            return current->index;
        }
        current = current->next;
    }
    return -1;
}

int main() {
    IndexEntry* indexHead = NULL;
    insertIndexEntry(indexHead, "Sir Robin", 1);
    insertIndexEntry(indexHead, "Lady Alice", 2);
    insertIndexEntry(indexHead, "The Knight of the Round Table", 3);

    int index = searchIndexEntry(indexHead, "Lady Alice");
    if (index != -1) {
        printf("Index of Lady Alice: %d\n", index);
    } else {
        printf("Lady Alice not found.\n");
    }

    return 0;
}