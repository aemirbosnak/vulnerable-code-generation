//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: configurable
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
} record;

// Define the structure of the database
typedef struct {
    record records[MAX_RECORDS];
    int num_records;
} database;

// Create a new database
database* create_database() {
    database* db = malloc(sizeof(database));
    db->num_records = 0;
    return db;
}

// Add a new record to the database
void add_record(database* db, record* record) {
    db->records[db->num_records] = *record;
    db->num_records++;
}

// Delete a record from the database by index
void delete_record(database* db, int index) {
    for (int i = index; i < db->num_records - 1; i++) {
        db->records[i] = db->records[i + 1];
    }
    db->num_records--;
}

// Find a record in the database by name
record* find_record(database* db, char* name) {
    for (int i = 0; i < db->num_records; i++) {
        if (strcmp(db->records[i].name, name) == 0) {
            return &db->records[i];
        }
    }
    return NULL;
}

// Print the database to the console
void print_database(database* db) {
    for (int i = 0; i < db->num_records; i++) {
        printf("%s, %d, %s\n", db->records[i].name, db->records[i].age, db->records[i].address);
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
    record record3 = {"Bob Smith", 40, "789 Oak Street"};
    add_record(db, &record3);

    // Print the database to the console
    printf("Database:\n");
    print_database(db);

    // Find a record in the database by name
    record* found_record = find_record(db, "John Doe");
    if (found_record != NULL) {
        printf("Found record:\n");
        printf("%s, %d, %s\n", found_record->name, found_record->age, found_record->address);
    } else {
        printf("Record not found.\n");
    }

    // Delete a record from the database by index
    delete_record(db, 1);

    // Print the database to the console again
    printf("Database after deletion:\n");
    print_database(db);

    // Free the memory allocated for the database
    free(db);

    return 0;
}