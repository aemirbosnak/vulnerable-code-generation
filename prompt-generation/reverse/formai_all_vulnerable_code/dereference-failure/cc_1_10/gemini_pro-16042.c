//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of records in the database
#define MAX_RECORDS 100

// Define the maximum length of a field in a record
#define MAX_FIELD_LENGTH 100

// Define the structure of a record
typedef struct {
    char name[MAX_FIELD_LENGTH];
    char address[MAX_FIELD_LENGTH];
    char phone[MAX_FIELD_LENGTH];
} record_t;

// Define the structure of the database
typedef struct {
    record_t records[MAX_RECORDS];
    int num_records;
} database_t;

// Create a new database
database_t *create_database() {
    database_t *db = malloc(sizeof(database_t));
    db->num_records = 0;
    return db;
}

// Add a new record to the database
void add_record(database_t *db, record_t *record) {
    if (db->num_records < MAX_RECORDS) {
        db->records[db->num_records] = *record;
        db->num_records++;
    } else {
        printf("Error: Database is full.\n");
    }
}

// Find a record in the database by name
record_t *find_record(database_t *db, char *name) {
    for (int i = 0; i < db->num_records; i++) {
        if (strcmp(db->records[i].name, name) == 0) {
            return &db->records[i];
        }
    }
    return NULL;
}

// Print the contents of the database
void print_database(database_t *db) {
    for (int i = 0; i < db->num_records; i++) {
        printf("Record %d:\n", i + 1);
        printf("Name: %s\n", db->records[i].name);
        printf("Address: %s\n", db->records[i].address);
        printf("Phone: %s\n", db->records[i].phone);
        printf("\n");
    }
}

// Main function
int main() {
    // Create a new database
    database_t *db = create_database();

    // Add some records to the database
    record_t record1 = {"John Doe", "123 Main Street", "555-1212"};
    add_record(db, &record1);
    record_t record2 = {"Jane Doe", "456 Elm Street", "555-1213"};
    add_record(db, &record2);
    record_t record3 = {"Bob Smith", "789 Oak Street", "555-1214"};
    add_record(db, &record3);

    // Find a record in the database by name
    record_t *record = find_record(db, "John Doe");
    if (record != NULL) {
        printf("Found record:\n");
        printf("Name: %s\n", record->name);
        printf("Address: %s\n", record->address);
        printf("Phone: %s\n", record->phone);
        printf("\n");
    } else {
        printf("Record not found.\n");
    }

    // Print the contents of the database
    print_database(db);

    return 0;
}