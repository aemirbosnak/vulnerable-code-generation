//FormAI DATASET v1.0 Category: Database simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a single node in our database
typedef struct node {
    int id;
    char name[50];
    char email[100];
    struct node* next;
} Node;

// Initialize the head node of our database
Node* head = NULL;

// Function to insert a new record into our database
void insert(int id, char* name, char* email) {
    // Allocate memory for a new node
    Node* new_node = (Node*) malloc(sizeof(Node));

    // Set the properties of the new node
    new_node->id = id;
    strcpy(new_node->name, name);
    strcpy(new_node->email, email);
    new_node->next = NULL;

    // If the head node is null, set our new node as the head node
    if (head == NULL) {
        head = new_node;
    } else {
        // If there are other nodes in the database, append our new node to the end of the list
        Node* current_node = head;

        while (current_node->next != NULL) {
            current_node = current_node->next;
        }

        current_node->next = new_node;
    }
}

// Function to search for a record in the database by ID
Node* search(int id) {
    Node* current_node = head;

    while (current_node != NULL && current_node->id != id) {
        current_node = current_node->next;
    }

    return current_node;
}

// Function to delete a record from the database by ID
void delete(int id) {
    Node* current_node = head;
    Node* prev_node = NULL;

    while (current_node->id != id && current_node->next != NULL) {
        prev_node = current_node;
        current_node = current_node->next;
    }

    if (current_node->id == id) {
        if (prev_node == NULL) {
            head = current_node->next;
        } else {
            prev_node->next = current_node->next;
        }
    }

    free(current_node);
}

// Function to print all records in the database
void print_database() {
    Node* current_node = head;

    while (current_node != NULL) {
        printf("ID: %d\nName: %s\nEmail: %s\n\n", current_node->id, current_node->name, current_node->email);
        current_node = current_node->next;
    }
}

// Entry point of the program
int main() {
    // Insert records into the database
    insert(1, "John", "john@example.com");
    insert(2, "Jane", "jane@example.com");
    insert(3, "Bob", "bob@example.com");
    insert(4, "Alice", "alice@example.com");
    insert(5, "Charlie", "charlie@example.com");

    // Print the database
    printf("Initial database:\n");
    print_database();

    // Search for a record
    Node* search_result = search(3);

    if (search_result != NULL) {
        printf("Record with ID 3:\n");
        printf("Name: %s\nEmail: %s\n\n", search_result->name, search_result->email);
    } else {
        printf("Record not found.\n");
    }

    // Delete a record
    delete(4);

    // Print the database again
    printf("Final database:\n");
    print_database();

    return 0;
}