//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DATABASE_SIZE 100
#define RECORD_SIZE 50

// Structure to store database records
typedef struct {
    char name[RECORD_SIZE];
    int age;
    char address[20];
} record_t;

// Function to insert a record into the database
void insert_record(record_t** database, int* size, const char* name, int age, const char* address) {
    int i;
    for (i = 0; i < *size; i++) {
        if (strcmp(database[i]->name, name) == 0) {
            // Record already exists, update the age and address
            database[i]->age = age;
            strcpy(database[i]->address, address);
            return;
        }
    }
    // Record does not exist, allocate a new slot and insert the record
    if (*size == DATABASE_SIZE) {
        printf("Database full, cannot insert new record\n");
        return;
    }
    *size += 1;
    database[*size] = (record_t*) malloc(sizeof(record_t));
    strcpy(database[*size]->name, name);
    database[*size]->age = age;
    strcpy(database[*size]->address, address);
}

// Function to search for a record in the database
int search_record(record_t** database, int size, const char* name) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(database[i]->name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to delete a record from the database
void delete_record(record_t** database, int size, int index) {
    if (index < size) {
        // Free the memory allocated for the record
        free(database[index]);
        // Shift the remaining records to fill the gap
        memmove(database + index, database + index + 1, (size - index - 1) * sizeof(record_t*));
        size -= 1;
    }
}

int main() {
    record_t** database;
    int size = 0;

    // Create the database with an initial size of 100 slots
    database = (record_t**) malloc(DATABASE_SIZE * sizeof(record_t*));
    for (int i = 0; i < DATABASE_SIZE; i++) {
        database[i] = (record_t*) malloc(sizeof(record_t));
        strcpy(database[i]->name, "Unknown");
        database[i]->age = 0;
        database[i]->address[0] = '\0';
    }

    // Insert some records
    insert_record(database, &size, "Alice", 25, "123 Main St");
    insert_record(database, &size, "Bob", 30, "456 Elm St");
    insert_record(database, &size, "Charlie", 35, "789 Oak St");

    // Search for a record
    int index = search_record(database, size, "Bob");
    if (index >= 0) {
        printf("Found record for Bob at index %d\n", index);
    } else {
        printf("No record found for Bob\n");
    }

    // Delete a record
    delete_record(database, size, 1);

    // Print the remaining records
    for (int i = 0; i < size; i++) {
        printf("%d: %s %d %s\n", i, database[i]->name, database[i]->age, database[i]->address);
    }

    // Free the memory allocated for the database
    free(database);

    return 0;
}