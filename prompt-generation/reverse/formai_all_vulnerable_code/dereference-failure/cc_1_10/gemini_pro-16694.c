//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct index_entry {
    char *key;
    int value;
} index_entry;

typedef struct database {
    char *name;
    int num_entries;
    index_entry *entries;
} database;

// Create a new database
database *create_database(char *name) {
    database *db = (database *)malloc(sizeof(database));
    db->name = strdup(name);
    db->num_entries = 0;
    db->entries = NULL;
    return db;
}

// Add a new entry to the database
void add_entry(database *db, char *key, int value) {
    db->entries = (index_entry *)realloc(db->entries, (db->num_entries + 1) * sizeof(index_entry));
    index_entry *entry = &db->entries[db->num_entries];
    entry->key = strdup(key);
    entry->value = value;
    db->num_entries++;
}

// Get the value of an entry by key
int get_value(database *db, char *key) {
    for (int i = 0; i < db->num_entries; i++) {
        if (strcmp(db->entries[i].key, key) == 0) {
            return db->entries[i].value;
        }
    }
    return -1;
}

// Print the database
void print_database(database *db) {
    printf("Database: %s\n", db->name);
    for (int i = 0; i < db->num_entries; i++) {
        printf("%s: %d\n", db->entries[i].key, db->entries[i].value);
    }
}

// Free the database
void free_database(database *db) {
    for (int i = 0; i < db->num_entries; i++) {
        free(db->entries[i].key);
    }
    free(db->entries);
    free(db->name);
    free(db);
}

int main() {
    // Create a new database
    database *db = create_database("my_database");

    // Add some entries to the database
    add_entry(db, "key1", 1);
    add_entry(db, "key2", 2);
    add_entry(db, "key3", 3);

    // Print the database
    print_database(db);

    // Get the value of an entry by key
    int value = get_value(db, "key2");
    printf("The value of key2 is %d\n", value);

    // Free the database
    free_database(db);

    return 0;
}