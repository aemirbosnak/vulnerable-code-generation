//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>


// Index structure
typedef struct index_node {
    int key;
    int value;
    struct index_node* next;
} index_node;

// Database structure
typedef struct database {
    int num_records;
    index_node* index;
} database;

// Create a new database
database* create_database() {
    database* db = (database*)malloc(sizeof(database));
    db->num_records = 0;
    db->index = NULL;
    return db;
}

// Insert a new record into the database
void insert_record(database* db, int key, int value) {
    // Create a new index node
    index_node* new_node = (index_node*)malloc(sizeof(index_node));
    new_node->key = key;
    new_node->value = value;

    // Insert the new node into the index
    new_node->next = db->index;
    db->index = new_node;

    // Increment the number of records in the database
    db->num_records++;
}

// Search for a record in the database using the index
int search_record(database* db, int key) {
    // Traverse the index to find the record
    index_node* node = db->index;
    while (node != NULL) {
        if (node->key == key) {
            return node->value;
        }
        node = node->next;
    }

    // Return -1 if the record was not found
    return -1;
}

// Print the database
void print_database(database* db) {
    // Traverse the index to print the records
    index_node* node = db->index;
    while (node != NULL) {
        printf("%d: %d\n", node->key, node->value);
        node = node->next;
    }
}

// Free the memory allocated to the database
void free_database(database* db) {
    // Free the index nodes
    index_node* node = db->index;
    while (node != NULL) {
        index_node* next = node->next;
        free(node);
        node = next;
    }

    // Free the database structure
    free(db);
}

// Test the database indexing system
int main() {
    // Create a new database
    database* db = create_database();

    // Insert some records into the database
    insert_record(db, 1, 10);
    insert_record(db, 2, 20);
    insert_record(db, 3, 30);

    // Search for a record in the database
    int value = search_record(db, 2);
    if (value != -1) {
        printf("Found record: %d\n", value);
    } else {
        printf("Record not found\n");
    }

    // Print the database
    print_database(db);

    // Free the database
    free_database(db);

    return 0;
}