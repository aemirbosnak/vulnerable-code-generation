//FormAI DATASET v1.0 Category: Database Indexing System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length for key and value string
#define MAX_LENGTH 100

// Define the struct for the node
struct Node {
    char key[MAX_LENGTH];
    char value[MAX_LENGTH];
    struct Node* next;
};

// Define the struct for the index
struct Index {
    int size;
    struct Node** table;
};

// Initialize the index with a given size
struct Index* initIndex(int size) {
    struct Index* index = (struct Index*) malloc(sizeof(struct Index));
    index->size = size;
    index->table = (struct Node**) malloc(sizeof(struct Node*) * size);

    // Initialize all values in the table to NULL
    int i;
    for (i = 0; i < size; i++) {
        index->table[i] = NULL;
    }

    return index;
}

// Hash function to calculate the index for a given key
int hash(struct Index* index, char* key) {
    int sum = 0;
    int i;
    for (i = 0; i < strlen(key); i++) {
        sum += key[i];
    }

    return sum % index->size;
}

// Insert a key-value pair into the index
void insert(struct Index* index, char* key, char* value) {
    int idx = hash(index, key);
    struct Node* node = index->table[idx];

    // If the table is empty, create a new node
    if (node == NULL) {
        node = (struct Node*) malloc(sizeof(struct Node));
        strcpy(node->key, key);
        strcpy(node->value, value);
        node->next = NULL;
        index->table[idx] = node;
        return;
    }

    // Traverse the linked list and check for duplicates
    while (node) {
        if (strcmp(node->key, key) == 0) {
            strcpy(node->value, value);
            return;
        }

        if (node->next == NULL) break;
        node = node->next;
    }

    // If no duplicates, insert a new node at the end of the list
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    strcpy(newNode->key, key);
    strcpy(newNode->value, value);
    newNode->next = NULL;
    node->next = newNode;
}

// Retrieve a value from the index
char* retrieve(struct Index* index, char* key) {
    int idx = hash(index, key);
    struct Node* node = index->table[idx];

    // Traverse the linked list and check for a match
    while (node) {
        if (strcmp(node->key, key) == 0) {
            return node->value;
        }

        node = node->next;
    }

    return NULL;
}

// Print the index
void printIndex(struct Index* index) {
    printf("Index:\n");
    int i;
    for (i = 0; i < index->size; i++) {
        struct Node* node = index->table[i];
        printf("[%d]: ", i);
        while (node) {
            printf("(%s, %s) ", node->key, node->value);
            node = node->next;
        }
        printf("\n");
    }
}

// Main function to test the index
int main() {
    struct Index* index = initIndex(10);
    insert(index, "key1", "value1");
    insert(index, "key2", "value2");
    insert(index, "key3", "value3");
    insert(index, "key4", "value4");
    printIndex(index);
    char* value = retrieve(index, "key3");
    printf("Value: %s\n", value);
    return 0;
}