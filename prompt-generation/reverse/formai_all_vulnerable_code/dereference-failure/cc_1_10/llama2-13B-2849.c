//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DATABASE_SIZE 1000
#define RECORD_SIZE 50

// Structure to store a single record
typedef struct {
    char name[50];
    int age;
    float salary;
} record_t;

// Function to initialize the database
void init_database(record_t** database) {
    int i;
    for (i = 0; i < DATABASE_SIZE; i++) {
        record_t* record = malloc(sizeof(record_t));
        srand(time(NULL));
        strcpy(record->name, "Person");
        record->age = rand() % 100;
        record->salary = rand() % 10000;
        database[i] = record;
    }
}

// Function to insert a record into the database
void insert_record(record_t** database, char* name, int age, float salary) {
    int i;
    for (i = 0; i < DATABASE_SIZE; i++) {
        if (strcmp(database[i]->name, name) == 0) {
            // Record already exists, update it
            database[i]->age = age;
            database[i]->salary = salary;
            break;
        }
    }
    if (i == DATABASE_SIZE) {
        // Record does not exist, insert it
        record_t* new_record = malloc(sizeof(record_t));
        strcpy(new_record->name, name);
        new_record->age = age;
        new_record->salary = salary;
        database[i] = new_record;
    }
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
            // Found the record to delete
            free(database[i]);
            database[i] = NULL;
            break;
        }
    }
}

int main() {
    record_t** database;
    init_database(&database);

    // Insert some records
    insert_record(database, "Alice", 25, 50000);
    insert_record(database, "Bob", 30, 60000);
    insert_record(database, "Charlie", 35, 70000);

    // Search for a record
    record_t* alice = search_record(database, "Alice");
    if (alice != NULL) {
        printf("Found Alice with age %d and salary %f\n", alice->age, alice->salary);
    } else {
        printf("No record found\n");
    }

    // Delete a record
    delete_record(database, "Bob");

    // Print the remaining records
    for (int i = 0; i < DATABASE_SIZE; i++) {
        if (database[i] != NULL) {
            printf("Record %d: %s, age %d, salary %f\n", i, database[i]->name, database[i]->age, database[i]->salary);
        }
    }

    return 0;
}