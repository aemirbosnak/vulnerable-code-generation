//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of records in the database
#define MAX_RECORDS 100

// Define the maximum length of a record
#define MAX_RECORD_LENGTH 100

// Define the structure of a record
typedef struct record {
    char name[MAX_RECORD_LENGTH];
    int age;
    char address[MAX_RECORD_LENGTH];
} record;

// Define the structure of the database
typedef struct database {
    record records[MAX_RECORDS];
    int num_records;
} database;

// Create a new database
database* create_database() {
    database* db = malloc(sizeof(database));
    db->num_records = 0;
    return db;
}

// Add a record to the database
void add_record(database* db, record* record) {
    if (db->num_records < MAX_RECORDS) {
        db->records[db->num_records] = *record;
        db->num_records++;
    } else {
        printf("Error: Database is full\n");
    }
}

// Find a record in the database by name
record* find_record_by_name(database* db, char* name) {
    for (int i = 0; i < db->num_records; i++) {
        if (strcmp(db->records[i].name, name) == 0) {
            return &db->records[i];
        }
    }
    return NULL;
}

// Delete a record from the database by name
void delete_record_by_name(database* db, char* name) {
    for (int i = 0; i < db->num_records; i++) {
        if (strcmp(db->records[i].name, name) == 0) {
            db->records[i] = db->records[db->num_records - 1];
            db->num_records--;
            return;
        }
    }
    printf("Error: Record not found\n");
}

// Print the database
void print_database(database* db) {
    for (int i = 0; i < db->num_records; i++) {
        printf("Record %d:\n", i + 1);
        printf("Name: %s\n", db->records[i].name);
        printf("Age: %d\n", db->records[i].age);
        printf("Address: %s\n", db->records[i].address);
        printf("\n");
    }
}

// Main function
int main() {
    // Create a new database
    database* db = create_database();

    // Add some records to the database
    record record1 = {"John Doe", 30, "123 Main Street"};
    add_record(db, &record1);
    record record2 = {"Jane Doe", 25, "456 Elm Street"};
    add_record(db, &record2);
    record record3 = {"John Smith", 40, "789 Oak Street"};
    add_record(db, &record3);

    // Find a record in the database by name
    record* record = find_record_by_name(db, "John Doe");
    if (record != NULL) {
        printf("Found record:\n");
        printf("Name: %s\n", record->name);
        printf("Age: %d\n", record->age);
        printf("Address: %s\n", record->address);
        printf("\n");
    } else {
        printf("Error: Record not found\n");
    }

    // Delete a record from the database by name
    delete_record_by_name(db, "John Smith");

    // Print the database
    print_database(db);

    // Free the database
    free(db);

    return 0;
}