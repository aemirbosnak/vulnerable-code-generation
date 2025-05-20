//FormAI DATASET v1.0 Category: Database simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 50

// Define struct for the database entries
typedef struct {
    int id;
    char name[MAX_SIZE];
    int age;
} Entry;

// Define struct for the database itself
typedef struct {
    int size;
    Entry *entries;
} Database;

// Function to initialize a new empty database
Database *new_database() {
    Database *database = malloc(sizeof(Database));
    if (database == NULL) {
        printf("Error creating database\n");
        exit(1);
    }
    database->size = 0;
    database->entries = NULL;
    return database;
}

// Function to insert a new entry into the database
void insert(Database *database, Entry entry) {
    // Allocate memory for a new array of entries with space for the new entry
    database->entries = realloc(database->entries, (database->size + 1) * sizeof(Entry));
    if (database->entries == NULL) {
        printf("Error inserting entry\n");
        exit(1);
    }
    // Insert the new entry into the last position of the array
    database->entries[database->size++] = entry;
}

// Function to print all entries in the database
void print_all(Database *database) {
    printf("Database:\n");
    for (int i = 0; i < database->size; i++) {
        printf("ID: %d, Name: %s, Age: %d\n", database->entries[i].id, database->entries[i].name, database->entries[i].age);
    }
}

int main() {
    // Initialize the database
    Database *database = new_database();

    // Insert some entries into the database
    Entry entry1 = {1, "John", 42};
    insert(database, entry1);

    Entry entry2 = {2, "Mary", 25};
    insert(database, entry2);

    // Print entries in the database
    print_all(database);

    // Clean up memory used by the database
    free(database->entries);
    free(database);

    return 0;
}