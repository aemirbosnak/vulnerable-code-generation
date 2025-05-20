//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 100
#define MAX_VAL_LEN 1000
#define MAX_INDEX_SIZE 100000

typedef struct {
    char key[MAX_KEY_LEN];
    char val[MAX_VAL_LEN];
} Record;

typedef struct {
    Record *data;
    int size;
} Index;

Index *createIndex() {
    Index *index = malloc(sizeof(Index));
    index->data = malloc(MAX_INDEX_SIZE * sizeof(Record));
    index->size = 0;
    return index;
}

void addRecord(Index *index, char *key, char *val) {
    Record *rec = malloc(sizeof(Record));
    strncpy(rec->key, key, MAX_KEY_LEN);
    strncpy(rec->val, val, MAX_VAL_LEN);
    index->data[index->size++] = *rec;
    free(rec);
}

void searchIndex(Index *index, char *key) {
    int i;
    for (i = 0; i < index->size; i++) {
        if (strcmp(index->data[i].key, key) == 0) {
            printf("Value for key %s: %s\n", key, index->data[i].val);
            return;
        }
    }
    printf("No record found for key %s\n", key);
}

int main() {
    Index *index = createIndex();

    addRecord(index, "apple", "red");
    addRecord(index, "banana", "yellow");
    addRecord(index, "cherry", "red");

    searchIndex(index, "apple");
    searchIndex(index, "orange");

    return 0;
}