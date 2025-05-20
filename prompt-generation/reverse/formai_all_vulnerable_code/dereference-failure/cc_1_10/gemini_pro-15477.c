//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a database record
typedef struct {
    int id;
    char name[256];
    char address[256];
    char phone[256];
    char email[256];
} record;

// Structure to represent a database
typedef struct {
    record *records;
    int num_records;
} database;

// Function to create a new database
database *create_database() {
    database *db = malloc(sizeof(database));
    db->records = NULL;
    db->num_records = 0;
    return db;
}

// Function to add a new record to a database
void add_record(database *db, record *r) {
    db->records = realloc(db->records, (db->num_records + 1) * sizeof(record));
    db->records[db->num_records] = *r;
    db->num_records++;
}

// Function to find a record in a database by ID
record *find_record_by_id(database *db, int id) {
    for (int i = 0; i < db->num_records; i++) {
        if (db->records[i].id == id) {
            return &db->records[i];
        }
    }
    return NULL;
}

// Function to print a record
void print_record(record *r) {
    printf("ID: %d\n", r->id);
    printf("Name: %s\n", r->name);
    printf("Address: %s\n", r->address);
    printf("Phone: %s\n", r->phone);
    printf("Email: %s\n", r->email);
}

// Function to free the memory allocated for a database
void free_database(database *db) {
    free(db->records);
    free(db);
}

// Main function
int main() {
    // Create a new database
    database *db = create_database();

    // Add some records to the database
    record r1 = {1, "John Doe", "123 Main Street", "555-1212", "john.doe@example.com"};
    add_record(db, &r1);
    record r2 = {2, "Jane Doe", "456 Elm Street", "555-1213", "jane.doe@example.com"};
    add_record(db, &r2);
    record r3 = {3, "John Smith", "789 Oak Street", "555-1214", "john.smith@example.com"};
    add_record(db, &r3);

    // Find a record by ID
    record *r = find_record_by_id(db, 2);
    if (r != NULL) {
        // Print the record
        print_record(r);
    } else {
        printf("Record not found.\n");
    }

    // Free the memory allocated for the database
    free_database(db);

    return 0;
}