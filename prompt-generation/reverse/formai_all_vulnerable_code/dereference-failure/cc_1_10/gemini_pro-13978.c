//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the node structure
typedef struct node {
    char *key;
    char *value;
    struct node *next;
} node_t;

// Define the database structure
typedef struct database {
    node_t *head;
} database_t;

// Create a new database
database_t *create_database() {
    database_t *db = malloc(sizeof(database_t));
    db->head = NULL;
    return db;
}

// Insert a new key-value pair into the database
void insert(database_t *db, char *key, char *value) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->key = strdup(key);
    new_node->value = strdup(value);
    new_node->next = db->head;
    db->head = new_node;
}

// Get the value associated with a given key from the database
char *get(database_t *db, char *key) {
    node_t *current = db->head;
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return NULL;
}

// Delete a key-value pair from the database
void delete(database_t *db, char *key) {
    node_t *current = db->head;
    node_t *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            if (previous == NULL) {
                db->head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current->key);
            free(current->value);
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

// Print the contents of the database
void print_database(database_t *db) {
    node_t *current = db->head;
    while (current != NULL) {
        printf("%s: %s\n", current->key, current->value);
        current = current->next;
    }
}

// Free the memory allocated for the database
void free_database(database_t *db) {
    node_t *current = db->head;
    while (current != NULL) {
        node_t *next = current->next;
        free(current->key);
        free(current->value);
        free(current);
        current = next;
    }
    free(db);
}

// Main function
int main() {
    // Create a new database
    database_t *db = create_database();

    // Insert some key-value pairs into the database
    insert(db, "name", "John Doe");
    insert(db, "age", "30");
    insert(db, "occupation", "Software Engineer");

    // Get the value associated with a given key from the database
    char *value = get(db, "name");
    printf("Name: %s\n", value);

    // Delete a key-value pair from the database
    delete(db, "age");

    // Print the contents of the database
    print_database(db);

    // Free the memory allocated for the database
    free_database(db);

    return 0;
}