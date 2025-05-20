//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Structure to represent a record in the database
typedef struct {
    char name[50];
    int age;
} record_t;

// Function to insert a record into the database
void insert_record(record_t **database, int num_records, char *name, int age) {
    int i;
    for (i = 0; i < num_records; i++) {
        if (strcmp(database[i]->name, name) == 0) {
            // Record already exists, update the age
            database[i]->age = age;
            break;
        }
    }
    // Record does not exist, add it to the end of the list
    if (i == num_records) {
        database[num_records++] = (record_t *)malloc(sizeof(record_t));
        strcpy(database[num_records - 1]->name, name);
        database[num_records - 1]->age = age;
    }
}

// Function to search for a record in the database
record_t *search_record(record_t **database, int num_records, char *name) {
    int i;
    for (i = 0; i < num_records; i++) {
        if (strcmp(database[i]->name, name) == 0) {
            return database[i];
        }
    }
    return NULL;
}

// Function to display all records in the database
void display_records(record_t **database, int num_records) {
    int i;
    for (i = 0; i < num_records; i++) {
        printf("%s %d\n", database[i]->name, database[i]->age);
    }
}

int main() {
    // Create an empty database
    record_t *database = NULL;
    int num_records = 0;

    // Insert some records
    insert_record(&database, num_records, "Alice", 25);
    insert_record(&database, num_records, "Bob", 30);
    insert_record(&database, num_records, "Charlie", 35);
    insert_record(&database, num_records, "David", 20);

    // Search for a record
    record_t *alice = search_record(&database, num_records, "Alice");
    if (alice != NULL) {
        printf("Alice found at age %d\n", alice->age);
    } else {
        printf("Alice not found\n");
    }

    // Display all records
    display_records(&database, num_records);

    return 0;
}