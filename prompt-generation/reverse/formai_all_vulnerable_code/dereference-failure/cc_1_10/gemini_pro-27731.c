//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Grateful Index Structure
typedef struct _grateful_index {
    char *key;
    int value;
    struct _grateful_index *next;
} grateful_index;

// Grateful Database Structure
typedef struct _grateful_database {
    grateful_index *head;
    int size;
} grateful_database;

// Create a new grateful index
grateful_index *grateful_index_new(char *key, int value) {
    grateful_index *index = malloc(sizeof(grateful_index));
    index->key = strdup(key);
    index->value = value;
    index->next = NULL;
    return index;
}

// Create a new grateful database
grateful_database *grateful_database_new() {
    grateful_database *db = malloc(sizeof(grateful_database));
    db->head = NULL;
    db->size = 0;
    return db;
}

// Insert a new index into the grateful database
void grateful_database_insert(grateful_database *db, char *key, int value) {
    grateful_index *index = grateful_index_new(key, value);
    index->next = db->head;
    db->head = index;
    db->size++;
}

// Get the value of a key from the grateful database
int grateful_database_get(grateful_database *db, char *key) {
    grateful_index *index = db->head;
    while (index != NULL) {
        if (strcmp(index->key, key) == 0) {
            return index->value;
        }
        index = index->next;
    }
    return -1;
}

// Print the grateful database
void grateful_database_print(grateful_database *db) {
    grateful_index *index = db->head;
    while (index != NULL) {
        printf("%s: %d\n", index->key, index->value);
        index = index->next;
    }
}

// Free the grateful database
void grateful_database_free(grateful_database *db) {
    grateful_index *index = db->head;
    while (index != NULL) {
        grateful_index *next = index->next;
        free(index->key);
        free(index);
        index = next;
    }
    free(db);
}

int main() {
    // Create a new grateful database
    grateful_database *db = grateful_database_new();

    // Insert some indices into the database
    grateful_database_insert(db, "John", 25);
    grateful_database_insert(db, "Mary", 30);
    grateful_database_insert(db, "Bob", 35);

    // Get the value of a key from the database
    int age = grateful_database_get(db, "John");
    printf("John's age is %d\n", age);

    // Print the database
    grateful_database_print(db);

    // Free the database
    grateful_database_free(db);

    return 0;
}