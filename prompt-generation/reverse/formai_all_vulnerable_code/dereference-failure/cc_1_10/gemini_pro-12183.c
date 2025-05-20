//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of records in the database
#define MAX_RECORDS 100

// Define the maximum size of a record
#define MAX_RECORD_SIZE 100

// Define the structure of a record
typedef struct {
    char name[MAX_RECORD_SIZE];
    char address[MAX_RECORD_SIZE];
    char phone[MAX_RECORD_SIZE];
    char email[MAX_RECORD_SIZE];
} record;

// Define the structure of the database
typedef struct {
    record records[MAX_RECORDS];
    int numRecords;
} database;

// Function to create a new database
database* createDatabase() {
    database* db = malloc(sizeof(database));
    db->numRecords = 0;
    return db;
}

// Function to add a new record to the database
void addRecord(database* db, record* record) {
    if (db->numRecords >= MAX_RECORDS) {
        printf("Error: Database is full!\n");
        return;
    }
    db->records[db->numRecords++] = *record;
}

// Function to search for a record in the database by name
record* findRecordByName(database* db, char* name) {
    for (int i = 0; i < db->numRecords; i++) {
        if (strcmp(db->records[i].name, name) == 0) {
            return &db->records[i];
        }
    }
    return NULL;
}

// Function to search for a record in the database by address
record* findRecordByAddress(database* db, char* address) {
    for (int i = 0; i < db->numRecords; i++) {
        if (strcmp(db->records[i].address, address) == 0) {
            return &db->records[i];
        }
    }
    return NULL;
}

// Function to search for a record in the database by phone number
record* findRecordByPhone(database* db, char* phone) {
    for (int i = 0; i < db->numRecords; i++) {
        if (strcmp(db->records[i].phone, phone) == 0) {
            return &db->records[i];
        }
    }
    return NULL;
}

// Function to search for a record in the database by email address
record* findRecordByEmail(database* db, char* email) {
    for (int i = 0; i < db->numRecords; i++) {
        if (strcmp(db->records[i].email, email) == 0) {
            return &db->records[i];
        }
    }
    return NULL;
}

// Function to print the database
void printDatabase(database* db) {
    for (int i = 0; i < db->numRecords; i++) {
        printf("Name: %s\n", db->records[i].name);
        printf("Address: %s\n", db->records[i].address);
        printf("Phone: %s\n", db->records[i].phone);
        printf("Email: %s\n", db->records[i].email);
        printf("\n");
    }
}

// Main function
int main() {
    // Create a new database
    database* db = createDatabase();

    // Add some records to the database
    record record1 = {"John Doe", "123 Main Street", "555-1212", "john.doe@example.com"};
    addRecord(db, &record1);
    record record2 = {"Jane Doe", "456 Elm Street", "555-1213", "jane.doe@example.com"};
    addRecord(db, &record2);
    record record3 = {"Bob Smith", "789 Oak Street", "555-1214", "bob.smith@example.com"};
    addRecord(db, &record3);

    // Search for a record in the database by name
    record* record = findRecordByName(db, "John Doe");
    if (record != NULL) {
        printf("Found record: %s\n", record->name);
    } else {
        printf("Record not found!\n");
    }

    // Search for a record in the database by address
    record = findRecordByAddress(db, "123 Main Street");
    if (record != NULL) {
        printf("Found record: %s\n", record->name);
    } else {
        printf("Record not found!\n");
    }

    // Search for a record in the database by phone number
    record = findRecordByPhone(db, "555-1212");
    if (record != NULL) {
        printf("Found record: %s\n", record->name);
    } else {
        printf("Record not found!\n");
    }

    // Search for a record in the database by email address
    record = findRecordByEmail(db, "john.doe@example.com");
    if (record != NULL) {
        printf("Found record: %s\n", record->name);
    } else {
        printf("Record not found!\n");
    }

    // Print the database
    printDatabase(db);

    return 0;
}