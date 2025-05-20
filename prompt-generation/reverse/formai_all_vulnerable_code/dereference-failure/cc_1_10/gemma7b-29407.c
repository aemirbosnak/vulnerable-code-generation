//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Define the database structure
typedef struct Database {
    char name[20];
    int id;
    struct Database* next;
} Database;

// Function to insert a new node into the database
void insertNode(Database* head, char* name, int id) {
    Database* newNode = (Database*)malloc(sizeof(Database));
    strcpy(newNode->name, name);
    newNode->id = id;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }
    head = newNode;
}

// Function to search for a node in the database
Database* searchNode(Database* head, int id) {
    while (head) {
        if (head->id == id) {
            return head;
        } else {
            head = head->next;
        }
    }
    return NULL;
}

// Function to delete a node from the database
void deleteNode(Database* head, int id) {
    Database* prev = NULL;
    Database* current = head;

    while (current) {
        if (current->id == id) {
            if (prev) {
                prev->next = current->next;
            } else {
                head = current->next;
            }
            free(current);
            return;
        } else {
            prev = current;
            current = current->next;
        }
    }
    return;
}

int main() {
    Database* head = NULL;

    // Insert some nodes into the database
    insertNode(head, "John Doe", 1);
    insertNode(head, "Jane Doe", 2);
    insertNode(head, "Peter Pan", 3);

    // Search for a node in the database
    Database* foundNode = searchNode(head, 2);

    // Print the found node's information
    if (foundNode) {
        printf("Name: %s\n", foundNode->name);
        printf("ID: %d\n", foundNode->id);
    } else {
        printf("Node not found.\n");
    }

    // Delete a node from the database
    deleteNode(head, 1);

    // Search for the deleted node
    foundNode = searchNode(head, 1);

    // Print the found node's information
    if (foundNode) {
        printf("Name: %s\n", foundNode->name);
        printf("ID: %d\n", foundNode->id);
    } else {
        printf("Node not found.\n");
    }

    return 0;
}