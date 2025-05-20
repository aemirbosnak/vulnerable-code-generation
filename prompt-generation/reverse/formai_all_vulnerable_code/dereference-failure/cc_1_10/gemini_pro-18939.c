//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of records in the database
#define MAX_RECORDS 100

// Define the maximum length of a field in a record
#define MAX_FIELD_LENGTH 50

// Define the structure of a record
typedef struct {
    char name[MAX_FIELD_LENGTH];
    char address[MAX_FIELD_LENGTH];
    char phone[MAX_FIELD_LENGTH];
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

// Open an existing database from a file
database* open_database(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    database* db = malloc(sizeof(database));
    db->num_records = 0;

    while (!feof(fp)) {
        record r;
        fscanf(fp, "%s %s %s", r.name, r.address, r.phone);
        db->records[db->num_records++] = r;
    }

    fclose(fp);

    return db;
}

// Close a database
void close_database(database* db) {
    free(db);
}

// Add a new record to the database
void add_record(database* db, record r) {
    db->records[db->num_records++] = r;
}

// Delete a record from the database by index
void delete_record(database* db, int index) {
    for (int i = index; i < db->num_records - 1; i++) {
        db->records[i] = db->records[i + 1];
    }

    db->num_records--;
}

// Search for a record in the database by name
record* search_record_by_name(database* db, char* name) {
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
        printf("%s %s %s\n", db->records[i].name, db->records[i].address, db->records[i].phone);
    }
}

// Save the database to a file
void save_database(database* db, char* filename) {
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        return;
    }

    for (int i = 0; i < db->num_records; i++) {
        fprintf(fp, "%s %s %s\n", db->records[i].name, db->records[i].address, db->records[i].phone);
    }

    fclose(fp);
}

// Main function
int main() {
    // Create a new database
    database* db = create_database();

    // Add some records to the database
    record r1 = {"John Doe", "123 Main Street", "123-456-7890"};
    record r2 = {"Jane Doe", "456 Elm Street", "456-789-0123"};
    record r3 = {"John Smith", "789 Oak Street", "789-012-3456"};
    add_record(db, r1);
    add_record(db, r2);
    add_record(db, r3);

    // Print the database to the console
    print_database(db);

    // Save the database to a file
    save_database(db, "database.txt");

    // Close the database
    close_database(db);

    return 0;
}