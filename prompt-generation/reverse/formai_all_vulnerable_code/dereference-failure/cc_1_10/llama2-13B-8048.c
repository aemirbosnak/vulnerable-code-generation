//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DATABASE_SIZE 1000
#define RECORD_SIZE 50

// Structure to store records in the database
typedef struct {
    char name[50];
    char email[50];
    int age;
} record_t;

// Function to initialize the database
void init_database(record_t** database) {
    int i;
    for (i = 0; i < DATABASE_SIZE; i++) {
        record_t* record = malloc(sizeof(record_t));
        srand(time(NULL));
        strcpy(record->name, "Person");
        strcpy(record->email, "person@email.com");
        record->age = rand() % 50 + 1;
        database[i] = record;
    }
}

// Function to insert a record into the database
void insert_record(record_t** database, char* name, char* email, int age) {
    int i;
    for (i = 0; i < DATABASE_SIZE; i++) {
        if (strcmp(database[i]->name, name) == 0) {
            // Record already exists, update the age
            database[i]->age = age;
            return;
        }
    }
    // Record does not exist, insert a new one
    record_t* new_record = malloc(sizeof(record_t));
    strcpy(new_record->name, name);
    strcpy(new_record->email, email);
    new_record->age = age;
    database[i] = new_record;
}

// Function to search for a record in the database
record_t* search_record(record_t** database, char* name) {
    int i;
    for (i = 0; i < DATABASE_SIZE; i++) {
        if (strcmp(database[i]->name, name) == 0) {
            return database[i];
        }
    }
    return NULL;
}

// Function to display all records in the database
void display_records(record_t** database) {
    int i;
    for (i = 0; i < DATABASE_SIZE; i++) {
        printf("%s %s %d\n", database[i]->name, database[i]->email, database[i]->age);
    }
}

int main() {
    record_t** database;
    init_database(&database);

    // Insert some records
    insert_record(database, "Alice", "alice@email.com", 25);
    insert_record(database, "Bob", "bob@email.com", 30);
    insert_record(database, "Charlie", "charlie@email.com", 35);

    // Search for a record
    record_t* found_record = search_record(database, "Alice");
    if (found_record != NULL) {
        printf("Found record: %s %s %d\n", found_record->name, found_record->email, found_record->age);
    } else {
        printf("Record not found\n");
    }

    // Display all records
    display_records(database);

    return 0;
}