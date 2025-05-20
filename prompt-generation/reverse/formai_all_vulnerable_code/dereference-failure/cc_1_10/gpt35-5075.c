//FormAI DATASET v1.0 Category: Database simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

// Structure for a database record
struct Record {
    int id;
    char name[50];
    int age;
    char gender;
};

// Structure for the database itself
struct Database {
    struct Record* records;
    int num_records;
};

// Function to add a new record to the database
void addRecord(struct Database* db, int id, char* name, int age, char gender) {
    // Increase the number of records in the database
    db->num_records++;

    // Reallocate memory for the records array to accomodate the new record
    db->records = realloc(db->records, sizeof(struct Record) * db->num_records);

    // Create a pointer to the last record in the database
    struct Record* record = &db->records[db->num_records - 1];

    // Set the values for the new record
    record->id = id;
    strcpy(record->name, name);
    record->age = age;
    record->gender = gender;
}

// Function to print all records in the database
void printRecords(struct Database* db) {
    // Loop through all records in the database
    for (int i = 0; i < db->num_records; i++) {
        // Create a pointer to the current record
        struct Record* record = &db->records[i];

        // Print out the record information
        printf("Record #%d:\n", record->id);
        printf("- Name: %s\n", record->name);
        printf("- Age: %d\n", record->age);
        printf("- Gender: %c\n", record->gender);
    }
}

int main() {
    // Create a new database
    struct Database db;
    db.records = NULL; // Initialize the records pointer to NULL
    db.num_records = 0; // Initialize the number of records to 0

    // Add some records to the database
    addRecord(&db, 1, "John", 25, 'M');
    addRecord(&db, 2, "Sarah", 30, 'F');
    addRecord(&db, 3, "Tom", 20, 'M');

    // Print out all records in the database
    printRecords(&db);

    // Deallocate memory for the records array
    free(db.records);

    return 0;
}