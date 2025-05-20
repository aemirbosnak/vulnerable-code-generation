//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DATABASE_SIZE 1000
#define MAX_RECORD_SIZE 256

// Structure to hold a record in the database
typedef struct {
    char name[MAX_RECORD_SIZE];
    int age;
} record_t;

// Function to insert a record into the database
void insert_record(record_t **database, int size, char *name, int age) {
    int i;

    for (i = 0; i < size; i++) {
        if (strcmp(database[i]->name, name) == 0) {
            // Record already exists, update the age
            database[i]->age = age;
            return;
        }
    }

    // Record does not exist, add it to the database
    database[size++] = (record_t *) malloc(sizeof(record_t));
    strcpy(database[size - 1]->name, name);
    database[size - 1]->age = age;
}

// Function to search for a record in the database
record_t *search_record(record_t **database, int size, char *name) {
    int i;

    for (i = 0; i < size; i++) {
        if (strcmp(database[i]->name, name) == 0) {
            return database[i];
        }
    }

    return NULL;
}

// Function to remove a record from the database
void remove_record(record_t **database, int size, char *name) {
    int i;

    for (i = 0; i < size; i++) {
        if (strcmp(database[i]->name, name) == 0) {
            // Found the record, remove it from the database
            memmove(database[i] + 1, database[i], sizeof(record_t *) * (size - i - 1));
            size--;
            return;
        }
    }
}

int main() {
    record_t *database[DATABASE_SIZE];
    int size = 0;

    // Initialize the database with some records
    insert_record(database, size, "Alice", 25);
    insert_record(database, size, "Bob", 30);
    insert_record(database, size, "Charlie", 35);

    // Search for a record
    record_t *record = search_record(database, size, "Bob");
    if (record != NULL) {
        printf("Found record: %s %d\n", record->name, record->age);
    } else {
        printf("Record not found\n");
    }

    // Remove a record
    remove_record(database, size, "Alice");

    // Print the updated database
    for (int i = 0; i < size; i++) {
        printf("%d. %s %d\n", i, database[i]->name, database[i]->age);
    }

    return 0;
}