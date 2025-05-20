//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a record in the database
typedef struct record {
    int id;
    char name[255];
    int age;
} record;

// Define the structure of the database
typedef struct database {
    int num_records;
    record *records;
} database;

// Create a new database
database *create_database() {
    database *db = malloc(sizeof(database));
    db->num_records = 0;
    db->records = NULL;
    return db;
}

// Add a new record to the database
void add_record(database *db, record *r) {
    db->num_records++;
    db->records = realloc(db->records, db->num_records * sizeof(record));
    db->records[db->num_records - 1] = *r;
}

// Get a record from the database by its id
record *get_record_by_id(database *db, int id) {
    for (int i = 0; i < db->num_records; i++) {
        if (db->records[i].id == id) {
            return &db->records[i];
        }
    }
    return NULL;
}

// Delete a record from the database by its id
void delete_record_by_id(database *db, int id) {
    for (int i = 0; i < db->num_records; i++) {
        if (db->records[i].id == id) {
            // Shift the records down to fill the gap
            for (int j = i; j < db->num_records - 1; j++) {
                db->records[j] = db->records[j + 1];
            }
            db->num_records--;
            db->records = realloc(db->records, db->num_records * sizeof(record));
            return;
        }
    }
}

// Print the database to the console
void print_database(database *db) {
    for (int i = 0; i < db->num_records; i++) {
        printf("Record %d:\n", db->records[i].id);
        printf("Name: %s\n", db->records[i].name);
        printf("Age: %d\n", db->records[i].age);
        printf("\n");
    }
}

// Main function
int main() {
    // Create a new database
    database *db = create_database();

    // Add some records to the database
    record r1 = {1, "John Doe", 30};
    add_record(db, &r1);
    record r2 = {2, "Jane Doe", 25};
    add_record(db, &r2);
    record r3 = {3, "John Smith", 40};
    add_record(db, &r3);

    // Print the database to the console
    print_database(db);

    // Get a record from the database by its id
    record *r = get_record_by_id(db, 2);
    if (r != NULL) {
        printf("Record found:\n");
        printf("Name: %s\n", r->name);
        printf("Age: %d\n", r->age);
        printf("\n");
    } else {
        printf("Record not found.\n");
    }

    // Delete a record from the database by its id
    delete_record_by_id(db, 3);

    // Print the database to the console
    print_database(db);

    // Free the memory allocated for the database
    free(db->records);
    free(db);

    return 0;
}