//FormAI DATASET v1.0 Category: Database simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for a record in the database
typedef struct {
    int id;
    char name[20];
    int age;
} Record;

// Define the struct for the actual database
typedef struct {
    Record *records;
    int num_records;
} Database;

// Define function to add a record to the database
void add_record(Database *db, Record record) {
    db->records = realloc(db->records, (db->num_records + 1) * sizeof(Record));
    db->records[db->num_records] = record;
    db->num_records++;
}

// Define function to print all records in the database
void print_records(Database db) {
    printf("All records in database:\n");
    for (int i = 0; i < db.num_records; i++) {
        printf("%d. %s (%d years old)\n", db.records[i].id, db.records[i].name, db.records[i].age);
    }
}

// Define function to search for a record by ID and return the index
int search_record(Database db, int id) {
    for (int i = 0; i < db.num_records; i++) {
        if (db.records[i].id == id) {
            return i;
        }
    }
    return -1;
}

int main() {
    // Create a new database
    Database my_db;
    my_db.records = NULL;
    my_db.num_records = 0;

    // Add some example records to the database
    Record record1 = {1, "John", 25};
    Record record2 = {2, "Jane", 30};
    add_record(&my_db, record1);
    add_record(&my_db, record2);

    // Print all the records in the database
    print_records(my_db);

    // Search for a record by ID and change the age
    int id = 2;
    int index = search_record(my_db, id);
    if (index != -1) {
        my_db.records[index].age = 35;
        printf("Record with ID %d was found and age was updated.\n", id);
    } else {
        printf("Record with ID %d was not found.\n", id);
    }

    // Add a new record to the database
    Record record3 = {3, "Bob", 28};
    add_record(&my_db, record3);

    // Print all the records in the database again
    print_records(my_db);

    // Free memory allocated for the database
    free(my_db.records);

    return 0;
}