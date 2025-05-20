//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX_INDEX 100

typedef struct IndexEntry {
    int key;
    struct IndexEntry* next;
} IndexEntry;

IndexEntry* InsertIndexEntry(IndexEntry* head, int key) {
    IndexEntry* newEntry = malloc(sizeof(IndexEntry));
    newEntry->key = key;
    newEntry->next = NULL;

    if (head == NULL) {
        head = newEntry;
    } else {
        IndexEntry* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newEntry;
    }

    return head;
}

void SearchIndexEntry(IndexEntry* head, int key) {
    IndexEntry* current = head;
    while (current) {
        if (current->key == key) {
            printf("Key found: %d\n", current->key);
            return;
        } else if (current->key > key) {
            current = current->next;
        } else {
            break;
        }
    }

    printf("Key not found.\n");
}

int main() {
    IndexEntry* head = NULL;

    InsertIndexEntry(head, 10);
    InsertIndexEntry(head, 20);
    InsertIndexEntry(head, 30);
    InsertIndexEntry(head, 40);
    InsertIndexEntry(head, 50);

    SearchIndexEntry(head, 30);
    SearchIndexEntry(head, 60);

    return 0;
}