//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_INDEX_LENGTH 10

typedef struct Record {
    int id;
    char name[MAX_NAME_LENGTH];
    struct Record *next;
} Record;

typedef struct IndexNode {
    int id;
    struct IndexNode *next;
} IndexNode;

IndexNode *indexHead = NULL;

// Function to create a new record
Record *createRecord(int id, const char *name) {
    Record *newRecord = (Record *)malloc(sizeof(Record));
    newRecord->id = id;
    strncpy(newRecord->name, name, MAX_NAME_LENGTH);
    newRecord->next = NULL;
    return newRecord;
}

// Function to create a new index node
IndexNode *createIndexNode(int id) {
    IndexNode *newIndexNode = (IndexNode *)malloc(sizeof(IndexNode));
    newIndexNode->id = id;
    newIndexNode->next = NULL;
    return newIndexNode;
}

// Function to add a record to the database and update the index
void addRecord(int id, const char *name) {
    Record *record = createRecord(id, name);
    
    // Add record to the end of the linked list
    if (!indexHead) {
        indexHead = createIndexNode(id);
    } else {
        IndexNode *currentIndex = indexHead;
        while (currentIndex->next) {
            currentIndex = currentIndex->next;
        }
        currentIndex->next = createIndexNode(id);
    }
    printf("Record added: ID = %d, Name = %s\n", id, name);
}

// Function to search for a record by ID
Record *searchRecord(int id) {
    IndexNode *currentIndex = indexHead;
    while (currentIndex) {
        if (currentIndex->id == id) {
            return currentIndex;
        }
        currentIndex = currentIndex->next;
    }
    return NULL;
}

// Function to display all records
void displayRecords() {
    IndexNode *currentIndex = indexHead;
    printf("Displaying all records:\n");
    while (currentIndex) {
        printf("Record ID: %d\n", currentIndex->id);
        currentIndex = currentIndex->next;
    }
}

// Function to free allocated memory
void freeMemory() {
    IndexNode *currentIndex = indexHead;
    while (currentIndex) {
        IndexNode *temp = currentIndex;
        currentIndex = currentIndex->next;
        free(temp);
    }
}

// Main function demonstrating the use of the indexing system
int main() {
    addRecord(1, "Alice");
    addRecord(2, "Bob");
    addRecord(3, "Charlie");
    
    displayRecords();
    
    int searchId = 2;
    Record *foundRecord = searchRecord(searchId);
    if (foundRecord) {
        printf("Found Record: ID = %d\n", foundRecord->id);
    } else {
        printf("Record with ID = %d not found.\n", searchId);
    }
    
    freeMemory();
    return 0;
}