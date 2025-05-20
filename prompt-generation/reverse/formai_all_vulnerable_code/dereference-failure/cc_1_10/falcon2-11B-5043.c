//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structure to hold each record in the database
struct Record {
    char name[50];
    char phone[20];
    char address[100];
};

// Structure to hold the entire database
struct Database {
    struct Record* records;
    int size;
    int capacity;
};

// Function to initialize a new database
struct Database* initDatabase(int capacity) {
    struct Database* db = malloc(sizeof(struct Database));
    db->size = 0;
    db->capacity = capacity;
    db->records = NULL;
    return db;
}

// Function to search for a record by name
struct Record* searchRecord(struct Database* db, char* name) {
    int index = -1;
    for (int i = 0; i < db->size; i++) {
        if (strcmp(db->records[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    return index == -1? NULL : db->records + index;
}

// Function to add a new record to the database
void addRecord(struct Database* db, char* name, char* phone, char* address) {
    struct Record* record = malloc(sizeof(struct Record));
    strcpy(record->name, name);
    strcpy(record->phone, phone);
    strcpy(record->address, address);
    db->records = realloc(db->records, (db->size + 1) * sizeof(struct Record));
    db->records[db->size++] = *record;
    free(record);
}

// Function to print all records in the database
void printDatabase(struct Database* db) {
    for (int i = 0; i < db->size; i++) {
        printf("%s - %s - %s\n", db->records[i].name, db->records[i].phone, db->records[i].address);
    }
}

int main() {
    // Initialize a new database with a capacity of 10 records
    struct Database* db = initDatabase(10);

    // Add some records to the database
    addRecord(db, "John Doe", "1234567890", "123 Main St.");
    addRecord(db, "Jane Smith", "9876543210", "456 Elm St.");
    addRecord(db, "Bob Johnson", "5555555555", "789 Oak St.");

    // Search for a record by name
    struct Record* record = searchRecord(db, "John Doe");
    if (record) {
        printf("Found %s - %s - %s\n", record->name, record->phone, record->address);
        free(record);
    }

    // Print all records in the database
    printDatabase(db);

    // Free the memory used by the database
    free(db->records);
    free(db);

    return 0;
}