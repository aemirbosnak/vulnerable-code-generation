//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DATABASE_SIZE 1000
#define RECORD_SIZE 50

// Structure to store a record in the database
typedef struct {
    char name[20];
    int age;
    float salary;
} record_t;

// Function to create a new record
record_t *create_record(char *name, int age, float salary) {
    record_t *new_record = (record_t *)malloc(sizeof(record_t));
    strcpy(new_record->name, name);
    new_record->age = age;
    new_record->salary = salary;
    return new_record;
}

// Function to insert a record into the database
void insert_record(record_t **database, int size, record_t *new_record) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(database[i]->name, new_record->name) == 0) {
            // Record already exists, update the values
            database[i]->age = new_record->age;
            database[i]->salary = new_record->salary;
            return;
        }
    }
    // Record does not exist, add it to the end of the database
    database[size++] = new_record;
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

// Function to delete a record from the database
void delete_record(record_t **database, int size, char *name) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(database[i]->name, name) == 0) {
            // Found the record, remove it from the database
            memmove(database[i] + 1, database[i], sizeof(record_t *) * (size - i - 1));
            size--;
            break;
        }
    }
}

int main() {
    srand(time(NULL));

    // Create a database with 1000 records
    record_t **database = (record_t **)malloc(sizeof(record_t *) * DATABASE_SIZE);
    for (int i = 0; i < DATABASE_SIZE; i++) {
        record_t *new_record = create_record("Person", rand() % 100 + 1, rand() % 100000 + 1);
        insert_record(database, i, new_record);
    }

    // Search for a record
    char name[] = "John Doe";
    record_t *found_record = search_record(database, DATABASE_SIZE, name);
    if (found_record != NULL) {
        printf("Found record: %s, age: %d, salary: %f\n", found_record->name, found_record->age, found_record->salary);
    } else {
        printf("Record not found\n");
    }

    // Delete a record
    char delete_name[] = "Jane Doe";
    delete_record(database, DATABASE_SIZE, delete_name);

    // Print the updated database
    for (int i = 0; i < DATABASE_SIZE; i++) {
        printf("%d: %s, age: %d, salary: %f\n", i, database[i]->name, database[i]->age, database[i]->salary);
    }

    return 0;
}