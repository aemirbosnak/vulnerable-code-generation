//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: creative
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
} Record;

// Define the structure of the database
typedef struct {
    Record records[MAX_RECORDS];
    int num_records;
} Database;

// Create a new database
Database* create_database() {
    Database* db = malloc(sizeof(Database));
    db->num_records = 0;
    return db;
}

// Add a new record to the database
void add_record(Database* db, Record* record) {
    if (db->num_records < MAX_RECORDS) {
        db->records[db->num_records] = *record;
        db->num_records++;
    } else {
        printf("Error: Database is full.\n");
    }
}

// Print the records in the database
void print_records(Database* db) {
    for (int i = 0; i < db->num_records; i++) {
        printf("Record %d:\n", i + 1);
        printf("Name: %s\n", db->records[i].name);
        printf("Age: %d\n", db->records[i].age);
        printf("Address: %s\n", db->records[i].address);
    }
}

// Search for a record in the database by name
Record* search_record_by_name(Database* db, char* name) {
    for (int i = 0; i < db->num_records; i++) {
        if (strcmp(db->records[i].name, name) == 0) {
            return &db->records[i];
        }
    }
    return NULL;
}

// Delete a record from the database by name
void delete_record_by_name(Database* db, char* name) {
    int index = -1;
    for (int i = 0; i < db->num_records; i++) {
        if (strcmp(db->records[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < db->num_records - 1; i++) {
            db->records[i] = db->records[i + 1];
        }
        db->num_records--;
    } else {
        printf("Error: Record not found.\n");
    }
}

// Update a record in the database by name
void update_record_by_name(Database* db, char* name, Record* new_record) {
    int index = -1;
    for (int i = 0; i < db->num_records; i++) {
        if (strcmp(db->records[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        db->records[index] = *new_record;
    } else {
        printf("Error: Record not found.\n");
    }
}

// Main function
int main() {
    // Create a new database
    Database* db = create_database();

    // Add some records to the database
    Record record1 = {"John Doe", 30, "123 Main Street"};
    add_record(db, &record1);
    Record record2 = {"Jane Doe", 25, "456 Elm Street"};
    add_record(db, &record2);
    Record record3 = {"Jack Doe", 20, "789 Oak Street"};
    add_record(db, &record3);

    // Print the records in the database
    printf("Records in the database:\n");
    print_records(db);

    // Search for a record in the database by name
    char* name = "John Doe";
    Record* record = search_record_by_name(db, name);
    if (record != NULL) {
        printf("Record found:\n");
        printf("Name: %s\n", record->name);
        printf("Age: %d\n", record->age);
        printf("Address: %s\n", record->address);
    } else {
        printf("Error: Record not found.\n");
    }

    // Delete a record from the database by name
    name = "Jane Doe";
    delete_record_by_name(db, name);

    // Print the records in the database
    printf("Records in the database after deletion:\n");
    print_records(db);

    // Update a record in the database by name
    name = "Jack Doe";
    Record new_record = {"Jack Doe", 21, "789 Oak Street, Apt. 1"};
    update_record_by_name(db, name, &new_record);

    // Print the records in the database
    printf("Records in the database after update:\n");
    print_records(db);

    // Free the memory allocated for the database
    free(db);

    return 0;
}