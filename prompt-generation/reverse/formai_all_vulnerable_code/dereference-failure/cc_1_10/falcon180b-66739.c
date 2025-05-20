//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 100
#define MAX_VALUE_LENGTH 1000

// Node structure for the database
typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
    struct node* next;
} Node;

// Linked list structure for the database
typedef struct {
    Node* head;
} LinkedList;

// Function to create a new node
Node* createNode(char* key, char* value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->key, key);
    strcpy(newNode->value, value);
    newNode->next = NULL;
    return newNode;
}

// Function to add a new key-value pair to the database
void addPair(LinkedList* list, char* key, char* value) {
    Node* newNode = createNode(key, value);
    Node* current = list->head;
    while (current!= NULL && strcmp(current->key, key) < 1) {
        current = current->next;
    }
    newNode->next = current;
    list->head = newNode;
}

// Function to search for a key in the database and return its value
char* searchKey(LinkedList* list, char* key) {
    Node* current = list->head;
    while (current!= NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return NULL;
}

// Main function to test the database indexing system
int main() {
    LinkedList database;
    database.head = NULL;

    // Add key-value pairs to the database
    addPair(&database, "John", "Doe");
    addPair(&database, "Jane", "Doe");
    addPair(&database, "Bob", "Smith");

    // Search for keys in the database
    char* value1 = searchKey(&database, "John");
    char* value2 = searchKey(&database, "Jane");
    char* value3 = searchKey(&database, "Bob");

    // Print the results
    if (value1!= NULL) {
        printf("John: %s\n", value1);
    } else {
        printf("John not found.\n");
    }

    if (value2!= NULL) {
        printf("Jane: %s\n", value2);
    } else {
        printf("Jane not found.\n");
    }

    if (value3!= NULL) {
        printf("Bob: %s\n", value3);
    } else {
        printf("Bob not found.\n");
    }

    return 0;
}