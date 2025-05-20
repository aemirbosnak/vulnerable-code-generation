//FormAI DATASET v1.0 Category: Database querying ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for our database entries
typedef struct Entry {
    int id;
    char name[50];
    int age;
    char occupation[50];
} Entry;

// Define struct for our database table
typedef struct Table {
    Entry* entries;
    int num_entries;
} Table;

// Define a function to query the database for entries with a specific occupation
void query_database(Table* table, char* occupation) {
    // Loop through entries in the table
    for (int i = 0; i < table->num_entries; i++) {
        // Check if entry has the specified occupation
        if (strcmp(table->entries[i].occupation, occupation) == 0) {
            // Print out the entry's information
            printf("ID: %d\n", table->entries[i].id);
            printf("Name: %s\n", table->entries[i].name);
            printf("Age: %d\n", table->entries[i].age);
            printf("Occupation: %s\n", table->entries[i].occupation);
        }
    }
}

int main() {
    // Allocate memory for our table
    Table* table = (Table*) malloc(sizeof(Table));
    table->num_entries = 3;
    table->entries = (Entry*) malloc(sizeof(Entry) * table->num_entries);

    // Add some entries to our table
    table->entries[0].id = 1;
    strcpy(table->entries[0].name, "John");
    table->entries[0].age = 25;
    strcpy(table->entries[0].occupation, "Programmer");

    table->entries[1].id = 2;
    strcpy(table->entries[1].name, "Sarah");
    table->entries[1].age = 30;
    strcpy(table->entries[1].occupation, "Designer");

    table->entries[2].id = 3;
    strcpy(table->entries[2].name, "Mike");
    table->entries[2].age = 22;
    strcpy(table->entries[2].occupation, "Programmer");

    // Query our database for programmers
    char* occupation = "Programmer";
    query_database(table, occupation);

    // Free memory allocated for our table
    free(table->entries);
    free(table);

    return 0;
}