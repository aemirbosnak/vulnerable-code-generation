//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define DB_NAME "my_database"
#define MAX_RECORDS 1000
#define RECORD_SIZE 50

// Structure to represent a record in the database
typedef struct {
    char name[50];
    int age;
    float salary;
} record_t;

// Function to create a new record
record_t *create_record(char *name, int age, float salary) {
    record_t *new_record = (record_t *)malloc(sizeof(record_t));
    strcpy(new_record->name, name);
    new_record->age = age;
    new_record->salary = salary;
    return new_record;
}

// Function to insert a record into the database
void insert_record(record_t **records, int *num_records, char *name, int age, float salary) {
    int i;
    for (i = 0; i < *num_records; i++) {
        if (strcmp(records[i]->name, name) == 0) {
            // Record already exists, update the values
            records[i]->age = age;
            records[i]->salary = salary;
            return;
        }
    }
    // Record does not exist, add it to the end of the list
    records[*num_records] = create_record(name, age, salary);
    (*num_records)++;
}

// Function to search for a record in the database
record_t *search_record(record_t **records, int num_records, char *name) {
    int i;
    for (i = 0; i < num_records; i++) {
        if (strcmp(records[i]->name, name) == 0) {
            return records[i];
        }
    }
    return NULL;
}

// Function to update a record in the database
void update_record(record_t **records, int num_records, char *name, int age, float salary) {
    record_t *record = search_record(records, num_records, name);
    if (record != NULL) {
        record->age = age;
        record->salary = salary;
    }
}

// Function to delete a record from the database
void delete_record(record_t **records, int num_records, char *name) {
    int i;
    for (i = 0; i < num_records; i++) {
        if (strcmp(records[i]->name, name) == 0) {
            // Found the record to delete
            free(records[i]);
            memmove(records[i], records[i + 1], (num_records - i - 1) * sizeof(record_t));
            num_records--;
            return;
        }
    }
}

int main() {
    // Initialize the database with some sample records
    record_t *records[MAX_RECORDS];
    int num_records = 0;
    records[0] = create_record("John Doe", 30, 50000.0);
    records[1] = create_record("Jane Doe", 25, 35000.0);
    records[2] = create_record("Bob Smith", 40, 60000.0);
    records[3] = create_record("Alice Johnson", 35, 45000.0);

    // Insert some new records
    insert_record(records, &num_records, "Jane Doe", 28, 40000.0);
    insert_record(records, &num_records, "Bob Smith", 42, 70000.0);

    // Search for a record
    record_t *record = search_record(records, num_records, "John Doe");
    if (record != NULL) {
        printf("Found record: %s (age: %d, salary: %f)\n", record->name, record->age, record->salary);
    } else {
        printf("Record not found\n");
    }

    // Update a record
    update_record(records, num_records, "Jane Doe", 30, 55000.0);

    // Delete a record
    delete_record(records, num_records, "Bob Smith");

    // Print the remaining records
    for (int i = 0; i < num_records; i++) {
        printf("%d: %s (age: %d, salary: %f)\n", i, records[i]->name, records[i]->age, records[i]->salary);
    }

    return 0;
}