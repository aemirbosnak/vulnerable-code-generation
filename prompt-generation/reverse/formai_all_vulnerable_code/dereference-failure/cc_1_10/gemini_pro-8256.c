//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// We're not actually going to store any data here, this is just a placeholder
typedef struct _Node {
    int key;
    char* value;
    struct _Node* next;
} Node;

// Our "database" is simply a linked list of nodes
Node* database = NULL;

// This function adds a new record to the database
void add_record(int key, char* value) {
    // Create a new node
    Node* node = malloc(sizeof(Node));
    node->key = key;
    node->value = strdup(value);
    node->next = NULL;

    // Add the new node to the end of the linked list
    if (database == NULL) {
        database = node;
    } else {
        Node* current = database;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
    }
}

// This function searches for a record in the database based on its key
char* search_record(int key) {
    // Iterate through the linked list and check each node's key
    Node* current = database;
    while (current != NULL) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }

    // If we reach the end of the linked list without finding the key, return NULL
    return NULL;
}

// This function deletes a record from the database based on its key
void delete_record(int key) {
    // If the database is empty, there's nothing to delete
    if (database == NULL) {
        return;
    }

    // If the first node's key matches the key we're looking for, delete it
    if (database->key == key) {
        database = database->next;
        return;
    }

    // Otherwise, iterate through the linked list and find the node before the one we want to delete
    Node* current = database;
    while (current->next != NULL && current->next->key != key) {
        current = current->next;
    }

    // If we reach the end of the linked list without finding the key, the record doesn't exist
    if (current->next == NULL) {
        return;
    }

    // Delete the node after the one we found
    Node* node_to_delete = current->next;
    current->next = node_to_delete->next;
    free(node_to_delete);
}

// This function prints the contents of the database
void print_database() {
    Node* current = database;
    while (current != NULL) {
        printf("%d: %s\n", current->key, current->value);
        current = current->next;
    }
}

int main() {
    // Add some records to the database
    add_record(1, "John Doe");
    add_record(2, "Jane Doe");
    add_record(3, "John Smith");

    // Search for a record based on its key
    char* value = search_record(2);
    if (value != NULL) {
        printf("Found record: %s\n", value);
    } else {
        printf("Record not found\n");
    }

    // Delete a record based on its key
    delete_record(2);

    // Print the contents of the database
    print_database();

    return 0;
}