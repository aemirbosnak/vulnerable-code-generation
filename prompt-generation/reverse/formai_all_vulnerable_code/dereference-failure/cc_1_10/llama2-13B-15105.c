//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to represent a record in the database
typedef struct {
    int id;
    char name[50];
    char email[50];
} record_t;

// Function to insert a record into the database
void insert_record(record_t** database, int* num_records, const char* name, const char* email) {
    // Generate a unique ID for the record
    int id = (int)time(NULL);

    // Allocate memory for the new record
    record_t* new_record = (record_t*)malloc(sizeof(record_t));
    new_record->id = id;
    strcpy(new_record->name, name);
    strcpy(new_record->email, email);

    // Add the new record to the end of the database
    *num_records += 1;
    database = (record_t**)realloc(database, (*num_records)*sizeof(record_t*));
    database[*num_records - 1] = new_record;
}

// Function to search for a record in the database
record_t* search_record(record_t** database, int num_records, const char* name) {
    for (int i = 0; i < num_records; i++) {
        if (strcmp(database[i]->name, name) == 0) {
            return database[i];
        }
    }
    return NULL;
}

// Function to update a record in the database
void update_record(record_t** database, int* num_records, int id, const char* name, const char* email) {
    for (int i = 0; i < *num_records; i++) {
        if (database[i]->id == id) {
            strcpy(database[i]->name, name);
            strcpy(database[i]->email, email);
            break;
        }
    }
}

// Function to delete a record from the database
void delete_record(record_t** database, int* num_records, int id) {
    for (int i = 0; i < *num_records; i++) {
        if (database[i]->id == id) {
            // Free the memory allocated for the record
            free(database[i]);

            // Decrease the number of records in the database
            *num_records -= 1;

            // Shift the remaining records to fill the gap
            for (int j = i; j < *num_records; j++) {
                database[j] = database[j + 1];
            }

            break;
        }
    }
}

int main() {
    // Create a database with 5 records
    record_t** database = (record_t**)malloc(5*sizeof(record_t*));
    int num_records = 5;

    // Insert some records into the database
    insert_record(database, &num_records, "Alice", "alice@example.com");
    insert_record(database, &num_records, "Bob", "bob@example.com");
    insert_record(database, &num_records, "Charlie", "charlie@example.com");

    // Search for a record in the database
    record_t* found_record = search_record(database, num_records, "Alice");
    if (found_record != NULL) {
        printf("Found record: %s %s\n", found_record->name, found_record->email);
    } else {
        printf("Record not found\n");
    }

    // Update a record in the database
    update_record(database, &num_records, 2, "Bob", "bob2@example.com");

    // Delete a record from the database
    delete_record(database, &num_records, 3);

    // Print the remaining records in the database
    for (int i = 0; i < num_records; i++) {
        printf("%d: %s %s\n", database[i]->id, database[i]->name, database[i]->email);
    }

    // Free the memory allocated for the database
    free(database);

    return 0;
}