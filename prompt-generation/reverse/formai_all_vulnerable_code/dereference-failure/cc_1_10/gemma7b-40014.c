//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the database structure
typedef struct Database {
    char name[255];
    int age;
    struct Database* next;
} Database;

// Define the indexing system structure
typedef struct IndexingSystem {
    Database* head;
    struct IndexingSystem* next;
} IndexingSystem;

// Function to insert a new database entry
void insertDatabaseEntry(IndexingSystem* system, char* name, int age) {
    // Allocate memory for the new entry
    Database* newEntry = (Database*)malloc(sizeof(Database));

    // Copy the name and age of the new entry
    strcpy(newEntry->name, name);
    newEntry->age = age;

    // Insert the new entry into the head of the list
    if (system->head == NULL) {
        system->head = newEntry;
    } else {
        system->head->next = newEntry;
    }
}

// Function to search for a database entry
Database* searchDatabaseEntry(IndexingSystem* system, char* name) {
    // Traverse the list of database entries
    Database* currentEntry = system->head;
    while (currentEntry) {
        // Check if the name of the current entry matches the search name
        if (strcmp(currentEntry->name, name) == 0) {
            // Return the current entry
            return currentEntry;
        }
        // Move to the next entry
        currentEntry = currentEntry->next;
    }

    // Return NULL if no entry is found
    return NULL;
}

int main() {
    // Create a new indexing system
    IndexingSystem* system = (IndexingSystem*)malloc(sizeof(IndexingSystem));
    system->head = NULL;

    // Insert some database entries
    insertDatabaseEntry(system, "John Doe", 25);
    insertDatabaseEntry(system, "Jane Doe", 30);
    insertDatabaseEntry(system, "Peter Pan", 12);

    // Search for a database entry
    Database* entry = searchDatabaseEntry(system, "Jane Doe");

    // Print the name and age of the entry
    if (entry) {
        printf("Name: %s\n", entry->name);
        printf("Age: %d\n", entry->age);
    } else {
        printf("No entry found\n");
    }

    return 0;
}