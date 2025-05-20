//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// A simple index entry structure
struct IndexEntry {
    char *key;
    int value;
};

// A simple database structure
struct Database {
    int num_entries;
    struct IndexEntry *entries;
};

// Create a new database
struct Database *create_database(void) {
    struct Database *db = malloc(sizeof(struct Database));
    if (db == NULL) {
        return NULL;
    }

    db->num_entries = 0;
    db->entries = NULL;

    return db;
}

// Destroy a database
void destroy_database(struct Database *db) {
    if (db == NULL) {
        return;
    }

    for (int i = 0; i < db->num_entries; i++) {
        free(db->entries[i].key);
    }

    free(db->entries);
    free(db);
}

// Index a key in the database
int index_key(struct Database *db, char *key, int value) {
    if (db == NULL || key == NULL) {
        return -1;
    }

    // Check if the key already exists
    for (int i = 0; i < db->num_entries; i++) {
        if (strcmp(db->entries[i].key, key) == 0) {
            return -1;
        }
    }

    // Create a new index entry
    struct IndexEntry *entry = malloc(sizeof(struct IndexEntry));
    if (entry == NULL) {
        return -1;
    }

    entry->key = strdup(key);
    entry->value = value;

    // Insert the new entry into the database
    db->entries = realloc(db->entries, (db->num_entries + 1) * sizeof(struct IndexEntry));
    if (db->entries == NULL) {
        free(entry);
        return -1;
    }

    db->entries[db->num_entries] = *entry;
    db->num_entries++;

    return 0;
}

// Get the value associated with a key in the database
int get_value(struct Database *db, char *key) {
    if (db == NULL || key == NULL) {
        return -1;
    }

    // Search for the key in the database
    for (int i = 0; i < db->num_entries; i++) {
        if (strcmp(db->entries[i].key, key) == 0) {
            return db->entries[i].value;
        }
    }

    return -1;
}

// Print the database
void print_database(struct Database *db) {
    if (db == NULL) {
        return;
    }

    for (int i = 0; i < db->num_entries; i++) {
        printf("%s: %d\n", db->entries[i].key, db->entries[i].value);
    }
}

// Test the database
int main(void) {
    // Create a new database
    struct Database *db = create_database();
    assert(db != NULL);

    // Index some keys in the database
    assert(index_key(db, "key1", 1) == 0);
    assert(index_key(db, "key2", 2) == 0);
    assert(index_key(db, "key3", 3) == 0);

    // Get the values associated with some keys in the database
    assert(get_value(db, "key1") == 1);
    assert(get_value(db, "key2") == 2);
    assert(get_value(db, "key3") == 3);

    // Print the database
    print_database(db);

    // Destroy the database
    destroy_database(db);

    return 0;
}