//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_RECORDS 100
#define MAX_FIELDS 5

// Structure to represent a record
typedef struct {
    char name[20];
    int age;
    float salary;
} record_t;

// Function to create a record
record_t *create_record(char *name, int age, float salary) {
    record_t *record = malloc(sizeof(record_t));
    strcpy(record->name, name);
    record->age = age;
    record->salary = salary;
    return record;
}

// Function to insert a record into the database
void insert_record(record_t **database, int num_records, record_t *record) {
    if (num_records == MAX_RECORDS) {
        printf("Database is full. No more records can be inserted.\n");
        return;
    }

    // Find an empty slot in the database
    int i;
    for (i = 0; i < num_records; i++) {
        if (database[i] == NULL) {
            break;
        }
    }

    // Insert the record into the database
    database[i] = record;
    num_records++;

    // Print the updated database
    printf("Database: ");
    for (i = 0; i < num_records; i++) {
        printf("%s %d %f\n", database[i]->name, database[i]->age, database[i]->salary);
    }
}

// Function to retrieve a record from the database
record_t *retrieve_record(record_t **database, int num_records, char *name) {
    int i;
    for (i = 0; i < num_records; i++) {
        if (strcmp(database[i]->name, name) == 0) {
            return database[i];
        }
    }

    // Record not found
    return NULL;
}

// Function to update a record in the database
void update_record(record_t **database, int num_records, char *name, int age, float salary) {
    record_t *record = retrieve_record(database, num_records, name);
    if (record != NULL) {
        record->age = age;
        record->salary = salary;
        printf("Record updated: %s %d %f\n", record->name, record->age, record->salary);
    } else {
        printf("Record not found\n");
    }
}

// Function to delete a record from the database
void delete_record(record_t **database, int num_records, char *name) {
    int i;
    for (i = 0; i < num_records; i++) {
        if (strcmp(database[i]->name, name) == 0) {
            // Found the record to be deleted
            free(database[i]);
            num_records--;
            break;
        }
    }

    // Print the updated database
    printf("Database: ");
    for (i = 0; i < num_records; i++) {
        printf("%s %d %f\n", database[i]->name, database[i]->age, database[i]->salary);
    }
}

int main() {
    record_t **database;
    int num_records = 0;

    // Create some records and insert them into the database
    record_t *record1 = create_record("John", 25, 50000.0);
    record_t *record2 = create_record("Jane", 30, 60000.0);
    record_t *record3 = create_record("Bob", 35, 70000.0);
    insert_record(&database, num_records, record1);
    insert_record(&database, num_records, record2);
    insert_record(&database, num_records, record3);

    // Retrieve and update a record
    record_t *record = retrieve_record(&database, num_records, "John");
    update_record(&database, num_records, "John", 30, 60000.0);

    // Retrieve and delete a record
    record = retrieve_record(&database, num_records, "Jane");
    delete_record(&database, num_records, "Jane");

    // Print the updated database
    printf("Database: ");
    for (int i = 0; i < num_records; i++) {
        printf("%s %d %f\n", database[i]->name, database[i]->age, database[i]->salary);
    }

    return 0;
}