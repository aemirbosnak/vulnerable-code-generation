//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_SIZE 100

// Node structure for the index
typedef struct {
    char *key;
    int value;
    struct node *next;
} Node;

// Function to create a new node
Node *createNode(char *key, int value) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->key = strdup(key);
    node->value = value;
    node->next = NULL;
    return node;
}

// Function to add a new entry to the index
void addEntry(Node **index, char *key, int value) {
    Node *node = *index;
    while (node!= NULL) {
        if (strcmp(node->key, key) == 0) {
            // Entry already exists, update the value
            node->value = value;
            return;
        }
        node = node->next;
    }
    // Entry does not exist, add a new node
    node = createNode(key, value);
    node->next = *index;
    *index = node;
}

// Function to search for an entry in the index
int searchEntry(Node *index, char *key) {
    Node *node = index;
    while (node!= NULL) {
        if (strcmp(node->key, key) == 0) {
            // Entry found, return the value
            return node->value;
        }
        node = node->next;
    }
    // Entry not found, return -1
    return -1;
}

// Function to print the index
void printIndex(Node *index) {
    Node *node = index;
    while (node!= NULL) {
        printf("%s -> %d\n", node->key, node->value);
        node = node->next;
    }
}

int main() {
    Node *index = NULL;

    // Add some entries to the index
    addEntry(&index, "apple", 1);
    addEntry(&index, "banana", 2);
    addEntry(&index, "cherry", 3);

    // Print the index
    printf("Index:\n");
    printIndex(index);

    // Search for an entry in the index
    int value = searchEntry(index, "banana");
    if (value!= -1) {
        printf("Value for banana: %d\n", value);
    } else {
        printf("Entry not found\n");
    }

    return 0;
}