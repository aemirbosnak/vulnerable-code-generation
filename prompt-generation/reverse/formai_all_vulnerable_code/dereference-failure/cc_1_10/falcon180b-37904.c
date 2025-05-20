//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: genious
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a record in the database
typedef struct {
    int id;
    char name[50];
    char address[100];
    int phone;
} Record;

// Define the structure of the database
typedef struct {
    Record *records;
    int num_records;
    int max_records;
} Database;

// Function to create a new database with the given maximum number of records
Database *create_database(int max_records) {
    Database *db = malloc(sizeof(Database));
    db->records = malloc(max_records * sizeof(Record));
    db->num_records = 0;
    db->max_records = max_records;
    return db;
}

// Function to add a new record to the database
void add_record(Database *db, int id, char *name, char *address, int phone) {
    if (db->num_records >= db->max_records) {
        printf("Database is full.\n");
        return;
    }
    Record *record = db->records + db->num_records;
    record->id = id;
    strcpy(record->name, name);
    strcpy(record->address, address);
    record->phone = phone;
    db->num_records++;
}

// Function to search for a record in the database by ID
Record *search_record(Database *db, int id) {
    for (int i = 0; i < db->num_records; i++) {
        Record *record = db->records + i;
        if (record->id == id) {
            return record;
        }
    }
    return NULL;
}

// Function to print all records in the database
void print_records(Database *db) {
    for (int i = 0; i < db->num_records; i++) {
        Record *record = db->records + i;
        printf("ID: %d, Name: %s, Address: %s, Phone: %d\n", record->id, record->name, record->address, record->phone);
    }
}

int main() {
    Database *db = create_database(10);
    add_record(db, 1, "John Doe", "123 Main St.", 5551234);
    add_record(db, 2, "Jane Doe", "456 Elm St.", 5555678);
    print_records(db);
    Record *record = search_record(db, 1);
    if (record!= NULL) {
        printf("Found record with ID %d\n", record->id);
    } else {
        printf("Record not found.\n");
    }
    return 0;
}