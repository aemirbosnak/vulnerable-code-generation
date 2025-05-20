//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_ENTRIES 1024

typedef struct IndexEntry {
    char key[256];
    struct IndexEntry* next;
} IndexEntry;

IndexEntry* index_insert(IndexEntry* head, char* key) {
    IndexEntry* new_entry = malloc(sizeof(IndexEntry));
    strcpy(new_entry->key, key);
    new_entry->next = NULL;

    if (head == NULL) {
        head = new_entry;
    } else {
        IndexEntry* current = head;
        IndexEntry* previous = NULL;
        while (current) {
            if (strcmp(current->key, key) == 0) {
                return NULL;
            } else if (strcmp(current->key, key) < 0) {
                previous = current;
                current = current->next;
            } else {
                break;
            }
        }

        if (previous) {
            previous->next = new_entry;
        } else {
            head = new_entry;
        }
    }

    return head;
}

void index_search(IndexEntry* head, char* key) {
    IndexEntry* current = head;
    while (current) {
        if (strcmp(current->key, key) == 0) {
            printf("Key found: %s\n", current->key);
            return;
        } else if (strcmp(current->key, key) < 0) {
            current = current->next;
        } else {
            break;
        }
    }

    printf("Key not found: %s\n", key);
}

int main() {
    IndexEntry* head = NULL;

    index_insert(head, "a");
    index_insert(head, "b");
    index_insert(head, "c");
    index_insert(head, "d");

    index_search(head, "b");
    index_search(head, "e");

    return 0;
}