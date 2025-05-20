//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of records
#define MAX_RECORDS 100

// Define the record structure
typedef struct Record {
    char name[50];
    int age;
    struct Record* next;
} Record;

// Define the indexing structure
typedef struct Index {
    int key;
    struct Index* next;
} Index;

// Create a new record
Record* createRecord() {
    Record* newRecord = (Record*)malloc(sizeof(Record));
    newRecord->next = NULL;
    return newRecord;
}

// Insert a new record
void insertRecord(Record** head, char* name, int age) {
    Record* newRecord = createRecord();
    strcpy(newRecord->name, name);
    newRecord->age = age;

    if (*head == NULL) {
        *head = newRecord;
    } else {
        (*head)->next = newRecord;
    }
}

// Create a new index entry
Index* createIndexEntry(int key) {
    Index* newIndexEntry = (Index*)malloc(sizeof(Index));
    newIndexEntry->key = key;
    newIndexEntry->next = NULL;
    return newIndexEntry;
}

// Insert a new index entry
void insertIndexEntry(Index** head, int key) {
    Index* newIndexEntry = createIndexEntry(key);

    if (*head == NULL) {
        *head = newIndexEntry;
    } else {
        (*head)->next = newIndexEntry;
    }
}

// Search for a record by name
Record* searchRecordByName(Record* head, char* name) {
    while (head) {
        if (strcmp(head->name, name) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// Main function
int main() {
    // Create a linked list of records
    Record* head = NULL;

    // Insert some records
    insertRecord(&head, "John Doe", 25);
    insertRecord(&head, "Jane Doe", 30);
    insertRecord(&head, "Bill Smith", 40);

    // Create an indexing structure
    Index* headIndex = NULL;

    // Insert index entries
    insertIndexEntry(&headIndex, 25);
    insertIndexEntry(&headIndex, 30);
    insertIndexEntry(&headIndex, 40);

    // Search for a record by name
    Record* record = searchRecordByName(head, "Jane Doe");

    // Print the record
    if (record) {
        printf("Name: %s\n", record->name);
        printf("Age: %d\n", record->age);
    } else {
        printf("Record not found.\n");
    }

    return 0;
}