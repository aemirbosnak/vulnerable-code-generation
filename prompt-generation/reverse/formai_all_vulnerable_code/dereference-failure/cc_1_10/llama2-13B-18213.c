//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/mman.h>

#define MAX_RECORDS 1000
#define RECORD_SIZE 50

typedef struct record {
    char name[50];
    int age;
    float salary;
} record_t;

typedef struct database {
    char *name;
    int num_records;
    record_t *records;
} database_t;

// Function to create a new database
database_t *create_database(const char *name) {
    database_t *db = (database_t *) malloc(sizeof(database_t));
    db->name = name;
    db->num_records = 0;
    db->records = (record_t *) malloc(sizeof(record_t) * MAX_RECORDS);
    return db;
}

// Function to add a new record to the database
void add_record(database_t *db, const char *name, int age, float salary) {
    if (db->num_records == MAX_RECORDS) {
        printf("Error: Database is full. Cannot add any more records.\n");
        return;
    }

    record_t *new_record = (record_t *) malloc(sizeof(record_t));
    strcpy(new_record->name, name);
    new_record->age = age;
    new_record->salary = salary;

    db->records[db->num_records] = *new_record;
    db->num_records++;
}

// Function to retrieve a record from the database
record_t *get_record(database_t *db, const char *name) {
    for (int i = 0; i < db->num_records; i++) {
        if (strcmp(db->records[i].name, name) == 0) {
            return &db->records[i];
        }
    }

    return NULL;
}

// Function to remove a record from the database
void remove_record(database_t *db, const char *name) {
    for (int i = 0; i < db->num_records; i++) {
        if (strcmp(db->records[i].name, name) == 0) {
            memcpy(&db->records[i], &db->records[db->num_records - 1], sizeof(record_t));
            db->num_records--;
            break;
        }
    }
}

int main() {
    database_t *db = create_database("My Database");

    // Add some records
    add_record(db, "Alice", 25, 50000.0);
    add_record(db, "Bob", 30, 75000.0);
    add_record(db, "Charlie", 35, 100000.0);

    // Retrieve a record
    record_t *alice = get_record(db, "Alice");
    printf("Alice's name is: %s\n", alice->name);
    printf("Alice's age is: %d\n", alice->age);
    printf("Alice's salary is: %f\n", alice->salary);

    // Remove a record
    remove_record(db, "Bob");

    // Print the updated database
    for (int i = 0; i < db->num_records; i++) {
        printf("%d. %s (%d, %f)\n", i + 1, db->records[i].name, db->records[i].age, db->records[i].salary);
    }

    // Clean up
    free(db->records);
    free(db);

    return 0;
}