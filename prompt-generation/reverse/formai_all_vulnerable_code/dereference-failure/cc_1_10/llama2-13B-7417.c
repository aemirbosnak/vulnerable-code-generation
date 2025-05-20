//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a record in the database
typedef struct {
    char name[50];  // Name of the person
    int age;      // Age of the person
} record_t;

// Function to insert a record into the database
void insert_record(record_t **database, int num_records, char *name, int age) {
    // Find the first empty slot in the database
    int i = 0;
    for (; i < num_records; i++) {
        if (database[i] == NULL) {
            break;
        }
    }

    // If no empty slots found, reallocate the database
    if (i == num_records) {
        int new_size = num_records * 2;
        record_t **new_database = realloc(database, new_size * sizeof(record_t *));
        if (new_database == NULL) {
            printf("Error: Reallocation failed\n");
            return;
        }
        database = new_database;
    }

    // Insert the new record
    database[i] = malloc(sizeof(record_t));
    strcpy(database[i]->name, name);
    database[i]->age = age;
}

// Function to search for a record in the database
int search_record(record_t **database, int num_records, char *name) {
    int i = 0;
    for (; i < num_records; i++) {
        if (strcmp(database[i]->name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to print all records in the database
void print_records(record_t **database, int num_records) {
    int i = 0;
    for (; i < num_records; i++) {
        printf("%d. %s %d\n", i, database[i]->name, database[i]->age);
    }
}

int main() {
    // Initialize the database with some records
    record_t **database = malloc(10 * sizeof(record_t *));
    for (int i = 0; i < 10; i++) {
        insert_record(database, i, "John", 25);
    }

    // Search for a record
    int found = search_record(database, 10, "John");
    if (found != -1) {
        printf("Found record at index %d\n", found);
    } else {
        printf("Record not found\n");
    }

    // Print all records
    print_records(database, 10);

    return 0;
}