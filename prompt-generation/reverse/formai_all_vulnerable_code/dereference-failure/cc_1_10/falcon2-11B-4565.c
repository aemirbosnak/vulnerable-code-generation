//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_NAME_LEN 20

// Structure to hold a record
typedef struct record {
    char name[MAX_NAME_LEN];
    int id;
} Record;

// Structure to hold a database index
typedef struct index {
    int id;
    Record records[MAX_ROWS];
} Index;

// Function to create a new index
Index* createIndex() {
    Index* index = (Index*)malloc(sizeof(Index));
    if (index == NULL) {
        fprintf(stderr, "Error: failed to allocate memory for index\n");
        exit(1);
    }
    return index;
}

// Function to add a record to the index
void addRecord(Index* index, const char* name, int id) {
    Record* record = &index->records[index->id];
    strcpy(record->name, name);
    record->id = id;
    index->id++;
}

// Function to search for a record in the index
Record* findRecord(Index* index, const char* name) {
    int i;
    Record* record = NULL;
    for (i = 0; i < index->id; i++) {
        if (strcmp(index->records[i].name, name) == 0) {
            record = &index->records[i];
            break;
        }
    }
    return record;
}

// Function to display all records in the index
void displayRecords(Index* index) {
    int i;
    for (i = 0; i < index->id; i++) {
        printf("Record %d: %s\n", i + 1, index->records[i].name);
    }
}

// Function to free memory allocated for the index
void freeIndex(Index* index) {
    free(index);
}

// Main function
int main() {
    Index* index = createIndex();
    if (index == NULL) {
        return 1;
    }

    addRecord(index, "John Doe", 1);
    addRecord(index, "Jane Doe", 2);
    addRecord(index, "Bob Smith", 3);

    displayRecords(index);

    Record* record = findRecord(index, "Jane Doe");
    if (record!= NULL) {
        printf("Found record for Jane Doe\n");
    } else {
        printf("Record not found\n");
    }

    freeIndex(index);

    return 0;
}