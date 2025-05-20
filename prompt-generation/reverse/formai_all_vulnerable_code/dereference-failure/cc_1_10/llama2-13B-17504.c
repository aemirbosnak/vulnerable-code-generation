//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: rigorous
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
record_t* new_record(char* name, int age, float salary) {
    record_t* rec = (record_t*) malloc(sizeof(record_t));
    strcpy(rec->name, name);
    rec->age = age;
    rec->salary = salary;
    return rec;
}

// Function to print a record
void print_record(record_t* rec) {
    printf("Name: %s, Age: %d, Salary: %f\n", rec->name, rec->age, rec->salary);
}

// Function to insert a record into the database
void insert_record(record_t** records, int* num_records, char* name, int age, float salary) {
    int i;
    for (i = 0; i < *num_records; i++) {
        if (strcmp(records[i]->name, name) < 0) {
            break;
        }
    }
    if (i == *num_records) {
        records[*num_records] = new_record(name, age, salary);
        (*num_records)++;
    } else {
        records[i] = new_record(name, age, salary);
    }
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

// Function to delete a record from the database
void delete_record(record_t** records, int* num_records, char* name) {
    int i;
    for (i = 0; i < *num_records; i++) {
        if (strcmp(records[i]->name, name) == 0) {
            break;
        }
    }
    if (i < *num_records) {
        memmove(&records[i], &records[i+1], sizeof(record_t*) * (*num_records - i - 1));
        (*num_records)--;
    }
}

int main() {
    record_t** records = (record_t**) malloc(sizeof(record_t*) * MAX_RECORDS);
    int num_records = 0;

    srand(time(NULL));

    for (int i = 0; i < MAX_RECORDS; i++) {
        char name[50];
        int age;
        float salary;
        printf("Enter name, age, and salary: ");
        scanf("%49s%d%f", name, &age, &salary);
        insert_record(&records, &num_records, name, age, salary);
    }

    record_t* search_result = search_record(records, &num_records, "Alice");
    if (search_result != NULL) {
        print_record(search_result);
    } else {
        printf("No record found\n");
    }

    delete_record(records, &num_records, "Bob");

    for (int i = 0; i < num_records; i++) {
        print_record(records[i]);
    }

    return 0;
}