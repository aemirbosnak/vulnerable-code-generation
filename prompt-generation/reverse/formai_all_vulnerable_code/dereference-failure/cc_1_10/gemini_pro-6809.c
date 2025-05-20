//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of records in the database
#define MAX_RECORDS 100

// Define the maximum length of a field in a record
#define MAX_FIELD_LENGTH 50

// Define the structure of a record
typedef struct {
    int id;
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
database_t* create_database() {
    database_t* db = malloc(sizeof(database_t));
    db->num_records = 0;
    return db;
}

// Insert a new record into the database
void insert_record(database_t* db, record_t* record) {
    db->records[db->num_records] = *record;
    db->num_records++;
}

// Find a record by its id
record_t* find_record_by_id(database_t* db, int id) {
    for (int i = 0; i < db->num_records; i++) {
        if (db->records[i].id == id) {
            return &db->records[i];
        }
    }
    return NULL;
}

// Delete a record by its id
void delete_record_by_id(database_t* db, int id) {
    for (int i = 0; i < db->num_records; i++) {
        if (db->records[i].id == id) {
            for (int j = i + 1; j < db->num_records; j++) {
                db->records[j - 1] = db->records[j];
            }
            db->num_records--;
            return;
        }
    }
}

// Print the database
void print_database(database_t* db) {
    for (int i = 0; i < db->num_records; i++) {
        printf("%d %s %s %s\n", db->records[i].id, db->records[i].name, db->records[i].address, db->records[i].phone);
    }
}

// Main function
int main() {
    // Create a new database
    database_t* db = create_database();

    // Insert some records into the database
    record_t record1 = {1, "John Doe", "123 Main Street", "555-1212"};
    insert_record(db, &record1);
    record_t record2 = {2, "Jane Doe", "456 Elm Street", "555-1213"};
    insert_record(db, &record2);
    record_t record3 = {3, "Bob Smith", "789 Oak Street", "555-1214"};
    insert_record(db, &record3);

    // Find a record by its id
    record_t* found_record = find_record_by_id(db, 2);
    if (found_record != NULL) {
        printf("Found record: %d %s %s %s\n", found_record->id, found_record->name, found_record->address, found_record->phone);
    } else {
        printf("Record not found.\n");
    }

    // Delete a record by its id
    delete_record_by_id(db, 3);

    // Print the database
    print_database(db);

    // Free the database
    free(db);

    return 0;
}