//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW 1000
#define MAX_COL 1000

// Node structure for linked list implementation of database
typedef struct node {
    char *key;
    char *value;
    struct node *next;
} node_t;

// Linked list implementation of database
node_t *db = NULL;

// Function to insert a key-value pair into the database
void insert(char *key, char *value) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->key = strdup(key);
    new_node->value = strdup(value);
    new_node->next = db;
    db = new_node;
}

// Function to search for a key in the database and return its value
char *search(char *key) {
    node_t *curr_node = db;
    while (curr_node!= NULL) {
        if (strcmp(curr_node->key, key) == 0) {
            return curr_node->value;
        }
        curr_node = curr_node->next;
    }
    return NULL;
}

// Function to delete a key-value pair from the database
void delete(char *key) {
    node_t *prev_node = NULL;
    node_t *curr_node = db;
    while (curr_node!= NULL) {
        if (strcmp(curr_node->key, key) == 0) {
            if (prev_node == NULL) {
                db = curr_node->next;
            } else {
                prev_node->next = curr_node->next;
            }
            free(curr_node->key);
            free(curr_node->value);
            free(curr_node);
            return;
        }
        prev_node = curr_node;
        curr_node = curr_node->next;
    }
}

// Function to print the entire database
void print_db() {
    node_t *curr_node = db;
    while (curr_node!= NULL) {
        printf("%s: %s\n", curr_node->key, curr_node->value);
        curr_node = curr_node->next;
    }
}

int main() {
    // Example usage
    insert("name", "John Doe");
    insert("age", "30");
    insert("city", "New York");

    printf("Database:\n");
    print_db();

    char *value = search("age");
    if (value!= NULL) {
        printf("Age: %s\n", value);
    } else {
        printf("Age not found.\n");
    }

    delete("age");

    printf("\nDatabase after deleting 'age':\n");
    print_db();

    return 0;
}