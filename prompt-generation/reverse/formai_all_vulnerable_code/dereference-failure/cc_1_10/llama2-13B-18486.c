//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: artistic
// A whimsical journey through a database simulation

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_RECORDS 100
#define MAX_FIELDS 5

// Structure to hold a record
typedef struct {
    char name[50];
    int age;
    char gender;
    float salary;
    char address[100];
} record_t;

// Function to create a record
record_t* create_record(char* name, int age, char gender, float salary, char* address) {
    record_t* rec = (record_t*) malloc(sizeof(record_t));
    strcpy(rec->name, name);
    rec->age = age;
    rec->gender = gender;
    rec->salary = salary;
    strcpy(rec->address, address);
    return rec;
}

// Function to print a record
void print_record(record_t* rec) {
    printf("Name: %s\nAge: %d\nGender: %c\nSalary: %f\nAddress: %s\n",
           rec->name, rec->age, rec->gender, rec->salary, rec->address);
}

// Function to insert a record
void insert_record(record_t** records, int* num_records, char* name, int age, char gender, float salary, char* address) {
    record_t* rec = create_record(name, age, gender, salary, address);
    *num_records += 1;
    records[*num_records - 1] = rec;
}

// Function to search for a record
record_t* search_record(record_t** records, int* num_records, char* name) {
    int i;
    for (i = 0; i < *num_records; i++) {
        if (strcmp(records[i]->name, name) == 0) {
            return records[i];
        }
    }
    return NULL;
}

// Function to update a record
void update_record(record_t** records, int* num_records, int index, char* name, int age, char gender, float salary, char* address) {
    record_t* rec = records[index];
    strcpy(rec->name, name);
    rec->age = age;
    rec->gender = gender;
    rec->salary = salary;
    strcpy(rec->address, address);
}

// Function to delete a record
void delete_record(record_t** records, int* num_records, int index) {
    free(records[index]);
    *num_records -= 1;
}

int main() {
    // Initialize variables
    record_t** records = NULL;
    int num_records = 0;

    // Create some records
    insert_record(&records, &num_records, "Alice", 25, 'F', 50000.0, "123 Main St");
    insert_record(&records, &num_records, "Bob", 30, 'M', 60000.0, "456 Elm St");
    insert_record(&records, &num_records, "Charlie", 20, 'M', 40000.0, "789 Oak St");

    // Search for a record
    record_t* alice = search_record(records, &num_records, "Alice");
    if (alice != NULL) {
        printf("Found Alice at index %d\n", alice - records[0]);
    } else {
        printf("Alice not found\n");
    }

    // Update a record
    update_record(records, &num_records, 1, "Bob", 35, 'M', 70000.0, "901 Maple St");

    // Delete a record
    delete_record(records, &num_records, 2);

    // Print the remaining records
    for (int i = 0; i < num_records; i++) {
        print_record(records[i]);
    }

    return 0;
}