//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 100
#define MAX_VALUE_LEN 1000
#define MAX_INDEX_LEN 1000

typedef struct {
    char key[MAX_KEY_LEN];
    char value[MAX_VALUE_LEN];
} Record;

typedef struct {
    Record records[MAX_INDEX_LEN];
    int numRecords;
} Index;

Index* createIndex() {
    Index *index = (Index*) malloc(sizeof(Index));
    index->numRecords = 0;
    return index;
}

int addRecordToIndex(Index *index, char *key, char *value) {
    Record record;
    strncpy(record.key, key, MAX_KEY_LEN);
    strncpy(record.value, value, MAX_VALUE_LEN);
    if (index->numRecords >= MAX_INDEX_LEN) {
        printf("Index is full. Cannot add record.\n");
        return -1;
    }
    index->records[index->numRecords++] = record;
    return 0;
}

int searchIndex(Index *index, char *key) {
    for (int i = 0; i < index->numRecords; i++) {
        if (strcmp(index->records[i].key, key) == 0) {
            printf("%s\n", index->records[i].value);
            return 0;
        }
    }
    printf("Record not found.\n");
    return -1;
}

int main() {
    Index *index = createIndex();
    addRecordToIndex(index, "John", "25");
    addRecordToIndex(index, "Jane", "30");
    addRecordToIndex(index, "Bob", "40");
    searchIndex(index, "John");
    searchIndex(index, "Alice");
    return 0;
}