//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to represent a database record
typedef struct {
    int id;
    char name[50];
    double score;
} record_t;

// Function to insert a record into the database
void insert(record_t** database, int size, int id, char name[50], double score) {
    // Check if the record already exists
    for (int i = 0; i < size; i++) {
        if (database[i]->id == id) {
            printf("Record already exists with id %d\n", id);
            return;
        }
    }

    // Allocate memory for a new record
    record_t* new_record = (record_t*) malloc(sizeof(record_t));
    new_record->id = id;
    strcpy(new_record->name, name);
    new_record->score = score;

    // Insert the new record into the database
    int index = size++;
    database[index] = new_record;

    // Print the updated database
    for (int i = 0; i < size; i++) {
        printf("%d: %s (%.2f)\n", database[i]->id, database[i]->name, database[i]->score);
    }
}

// Function to search for a record in the database
record_t* search(record_t** database, int size, int id) {
    for (int i = 0; i < size; i++) {
        if (database[i]->id == id) {
            return database[i];
        }
    }

    return NULL;
}

// Function to update a record in the database
void update(record_t** database, int size, int id, char name[50], double score) {
    record_t* found_record = search(database, size, id);

    if (found_record != NULL) {
        strcpy(found_record->name, name);
        found_record->score = score;

        // Print the updated database
        for (int i = 0; i < size; i++) {
            printf("%d: %s (%.2f)\n", database[i]->id, database[i]->name, database[i]->score);
        }
    } else {
        printf("Record not found with id %d\n", id);
    }
}

// Function to delete a record from the database
void delete(record_t** database, int size, int id) {
    for (int i = 0; i < size; i++) {
        if (database[i]->id == id) {
            // Free memory for the record
            free(database[i]);

            // Remove the record from the database
            for (int j = i; j < size - 1; j++) {
                database[j] = database[j + 1];
            }

            size--;

            // Print the updated database
            for (int i = 0; i < size; i++) {
                printf("%d: %s (%.2f)\n", database[i]->id, database[i]->name, database[i]->score);
            }

            return;
        }
    }

    printf("Record not found with id %d\n", id);
}

int main() {
    // Create a database with 5 records
    record_t** database = (record_t**) malloc(5 * sizeof(record_t*));
    for (int i = 0; i < 5; i++) {
        record_t* new_record = (record_t*) malloc(sizeof(record_t));
        new_record->id = i + 1;
        strcpy(new_record->name, "Student");
        new_record->score = (double) i / 10.0;

        database[i] = new_record;
    }

    // Insert some records
    insert(database, 5, 1, "John", 90.0);
    insert(database, 5, 2, "Jane", 85.0);
    insert(database, 5, 3, "Bob", 75.0);

    // Search for a record
    record_t* found_record = search(database, 5, 2);
    if (found_record != NULL) {
        printf("Found record with id %d: %s (%.2f)\n", found_record->id, found_record->name, found_record->score);
    } else {
        printf("Record not found with id %d\n", 2);
    }

    // Update a record
    update(database, 5, 3, "Bob", 80.0);

    // Delete a record
    delete(database, 5, 1);

    return 0;
}