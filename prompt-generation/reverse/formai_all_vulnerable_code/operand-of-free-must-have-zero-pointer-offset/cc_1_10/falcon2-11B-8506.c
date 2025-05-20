//Falcon2-11B DATASET v1.0 Category: Database querying ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for the database entries
typedef struct {
    char name[50];
    int age;
} DatabaseEntry;

// Function to query the database for entries by name
DatabaseEntry* queryDatabaseByName(DatabaseEntry* database, char* name) {
    // Search through the database entries for the specified name
    for (int i = 0; i < 10; i++) {
        if (strcmp(database[i].name, name) == 0) {
            // Found a match, return the entry
            return &database[i];
        }
    }

    // Entry not found, return NULL
    return NULL;
}

// Function to print the results of a query
void printQueryResults(DatabaseEntry* entries) {
    for (int i = 0; entries[i].name!= NULL; i++) {
        printf("%s, %d\n", entries[i].name, entries[i].age);
    }
}

int main() {
    // Create an array of database entries
    DatabaseEntry database[10];

    // Fill the database with some entries
    strcpy(database[0].name, "John Doe");
    database[0].age = 25;
    strcpy(database[1].name, "Jane Smith");
    database[1].age = 30;
    strcpy(database[2].name, "Bob Johnson");
    database[2].age = 35;

    // Query the database for entries by name
    DatabaseEntry* results = queryDatabaseByName(database, "Jane");

    // Print the results of the query
    if (results!= NULL) {
        printQueryResults(results);
    }

    // Clean up and exit
    for (int i = 0; i < 10; i++) {
        free(database[i].name);
    }
    free(database);

    return 0;
}