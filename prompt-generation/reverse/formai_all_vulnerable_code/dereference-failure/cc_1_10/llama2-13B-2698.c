//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: visionary
// Visionary Database Simulation

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DATABASE_SIZE 1000
#define RECORD_SIZE 50

// Structure to store records
typedef struct record {
    char name[50];
    int age;
    float salary;
} record_t;

// Function to insert records
void insert_record(record_t** database, int* size, const char* name, int age, float salary) {
    int i;
    for (i = 0; i < *size; i++) {
        if (strcmp(database[i]->name, name) == 0) {
            // Record already exists, update the values
            database[i]->age = age;
            database[i]->salary = salary;
            return;
        }
    }
    // Record does not exist, add it to the database
    database = (record_t**) realloc(database, (*size + 1) * sizeof(record_t*));
    database[*size] = (record_t*) malloc(sizeof(record_t));
    strcpy(database[*size]->name, name);
    database[*size]->age = age;
    database[*size]->salary = salary;
    (*size)++;
}

// Function to retrieve records
void retrieve_records(record_t** database, int* size, const char* name) {
    int i;
    for (i = 0; i < *size; i++) {
        if (strcmp(database[i]->name, name) == 0) {
            printf("%s - %d - %f\n", database[i]->name, database[i]->age, database[i]->salary);
        }
    }
}

// Function to delete records
void delete_record(record_t** database, int* size, const char* name) {
    int i;
    for (i = 0; i < *size; i++) {
        if (strcmp(database[i]->name, name) == 0) {
            // Remove the record from the database
            for (int j = i; j < *size - 1; j++) {
                database[j] = database[j + 1];
            }
            *size--;
            free(database[*size]);
            break;
        }
    }
}

int main() {
    record_t** database = NULL;
    int size = 0;

    // Initialize the database
    for (int i = 0; i < DATABASE_SIZE; i++) {
        database[i] = (record_t*) malloc(sizeof(record_t));
        strcpy(database[i]->name, "Unknown");
        database[i]->age = 0;
        database[i]->salary = 0.0f;
    }

    // Insert some records
    insert_record(&database, &size, "John Doe", 30, 50000.0f);
    insert_record(&database, &size, "Jane Doe", 25, 30000.0f);
    insert_record(&database, &size, "Bob Smith", 40, 60000.0f);

    // Retrieve all records
    retrieve_records(&database, &size, "John Doe");

    // Delete a record
    delete_record(&database, &size, "Jane Doe");

    // Retrieve all records again
    retrieve_records(&database, &size, "John Doe");

    // Free the database
    for (int i = 0; i < size; i++) {
        free(database[i]);
    }
    free(database);

    return 0;
}