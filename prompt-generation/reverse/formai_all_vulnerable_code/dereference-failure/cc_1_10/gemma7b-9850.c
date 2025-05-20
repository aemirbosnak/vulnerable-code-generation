//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_ENTRIES 100

typedef struct IndexEntry {
    char key[MAX_INDEX_ENTRIES];
    struct IndexEntry* next;
} IndexEntry;

IndexEntry* insertIndexEntry(IndexEntry* head, char key) {
    IndexEntry* newEntry = (IndexEntry*)malloc(sizeof(IndexEntry));
    newEntry->key[0] = key;
    newEntry->next = NULL;

    if (head == NULL) {
        head = newEntry;
    } else {
        IndexEntry* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newEntry;
    }

    return head;
}

int searchIndexEntry(IndexEntry* head, char key) {
    IndexEntry* current = head;
    while (current) {
        if (strcmp(current->key, key) == 0) {
            return 1;
        }
        current = current->next;
    }

    return 0;
}

int main() {
    IndexEntry* indexHead = NULL;

    insertIndexEntry(indexHead, 'a');
    insertIndexEntry(indexHead, 'b');
    insertIndexEntry(indexHead, 'c');

    if (searchIndexEntry(indexHead, 'b') == 1) {
        printf("Key 'b' found!\n");
    }

    return 0;
}