//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DATABASE_SIZE 100
#define MAX_RECORDS 50

// Structure to store database records
typedef struct {
    char name[50];
    int age;
} record_t;

// Function to initialize the database
void init_database(record_t** database) {
    int i;
    for (i = 0; i < DATABASE_SIZE; i++) {
        record_t* record = malloc(sizeof(record_t));
        record->name[0] = '\0';
        record->age = rand() % 100;
        database[i] = record;
    }
}

// Function to add a record to the database
void add_record(record_t** database, char* name, int age) {
    int i;
    for (i = 0; i < DATABASE_SIZE; i++) {
        if (strcmp(database[i]->name, name) == 0) {
            // Record already exists, update the age
            database[i]->age = age;
            return;
        }
    }
    // Record does not exist, add it to the database
    record_t* new_record = malloc(sizeof(record_t));
    strcpy(new_record->name, name);
    new_record->age = age;
    database[i] = new_record;
}

// Function to retrieve a record from the database
record_t* retrieve_record(record_t** database, char* name) {
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
            return;
        }
    }
}

int main() {
    record_t** database = malloc(DATABASE_SIZE * sizeof(record_t*));
    init_database(database);

    // Add some records to the database
    add_record(database, "John", 25);
    add_record(database, "Jane", 30);
    add_record(database, "Bob", 35);

    // Retrieve a record from the database
    record_t* john = retrieve_record(database, "John");
    if (john != NULL) {
        printf("John's age is %d\n", john->age);
    }

    // Delete a record from the database
    delete_record(database, "Jane");

    // Print the remaining records in the database
    for (int i = 0; i < DATABASE_SIZE; i++) {
        if (database[i] != NULL) {
            printf("%s is %d years old\n", database[i]->name, database[i]->age);
        }
    }

    return 0;
}