//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_ENTRIES 100

typedef struct IndexEntry {
    char *key;
    struct IndexEntry *next;
} IndexEntry;

IndexEntry *insertIndexEntry(IndexEntry *head, char *key) {
    IndexEntry *newEntry = malloc(sizeof(IndexEntry));
    newEntry->key = strdup(key);
    newEntry->next = NULL;

    if (head == NULL) {
        head = newEntry;
    } else {
        IndexEntry *prev = head;
        IndexEntry *curr = head;

        while (curr) {
            if (strcmp(key, curr->key) < 0) {
                prev = curr;
                curr = curr->next;
            } else if (strcmp(key, curr->key) == 0) {
                return NULL;
            }
        }

        prev->next = newEntry;
    }

    return head;
}

int main() {
    IndexEntry *head = NULL;

    insertIndexEntry(head, "a");
    insertIndexEntry(head, "b");
    insertIndexEntry(head, "c");
    insertIndexEntry(head, "d");
    insertIndexEntry(head, "e");

    IndexEntry *curr = head;

    while (curr) {
        printf("%s ", curr->key);
        curr = curr->next;
    }

    return 0;
}