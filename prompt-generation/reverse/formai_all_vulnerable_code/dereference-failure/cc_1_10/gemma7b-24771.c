//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>

#define MAX_INDEX_ENTRIES 1024

typedef struct IndexEntry {
    char *key;
    struct IndexEntry *next;
} IndexEntry;

IndexEntry *insertIndexEntry(IndexEntry *head, char *key);
void printIndexEntries(IndexEntry *head);

int main() {
    IndexEntry *head = NULL;
    char key[256];

    printf("Enter a key: ");
    scanf("%s", key);

    insertIndexEntry(head, key);

    printf("Index entries:\n");
    printIndexEntries(head);

    return 0;
}

IndexEntry *insertIndexEntry(IndexEntry *head, char *key) {
    IndexEntry *newEntry = malloc(sizeof(IndexEntry));
    newEntry->key = strdup(key);
    newEntry->next = NULL;

    if (head == NULL) {
        head = newEntry;
    } else {
        IndexEntry *traverse = head;
        while (traverse->next) {
            traverse = traverse->next;
        }
        traverse->next = newEntry;
    }

    return head;
}

void printIndexEntries(IndexEntry *head) {
    IndexEntry *traverse = head;
    while (traverse) {
        printf("%s\n", traverse->key);
        traverse = traverse->next;
    }
}