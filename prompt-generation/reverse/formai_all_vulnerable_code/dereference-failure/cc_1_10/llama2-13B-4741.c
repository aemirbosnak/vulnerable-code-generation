//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define database structure
typedef struct {
    char *name;
    int age;
} person;

// Define an array to store database records
person database[10];

// Function to insert a record into the database
void insert_record(person *new_record) {
    int i = 0;
    for (i = 0; i < 10; i++) {
        if (strcmp(database[i].name, new_record->name) == 0) {
            printf("Record already exists!\n");
            return;
        }
    }
    // If no record exists, insert the new one
    database[i] = *new_record;
}

// Function to search for a record in the database
person *search_record(char *name) {
    int i = 0;
    for (i = 0; i < 10; i++) {
        if (strcmp(database[i].name, name) == 0) {
            return &database[i];
        }
    }
    return NULL;
}

// Function to update a record in the database
void update_record(person *record) {
    int i = 0;
    for (i = 0; i < 10; i++) {
        if (strcmp(record->name, database[i].name) == 0) {
            database[i].age = record->age;
            break;
        }
    }
}

// Function to delete a record from the database
void delete_record(char *name) {
    int i = 0;
    for (i = 0; i < 10; i++) {
        if (strcmp(database[i].name, name) == 0) {
            // If the record is found, remove it from the array
            memmove(&database[i], &database[i + 1], sizeof(person) * (10 - i - 1));
            break;
        }
    }
}

int main() {
    // Insert some records into the database
    person new_record1 = {"Alice", 25};
    insert_record(&new_record1);
    person new_record2 = {"Bob", 30};
    insert_record(&new_record2);
    person new_record3 = {"Charlie", 35};
    insert_record(&new_record3);

    // Search for a record in the database
    person *found_record = search_record("Alice");
    if (found_record != NULL) {
        printf("Found record: %s, %d\n", found_record->name, found_record->age);
    } else {
        printf("Record not found\n");
    }

    // Update a record in the database
    person updated_record = {"Bob", 35};
    update_record(&updated_record);

    // Delete a record from the database
    delete_record("Bob");

    return 0;
}