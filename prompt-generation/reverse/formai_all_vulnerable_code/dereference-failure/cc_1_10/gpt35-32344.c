//FormAI DATASET v1.0 Category: Database simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a database record
typedef struct {
    int id;
    char name[50];
    int age;
} Record;

// Define the structure of the database itself
typedef struct {
    int num_records;
    Record* records;
} Database;

// Function to add a record to the database
void add_record(Database* db, Record r) {
    db->num_records++;
    db->records = (Record*) realloc(db->records, db->num_records * sizeof(Record));
    db->records[db->num_records-1] = r;
}

// Function to print out all records in the database
void print_records(Database* db) {
    int i;
    for (i = 0; i < db->num_records; i++) {
        printf("ID: %d\tName: %s\tAge: %d\n", db->records[i].id, db->records[i].name, db->records[i].age);
    }
}

// Main function
int main() {
    Database db;
    db.num_records = 0;
    db.records = NULL;

    // Add some example records to the database
    Record r1 = {1, "John Smith", 35};
    Record r2 = {2, "Jane Doe", 27};
    Record r3 = {3, "Bob Johnson", 42};
    add_record(&db, r1);
    add_record(&db, r2);
    add_record(&db, r3);

    // Print out all records in the database
    printf("All records:\n");
    print_records(&db);

    // Search for a specific record by name
    char search_name[50];
    printf("Enter name to search for: ");
    scanf("%s", search_name);
    int i;
    for (i = 0; i < db.num_records; i++) {
        if (strcmp(db.records[i].name, search_name) == 0) {
            printf("Record found:\nID: %d\tName: %s\tAge: %d\n", db.records[i].id, db.records[i].name, db.records[i].age);
            break;
        }
    }
    if (i == db.num_records) {
        printf("Record not found.\n");
    }

    // Free the memory used by the database
    free(db.records);

    return 0;
}