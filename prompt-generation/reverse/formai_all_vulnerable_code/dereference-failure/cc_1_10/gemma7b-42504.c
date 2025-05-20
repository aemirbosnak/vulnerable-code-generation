//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_INDEX_ENTRIES 100

typedef struct IndexEntry {
    char key[255];
    struct IndexEntry* next;
} IndexEntry;

IndexEntry* InsertIndexEntry(IndexEntry* head, char key) {
    IndexEntry* newEntry = malloc(sizeof(IndexEntry));
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

void SearchIndex(IndexEntry* head, char key) {
    IndexEntry* current = head;
    while (current) {
        if (strcmp(current->key, key) == 0) {
            printf("Key found: %s\n", current->key);
            return;
        }
        current = current->next;
    }

    printf("Key not found: %s\n", key);
}

int main() {
    IndexEntry* head = NULL;

    InsertIndexEntry(head, 'a');
    InsertIndexEntry(head, 'b');
    InsertIndexEntry(head, 'c');
    InsertIndexEntry(head, 'd');

    SearchIndex(head, 'b');
    SearchIndex(head, 'e');

    return 0;
}