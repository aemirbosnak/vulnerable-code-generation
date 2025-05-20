//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Database structure
typedef struct {
    int id;
    char *name;
    char *address;
    char *city;
    char *state;
    char *zip;
} Record;

// Index structure
typedef struct {
    int id;
    int offset;
} Index;

// Create a new database
Record *create_database(int num_records) {
    Record *database = malloc(sizeof(Record) * num_records);
    for (int i = 0; i < num_records; i++) {
        database[i].id = i;
        database[i].name = malloc(sizeof(char) * 100);
        database[i].address = malloc(sizeof(char) * 100);
        database[i].city = malloc(sizeof(char) * 100);
        database[i].state = malloc(sizeof(char) * 100);
        database[i].zip = malloc(sizeof(char) * 100);
        sprintf(database[i].name, "John Doe %d", i);
        sprintf(database[i].address, "123 Main Street %d", i);
        sprintf(database[i].city, "Anytown %d", i);
        sprintf(database[i].state, "CA %d", i);
        sprintf(database[i].zip, "12345 %d", i);
    }
    return database;
}

// Create an index for a database
Index *create_index(Record *database, int num_records) {
    Index *index = malloc(sizeof(Index) * num_records);
    for (int i = 0; i < num_records; i++) {
        index[i].id = database[i].id;
        index[i].offset = i * sizeof(Record);
    }
    return index;
}

// Search a database menggunakan index
Record *search_database_using_index(Index *index, int num_records, int id) {
    for (int i = 0; i < num_records; i++) {
        if (index[i].id == id) {
            return (Record *)((char *)index + index[i].offset);
        }
    }
    return NULL;
}

// Search a database secara linear
Record *search_database_linearly(Record *database, int num_records, int id) {
    for (int i = 0; i < num_records; i++) {
        if (database[i].id == id) {
            return &database[i];
        }
    }
    return NULL;
}

// Print a database
void print_database(Record *database, int num_records) {
    for (int i = 0; i < num_records; i++) {
        printf("ID: %d\n", database[i].id);
        printf("Name: %s\n", database[i].name);
        printf("Address: %s\n", database[i].address);
        printf("City: %s\n", database[i].city);
        printf("State: %s\n", database[i].state);
        printf("Zip: %s\n", database[i].zip);
        printf("----------------------------\n");
    }
}

// Main function
int main() {
    // Create a database
    Record *database = create_database(100000);

    // Create an index for the database
    Index *index = create_index(database, 100000);

    // Search for a record using the index
    Record *record = search_database_using_index(index, 100000, 50000);

    // Print the record
    printf("Record found:\n");
    print_database(record, 1);

    // Search for a record linearly
    record = search_database_linearly(database, 100000, 50000);

    // Print the record
    printf("Record found:\n");
    print_database(record, 1);

    // Free the database
    for (int i = 0; i < 100000; i++) {
        free(database[i].name);
        free(database[i].address);
        free(database[i].city);
        free(database[i].state);
        free(database[i].zip);
    }
    free(database);

    // Free the index
    free(index);

    return 0;
}