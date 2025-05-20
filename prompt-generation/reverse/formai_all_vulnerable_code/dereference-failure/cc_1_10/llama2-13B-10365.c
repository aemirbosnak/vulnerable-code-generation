//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_RECORDS 1000
#define MAX_FIELDS 5

// Structure to represent a record
typedef struct {
    char name[50];
    int age;
    float salary;
} record_t;

// Function to insert a record into the database
void insert_record(record_t **database, int *num_records, int index) {
    // Check if the record already exists
    for (int i = 0; i < *num_records; i++) {
        if (strcmp(database[i]->name, database[index]->name) == 0) {
            printf("Record already exists! Skipping...\n");
            return;
        }
    }

    // Allocate memory for the new record
    record_t *new_record = malloc(sizeof(record_t));
    strcpy(new_record->name, database[index]->name);
    new_record->age = database[index]->age;
    new_record->salary = database[index]->salary;

    // Add the new record to the database
    *num_records += 1;
    database = realloc(database, sizeof(record_t *) * (*num_records));
    database[*num_records - 1] = new_record;

    // Print the updated database
    printf("Inserted record: %s, %d, %f\n", new_record->name, new_record->age, new_record->salary);
}

// Function to search for a record in the database
record_t *search_record(record_t **database, int *num_records, const char *name) {
    for (int i = 0; i < *num_records; i++) {
        if (strcmp(database[i]->name, name) == 0) {
            return database[i];
        }
    }

    return NULL;
}

// Function to update a record in the database
void update_record(record_t **database, int *num_records, int index, int age, float salary) {
    record_t *record = database[index];
    record->age = age;
    record->salary = salary;

    // Print the updated record
    printf("Updated record: %s, %d, %f\n", record->name, record->age, record->salary);
}

// Function to delete a record from the database
void delete_record(record_t **database, int *num_records, int index) {
    // Check if the record exists
    if (index < *num_records) {
        // Free the memory for the record
        free(database[index]);

        // Update the number of records and shift the remaining records
        *num_records -= 1;
        for (int i = index; i < *num_records; i++) {
            database[i] = database[i + 1];
        }

        // Print the updated database
        printf("Deleted record: %s, %d, %f\n", database[*num_records - 1]->name, database[*num_records - 1]->age, database[*num_records - 1]->salary);
    } else {
        printf("Record not found! Skipping...\n");
    }
}

int main() {
    // Initialize the database with some sample records
    record_t *database[MAX_RECORDS] = {
        {"Alice", 25, 50000.0},
        {"Bob", 30, 60000.0},
        {"Charlie", 35, 70000.0},
        {"David", 20, 40000.0},
        {"Eve", 25, 55000.0}
    };
    int num_records = 5;

    // Insert some new records
    insert_record(database, &num_records, 0);
    insert_record(database, &num_records, 1);
    insert_record(database, &num_records, 2);

    // Search for a record
    record_t *record = search_record(database, &num_records, "Alice");
    if (record != NULL) {
        printf("Found record: %s, %d, %f\n", record->name, record->age, record->salary);
    } else {
        printf("Record not found! Skipping...\n");
    }

    // Update a record
    update_record(database, &num_records, 1, 31, 70000.1);

    // Delete a record
    delete_record(database, &num_records, 2);

    // Print the updated database
    printf("Updated database: \n");
    for (int i = 0; i < num_records; i++) {
        printf("%d: %s, %d, %f\n", i, database[i]->name, database[i]->age, database[i]->salary);
    }

    return 0;
}