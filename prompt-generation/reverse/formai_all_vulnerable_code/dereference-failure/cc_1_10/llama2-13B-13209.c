//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_RECORDS 1000
#define MAX_FIELDS 5

// Structure to represent a record
typedef struct {
    char name[50];
    int age;
    float salary;
} record_t;

// Function to create a new record
record_t* create_record(char* name, int age, float salary) {
    record_t* new_record = (record_t*) malloc(sizeof(record_t));
    strcpy(new_record->name, name);
    new_record->age = age;
    new_record->salary = salary;
    return new_record;
}

// Function to insert a record into the database
void insert_record(record_t** records, int* num_records, char* name, int age, float salary) {
    int i;
    for (i = 0; i < *num_records; i++) {
        if (strcmp(records[i]->name, name) == 0) {
            // Record already exists, update the fields
            records[i]->age = age;
            records[i]->salary = salary;
            return;
        }
    }
    // Record does not exist, add it to the end of the list
    records[*num_records] = create_record(name, age, salary);
    (*num_records)++;
}

// Function to retrieve all records from the database
void get_all_records(record_t** records, int* num_records) {
    int i;
    for (i = 0; i < *num_records; i++) {
        printf("%s %d %f\n", records[i]->name, records[i]->age, records[i]->salary);
    }
}

// Function to search for a record by name
void search_record(record_t** records, int* num_records, char* name) {
    int i;
    for (i = 0; i < *num_records; i++) {
        if (strcmp(records[i]->name, name) == 0) {
            printf("%s %d %f\n", records[i]->name, records[i]->age, records[i]->salary);
            return;
        }
    }
    printf("Record not found\n");
}

int main() {
    record_t** records = (record_t**) malloc(MAX_RECORDS * sizeof(record_t*));
    int num_records = 0;

    // Insert some records
    insert_record(&records, &num_records, "John Doe", 30, 50000.0f);
    insert_record(&records, &num_records, "Jane Doe", 25, 40000.0f);
    insert_record(&records, &num_records, "Bob Smith", 40, 60000.0f);

    // Retrieve all records
    get_all_records(&records, &num_records);

    // Search for a record by name
    search_record(&records, &num_records, "John Doe");

    // Free the memory
    free(records);

    return 0;
}