//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INDEX_SIZE 256

typedef struct {
    char *key;
    char *value;
} IndexEntry;

typedef struct {
    IndexEntry *entries;
    int num_entries;
    int max_entries;
} Index;

void initIndex(Index *index) {
    index->num_entries = 0;
    index->max_entries = 0;
    index->entries = NULL;
}

void addIndexEntry(Index *index, char *key, char *value) {
    if (index->num_entries >= index->max_entries) {
        IndexEntry *new_entries = (IndexEntry *)realloc(index->entries, (index->max_entries + 1) * sizeof(IndexEntry));
        if (new_entries == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }
        index->entries = new_entries;
        index->max_entries += 1;
    }
    IndexEntry new_entry = {key, value};
    index->entries[index->num_entries] = new_entry;
    index->num_entries += 1;
}

char *getIndexEntry(Index *index, char *key) {
    for (int i = 0; i < index->num_entries; i++) {
        if (strcmp(index->entries[i].key, key) == 0) {
            return index->entries[i].value;
        }
    }
    return NULL;
}

int main() {
    Index index;
    initIndex(&index);
    addIndexEntry(&index, "apple", "fruit");
    addIndexEntry(&index, "banana", "fruit");
    addIndexEntry(&index, "orange", "fruit");
    addIndexEntry(&index, "carrot", "vegetable");
    addIndexEntry(&index, "broccoli", "vegetable");
    addIndexEntry(&index, "tomato", "fruit");

    char *apple = getIndexEntry(&index, "apple");
    if (apple!= NULL) {
        printf("Apple is a %s\n", apple);
    }
    else {
        printf("Apple is not found\n");
    }

    char *banana = getIndexEntry(&index, "banana");
    if (banana!= NULL) {
        printf("Banana is a %s\n", banana);
    }
    else {
        printf("Banana is not found\n");
    }

    char *carrot = getIndexEntry(&index, "carrot");
    if (carrot!= NULL) {
        printf("Carrot is a %s\n", carrot);
    }
    else {
        printf("Carrot is not found\n");
    }

    char *broccoli = getIndexEntry(&index, "broccoli");
    if (broccoli!= NULL) {
        printf("Broccoli is a %s\n", broccoli);
    }
    else {
        printf("Broccoli is not found\n");
    }

    char *tomato = getIndexEntry(&index, "tomato");
    if (tomato!= NULL) {
        printf("Tomato is a %s\n", tomato);
    }
    else {
        printf("Tomato is not found\n");
    }

    return 0;
}