//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define DB_NAME "my_database"
#define MAX_RECORDS 100

// Structure to hold a single record
typedef struct {
    char name[50];
    int age;
} record_t;

// Function to create a new record
record_t* new_record(char* name, int age) {
    record_t* rec = (record_t*) malloc(sizeof(record_t));
    strcpy(rec->name, name);
    rec->age = age;
    return rec;
}

// Function to insert a record into the database
void insert_record(record_t** records, int* num_records, char* name, int age) {
    // Check if the record already exists
    int i;
    for (i = 0; i < *num_records; i++) {
        if (strcmp(records[i]->name, name) == 0) {
            printf("Record already exists! Skipping...\n");
            return;
        }
    }

    // If the record doesn't exist, insert it
    records[*num_records] = new_record(name, age);
    (*num_records)++;
}

// Function to retrieve all records from the database
void get_all_records(record_t** records, int* num_records) {
    *num_records = 0;
    for (int i = 0; i < MAX_RECORDS; i++) {
        if (records[i] != NULL) {
            (*num_records)++;
        }
    }
}

// Function to retrieve a single record from the database
record_t* get_record(record_t** records, int num_records, char* name) {
    int i;
    for (i = 0; i < num_records; i++) {
        if (strcmp(records[i]->name, name) == 0) {
            return records[i];
        }
    }
    return NULL;
}

// Function to update a record in the database
void update_record(record_t** records, int num_records, char* name, int age) {
    int i;
    for (i = 0; i < num_records; i++) {
        if (strcmp(records[i]->name, name) == 0) {
            records[i]->age = age;
            break;
        }
    }
}

// Function to delete a record from the database
void delete_record(record_t** records, int num_records, char* name) {
    int i;
    for (i = 0; i < num_records; i++) {
        if (strcmp(records[i]->name, name) == 0) {
            // Free the memory of the record
            free(records[i]);
            // Remove the record from the array
            memmove(&records[i], &records[i+1], (num_records - i - 1) * sizeof(record_t*));
            num_records--;
            break;
        }
    }
}

int main() {
    record_t** records = (record_t**) malloc(MAX_RECORDS * sizeof(record_t*));
    int num_records = 0;

    // Insert some records
    insert_record(records, &num_records, "Alice", 25);
    insert_record(records, &num_records, "Bob", 30);
    insert_record(records, &num_records, "Charlie", 35);

    // Retrieve all records
    get_all_records(records, &num_records);

    // Print all records
    for (int i = 0; i < num_records; i++) {
        printf("%s %d\n", records[i]->name, records[i]->age);
    }

    // Retrieve a single record
    record_t* alice = get_record(records, num_records, "Alice");
    if (alice != NULL) {
        printf("Alice's age is %d\n", alice->age);
    }

    // Update a record
    update_record(records, num_records, "Bob", 35);

    // Retrieve all records again
    get_all_records(records, &num_records);

    // Print all records again
    for (int i = 0; i < num_records; i++) {
        printf("%s %d\n", records[i]->name, records[i]->age);
    }

    // Delete a record
    delete_record(records, num_records, "Charlie");

    // Retrieve all records again
    get_all_records(records, &num_records);

    // Print all records again
    for (int i = 0; i < num_records; i++) {
        printf("%s %d\n", records[i]->name, records[i]->age);
    }

    return 0;
}