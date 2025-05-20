//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: all-encompassing
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
    char address[MAX_RECORD_LENGTH];
    char phone[MAX_RECORD_LENGTH];
} record;

// Define the structure of the database
typedef struct database {
    record records[MAX_RECORDS];
    int num_records;
} database;

// Create a new database
database *create_database() {
    database *db = malloc(sizeof(database));
    db->num_records = 0;
    return db;
}

// Add a new record to the database
void add_record(database *db, record *record) {
    if (db->num_records == MAX_RECORDS) {
        printf("Error: Database is full.\n");
        return;
    }

    db->records[db->num_records++] = *record;
}

// Delete a record from the database
void delete_record(database *db, int index) {
    if (index < 0 || index >= db->num_records) {
        printf("Error: Invalid index.\n");
        return;
    }

    for (int i = index; i < db->num_records - 1; i++) {
        db->records[i] = db->records[i + 1];
    }

    db->num_records--;
}

// Print the database
void print_database(database *db) {
    for (int i = 0; i < db->num_records; i++) {
        printf("Record %d:\n", i + 1);
        printf("Name: %s\n", db->records[i].name);
        printf("Address: %s\n", db->records[i].address);
        printf("Phone: %s\n", db->records[i].phone);
        printf("\n");
    }
}

// Free the memory allocated for the database
void free_database(database *db) {
    free(db);
}

// Main function
int main() {
    // Create a new database
    database *db = create_database();

    // Add some records to the database
    record record1 = {"John Doe", "123 Main Street", "555-1212"};
    add_record(db, &record1);
    record record2 = {"Jane Doe", "456 Elm Street", "555-1213"};
    add_record(db, &record2);
    record record3 = {"Bill Smith", "789 Oak Street", "555-1214"};
    add_record(db, &record3);

    // Print the database
    print_database(db);

    // Delete a record from the database
    delete_record(db, 1);

    // Print the database again
    print_database(db);

    // Free the memory allocated for the database
    free_database(db);

    return 0;
}