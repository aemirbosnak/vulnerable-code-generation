//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of records in the database
#define MAX_RECORDS 1000

// Define the maximum length of a record
#define MAX_RECORD_LENGTH 100

// Define the structure of a record
typedef struct {
    char name[MAX_RECORD_LENGTH];
    int age;
    char address[MAX_RECORD_LENGTH];
} Record;

// Define the structure of a database
typedef struct {
    Record records[MAX_RECORDS];
    int numRecords;
} Database;

// Create a new database
Database* createDatabase() {
    Database* db = (Database*)malloc(sizeof(Database));
    db->numRecords = 0;
    return db;
}

// Add a record to the database
void addRecord(Database* db, Record* record) {
    if (db->numRecords < MAX_RECORDS) {
        db->records[db->numRecords] = *record;
        db->numRecords++;
    }
}

// Get a record from the database by name
Record* getRecordByName(Database* db, char* name) {
    for (int i = 0; i < db->numRecords; i++) {
        if (strcmp(db->records[i].name, name) == 0) {
            return &db->records[i];
        }
    }
    return NULL;
}

// Get a record from the database by age
Record* getRecordByAge(Database* db, int age) {
    for (int i = 0; i < db->numRecords; i++) {
        if (db->records[i].age == age) {
            return &db->records[i];
        }
    }
    return NULL;
}

// Get a record from the database by address
Record* getRecordByAddress(Database* db, char* address) {
    for (int i = 0; i < db->numRecords; i++) {
        if (strcmp(db->records[i].address, address) == 0) {
            return &db->records[i];
        }
    }
    return NULL;
}

// Print the database
void printDatabase(Database* db) {
    for (int i = 0; i < db->numRecords; i++) {
        printf("%s, %d, %s\n", db->records[i].name, db->records[i].age, db->records[i].address);
    }
}

// Free the memory allocated for the database
void freeDatabase(Database* db) {
    free(db);
}

int main() {
    // Create a new database
    Database* db = createDatabase();

    // Add some records to the database
    Record record1 = {"John", 30, "123 Main Street"};
    addRecord(db, &record1);
    Record record2 = {"Mary", 25, "456 Elm Street"};
    addRecord(db, &record2);
    Record record3 = {"Bob", 40, "789 Oak Street"};
    addRecord(db, &record3);

    // Print the database
    printDatabase(db);

    // Get a record from the database by name
    Record* record = getRecordByName(db, "John");
    if (record != NULL) {
        printf("Found record: %s, %d, %s\n", record->name, record->age, record->address);
    } else {
        printf("Record not found.\n");
    }

    // Get a record from the database by age
    record = getRecordByAge(db, 25);
    if (record != NULL) {
        printf("Found record: %s, %d, %s\n", record->name, record->age, record->address);
    } else {
        printf("Record not found.\n");
    }

    // Get a record from the database by address
    record = getRecordByAddress(db, "456 Elm Street");
    if (record != NULL) {
        printf("Found record: %s, %d, %s\n", record->name, record->age, record->address);
    } else {
        printf("Record not found.\n");
    }

    // Free the memory allocated for the database
    freeDatabase(db);

    return 0;
}