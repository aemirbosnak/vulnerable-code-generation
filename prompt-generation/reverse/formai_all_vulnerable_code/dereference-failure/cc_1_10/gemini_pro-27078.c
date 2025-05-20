//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of records in the database
#define MAX_RECORDS 100

// Define the maximum length of a record
#define MAX_RECORD_LENGTH 100

// Define the structure of a record
typedef struct {
    char name[MAX_RECORD_LENGTH];
    int age;
    char address[MAX_RECORD_LENGTH];
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

// Add a record to the database
void add_record(database_t *db, record_t *record) {
    if (db->num_records < MAX_RECORDS) {
        db->records[db->num_records++] = *record;
    }
}

// Delete a record from the database
void delete_record(database_t *db, int index) {
    if (index >= 0 && index < db->num_records) {
        for (int i = index; i < db->num_records - 1; i++) {
            db->records[i] = db->records[i + 1];
        }
        db->num_records--;
    }
}

// Update a record in the database
void update_record(database_t *db, int index, record_t *record) {
    if (index >= 0 && index < db->num_records) {
        db->records[index] = *record;
    }
}

// Print the database
void print_database(database_t *db) {
    for (int i = 0; i < db->num_records; i++) {
        printf("Record %d:\n", i + 1);
        printf("Name: %s\n", db->records[i].name);
        printf("Age: %d\n", db->records[i].age);
        printf("Address: %s\n\n", db->records[i].address);
    }
}

// Free the memory allocated for the database
void free_database(database_t *db) {
    free(db);
}

// Main function
int main() {
    // Create a new database
    database_t *db = create_database();

    // Add some records to the database
    record_t record1 = {"John Doe", 25, "123 Main Street"};
    add_record(db, &record1);

    record_t record2 = {"Jane Doe", 30, "456 Elm Street"};
    add_record(db, &record2);

    // Print the database
    print_database(db);

    // Delete a record from the database
    delete_record(db, 1);

    // Update a record in the database
    record_t record3 = {"John Smith", 35, "789 Oak Street"};
    update_record(db, 0, &record3);

    // Print the database
    print_database(db);

    // Free the memory allocated for the database
    free_database(db);

    return 0;
}