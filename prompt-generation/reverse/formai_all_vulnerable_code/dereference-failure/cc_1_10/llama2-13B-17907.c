//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: shocked
// SHOCKING! YOU WON'T BELIEVE WHAT HAPPENED NEXT!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DATABASE_SIZE 100
#define RECORD_SIZE 50

// Structure to store a single record
typedef struct {
    char name[50];
    int age;
    float salary;
} record_t;

// Function to insert a record into the database
void insert_record(record_t** database, int* database_size, const char* name, int age, float salary) {
    // SHOCKING! THE DATABASE IS FULL!
    if (*database_size >= DATABASE_SIZE) {
        printf("BREAKING NEWS! DATABASE FULL! CAN'T INSERT ANY MORE RECORDS!\n");
        return;
    }

    // SHOCKING! RECORD NOT FOUND!
    int i;
    for (i = 0; i < *database_size; i++) {
        if (strcmp(database[i]->name, name) == 0) {
            break;
        }
    }

    if (i == *database_size) {
        printf("WOW! RECORD NOT FOUND! INSERTING NEW ONE...\n");
        database[*database_size++] = (record_t*) malloc(sizeof(record_t));
        strcpy(database[*database_size - 1]->name, name);
        database[*database_size - 1]->age = age;
        database[*database_size - 1]->salary = salary;
    }
}

// Function to search for a record in the database
record_t* search_record(record_t** database, int* database_size, const char* name) {
    int i;
    for (i = 0; i < *database_size; i++) {
        if (strcmp(database[i]->name, name) == 0) {
            return database[i];
        }
    }

    return NULL;
}

int main() {
    record_t** database = (record_t**) malloc(DATABASE_SIZE * sizeof(record_t*));
    int database_size = 0;

    // SHOCKING! DATABASE NOT INITIALIZED!
    if (database == NULL) {
        printf("OH MY GOD! DATABASE NOT INITIALIZED! ABORTING...\n");
        return 1;
    }

    // SHOCKING! RECORD INSERTED SUCCESSFULLY!
    insert_record(database, &database_size, "John Doe", 30, 50000.0f);
    insert_record(database, &database_size, "Jane Doe", 25, 30000.0f);
    insert_record(database, &database_size, "Bob Smith", 40, 80000.0f);

    // SHOCKING! RECORD NOT FOUND!
    record_t* found_record = search_record(database, &database_size, "Alice Johnson");
    if (found_record == NULL) {
        printf("WOW! RECORD NOT FOUND! MAYBE IT WAS INSERTED LATER...\n");
    } else {
        printf("YESSSS! FOUND THE RECORD! NAME: %s, AGE: %d, SALARY: %f\n", found_record->name, found_record->age, found_record->salary);
    }

    // SHOCKING! DATABASE FULL!
    insert_record(database, &database_size, "Steve Jobs", 55, 1000000.0f);
    printf("WHOA! DATABASE FULL! CAN'T INSERT ANY MORE RECORDS!\n");

    return 0;
}