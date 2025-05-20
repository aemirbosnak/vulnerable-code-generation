//FormAI DATASET v1.0 Category: Database Indexing System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold a record
typedef struct Record {
    int id;
    char name[50];
    int age;
} Record;

// Define a structure to hold an index entry
typedef struct IndexEntry {
    int id;
    int position;
} IndexEntry;

// Define global variables
int MAX_RECORDS = 100;
int NUM_RECORDS = 0;
Record* RECORD_LIST;
IndexEntry* INDEX_LIST;

// Function to add a record to the database
void addRecord(int id, char* name, int age) {
    // Check if we have reached the maximum number of records
    if (NUM_RECORDS == MAX_RECORDS) {
        printf("Error: database is full\n");
        return;
    }
    
    // Allocate memory for the new record
    Record* newRecord = (Record*) malloc(sizeof(Record));
    
    // Set the values for the new record
    newRecord->id = id;
    strcpy(newRecord->name, name);
    newRecord->age = age;
    
    // Add the new record to the end of the record list
    RECORD_LIST[NUM_RECORDS] = *newRecord;
    
    // Add an entry to the index list for the new record
    IndexEntry* newIndexEntry = (IndexEntry*) malloc(sizeof(IndexEntry));
    newIndexEntry->id = id;
    newIndexEntry->position = NUM_RECORDS;
    INDEX_LIST[NUM_RECORDS] = *newIndexEntry;
    
    // Increase the number of records by 1
    NUM_RECORDS++;
}

// Function to search for a record by id
Record* searchById(int id) {
    // Loop through the index list to find the position of the record
    int i;
    for (i = 0; i < NUM_RECORDS; i++) {
        if (INDEX_LIST[i].id == id) {
            // If we find the record, return a pointer to it
            return &RECORD_LIST[INDEX_LIST[i].position];
        }
    }
    
    // If we don't find the record, return NULL
    return NULL;
}

// Main function
int main() {
    // Allocate memory for the record and index lists
    RECORD_LIST = (Record*) malloc(MAX_RECORDS * sizeof(Record));
    INDEX_LIST = (IndexEntry*) malloc(MAX_RECORDS * sizeof(IndexEntry));
    
    // Add some records to the database
    addRecord(1, "John Smith", 25);
    addRecord(2, "Jane Doe", 30);
    addRecord(3, "Bob Johnson", 45);
    addRecord(4, "Mary Williams", 50);
    addRecord(5, "Tom Brown", 18);
    
    // Search for a record by id
    Record* record = searchById(3);
    
    // Print the record
    printf("Record Found:\n");
    printf("ID: %d\n", record->id);
    printf("Name: %s\n", record->name);
    printf("Age: %d\n", record->age);
    
    return 0;
}