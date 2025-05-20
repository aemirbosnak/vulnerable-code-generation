//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INDEX_ENTRIES 1024

typedef struct IndexEntry {
    char *key;
    int data;
    struct IndexEntry *next;
} IndexEntry;

IndexEntry *insertIndexEntry(IndexEntry *head, char *key, int data) {
    IndexEntry *newEntry = malloc(sizeof(IndexEntry));
    newEntry->key = strdup(key);
    newEntry->data = data;
    newEntry->next = NULL;

    if (head == NULL) {
        head = newEntry;
    } else {
        IndexEntry *prev = head;
        IndexEntry *curr = head;
        while (curr) {
            if (strcmp(curr->key, key) == 0) {
                return NULL;
            } else if (strcmp(curr->key, key) < 0) {
                prev = curr;
                curr = curr->next;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }

        prev->next = newEntry;
    }

    return head;
}

int searchIndexEntry(IndexEntry *head, char *key) {
    IndexEntry *curr = head;
    while (curr) {
        if (strcmp(curr->key, key) == 0) {
            return curr->data;
        }
        curr = curr->next;
    }

    return -1;
}

int main() {
    IndexEntry *head = NULL;
    insertIndexEntry(head, "John Doe", 12);
    insertIndexEntry(head, "Jane Doe", 14);
    insertIndexEntry(head, "Bill Smith", 16);

    int data = searchIndexEntry(head, "Jane Doe");
    if (data != -1) {
        printf("Data for Jane Doe: %d\n", data);
    } else {
        printf("Key not found: Jane Doe\n");
    }

    return 0;
}