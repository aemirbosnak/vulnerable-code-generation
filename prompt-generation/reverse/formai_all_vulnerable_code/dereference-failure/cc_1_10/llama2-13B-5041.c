//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_RECORDS 1000
#define MAX_FIELDS 5

// Structure to hold a record
typedef struct {
    char name[50];
    int age;
    float salary;
} record_t;

// Function to create a record
record_t* create_record(char* name, int age, float salary) {
    record_t* record = (record_t*)malloc(sizeof(record_t));
    strcpy(record->name, name);
    record->age = age;
    record->salary = salary;
    return record;
}

// Function to insert a record into the database
void insert_record(record_t** records, int* num_records, char* name, int age, float salary) {
    // Check if the record already exists
    for (int i = 0; i < *num_records; i++) {
        if (strcmp(records[i]->name, name) == 0) {
            printf("Record already exists\n");
            return;
        }
    }

    // Allocate a new record and insert it into the database
    record_t* new_record = create_record(name, age, salary);
    records[*num_records] = new_record;
    (*num_records)++;
}

// Function to retrieve a record from the database
record_t* retrieve_record(record_t** records, int* num_records, char* name) {
    for (int i = 0; i < *num_records; i++) {
        if (strcmp(records[i]->name, name) == 0) {
            return records[i];
        }
    }
    return NULL;
}

// Function to update a record in the database
void update_record(record_t** records, int* num_records, char* name, int age, float salary) {
    record_t* record = retrieve_record(records, num_records, name);
    if (record != NULL) {
        record->age = age;
        record->salary = salary;
    } else {
        printf("Record not found\n");
    }
}

// Function to delete a record from the database
void delete_record(record_t** records, int* num_records, char* name) {
    int index = -1;
    for (int i = 0; i < *num_records; i++) {
        if (strcmp(records[i]->name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        // Free the memory allocated for the record
        free(records[index]);
        // Shift the remaining records to fill the gap
        for (int j = index + 1; j < *num_records; j++) {
            records[index] = records[j];
        }
        (*num_records)--;
    } else {
        printf("Record not found\n");
    }
}

int main() {
    // Create an array of records
    record_t* records[MAX_RECORDS];
    int num_records = 0;

    // Insert some records
    insert_record(records, &num_records, "Alice", 25, 50000.0);
    insert_record(records, &num_records, "Bob", 30, 60000.0);
    insert_record(records, &num_records, "Charlie", 35, 70000.0);

    // Retrieve a record
    record_t* record = retrieve_record(records, &num_records, "Alice");
    if (record != NULL) {
        printf("Record found: %s %d %f\n", record->name, record->age, record->salary);
    } else {
        printf("Record not found\n");
    }

    // Update a record
    update_record(records, &num_records, "Alice", 30, 60000.0);

    // Delete a record
    delete_record(records, &num_records, "Bob");

    return 0;
}