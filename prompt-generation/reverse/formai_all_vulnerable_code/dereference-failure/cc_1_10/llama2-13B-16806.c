//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_RECORDS 100
#define MAX_FIELDS 5

// Structure to represent a record
typedef struct {
    char name[20];
    int age;
    float salary;
} record_t;

// Function to create a new record
record_t *new_record(char *name, int age, float salary) {
    record_t *r = malloc(sizeof(record_t));
    strcpy(r->name, name);
    r->age = age;
    r->salary = salary;
    return r;
}

// Function to insert a record into the database
void insert_record(record_t **records, int *num_records, char *name, int age, float salary) {
    int i;
    for (i = 0; i < *num_records; i++) {
        if (strcmp(records[i]->name, name) < 0) {
            break;
        }
    }
    if (i == *num_records) {
        records = realloc(records, (i + 1) * sizeof(record_t *));
        records[i] = new_record(name, age, salary);
        (*num_records)++;
    }
}

// Function to retrieve a record from the database
record_t *get_record(record_t **records, int *num_records, char *name) {
    int i;
    for (i = 0; i < *num_records; i++) {
        if (strcmp(records[i]->name, name) == 0) {
            return records[i];
        }
    }
    return NULL;
}

// Function to update a record in the database
void update_record(record_t **records, int *num_records, char *name, int age, float salary) {
    record_t *r = get_record(records, num_records, name);
    if (r != NULL) {
        r->age = age;
        r->salary = salary;
    }
}

// Function to delete a record from the database
void delete_record(record_t **records, int *num_records, char *name) {
    int i;
    for (i = 0; i < *num_records; i++) {
        if (strcmp(records[i]->name, name) == 0) {
            free(records[i]);
            *num_records -= 1;
            break;
        }
    }
}

int main() {
    record_t **records = malloc(MAX_RECORDS * sizeof(record_t *));
    int num_records = 0;

    // Insert some records
    insert_record(records, &num_records, "Alice", 25, 50000.0f);
    insert_record(records, &num_records, "Bob", 30, 60000.0f);
    insert_record(records, &num_records, "Charlie", 35, 70000.0f);

    // Retrieve a record
    record_t *r = get_record(records, &num_records, "Alice");
    printf("Record: %s, age: %d, salary: %f\n", r->name, r->age, r->salary);

    // Update a record
    update_record(records, &num_records, "Bob", 31, 61000.0f);

    // Delete a record
    delete_record(records, &num_records, "Charlie");

    free(records);
    return 0;
}