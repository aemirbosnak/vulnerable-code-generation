//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defines the maximum length of a record
#define MAX_RECORD_LENGTH 100

// Defines the maximum number of records in the database
#define MAX_RECORDS 100

// Defines the structure of a record
typedef struct {
    char name[50];
    int age;
    char address[50];
} Record;

// Defines the structure of the database
typedef struct {
    Record records[MAX_RECORDS];
    int num_records;
} Database;

// Creates a new database
Database* create_database() {
    Database* db = (Database*)malloc(sizeof(Database));
    db->num_records = 0;
    return db;
}

// Adds a new record to the database
void add_record(Database* db, Record record) {
    if (db->num_records < MAX_RECORDS) {
        db->records[db->num_records] = record;
        db->num_records++;
    }
}

// Finds a record by name in the database
Record* find_record(Database* db, char* name) {
    for (int i = 0; i < db->num_records; i++) {
        if (strcmp(db->records[i].name, name) == 0) {
            return &db->records[i];
        }
    }
    return NULL;
}

// Prints the database to the console
void print_database(Database* db) {
    for (int i = 0; i < db->num_records; i++) {
        printf("%s, %d, %s\n", db->records[i].name, db->records[i].age, db->records[i].address);
    }
}

// Main function
int main() {
    // Creates a new database
    Database* db = create_database();

    // Adds some records to the database
    add_record(db, (Record){"John", 30, "123 Main Street"});
    add_record(db, (Record){"Jane", 25, "456 Elm Street"});
    add_record(db, (Record){"Joe", 40, "789 Oak Street"});

    // Finds a record by name
    Record* record = find_record(db, "John");

    // Prints the record to the console
    if (record != NULL) {
        printf("Found record: %s, %d, %s\n", record->name, record->age, record->address);
    } else {
        printf("Record not found.\n");
    }

    // Prints the database to the console
    print_database(db);

    return 0;
}