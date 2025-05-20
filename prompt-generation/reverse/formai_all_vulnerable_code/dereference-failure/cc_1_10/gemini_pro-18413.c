//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: future-proof
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
database *create_database() {
    database *db = malloc(sizeof(database));
    db->num_records = 0;
    return db;
}

// Add a record to the database
void add_record(database *db, record *record) {
    if (db->num_records < MAX_RECORDS) {
        db->records[db->num_records] = *record;
        db->num_records++;
    }
}

// Find a record in the database by name
record *find_record_by_name(database *db, char *name) {
    for (int i = 0; i < db->num_records; i++) {
        if (strcmp(db->records[i].name, name) == 0) {
            return &db->records[i];
        }
    }
    return NULL;
}

// Delete a record from the database by name
void delete_record_by_name(database *db, char *name) {
    for (int i = 0; i < db->num_records; i++) {
        if (strcmp(db->records[i].name, name) == 0) {
            // Shift the records down to fill the gap
            for (int j = i; j < db->num_records - 1; j++) {
                db->records[j] = db->records[j + 1];
            }
            db->num_records--;
            break;
        }
    }
}

// Print the database to the console
void print_database(database *db) {
    for (int i = 0; i < db->num_records; i++) {
        printf("%s\n", db->records[i].name);
        printf("%d\n", db->records[i].age);
        printf("%s\n", db->records[i].address);
        printf("\n");
    }
}

// Free the memory allocated for the database
void free_database(database *db) {
    free(db);
}

int main() {
    // Create a new database
    database *db = create_database();

    // Add some records to the database
    record record1 = {"John", 30, "123 Main Street"};
    add_record(db, &record1);
    record record2 = {"Jane", 25, "456 Elm Street"};
    add_record(db, &record2);

    // Find a record in the database by name
    record *record3 = find_record_by_name(db, "John");
    if (record3 != NULL) {
        printf("Found record: %s\n", record3->name);
    } else {
        printf("Record not found\n");
    }

    // Delete a record from the database by name
    delete_record_by_name(db, "Jane");

    // Print the database to the console
    print_database(db);

    // Free the memory allocated for the database
    free_database(db);

    return 0;
}