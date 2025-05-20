//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_SIZE 10

typedef struct IndexEntry {
    char key[MAX_INDEX_SIZE];
    struct IndexEntry* next;
} IndexEntry;

typedef struct Database {
    IndexEntry** buckets;
    int numBuckets;
    int numEntries;
} Database;

void insertEntry(Database* db, char* key) {
    IndexEntry* newEntry = malloc(sizeof(IndexEntry));
    strcpy(newEntry->key, key);
    newEntry->next = NULL;

    if (db->numEntries == 0) {
        db->buckets = malloc(sizeof(IndexEntry*) * db->numBuckets);
        db->buckets[0] = newEntry;
        db->numEntries++;
    } else {
        IndexEntry* prevEntry = db->buckets[0];
        for (int i = 1; prevEntry->next != NULL; i++) {
            prevEntry = prevEntry->next;
        }
        prevEntry->next = newEntry;
        db->numEntries++;
    }
}

int main() {
    Database* db = malloc(sizeof(Database));
    db->buckets = NULL;
    db->numBuckets = 0;
    db->numEntries = 0;

    insertEntry(db, "John");
    insertEntry(db, "Mary");
    insertEntry(db, "Bob");

    IndexEntry* entry = db->buckets[0];
    while (entry) {
        printf("%s\n", entry->key);
        entry = entry->next;
    }

    free(db);

    return 0;
}