//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DATABASE_SIZE 1000
#define RECORD_SIZE 50

// Structure to hold a single record
typedef struct {
    char name[RECORD_SIZE];
    int age;
    float salary;
} record_t;

// Function to initialize the database
void init_database(record_t** database) {
    int i;
    for (i = 0; i < DATABASE_SIZE; i++) {
        record_t* record = malloc(sizeof(record_t));
        sprintf(record->name, "Person %d", i);
        record->age = i % 10;
        record->salary = (float)i * 10;
        database[i] = record;
    }
}

// Function to search for a record
record_t* search_record(record_t** database, char* name) {
    int i;
    for (i = 0; i < DATABASE_SIZE; i++) {
        if (strcmp(database[i]->name, name) == 0) {
            return database[i];
        }
    }
    return NULL;
}

// Function to add a new record
void add_record(record_t** database, char* name, int age, float salary) {
    int i;
    for (i = 0; i < DATABASE_SIZE; i++) {
        if (database[i] == NULL) {
            break;
        }
    }
    if (i == DATABASE_SIZE) {
        printf("Database is full, cannot add more records\n");
        return;
    }
    record_t* record = malloc(sizeof(record_t));
    sprintf(record->name, "%s", name);
    record->age = age;
    record->salary = salary;
    database[i] = record;
}

// Function to delete a record
void delete_record(record_t** database, char* name) {
    int i;
    for (i = 0; i < DATABASE_SIZE; i++) {
        if (strcmp(database[i]->name, name) == 0) {
            free(database[i]);
            database[i] = NULL;
            break;
        }
    }
}

int main() {
    record_t** database;
    init_database(&database);

    // Add some records
    add_record(database, "John Doe", 30, 50000.0);
    add_record(database, "Jane Doe", 25, 40000.0);
    add_record(database, "Bob Smith", 40, 60000.0);

    // Search for a record
    record_t* found_record = search_record(database, "John Doe");
    if (found_record != NULL) {
        printf("Found record: %s, %d, %f\n", found_record->name, found_record->age, found_record->salary);
    } else {
        printf("Record not found\n");
    }

    // Delete a record
    delete_record(database, "Jane Doe");

    // Print the remaining records
    for (int i = 0; i < DATABASE_SIZE; i++) {
        if (database[i] != NULL) {
            printf("Record %d: %s, %d, %f\n", i, database[i]->name, database[i]->age, database[i]->salary);
        }
    }

    return 0;
}