//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DATABASE_SIZE 10000
#define RECORD_SIZE 50

// Structure to store records in the database
typedef struct {
    char name[50];
    int age;
    float height;
    char gender;
} record_t;

// Function to initialize the database
void init_database(record_t** database) {
    int i;
    for (i = 0; i < DATABASE_SIZE; i++) {
        record_t* record = malloc(sizeof(record_t));
        record->name[0] = '\0';
        record->age = (int)((double)i / 10);
        record->height = (float)((double)i / 10) * 2.5;
        record->gender = 'M'; // Male by default
        database[i] = record;
    }
}

// Function to add a record to the database
void add_record(record_t** database, char* name, int age, float height, char gender) {
    int i = DATABASE_SIZE;
    while (i-- > 0 && strcmp(database[i]->name, name) != 0) {}
    if (i < 0) {
        record_t* record = malloc(sizeof(record_t));
        strcpy(record->name, name);
        record->age = age;
        record->height = height;
        record->gender = gender;
        database[i] = record;
    }
}

// Function to retrieve a record from the database
record_t* retrieve_record(record_t** database, char* name) {
    int i = DATABASE_SIZE;
    while (i-- > 0 && strcmp(database[i]->name, name) != 0) {}
    if (i < 0) {
        return NULL;
    }
    return database[i];
}

// Function to print all records in the database
void print_database(record_t** database) {
    int i = DATABASE_SIZE;
    while (i-- > 0) {
        printf("%s %d %f %c\n", database[i]->name, database[i]->age, database[i]->height, database[i]->gender);
    }
}

int main() {
    record_t** database = malloc(DATABASE_SIZE * sizeof(record_t*));
    init_database(database);

    // Add some records to the database
    add_record(database, "John", 25, 1.75, 'M');
    add_record(database, "Jane", 30, 1.60, 'F');
    add_record(database, "Bob", 35, 1.80, 'M');

    // Retrieve a record from the database
    record_t* john = retrieve_record(database, "John");
    if (john != NULL) {
        printf("John's details: %s %d %f %c\n", john->name, john->age, john->height, john->gender);
    } else {
        printf("John not found in the database\n");
    }

    // Print all records in the database
    print_database(database);

    return 0;
}