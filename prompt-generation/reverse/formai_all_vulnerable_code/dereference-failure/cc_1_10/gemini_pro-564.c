//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of records in the database.
#define MAX_RECORDS 100

// Define the maximum length of a record.
#define MAX_RECORD_LENGTH 100

// Define the structure of a record.
typedef struct {
    int id;
    char name[MAX_RECORD_LENGTH];
    char address[MAX_RECORD_LENGTH];
    char phone[MAX_RECORD_LENGTH];
} record;

// Define the structure of a database.
typedef struct {
    record records[MAX_RECORDS];
    int num_records;
} database;

// Create a new database.
database* create_database() {
    database* db = malloc(sizeof(database));
    db->num_records = 0;
    return db;
}

// Insert a new record into the database.
void insert_record(database* db, record* record) {
    db->records[db->num_records++] = *record;
}

// Search for a record in the database by its id.
record* search_record_by_id(database* db, int id) {
    for (int i = 0; i < db->num_records; i++) {
        if (db->records[i].id == id) {
            return &db->records[i];
        }
    }
    return NULL;
}

// Search for a record in the database by its name.
record* search_record_by_name(database* db, char* name) {
    for (int i = 0; i < db->num_records; i++) {
        if (strcmp(db->records[i].name, name) == 0) {
            return &db->records[i];
        }
    }
    return NULL;
}

// Print the contents of the database.
void print_database(database* db) {
    for (int i = 0; i < db->num_records; i++) {
        printf("Record %d:\n", i+1);
        printf("ID: %d\n", db->records[i].id);
        printf("Name: %s\n", db->records[i].name);
        printf("Address: %s\n", db->records[i].address);
        printf("Phone: %s\n", db->records[i].phone);
        printf("\n");
    }
}

// Free the memory allocated for the database.
void free_database(database* db) {
    free(db);
}

// Main function.
int main() {
    // Create a new database.
    database* db = create_database();

    // Insert some records into the database.
    record record1 = {1, "John Doe", "123 Main Street", "555-1212"};
    insert_record(db, &record1);
    record record2 = {2, "Jane Doe", "456 Elm Street", "555-1213"};
    insert_record(db, &record2);
    record record3 = {3, "John Smith", "789 Oak Street", "555-1214"};
    insert_record(db, &record3);

    // Search for a record in the database by its id.
    record* record_by_id = search_record_by_id(db, 2);
    if (record_by_id != NULL) {
        printf("Found record by id:\n");
        printf("ID: %d\n", record_by_id->id);
        printf("Name: %s\n", record_by_id->name);
        printf("Address: %s\n", record_by_id->address);
        printf("Phone: %s\n", record_by_id->phone);
        printf("\n");
    } else {
        printf("Record not found.\n");
    }

    // Search for a record in the database by its name.
    record* record_by_name = search_record_by_name(db, "John Smith");
    if (record_by_name != NULL) {
        printf("Found record by name:\n");
        printf("ID: %d\n", record_by_name->id);
        printf("Name: %s\n", record_by_name->name);
        printf("Address: %s\n", record_by_name->address);
        printf("Phone: %s\n", record_by_name->phone);
        printf("\n");
    } else {
        printf("Record not found.\n");
    }

    // Print the contents of the database.
    printf("Database:\n");
    print_database(db);

    // Free the memory allocated for the database.
    free_database(db);

    return 0;
}