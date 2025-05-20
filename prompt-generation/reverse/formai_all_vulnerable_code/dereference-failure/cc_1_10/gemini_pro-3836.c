//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: high level of detail
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
    char address[MAX_RECORD_LENGTH];
    char phone[MAX_RECORD_LENGTH];
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

// Open an existing database
database* open_database(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    database* db = malloc(sizeof(database));
    db->num_records = 0;

    while (1) {
        record r;
        if (fscanf(fp, "%s %s %s", r.name, r.address, r.phone) != 3) {
            break;
        }

        db->records[db->num_records++] = r;
    }

    fclose(fp);

    return db;
}

// Save a database to a file
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

// Insert a new record into the database
void insert_record(database* db, record r) {
    db->records[db->num_records++] = r;
}

// Delete a record from the database
void delete_record(database* db, int index) {
    for (int i = index; i < db->num_records - 1; i++) {
        db->records[i] = db->records[i + 1];
    }

    db->num_records--;
}

// Find a record in the database
int find_record(database* db, char* name) {
    for (int i = 0; i < db->num_records; i++) {
        if (strcmp(db->records[i].name, name) == 0) {
            return i;
        }
    }

    return -1;
}

// Print the database
void print_database(database* db) {
    for (int i = 0; i < db->num_records; i++) {
        printf("%s %s %s\n", db->records[i].name, db->records[i].address, db->records[i].phone);
    }
}

// Main function
int main() {
    // Create a new database
    database* db = create_database();

    // Insert some records into the database
    record r1 = {"John Doe", "123 Main Street", "555-1212"};
    insert_record(db, r1);
    record r2 = {"Jane Doe", "456 Elm Street", "555-1213"};
    insert_record(db, r2);
    record r3 = {"John Smith", "789 Oak Street", "555-1214"};
    insert_record(db, r3);

    // Print the database
    print_database(db);

    // Find a record in the database
    int index = find_record(db, "John Doe");
    if (index != -1) {
        printf("Found record: %s %s %s\n", db->records[index].name, db->records[index].address, db->records[index].phone);
    } else {
        printf("Record not found\n");
    }

    // Delete a record from the database
    delete_record(db, 1);

    // Print the database
    print_database(db);

    // Save the database to a file
    save_database(db, "database.txt");

    // Open the database from a file
    database* db2 = open_database("database.txt");

    // Print the database
    print_database(db2);

    return 0;
}