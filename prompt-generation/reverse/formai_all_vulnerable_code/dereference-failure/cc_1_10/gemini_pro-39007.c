//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: Dennis Ritchie
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// A simple database structure
typedef struct {
    char *key;
    char *value;
} entry;

// A simple database
typedef struct {
    entry *entries;
    int num_entries;
    int size;
} database;

// Create a new database
database *new_database() {
    database *db = malloc(sizeof(database));
    db->entries = NULL;
    db->num_entries = 0;
    db->size = 0;
    return db;
}

// Free a database
void free_database(database *db) {
    for (int i = 0; i < db->num_entries; i++) {
        free(db->entries[i].key);
        free(db->entries[i].value);
    }
    free(db->entries);
    free(db);
}

// Add an entry to a database
void add_entry(database *db, char *key, char *value) {
    // Resize the database if necessary
    if (db->num_entries == db->size) {
        db->size *= 2;
        db->entries = realloc(db->entries, db->size * sizeof(entry));
    }

    // Add the new entry
    db->entries[db->num_entries].key = strdup(key);
    db->entries[db->num_entries].value = strdup(value);
    db->num_entries++;
}

// Get an entry from a database
char *get_entry(database *db, char *key) {
    for (int i = 0; i < db->num_entries; i++) {
        if (strcmp(db->entries[i].key, key) == 0) {
            return db->entries[i].value;
        }
    }
    return NULL;
}

// Delete an entry from a database
void delete_entry(database *db, char *key) {
    for (int i = 0; i < db->num_entries; i++) {
        if (strcmp(db->entries[i].key, key) == 0) {
            // Move the last entry to the current position
            db->entries[i] = db->entries[db->num_entries - 1];
            db->num_entries--;
            break;
        }
    }
}

// Print a database
void print_database(database *db) {
    for (int i = 0; i < db->num_entries; i++) {
        printf("%s: %s\n", db->entries[i].key, db->entries[i].value);
    }
}

// Main function
int main() {
    // Create a new database
    database *db = new_database();

    // Add some entries to the database
    add_entry(db, "name", "John Doe");
    add_entry(db, "age", "30");
    add_entry(db, "city", "New York");

    // Get an entry from the database
    char *name = get_entry(db, "name");

    // Print the entry
    printf("Name: %s\n", name);

    // Delete an entry from the database
    delete_entry(db, "age");

    // Print the database
    print_database(db);

    // Free the database
    free_database(db);

    return 0;
}