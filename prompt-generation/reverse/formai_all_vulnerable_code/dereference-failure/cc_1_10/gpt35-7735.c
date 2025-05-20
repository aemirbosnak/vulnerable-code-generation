//FormAI DATASET v1.0 Category: Database Indexing System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

// Define a structure to hold the data we want to store in the database
typedef struct {
    int id;
    char name[50];
    int age;
} Person;

// Define a structure to hold the index values
typedef struct {
    int id;
    long offset;
} Index;

// Define the maximum number of records the database can hold
#define MAX_RECORDS 100

// Define the maximum number of indexes the database can hold
#define MAX_INDEXES 100

// Define the size of each record in bytes
#define RECORD_SIZE sizeof(Person)

// Define the size of each index in bytes
#define INDEX_SIZE sizeof(Index)

// Define the name of the binary file used to store the database
#define DATABASE_FILE "database.bin"

// Define the name of the binary file used to store the indexes
#define INDEX_FILE "indexes.bin"

// Create a function to add a record to the database
void addRecord(Person *p) {
    // Open the file for writing, and append to the end of the file
    FILE *file = fopen(DATABASE_FILE, "ab");
    // Write the record to the file
    fwrite(p, RECORD_SIZE, 1, file);
    // Close the file
    fclose(file);
}

// Create a function to add an index to the index file
void addIndex(Index *i) {
    // Open the file for writing, and append to the end of the file
    FILE *file = fopen(INDEX_FILE, "ab");
    // Write the index to the file
    fwrite(i, INDEX_SIZE, 1, file);
    // Close the file
    fclose(file);
}

// Create a function to generate an index for a specific record
Index generateIndex(int id, long offset) {
    Index i;
    i.id = id;
    i.offset = offset;
    return i;
}

// Create a function to build the indexes for the database
void buildIndexes() {
    // Open the database file for reading
    FILE *file = fopen(DATABASE_FILE, "rb");
    // Open the index file for writing
    FILE *indexFile = fopen(INDEX_FILE, "wb");
    // Define a variable to keep track of the number of records
    int recordCount = 0;
    // Define a variable to keep track of the position in the file
    long position = 0;
    // Define a variable to hold the current record
    Person *p = malloc(RECORD_SIZE);
    // While there are still records to read
    while (fread(p, RECORD_SIZE, 1, file)) {
        // Generate an index for the current record
        Index i = generateIndex(p->id, position);
        // Add the index to the index file
        addIndex(&i);
        // Increment the record count and position
        recordCount++;
        position = ftell(file);
    }
    // Close the files and free the memory
    fclose(file);
    fclose(indexFile);
    free(p);
}

// Create a function to get a record from the database by ID
Person* getRecordById(int id) {
    // Open the index file for reading
    FILE *indexFile = fopen(INDEX_FILE, "rb");
    // Define a variable to hold the current index
    Index *i = malloc(INDEX_SIZE);
    // Define a variable to hold the record we want to return
    Person *p = malloc(RECORD_SIZE);
    // Seek to the beginning of the index file
    fseek(indexFile, 0, SEEK_SET);
    // While there are still indexes to read
    while (fread(i, INDEX_SIZE, 1, indexFile)) {
        // If this index matches the requested ID
        if (i->id == id) {
            // Open the database file for reading
            FILE *file = fopen(DATABASE_FILE, "rb");
            // Seek to the offset of the record
            fseek(file, i->offset, SEEK_SET);
            // Read the record into our buffer
            fread(p, RECORD_SIZE, 1, file);
            // Close the database file and index file
            fclose(file);
            fclose(indexFile);
            free(i);
            // Return the record
            return p;
        }
    }
    // If we didn't find the record, return NULL
    fclose(indexFile);
    free(i);
    free(p);
    return NULL;
}

int main() {
    // Create some test data
    Person p1 = {1, "John Smith", 30};
    Person p2 = {2, "Jane Doe", 25};
    Person p3 = {3, "Bob Johnson", 40};
    // Add the data to the database
    addRecord(&p1);
    addRecord(&p2);
    addRecord(&p3);
    // Build the indexes for the database
    buildIndexes(); 
    // Get a record by ID
    printf("Record 2:\n");
    Person *p = getRecordById(2);
    if (p) {
        printf("ID: %d\n", p->id);
        printf("Name: %s\n", p->name);
        printf("Age: %d\n", p->age);
        free(p);
    } else {
        printf("Record not found\n");
    }
    return 0;
}