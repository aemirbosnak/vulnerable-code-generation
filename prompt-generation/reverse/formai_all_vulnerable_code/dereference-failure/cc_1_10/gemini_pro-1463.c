//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Database structure
typedef struct {
    char *key;
    char *value;
} DatabaseEntry;

// Index structure
typedef struct {
    char *key;
    int offset;
} IndexEntry;

// Create a new database
DatabaseEntry *create_database() {
    return malloc(sizeof(DatabaseEntry) * 100);
}

// Add a new entry to the database
void add_entry(DatabaseEntry *database, char *key, char *value) {
    int i;
    for (i = 0; i < 100; i++) {
        if (database[i].key == NULL) {
            database[i].key = strdup(key);
            database[i].value = strdup(value);
            break;
        }
    }
}

// Get the value associated with a key
char *get_value(DatabaseEntry *database, char *key) {
    int i;
    for (i = 0; i < 100; i++) {
        if (strcmp(database[i].key, key) == 0) {
            return database[i].value;
        }
    }
    return NULL;
}

// Create an index for the database
IndexEntry *create_index(DatabaseEntry *database) {
    int i;
    IndexEntry *index = malloc(sizeof(IndexEntry) * 100);
    for (i = 0; i < 100; i++) {
        index[i].key = database[i].key;
        index[i].offset = i;
    }
    return index;
}

// Search the index for a key
int search_index(IndexEntry *index, char *key) {
    int i;
    for (i = 0; i < 100; i++) {
        if (strcmp(index[i].key, key) == 0) {
            return index[i].offset;
        }
    }
    return -1;
}

// Get the value associated with a key using the index
char *get_value_indexed(DatabaseEntry *database, IndexEntry *index, char *key) {
    int offset = search_index(index, key);
    if (offset == -1) {
        return NULL;
    }
    return database[offset].value;
}

// Example usage
int main() {
    // Create a new database
    DatabaseEntry *database = create_database();

    // Add some entries to the database
    add_entry(database, "Alice", "123 Main Street");
    add_entry(database, "Bob", "456 Elm Street");
    add_entry(database, "Charlie", "789 Oak Street");

    // Create an index for the database
    IndexEntry *index = create_index(database);

    // Search for a value using the index
    char *value = get_value_indexed(database, index, "Bob");

    // Print the value
    printf("Bob's address: %s\n", value);

    return 0;
}