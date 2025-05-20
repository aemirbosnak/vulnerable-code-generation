//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INDEX_ENTRIES 1024

typedef struct IndexEntry {
    char *key;
    int data_index;
    struct IndexEntry *next;
} IndexEntry;

IndexEntry *insert_index_entry(IndexEntry *head, char *key, int data_index) {
    IndexEntry *new_entry = malloc(sizeof(IndexEntry));
    new_entry->key = strdup(key);
    new_entry->data_index = data_index;
    new_entry->next = NULL;

    if (head == NULL) {
        head = new_entry;
    } else {
        IndexEntry *prev = head;
        IndexEntry *curr = head;
        while (curr) {
            if (strcmp(curr->key, key) < 0) {
                prev = curr;
                curr = curr->next;
            } else if (strcmp(curr->key, key) == 0) {
                prev = curr;
                curr = curr->next;
            } else {
                break;
            }
        }
        prev->next = new_entry;
    }

    return head;
}

int search_index(IndexEntry *head, char *key) {
    IndexEntry *curr = head;
    while (curr) {
        if (strcmp(curr->key, key) == 0) {
            return curr->data_index;
        }
        curr = curr->next;
    }

    return -1;
}

int main() {
    IndexEntry *head = NULL;
    head = insert_index_entry(head, "John Doe", 12);
    head = insert_index_entry(head, "Jane Doe", 14);
    head = insert_index_entry(head, "Peter Pan", 16);

    int data_index = search_index(head, "Jane Doe");
    if (data_index != -1) {
        printf("Data index for Jane Doe is: %d\n", data_index);
    } else {
        printf("Key not found.\n");
    }

    return 0;
}