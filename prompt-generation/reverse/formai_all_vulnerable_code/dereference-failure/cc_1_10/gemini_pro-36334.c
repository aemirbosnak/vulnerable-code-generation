//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of records in the database.
#define MAX_RECORDS 100

// Define the maximum length of a record.
#define MAX_RECORD_LENGTH 100

// Define the number of fields in a record.
#define NUM_FIELDS 3

// Define the data types of the fields.
typedef char string[MAX_RECORD_LENGTH];
typedef int integer;
typedef float real;

// Define the structure of a record.
typedef struct record {
    string field1;
    integer field2;
    real field3;
} record;

// Define the structure of the database.
typedef struct database {
    record records[MAX_RECORDS];
    int num_records;
} database;

// Create a new database.
database *create_database() {
    database *db = malloc(sizeof(database));
    db->num_records = 0;
    return db;
}

// Open an existing database.
database *open_database(char *filename) {
    database *db = malloc(sizeof(database));
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        return NULL;
    }
    fread(db, sizeof(database), 1, file);
    fclose(file);
    return db;
}

// Save a database to a file.
void save_database(database *db, char *filename) {
    FILE *file = fopen(filename, "wb");
    fwrite(db, sizeof(database), 1, file);
    fclose(file);
}

// Add a new record to the database.
void add_record(database *db, record *record) {
    db->records[db->num_records] = *record;
    db->num_records++;
}

// Delete a record from the database.
void delete_record(database *db, int index) {
    for (int i = index; i < db->num_records - 1; i++) {
        db->records[i] = db->records[i + 1];
    }
    db->num_records--;
}

// Find a record in the database.
int find_record(database *db, char *field1) {
    for (int i = 0; i < db->num_records; i++) {
        if (strcmp(db->records[i].field1, field1) == 0) {
            return i;
        }
    }
    return -1;
}

// Print the database to the console.
void print_database(database *db) {
    for (int i = 0; i < db->num_records; i++) {
        printf("%s %d %f\n", db->records[i].field1, db->records[i].field2, db->records[i].field3);
    }
}

// Main function.
int main() {
    // Create a new database.
    database *db = create_database();

    // Add some records to the database.
    record record1 = {"John Doe", 30, 100000.00};
    add_record(db, &record1);
    record record2 = {"Jane Doe", 25, 50000.00};
    add_record(db, &record2);
    record record3 = {"Jack Doe", 20, 25000.00};
    add_record(db, &record3);

    // Print the database to the console.
    printf("Database:\n");
    print_database(db);

    // Find a record in the database.
    int index = find_record(db, "John Doe");
    if (index == -1) {
        printf("Record not found.\n");
    } else {
        printf("Record found at index %d.\n", index);
    }

    // Delete a record from the database.
    delete_record(db, index);

    // Print the database to the console again.
    printf("Database after deleting record:\n");
    print_database(db);

    // Save the database to a file.
    save_database(db, "database.bin");

    // Open the database from a file.
    database *db2 = open_database("database.bin");

    // Print the database from the file to the console.
    printf("Database from file:\n");
    print_database(db2);

    // Free the memory allocated for the databases.
    free(db);
    free(db2);

    return 0;
}