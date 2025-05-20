//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DATABASE_SIZE 100
#define MAX_RECORD_SIZE 100

// Structure to store a record in the database
typedef struct {
    char name[MAX_RECORD_SIZE];
    int age;
} record_t;

// Function to insert a record into the database
void insert_record(record_t* database, int size, const char* name, int age) {
    int i;

    // Check if the database is full
    if (size == DATABASE_SIZE) {
        printf("Database is full, cannot insert more records.\n");
        return;
    }

    // Find an empty slot in the database
    for (i = 0; i < size; i++) {
        if (database[i].name[0] == '\0') {
            break;
        }
    }

    // Insert the record into the database
    strcpy(database[i].name, name);
    database[i].age = age;

    // Print a message to the user
    printf("Record inserted successfully: %s, age %d\n", name, age);
}

// Function to search for a record in the database
record_t* search_record(record_t* database, int size, const char* name) {
    int i;

    // Check if the database is empty
    if (size == 0) {
        printf("Database is empty, no records found.\n");
        return NULL;
    }

    // Search for the record in the database
    for (i = 0; i < size; i++) {
        if (strcmp(database[i].name, name) == 0) {
            return &database[i];
        }
    }

    // If the record is not found, print a message to the user
    printf("Record not found: %s\n", name);
    return NULL;
}

// Function to display all records in the database
void display_records(record_t* database, int size) {
    int i;

    // Print a message to the user
    printf("Here are the records in the database:\n");

    // Display all records in the database
    for (i = 0; i < size; i++) {
        printf("%d. %s, age %d\n", i + 1, database[i].name, database[i].age);
    }
}

int main() {
    // Create a database with 100 slots
    record_t* database = malloc(DATABASE_SIZE * sizeof(record_t));

    // Initialize the database with some records
    insert_record(database, DATABASE_SIZE, "Alice", 25);
    insert_record(database, DATABASE_SIZE, "Bob", 30);
    insert_record(database, DATABASE_SIZE, "Charlie", 35);

    // Search for a record in the database
    record_t* found_record = search_record(database, DATABASE_SIZE, "Bob");

    // Display all records in the database
    display_records(database, DATABASE_SIZE);

    // Free the database memory
    free(database);

    return 0;
}