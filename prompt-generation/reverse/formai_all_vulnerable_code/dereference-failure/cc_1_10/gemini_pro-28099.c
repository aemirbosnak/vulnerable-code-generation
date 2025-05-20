//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: active
// Let's simulate a simple database with linked lists!

#include <stdio.h>
#include <stdlib.h>

// Define the basic node structure
typedef struct node {
    int id;
    char *name;
    int age;
    struct node *next;
} node_t;

// Initialize the database (head of the linked list)
node_t *db = NULL;

// Create a new node for the database
node_t *create_node(int id, char *name, int age) {
    // Allocate memory for the new node
    node_t *new_node = malloc(sizeof(node_t));

    // Set the values of the new node
    new_node->id = id;
    new_node->name = name;
    new_node->age = age;
    new_node->next = NULL;

    // Return the new node
    return new_node;
}

// Insert a new node into the database
void insert_node(int id, char *name, int age) {
    // Create a new node
    node_t *new_node = create_node(id, name, age);

    // If the database is empty, set the new node as the head
    if (db == NULL) {
        db = new_node;
    } else {
        // Otherwise, traverse the list until we reach the end
        node_t *curr = db;
        while (curr->next != NULL) {
            curr = curr->next;
        }

        // Insert the new node at the end of the list
        curr->next = new_node;
    }
}

// Search for a node in the database by ID
node_t *search_node_by_id(int id) {
    // Traverse the list until we find the node with the matching ID
    node_t *curr = db;
    while (curr != NULL) {
        if (curr->id == id) {
            return curr;
        }
        curr = curr->next;
    }

    // If we didn't find the node, return NULL
    return NULL;
}

// Delete a node from the database by ID
void delete_node_by_id(int id) {
    // If the database is empty, do nothing
    if (db == NULL) {
        return;
    }

    // If the node to be deleted is the head of the list
    if (db->id == id) {
        // Update the head of the list
        db = db->next;
        return;
    }

    // Otherwise, traverse the list until we find the node to be deleted
    node_t *curr = db;
    while (curr->next != NULL) {
        if (curr->next->id == id) {
            // Remove the node from the list
            curr->next = curr->next->next;
            return;
        }
        curr = curr->next;
    }
}

// Print the entire database
void print_database() {
    // Traverse the list and print the data of each node
    node_t *curr = db;
    while (curr != NULL) {
        printf("ID: %d, Name: %s, Age: %d\n", curr->id, curr->name, curr->age);
        curr = curr->next;
    }
}

// Main function
int main() {
    // Insert some sample data into the database
    insert_node(1, "John Doe", 25);
    insert_node(2, "Jane Doe", 23);
    insert_node(3, "Peter Parker", 22);

    // Print the database
    printf("Initial database:\n");
    print_database();

    // Search for a node in the database
    node_t *found_node = search_node_by_id(2);
    if (found_node != NULL) {
        printf("\nFound node with ID 2:\n");
        printf("ID: %d, Name: %s, Age: %d\n", found_node->id, found_node->name, found_node->age);
    } else {
        printf("\nNode with ID 2 not found.\n");
    }

    // Delete a node from the database
    delete_node_by_id(3);

    // Print the database again
    printf("\nDatabase after deleting node with ID 3:\n");
    print_database();

    return 0;
}