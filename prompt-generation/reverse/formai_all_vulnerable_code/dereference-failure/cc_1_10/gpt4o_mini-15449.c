//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a constant for the maximum length of names
#define MAX_NAME_LENGTH 100

// Node structure representing a database entry
typedef struct Node {
    int id;                           // Unique ID
    char name[MAX_NAME_LENGTH];       // Name associated with the ID
    struct Node* next;                // Pointer to next entry
} Node;

// Structure representing the index
typedef struct Index {
    Node* head;                       // Head of the linked list
} Index;

// Function to create a new node
Node* createNode(int id, const char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->id = id;
    strncpy(newNode->name, name, MAX_NAME_LENGTH);
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the index
Index* createIndex() {
    Index* index = (Index*)malloc(sizeof(Index));
    index->head = NULL;
    return index;
}

// Function to add an entry to the index
void addEntry(Index* index, int id, const char* name) {
    Node* newNode = createNode(id, name);
    if (index->head == NULL || index->head->id > id) {
        newNode->next = index->head;
        index->head = newNode;
        return;
    }

    Node* current = index->head;
    while (current->next != NULL && current->next->id < id) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Function to search for an entry by ID
Node* searchEntry(Index* index, int id) {
    Node* current = index->head;
    while (current != NULL) {
        if (current->id == id) {
            return current;
        }
        current = current->next;
    }
    return NULL; // Not found
}

// Function to print all entries in the index
void printIndex(Index* index) {
    Node* current = index->head;
    printf("Database Entries:\n");
    while (current != NULL) {
        printf("ID: %d, Name: %s\n", current->id, current->name);
        current = current->next;
    }
}

// Function to free all allocated memory in the index
void freeIndex(Index* index) {
    Node* current = index->head;
    Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    free(index);
}

// Main function demonstrating the database indexing system
int main() {
    Index* myIndex = createIndex();

    // Adding entries
    addEntry(myIndex, 3, "Alice");
    addEntry(myIndex, 1, "Bob");
    addEntry(myIndex, 2, "Charlie");
    addEntry(myIndex, 4, "Diana");
    addEntry(myIndex, 0, "Ethan");

    // Print all entries
    printIndex(myIndex);

    // Searching for specific entries
    int searchId;
    printf("\nEnter an ID to search: ");
    scanf("%d", &searchId);

    Node* foundEntry = searchEntry(myIndex, searchId);
    if (foundEntry) {
        printf("Found Entry: ID: %d, Name: %s\n", foundEntry->id, foundEntry->name);
    } else {
        printf("Entry with ID %d not found.\n", searchId);
    }

    // Cleaning up
    freeIndex(myIndex);
    return 0;
}