//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DATABASE_SIZE 100
#define MAX_RECORD_SIZE 256

// Structure to represent a record in the database
typedef struct {
    char name[MAX_RECORD_SIZE];
    int age;
} record_t;

// Function to initialize the database with random records
void init_database(record_t **database) {
    int i, j;

    for (i = 0; i < DATABASE_SIZE; i++) {
        // Generate a random name and age
        char name[MAX_RECORD_SIZE];
        int age = rand() % 100;

        // Create a new record and store it in the database
        record_t *new_record = malloc(sizeof(record_t));
        strcpy(new_record->name, name);
        new_record->age = age;
        database[i] = new_record;

        // Print the new record
        printf("Record %d: %s, age %d\n", i, new_record->name, new_record->age);
    }
}

// Function to search for a record in the database
record_t* search_record(record_t **database, char *name) {
    int i;

    for (i = 0; i < DATABASE_SIZE; i++) {
        if (strcmp(database[i]->name, name) == 0) {
            return database[i];
        }
    }

    return NULL;
}

// Function to insert a new record into the database
void insert_record(record_t **database, char *name, int age) {
    int i;

    for (i = 0; i < DATABASE_SIZE; i++) {
        if (database[i] == NULL) {
            // If the database is full, allocate a new record and copy the old records to the new one
            record_t *new_record = malloc(sizeof(record_t));
            strcpy(new_record->name, name);
            new_record->age = age;
            database[i] = new_record;

            // Copy the old records to the new one
            for (int j = 0; j < i; j++) {
                record_t *old_record = database[j];
                strcpy(new_record->name, old_record->name);
                new_record->age = old_record->age;
                database[j] = new_record;
            }

            break;
        }
    }
}

// Function to delete a record from the database
void delete_record(record_t **database, char *name) {
    int i;

    for (i = 0; i < DATABASE_SIZE; i++) {
        if (strcmp(database[i]->name, name) == 0) {
            // If the record is found, remove it from the database
            database[i] = database[i + 1];
            free(database[i]);
            break;
        }
    }
}

int main() {
    record_t **database = malloc(DATABASE_SIZE * sizeof(record_t*));
    init_database(database);

    // Search for a record
    record_t* found_record = search_record(database, "Alice");
    if (found_record != NULL) {
        printf("Found record: %s, age %d\n", found_record->name, found_record->age);
    } else {
        printf("Record not found\n");
    }

    // Insert a new record
    insert_record(database, "Bob", 25);

    // Delete a record
    delete_record(database, "Alice");

    return 0;
}