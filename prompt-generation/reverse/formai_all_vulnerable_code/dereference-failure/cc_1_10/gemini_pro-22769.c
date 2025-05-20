//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of records in the database
#define MAX_RECORDS 100

// Define the maximum size of a field in a record
#define MAX_FIELD_SIZE 50

// Define the structure of a record
typedef struct {
    char name[MAX_FIELD_SIZE];
    char address[MAX_FIELD_SIZE];
    char phone[MAX_FIELD_SIZE];
    char email[MAX_FIELD_SIZE];
} record;

// Define the structure of the database
typedef struct {
    record records[MAX_RECORDS];
    int num_records;
} database;

// Create a new database
database* create_database() {
    database* db = (database*)malloc(sizeof(database));
    db->num_records = 0;
    return db;
}

// Add a new record to the database
void add_record(database* db, record* record) {
    if (db->num_records >= MAX_RECORDS) {
        printf("Error: Database is full.\n");
        return;
    }

    db->records[db->num_records++] = *record;
}

// Delete a record from the database by index
void delete_record(database* db, int index) {
    if (index < 0 || index >= db->num_records) {
        printf("Error: Invalid record index.\n");
        return;
    }

    for (int i = index; i < db->num_records - 1; i++) {
        db->records[i] = db->records[i + 1];
    }

    db->num_records--;
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

// Print the contents of the database
void print_database(database* db) {
    printf("Database:\n");
    for (int i = 0; i < db->num_records; i++) {
        printf("Record %d:\n", i);
        printf("Name: %s\n", db->records[i].name);
        printf("Address: %s\n", db->records[i].address);
        printf("Phone: %s\n", db->records[i].phone);
        printf("Email: %s\n\n", db->records[i].email);
    }
}

// Main function
int main() {
    // Create a new database
    database* db = create_database();

    // Add some records to the database
    record record1 = {"John Doe", "123 Main Street", "555-1212", "john.doe@example.com"};
    add_record(db, &record1);

    record record2 = {"Jane Doe", "456 Elm Street", "555-1213", "jane.doe@example.com"};
    add_record(db, &record2);

    record record3 = {"Bob Smith", "789 Oak Street", "555-1214", "bob.smith@example.com"};
    add_record(db, &record3);

    // Print the contents of the database
    print_database(db);

    // Find a record in the database by name
    record* found_record = find_record_by_name(db, "Jane Doe");
    if (found_record != NULL) {
        printf("Found record:\n");
        printf("Name: %s\n", found_record->name);
        printf("Address: %s\n", found_record->address);
        printf("Phone: %s\n", found_record->phone);
        printf("Email: %s\n", found_record->email);
    } else {
        printf("Record not found.\n");
    }

    // Delete a record from the database
    delete_record(db, 1);

    // Print the contents of the database again
    print_database(db);

    // Free the memory allocated for the database
    free(db);

    return 0;
}