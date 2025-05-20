//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DATABASE_SIZE 1000
#define RECORD_SIZE 50

// Structure to store a single record
typedef struct {
    char name[20];
    int age;
    float salary;
} record_t;

// Function to initialize the database
void init_database(record_t** database) {
    int i;
    for (i = 0; i < DATABASE_SIZE; i++) {
        record_t* new_record = malloc(sizeof(record_t));
        new_record->name[0] = '\0';
        new_record->age = (int)(rand() % 50) + 1;
        new_record->salary = (float)(rand() % 1000) / 10.0;
        database[i] = new_record;
    }
}

// Function to insert a new record into the database
void insert_record(record_t** database, char* name, int age, float salary) {
    int i;
    for (i = 0; i < DATABASE_SIZE; i++) {
        if (strcmp(database[i]->name, name) == 0) {
            // Record already exists, update the values
            database[i]->age = age;
            database[i]->salary = salary;
            return;
        }
    }
    // Record does not exist, add it to the end of the database
    record_t* new_record = malloc(sizeof(record_t));
    strcpy(new_record->name, name);
    new_record->age = age;
    new_record->salary = salary;
    database[i] = new_record;
}

// Function to search for a record in the database
record_t* search_record(record_t** database, char* name) {
    int i;
    for (i = 0; i < DATABASE_SIZE; i++) {
        if (strcmp(database[i]->name, name) == 0) {
            return database[i];
        }
    }
    return NULL;
}

// Function to delete a record from the database
void delete_record(record_t** database, char* name) {
    int i;
    for (i = 0; i < DATABASE_SIZE; i++) {
        if (strcmp(database[i]->name, name) == 0) {
            // Found the record to delete, remove it from the database
            database[i] = database[i + 1];
            free(database[i]);
            break;
        }
    }
}

int main() {
    record_t** database = malloc(DATABASE_SIZE * sizeof(record_t*));
    init_database(database);

    // Insert some records
    insert_record(database, "Alice", 25, 50000.0);
    insert_record(database, "Bob", 30, 60000.0);
    insert_record(database, "Charlie", 35, 70000.0);

    // Search for a record
    record_t* found_record = search_record(database, "Bob");
    if (found_record != NULL) {
        printf("Found record: %s, age: %d, salary: %f\n", found_record->name, found_record->age, found_record->salary);
    } else {
        printf("Record not found\n");
    }

    // Delete a record
    delete_record(database, "Charlie");

    // Print the remaining records
    for (int i = 0; i < DATABASE_SIZE; i++) {
        if (database[i] != NULL) {
            printf("Record: %s, age: %d, salary: %f\n", database[i]->name, database[i]->age, database[i]->salary);
        }
    }

    return 0;
}