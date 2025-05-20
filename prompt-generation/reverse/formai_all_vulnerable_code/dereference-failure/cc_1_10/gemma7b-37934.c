//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 100
#define KEY_LEN 20

struct Entry {
    char key[KEY_LEN];
    struct Entry* next;
};

struct Index {
    struct Entry** buckets;
    int numBuckets;
    int entries;
};

struct Index* createIndex(int numBuckets) {
    struct Index* index = malloc(sizeof(struct Index));
    index->buckets = malloc(numBuckets * sizeof(struct Entry**));
    index->numBuckets = numBuckets;
    index->entries = 0;

    for (int i = 0; i < numBuckets; i++) {
        index->buckets[i] = NULL;
    }

    return index;
}

void insertEntry(struct Index* index, char* key) {
    int bucketIndex = hashKey(key) % index->numBuckets;

    struct Entry* entry = malloc(sizeof(struct Entry));
    strcpy(entry->key, key);
    entry->next = index->buckets[bucketIndex];
    index->buckets[bucketIndex] = entry;
    index->entries++;
}

struct Entry* searchEntry(struct Index* index, char* key) {
    int bucketIndex = hashKey(key) % index->numBuckets;

    for (struct Entry* entry = index->buckets[bucketIndex]; entry; entry = entry->next) {
        if (strcmp(entry->key, key) == 0) {
            return entry;
        }
    }

    return NULL;
}

int hashKey(char* key) {
    int hash = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hash = (hash * 33) + key[i];
    }

    return hash;
}

int main() {
    struct Index* index = createIndex(10);

    insertEntry(index, "Alice");
    insertEntry(index, "Bob");
    insertEntry(index, "Charlie");

    struct Entry* entry = searchEntry(index, "Bob");

    if (entry) {
        printf("Entry found: %s\n", entry->key);
    } else {
        printf("Entry not found\n");
    }

    return 0;
}