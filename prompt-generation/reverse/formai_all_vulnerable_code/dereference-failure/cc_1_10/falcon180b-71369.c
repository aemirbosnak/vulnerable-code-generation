//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 100
#define MAX_VALUE_LEN 1000
#define MAX_INDEX_COUNT 100

typedef struct {
    char key[MAX_KEY_LEN];
    char value[MAX_VALUE_LEN];
} Record;

typedef struct {
    Record record;
    int indexCount;
} Index;

Index *createIndex(int count) {
    Index *index = malloc(sizeof(Index));
    index->indexCount = 0;
    index->record.key[0] = '\0';
    index->record.value[0] = '\0';
    return index;
}

void addIndex(Index *index, char *key) {
    if (index->indexCount >= MAX_INDEX_COUNT) {
        printf("Error: Index count exceeded\n");
        return;
    }
    strcpy(index->record.key, key);
    index->indexCount++;
}

void printIndex(Index *index) {
    printf("Index:\n");
    printf("Key: %s\n", index->record.key);
    printf("Value: %s\n", index->record.value);
    printf("Index count: %d\n", index->indexCount);
}

int main() {
    Index *index = createIndex(1);
    addIndex(index, "John");
    printIndex(index);

    addIndex(index, "Jane");
    printIndex(index);

    addIndex(index, "Jack");
    printIndex(index);

    return 0;
}