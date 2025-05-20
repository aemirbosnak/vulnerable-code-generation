//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_RECORDS 100

typedef struct Record {
    int id;
    char name[MAX_NAME_LENGTH];
    struct Record *next;
} Record;

typedef struct Index {
    int id;
    Record *record;
    struct Index *next;
} Index;

Index *indexHead = NULL; // Index head pointer
Record *recordHead = NULL; // Records head pointer

// Function to add a new record
void addRecord(int id, const char *name) {
    Record *newRecord = (Record *)malloc(sizeof(Record));
    newRecord->id = id;
    strncpy(newRecord->name, name, MAX_NAME_LENGTH);
    newRecord->next = recordHead;
    recordHead = newRecord;

    // Add to index
    Index *newIndex = (Index *)malloc(sizeof(Index));
    newIndex->id = id;
    newIndex->record = newRecord;
    newIndex->next = indexHead;
    indexHead = newIndex;
}

// Function to search for a record by ID
Record *getRecordById(int id) {
    Index *currentIndex = indexHead;
    while (currentIndex != NULL) {
        if (currentIndex->id == id) {
            return currentIndex->record;
        }
        currentIndex = currentIndex->next;
    }
    return NULL; // Record not found
}

// Function to display all records
void displayRecords() {
    Record *current = recordHead;
    while (current != NULL) {
        printf("ID: %d, Name: %s\n", current->id, current->name);
        current = current->next;
    }
}

// Function to clean up memory
void cleanup() {
    Index *currentIndex = indexHead;
    while (currentIndex != NULL) {
        Index *tempIndex = currentIndex;
        currentIndex = currentIndex->next;
        free(tempIndex);
    }

    Record *currentRecord = recordHead;
    while (currentRecord != NULL) {
        Record *tempRecord = currentRecord;
        currentRecord = currentRecord->next;
        free(tempRecord);
    }
}

// Main function
int main() {
    addRecord(1, "Alice");
    addRecord(2, "Bob");
    addRecord(3, "Charlie");

    printf("All records:\n");
    displayRecords();

    int searchId;
    printf("Enter ID to search for: ");
    scanf("%d", &searchId);
    Record *foundRecord = getRecordById(searchId);
    if (foundRecord) {
        printf("Record found: ID: %d, Name: %s\n", foundRecord->id, foundRecord->name);
    } else {
        printf("Record not found with ID: %d\n", searchId);
    }

    // Clean up memory
    cleanup();
    return 0;
}