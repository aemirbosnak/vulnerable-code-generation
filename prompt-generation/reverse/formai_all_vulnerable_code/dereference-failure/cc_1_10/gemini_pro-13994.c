//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Index structure
typedef struct index {
    char *key;
    int value;
    struct index *next;
} index_t;

// Database structure
typedef struct database {
    int num_indices;
    index_t **indices;
} database_t;

// Create a new database
database_t *create_database() {
    database_t *db = malloc(sizeof(database_t));
    db->num_indices = 0;
    db->indices = NULL;
    return db;
}

// Add an index to the database
void add_index(database_t *db, char *key, int value) {
    // Create a new index
    index_t *index = malloc(sizeof(index_t));
    index->key = strdup(key);
    index->value = value;
    index->next = NULL;

    // Insert the index into the database
    if (db->num_indices == 0) {
        db->indices = malloc(sizeof(index_t *));
    } else {
        db->indices = realloc(db->indices, sizeof(index_t *) * (db->num_indices + 1));
    }
    db->indices[db->num_indices++] = index;
}

// Get the value of an index
int get_value(database_t *db, char *key) {
    for (int i = 0; i < db->num_indices; i++) {
        if (strcmp(db->indices[i]->key, key) == 0) {
            return db->indices[i]->value;
        }
    }
    return -1;
}

// Free the database
void free_database(database_t *db) {
    for (int i = 0; i < db->num_indices; i++) {
        free(db->indices[i]->key);
        free(db->indices[i]);
    }
    free(db->indices);
    free(db);
}

// Example usage
int main() {
    // Create a new database
    database_t *db = create_database();

    // Add some indices to the database
    add_index(db, "name", 1);
    add_index(db, "age", 2);
    add_index(db, "city", 3);

    // Get the value of an index
    int name = get_value(db, "name");
    printf("Name: %d\n", name);

    // Free the database
    free_database(db);

    return 0;
}