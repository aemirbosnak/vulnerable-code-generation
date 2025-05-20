//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 100
#define MAX_VALUE_LENGTH 1000
#define MAX_INDEX_SIZE 10000

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} Record;

typedef struct {
    Record data[MAX_INDEX_SIZE];
    int numRecords;
} Index;

Index* createIndex() {
    Index* index = (Index*)malloc(sizeof(Index));
    index->numRecords = 0;
    return index;
}

void addRecord(Index* index, const char* key, const char* value) {
    if (index->numRecords >= MAX_INDEX_SIZE) {
        printf("Error: Index is full.\n");
        return;
    }

    Record* record = &index->data[index->numRecords];
    strcpy(record->key, key);
    strcpy(record->value, value);

    index->numRecords++;
}

void searchIndex(Index* index, const char* key) {
    int i;
    for (i = 0; i < index->numRecords; i++) {
        if (strcmp(index->data[i].key, key) == 0) {
            printf("Found record with key '%s': %s\n", key, index->data[i].value);
            return;
        }
    }

    printf("No record found with key '%s'.\n", key);
}

int main() {
    Index* index = createIndex();

    addRecord(index, "John", "123 Main St.");
    addRecord(index, "Jane", "456 Elm Ave.");
    addRecord(index, "Bob", "789 Oak Blvd.");

    searchIndex(index, "John");
    searchIndex(index, "Dave");

    return 0;
}