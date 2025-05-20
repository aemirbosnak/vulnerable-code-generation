//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the database structure
typedef struct {
    char *name;
    char *value;
} DatabaseEntry;

// Define the database
DatabaseEntry *database = NULL;
int databaseSize = 0;

// Add a new entry to the database
void addEntry(char *name, char *value) {
    // Allocate memory for the new entry
    DatabaseEntry *newEntry = malloc(sizeof(DatabaseEntry));

    // Copy the name and value into the new entry
    newEntry->name = strdup(name);
    newEntry->value = strdup(value);

    // Add the new entry to the database
    database = realloc(database, (databaseSize + 1) * sizeof(DatabaseEntry));
    database[databaseSize++] = *newEntry;
}

// Get the value of an entry from the database
char *getEntry(char *name) {
    // Iterate over the database
    for (int i = 0; i < databaseSize; i++) {
        // Check if the name matches
        if (strcmp(database[i].name, name) == 0) {
            // Return the value
            return database[i].value;
        }
    }

    // Return NULL if the name was not found
    return NULL;
}

// Delete an entry from the database
void deleteEntry(char *name) {
    // Iterate over the database
    for (int i = 0; i < databaseSize; i++) {
        // Check if the name matches
        if (strcmp(database[i].name, name) == 0) {
            // Delete the entry
            free(database[i].name);
            free(database[i].value);
            database[i] = database[databaseSize - 1];
            databaseSize--;

            // Return
            return;
        }
    }
}

// Print the database
void printDatabase() {
    // Iterate over the database
    for (int i = 0; i < databaseSize; i++) {
        // Print the name and value
        printf("%s = %s\n", database[i].name, database[i].value);
    }
}

// Main function
int main() {
    // Add some entries to the database
    addEntry("name", "John Doe");
    addEntry("age", "25");
    addEntry("city", "New York");

    // Get the value of an entry
    char *name = getEntry("name");
    printf("Name: %s\n", name);

    // Delete an entry
    deleteEntry("age");

    // Print the database
    printDatabase();

    return 0;
}