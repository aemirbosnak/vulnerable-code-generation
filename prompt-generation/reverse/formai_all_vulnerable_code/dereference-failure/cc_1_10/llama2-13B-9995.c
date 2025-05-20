//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DATABASE_SIZE 100
#define RECORD_SIZE 50

// Structure to represent a record in the database
typedef struct {
    char name[RECORD_SIZE];
    char email[RECORD_SIZE];
    int age;
} record_t;

// Function to initialize the database
void init_database(record_t** database) {
    int i;
    for (i = 0; i < DATABASE_SIZE; i++) {
        record_t* record = (record_t*) malloc(sizeof(record_t));
        srand(time(NULL));
        strcpy(record->name, "Person ");
        strcpy(record->email, "person@example.com");
        record->age = rand() % 100;
        database[i] = record;
    }
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

// Function to add a record to the database
void add_record(record_t** database, char* name, char* email) {
    int i;
    for (i = 0; i < DATABASE_SIZE; i++) {
        if (strcmp(database[i]->name, name) == 0) {
            // Record already exists, do nothing
            return;
        }
    }
    record_t* new_record = (record_t*) malloc(sizeof(record_t));
    strcpy(new_record->name, name);
    strcpy(new_record->email, email);
    new_record->age = rand() % 100;
    database[i] = new_record;
}

// Function to remove a record from the database
void remove_record(record_t** database, char* name) {
    int i;
    for (i = 0; i < DATABASE_SIZE; i++) {
        if (strcmp(database[i]->name, name) == 0) {
            // Found the record to remove
            free(database[i]);
            database[i] = NULL;
            break;
        }
    }
}

int main() {
    record_t** database = (record_t**) malloc(DATABASE_SIZE * sizeof(record_t*));
    init_database(database);

    // Search for a record
    char* name = "John Doe";
    record_t* found_record = search_record(database, name);
    if (found_record != NULL) {
        printf("Found record: %s %s %d\n", found_record->name, found_record->email, found_record->age);
    } else {
        printf("Record not found\n");
    }

    // Add a new record
    char* new_name = "Jane Doe";
    char* new_email = "jane@example.com";
    add_record(database, new_name, new_email);

    // Remove a record
    char* remove_name = "John Doe";
    remove_record(database, remove_name);

    // Print the updated database
    for (int i = 0; i < DATABASE_SIZE; i++) {
        if (database[i] != NULL) {
            printf("%d. %s %s %d\n", i, database[i]->name, database[i]->email, database[i]->age);
        }
    }

    return 0;
}