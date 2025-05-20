//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Database structure
typedef struct {
    char *name;
    char *value;
} Entry;

// Database implementation
typedef struct {
    Entry *entries;
    int size;
    int capacity;
} Database;

// Create a new database
Database *database_new() {
    Database *db = malloc(sizeof(Database));
    db->entries = NULL;
    db->size = 0;
    db->capacity = 0;
    return db;
}

// Destroy a database
void database_destroy(Database *db) {
    for (int i = 0; i < db->size; i++) {
        free(db->entries[i].name);
        free(db->entries[i].value);
    }
    free(db->entries);
    free(db);
}

// Add an entry to the database
void database_add(Database *db, char *name, char *value) {
    // Reallocate the entries array if necessary
    if (db->size == db->capacity) {
        db->capacity = db->capacity == 0 ? 1 : db->capacity * 2;
        db->entries = realloc(db->entries, db->capacity * sizeof(Entry));
    }

    // Add the new entry
    Entry *entry = &db->entries[db->size++];
    entry->name = strdup(name);
    entry->value = strdup(value);
}

// Get an entry from the database
char *database_get(Database *db, char *name) {
    for (int i = 0; i < db->size; i++) {
        Entry *entry = &db->entries[i];
        if (strcmp(entry->name, name) == 0) {
            return entry->value;
        }
    }
    return NULL;
}

// Print the database
void database_print(Database *db) {
    for (int i = 0; i < db->size; i++) {
        Entry *entry = &db->entries[i];
        printf("%s: %s\n", entry->name, entry->value);
    }
}

// Main function
int main() {
    // Create a new database
    Database *db = database_new();

    // Add some entries to the database
    database_add(db, "name", "John Doe");
    database_add(db, "age", "30");
    database_add(db, "occupation", "Software Engineer");

    // Print the database
    database_print(db);

    // Get an entry from the database
    char *name = database_get(db, "name");
    printf("Name: %s\n", name);

    // Destroy the database
    database_destroy(db);

    return 0;
}