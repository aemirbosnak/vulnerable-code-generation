//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Index entry structure
typedef struct index_entry {
    char *key;
    long offset;
} index_entry;

// Database structure
typedef struct database {
    // List of index entries
    index_entry *entries;

    // Number of index entries
    int num_entries;

    // Size of each index entry
    int entry_size;
} database;

// Create a new database
database *create_database() {
    database *db = malloc(sizeof(database));
    if (db == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for database.\n");
        return NULL;
    }

    // Initialize the database
    db->entries = NULL;
    db->num_entries = 0;
    db->entry_size = sizeof(index_entry);

    return db;
}

// Destroy a database
void destroy_database(database *db) {
    if (db == NULL) {
        return;
    }

    // Free the index entries
    for (int i = 0; i < db->num_entries; i++) {
        free(db->entries[i].key);
    }
    free(db->entries);

    // Free the database
    free(db);
}

// Add a key-offset pair to the database
int add_to_database(database *db, char *key, long offset) {
    if (db == NULL) {
        fprintf(stderr, "Error: Database is NULL.\n");
        return -1;
    }

    // Check if the key already exists
    for (int i = 0; i < db->num_entries; i++) {
        if (strcmp(db->entries[i].key, key) == 0) {
            fprintf(stderr, "Error: Key already exists in database.\n");
            return -1;
        }
    }

    // Create a new index entry
    index_entry entry;
    entry.key = strdup(key);
    entry.offset = offset;

    // Add the entry to the database
    db->entries = realloc(db->entries, (db->num_entries + 1) * db->entry_size);
    db->entries[db->num_entries] = entry;
    db->num_entries++;

    return 0;
}

// Get the offset for a given key from the database
long get_from_database(database *db, char *key) {
    if (db == NULL) {
        fprintf(stderr, "Error: Database is NULL.\n");
        return -1;
    }

    // Iterate through the index entries to find the key
    for (int i = 0; i < db->num_entries; i++) {
        if (strcmp(db->entries[i].key, key) == 0) {
            return db->entries[i].offset;
        }
    }

    // Key not found
    return -1;
}

// Print the contents of the database
void print_database(database *db) {
    if (db == NULL) {
        fprintf(stderr, "Error: Database is NULL.\n");
        return;
    }

    // Iterate through the index entries and print the key-offset pairs
    for (int i = 0; i < db->num_entries; i++) {
        printf("%s: %ld\n", db->entries[i].key, db->entries[i].offset);
    }
}

// Main function
int main() {
    // Create a new database
    database *db = create_database();

    // Add some key-offset pairs to the database
    add_to_database(db, "key1", 100);
    add_to_database(db, "key2", 200);
    add_to_database(db, "key3", 300);

    // Print the contents of the database
    print_database(db);

    // Get the offset for a given key
    long offset = get_from_database(db, "key2");

    // Print the offset
    printf("Offset for key2: %ld\n", offset);

    // Destroy the database
    destroy_database(db);

    return 0;
}