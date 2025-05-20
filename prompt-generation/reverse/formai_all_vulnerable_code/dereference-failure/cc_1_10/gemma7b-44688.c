//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1024
#define HASH_SIZE 256

typedef struct Entry {
    char name[MAX_ENTRIES];
    struct Entry* next;
} Entry;

Entry** hashTable = NULL;

void insertEntry(char* name) {
    Entry* newEntry = malloc(sizeof(Entry));
    strcpy(newEntry->name, name);
    newEntry->next = NULL;

    if (hashTable == NULL) {
        hashTable = malloc(sizeof(Entry**));
        *hashTable = NULL;
    }

    Entry** current = hashTable;
    while (*current) {
        if (strcmp((*current)->name, name) == 0) {
            return;
        }
        current = &((*current)->next);
    }

    *current = newEntry;
    return;
}

int main() {
    insertEntry("John Doe");
    insertEntry("Jane Doe");
    insertEntry("Jack Sparrow");
    insertEntry("Captain Morgan");

    Entry* entry = hashTable[0];
    while (entry) {
        printf("%s\n", entry->name);
        entry = entry->next;
    }

    return 0;
}