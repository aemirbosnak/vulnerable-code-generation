//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Definition of a node in the database
typedef struct node {
    int key;        // Key of the record
    char value[50]; // Value of the record
    struct node* next; // Pointer to the next node in the list
} node_t;

// Definition of a database
typedef struct db {
    node_t* head; // Head of the database
    int size;    // Size of the database
} db_t;

// Function to insert a record into the database
void insert(db_t* db, int key, char value[]) {
    // Create a new node with the given key and value
    node_t* new_node = (node_t*) malloc(sizeof(node_t));
    new_node->key = key;
    strcpy(new_node->value, value);
    new_node->next = db->head;
    db->head = new_node;
    db->size++;
}

// Function to search for a record in the database
node_t* search(db_t* db, int key) {
    // Loop through the database until we find the key or reach the end
    node_t* current = db->head;
    while (current != NULL && current->key != key) {
        current = current->next;
    }
    return current;
}

// Function to delete a record from the database
void delete(db_t* db, int key) {
    // Find the record with the given key and delete it
    node_t* current = search(db, key);
    if (current != NULL) {
        // If the record is found, delete it and update the links
        current->next = current->next->next;
        db->size--;
    }
}

// Function to traverse the database
void traverse(db_t* db) {
    // Loop through the database and print each record
    node_t* current = db->head;
    while (current != NULL) {
        printf("%d: %s\n", current->key, current->value);
        current = current->next;
    }
}

int main() {
    // Create a new database
    db_t* db = (db_t*) malloc(sizeof(db_t));
    db->head = NULL;
    db->size = 0;

    // Insert some records into the database
    insert(db, 1, "apple");
    insert(db, 2, "banana");
    insert(db, 3, "cherry");

    // Search for a record in the database
    node_t* found = search(db, 2);
    if (found != NULL) {
        printf("Found record with key 2: %s\n", found->value);
    } else {
        printf("Record with key 2 not found\n");
    }

    // Delete a record from the database
    delete(db, 3);

    // Traverse the database
    traverse(db);

    // Free the memory allocated for the database
    free(db);
    return 0;
}