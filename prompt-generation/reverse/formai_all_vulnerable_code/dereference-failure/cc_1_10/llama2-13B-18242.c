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

// Function to create a new record
record_t* new_record(char* name, int age, float salary) {
    record_t* rec = (record_t*) malloc(sizeof(record_t));
    strcpy(rec->name, name);
    rec->age = age;
    rec->salary = salary;
    return rec;
}

// Function to insert a record into the database
void insert_record(record_t** records, int* num_records, char* name, int age, float salary) {
    int i;
    for (i = 0; i < *num_records; i++) {
        if (strcmp(records[i]->name, name) == 0) {
            // Record already exists, update fields
            records[i]->age = age;
            records[i]->salary = salary;
            return;
        }
    }
    // Record does not exist, add it to the end of the list
    records[*num_records] = new_record(name, age, salary);
    (*num_records)++;
}

// Function to search for a record in the database
record_t* search_record(record_t** records, int* num_records, char* name) {
    int i;
    for (i = 0; i < *num_records; i++) {
        if (strcmp(records[i]->name, name) == 0) {
            return records[i];
        }
    }
    return NULL;
}

// Function to display all records in the database
void display_records(record_t** records, int* num_records) {
    int i;
    for (i = 0; i < *num_records; i++) {
        printf("%s %d %f\n", records[i]->name, records[i]->age, records[i]->salary);
    }
}

int main() {
    record_t** records = (record_t**) malloc(MAX_RECORDS * sizeof(record_t*));
    int num_records = 0;

    // Insert some records
    insert_record(records, &num_records, "John", 30, 50000.0f);
    insert_record(records, &num_records, "Jane", 25, 40000.0f);
    insert_record(records, &num_records, "Bob", 40, 60000.0f);

    // Search for a record
    record_t* john = search_record(records, &num_records, "John");
    if (john != NULL) {
        printf("Found John with age %d and salary %f\n", john->age, john->salary);
    } else {
        printf("No John found\n");
    }

    // Display all records
    display_records(records, &num_records);

    // Free memory
    free(records);

    return 0;
}