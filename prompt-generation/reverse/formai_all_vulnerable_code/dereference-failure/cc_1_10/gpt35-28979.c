//FormAI DATASET v1.0 Category: Database Indexing System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INDEX_FILE "index.dat"
#define DATA_FILE "data.dat"

// Structure representing a record in the data file
typedef struct {
    int id;
    char name[25];
    float salary;
} Record;

// Structure representing an index entry
typedef struct {
    int id;
    long offset; // byte offset of record in the data file
} IndexEntry;

// Structure representing the index file
typedef struct {
    int numEntries;
    IndexEntry* entries;
} Index;

// Function to create a new index file
Index* createIndex() {
    Index* index = (Index*) malloc(sizeof(Index));
    index->numEntries = 0;
    index->entries = NULL;
    return index;
}

// Function to add an index entry to the index file
void addToIndex(Index* index, int id, long offset) {
    IndexEntry entry;
    entry.id = id;
    entry.offset = offset;

    index->numEntries++;
    index->entries = (IndexEntry*) realloc(index->entries, index->numEntries * sizeof(IndexEntry));
    index->entries[index->numEntries-1] = entry;
}

// Function to save the index to the index file
void saveIndex(Index* index) {
    FILE* indexFile = fopen(INDEX_FILE, "wb");

    if (indexFile == NULL) {
        perror("Error opening index file.");
        exit(1);
    }

    // Write the number of entries in the index
    fwrite(&index->numEntries, sizeof(int), 1, indexFile);

    // Write each entry in the index
    for (int i = 0; i < index->numEntries; i++) {
        fwrite(&index->entries[i].id, sizeof(int), 1, indexFile);
        fwrite(&index->entries[i].offset, sizeof(long), 1, indexFile);
    }

    fclose(indexFile);
}

// Function to load the index from the index file
Index* loadIndex() {
    FILE* indexFile = fopen(INDEX_FILE, "rb");

    if (indexFile == NULL) {
        perror("Error opening index file.");
        exit(1);
    }

    // Read the number of entries in the index
    int numEntries;
    fread(&numEntries, sizeof(int), 1, indexFile);

    // Allocate memory for the index and its entries
    Index* index = (Index*) malloc(sizeof(Index));
    index->numEntries = numEntries;
    index->entries = (IndexEntry*) malloc(numEntries * sizeof(IndexEntry));

    // Read each entry in the index
    for (int i = 0; i < numEntries; i++) {
        fread(&index->entries[i].id, sizeof(int), 1, indexFile);
        fread(&index->entries[i].offset, sizeof(long), 1, indexFile);
    }

    fclose(indexFile);
    return index;
}

// Function to add a record to the data file and index file
void addRecord(Record* record, Index* index) {
    long offset;
    FILE* dataFile = fopen(DATA_FILE, "ab");

    if (dataFile == NULL) {
        perror("Error opening data file.");
        exit(1);
    }

    // Write the record to the data file and get its byte offset
    offset = ftell(dataFile);
    fwrite(record, sizeof(Record), 1, dataFile);

    fclose(dataFile);

    // Add an index entry for the record
    addToIndex(index, record->id, offset);

    // Save the index file
    saveIndex(index);
}

// Function to retrieve a record by ID
Record* getRecordById(int id, Index* index) {
    FILE* dataFile = fopen(DATA_FILE, "rb");

    if (dataFile == NULL) {
        perror("Error opening data file.");
        exit(1);
    }

    // Search the index for the record's byte offset
    long offset = -1;
    for (int i = 0; i < index->numEntries; i++) {
        if (index->entries[i].id == id) {
            offset = index->entries[i].offset;
            break;
        }
    }

    if (offset == -1) {
        printf("Record with ID %d not found.\n", id);
        return NULL;
    }

    // Seek to the record's byte offset and read it from the data file
    fseek(dataFile, offset, SEEK_SET);
    Record* record = (Record*) malloc(sizeof(Record));
    fread(record, sizeof(Record), 1, dataFile);

    fclose(dataFile);

    return record;
}

// Function to print a record
void printRecord(Record* record) {
    printf("ID: %d\n", record->id);
    printf("Name: %s\n", record->name);
    printf("Salary: %.2f\n", record->salary);
}

int main() {
    Index* index = createIndex();

    // Add some records to the data file and index file
    Record record1 = { 1, "John", 5000.00 };
    Record record2 = { 2, "Jane", 6000.00 };
    Record record3 = { 3, "Bob", 4000.00 };
    addRecord(&record1, index);
    addRecord(&record2, index);
    addRecord(&record3, index);

    // Retrieve and print a record by ID
    Record* record = getRecordById(2, index);
    printRecord(record);

    return 0;
}