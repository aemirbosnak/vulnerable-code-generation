//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of records in the database
#define MAX_RECORDS 100

// Define the maximum length of a record
#define MAX_RECORD_LENGTH 100

// Define the maximum number of indexes in the database
#define MAX_INDEXES 10

// Define the maximum length of an index
#define MAX_INDEX_LENGTH 100

// Define the type of a record
typedef struct {
    char data[MAX_RECORD_LENGTH];
} Record;

// Define the type of an index
typedef struct {
    char name[MAX_INDEX_LENGTH];
    int *values;
    int num_values;
} Index;

// Define the type of a database
typedef struct {
    Record records[MAX_RECORDS];
    Index indexes[MAX_INDEXES];
    int num_records;
    int num_indexes;
} Database;

// Create a new database
Database *create_database() {
    Database *db = malloc(sizeof(Database));
    db->num_records = 0;
    db->num_indexes = 0;
    return db;
}

// Add a record to the database
void add_record(Database *db, char *data) {
    strcpy(db->records[db->num_records].data, data);
    db->num_records++;
}

// Create a new index on the database
void create_index(Database *db, char *name, int *values, int num_values) {
    strcpy(db->indexes[db->num_indexes].name, name);
    db->indexes[db->num_indexes].values = values;
    db->indexes[db->num_indexes].num_values = num_values;
    db->num_indexes++;
}

// Search the database for a record using an index
Record *search_index(Database *db, char *name, int value) {
    for (int i = 0; i < db->num_indexes; i++) {
        if (strcmp(db->indexes[i].name, name) == 0) {
            for (int j = 0; j < db->indexes[i].num_values; j++) {
                if (db->indexes[i].values[j] == value) {
                    return &db->records[j];
                }
            }
        }
    }
    return NULL;
}

// Print the contents of the database
void print_database(Database *db) {
    for (int i = 0; i < db->num_records; i++) {
        printf("%s\n", db->records[i].data);
    }
}

// Free the memory allocated for the database
void free_database(Database *db) {
    for (int i = 0; i < db->num_indexes; i++) {
        free(db->indexes[i].values);
    }
    free(db);
}

// Main function
int main() {
    // Create a new database
    Database *db = create_database();

    // Add some records to the database
    add_record(db, "John Doe");
    add_record(db, "Jane Doe");
    add_record(db, "John Smith");
    add_record(db, "Jane Smith");

    // Create an index on the database
    int values[] = {0, 2};
    create_index(db, "name", values, 2);

    // Search the database for a record using the index
    Record *record = search_index(db, "name", 2);

    // Print the record
    printf("%s\n", record->data);

    // Free the memory allocated for the database
    free_database(db);

    return 0;
}