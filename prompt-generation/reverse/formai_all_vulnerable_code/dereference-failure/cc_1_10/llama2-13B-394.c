//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/mman.h>

#define DATABASE_SIZE 10000
#define RECORD_SIZE 50

// Structure to hold a single record in the database
typedef struct {
    char name[50];
    char address[50];
    int age;
} record_t;

// Function to create a new record in the database
void insert_record(record_t** records, int* num_records, char* name, char* address, int age) {
    int i;

    // Check if the record already exists in the database
    for (i = 0; i < *num_records; i++) {
        if (strcmp(records[i]->name, name) == 0) {
            printf("Record already exists! Skipping...\n");
            return;
        }
    }

    // Allocate a new record and copy the data
    record_t* new_record = malloc(sizeof(record_t));
    strcpy(new_record->name, name);
    strcpy(new_record->address, address);
    new_record->age = age;

    // Insert the new record into the database
    *num_records += 1;
    records = realloc(records, (*num_records) * sizeof(record_t*));
    records[*num_records - 1] = new_record;
}

// Function to search for a record in the database
int search_record(record_t** records, int num_records, char* name) {
    int i;

    for (i = 0; i < num_records; i++) {
        if (strcmp(records[i]->name, name) == 0) {
            return i;
        }
    }

    return -1;
}

// Function to update a record in the database
void update_record(record_t** records, int num_records, int index, char* name, char* address, int age) {
    if (index < 0 || index >= num_records) {
        printf("Invalid index! Skipping...\n");
        return;
    }

    // Copy the record to update
    record_t* record = records[index];

    // Update the record fields
    strcpy(record->name, name);
    strcpy(record->address, address);
    record->age = age;

    // Update the record in the database
    records[index] = record;
}

// Function to delete a record from the database
void delete_record(record_t** records, int num_records, int index) {
    if (index < 0 || index >= num_records) {
        printf("Invalid index! Skipping...\n");
        return;
    }

    // Remove the record from the database
    memmove(records + index, records + index + 1, (num_records - index - 1) * sizeof(record_t*));
    num_records -= 1;

    // Free the memory of the deleted record
    free(records[index]);
    records[index] = NULL;
}

int main() {
    // Create the database with 10000 slots
    record_t** records = malloc(10000 * sizeof(record_t*));
    int num_records = 0;

    // Insert some records into the database
    insert_record(&records, &num_records, "John Doe", "123 Main St", 30);
    insert_record(&records, &num_records, "Jane Doe", "456 Elm St", 25);
    insert_record(&records, &num_records, "Bob Smith", "789 Oak St", 40);

    // Search for a record in the database
    int index = search_record(records, num_records, "John Doe");
    if (index >= 0) {
        printf("Found record at index %d\n", index);
    } else {
        printf("Record not found\n");
    }

    // Update a record in the database
    update_record(&records, num_records, 1, "John Doe", "789 Oak St", 45);

    // Delete a record from the database
    delete_record(&records, num_records, 0);

    // Print the updated database
    for (int i = 0; i < num_records; i++) {
        printf("%d: %s, %s, %d\n", i, records[i]->name, records[i]->address, records[i]->age);
    }

    return 0;
}