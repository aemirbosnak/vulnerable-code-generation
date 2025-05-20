//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_VALUE_LENGTH 1000

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} Record;

typedef struct {
    Record records[MAX_KEY_LENGTH];
    int count;
} Index;

// Function to create a new index
Index* createIndex() {
    Index* index = (Index*)malloc(sizeof(Index));
    index->count = 0;
    return index;
}

// Function to add a new record to the index
void addRecord(Index* index, char* key, char* value) {
    strcpy(index->records[index->count].key, key);
    strcpy(index->records[index->count].value, value);
    index->count++;
}

// Function to search for a record in the index
Record* searchRecord(Index* index, char* key) {
    int i;
    for (i = 0; i < index->count; i++) {
        if (strcmp(index->records[i].key, key) == 0) {
            return &(index->records[i]);
        }
    }
    return NULL;
}

// Function to print all records in the index
void printRecords(Index* index) {
    int i;
    for (i = 0; i < index->count; i++) {
        printf("Key: %s, Value: %s\n", index->records[i].key, index->records[i].value);
    }
}

int main() {
    Index* index = createIndex();
    addRecord(index, "John", "Doe");
    addRecord(index, "Jane", "Doe");
    addRecord(index, "Bob", "Smith");
    printRecords(index);
    Record* record = searchRecord(index, "John");
    if (record!= NULL) {
        printf("Found record: %s, %s\n", record->key, record->value);
    } else {
        printf("Record not found.\n");
    }
    return 0;
}