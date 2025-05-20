//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 10
#define MAX_VAL_LENGTH 50

// Node structure for the B-tree
typedef struct node {
    int key[MAX_KEY_LENGTH];
    int val[MAX_VAL_LENGTH];
    struct node *left, *right;
} Node;

// Function to create a new node
Node* createNode() {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key[0] = '\0';
    newNode->val[0] = '\0';
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to create a new B-tree
Node* createBtree() {
    Node* root = createNode();
    return root;
}

// Function to insert a key-value pair into the B-tree
void insert(Node* node, char* key, char* value) {
    if (node == NULL) {
        return;
    }

    // Split the key and value into their respective parts
    char* parts[MAX_KEY_LENGTH + 1];
    char* keyParts[MAX_KEY_LENGTH];
    char* valueParts[MAX_VAL_LENGTH];

    int i = 0;
    for (i = 0; i < MAX_KEY_LENGTH; i++) {
        parts[i] = "";
    }
    for (i = 0; i < MAX_VAL_LENGTH; i++) {
        parts[i + MAX_KEY_LENGTH] = "";
    }

    // Split the key into parts
    int keyLength = strlen(key);
    int j = 0;
    for (i = 0; i < MAX_KEY_LENGTH; i++) {
        if (i < keyLength) {
            parts[i] = key[i];
        } else {
            parts[i] = '\0';
        }
    }

    // Split the value into parts
    int valueLength = strlen(value);
    j = 0;
    for (i = 0; i < MAX_VAL_LENGTH; i++) {
        if (i < valueLength) {
            parts[i + MAX_KEY_LENGTH] = value[i];
        } else {
            parts[i + MAX_KEY_LENGTH] = '\0';
        }
    }

    // Find the correct position to insert the key-value pair
    if (node->key[0] == '\0') {
        // Insert at the root
        node->key[0] = keyParts[0];
        node->val[0] = valueParts[0];
        return;
    } else if (strcmp(node->key[0], keyParts[0]) < 0) {
        // Insert in the left subtree
        if (node->left == NULL) {
            // Create a new left subtree
            node->left = createNode();
            node->left->key[0] = keyParts[0];
            node->left->val[0] = valueParts[0];
            return;
        } else {
            // Recursively insert in the left subtree
            insert(node->left, key, value);
            return;
        }
    } else {
        // Insert in the right subtree
        if (node->right == NULL) {
            // Create a new right subtree
            node->right = createNode();
            node->right->key[0] = keyParts[0];
            node->right->val[0] = valueParts[0];
            return;
        } else {
            // Recursively insert in the right subtree
            insert(node->right, key, value);
            return;
        }
    }
}

// Function to retrieve a value from the B-tree using a given key
char* retrieve(Node* node, char* key) {
    if (node == NULL) {
        return NULL;
    }

    // Find the correct position to retrieve the value
    if (node->key[0] == '\0') {
        // Retrieve at the root
        return node->val[0];
    } else if (strcmp(node->key[0], key) < 0) {
        // Retrieve in the left subtree
        return retrieve(node->left, key);
    } else {
        // Retrieve in the right subtree
        return retrieve(node->right, key);
    }
}

// Function to print the B-tree
void printTree(Node* node) {
    if (node == NULL) {
        return;
    }

    // Print the root
    printf("Key: %s\n", node->key[0]);
    printf("Value: %s\n", node->val[0]);

    // Print the left subtree
    printTree(node->left);

    // Print the right subtree
    printTree(node->right);
}

// Function to free memory used by the B-tree
void freeTree(Node* node) {
    if (node == NULL) {
        return;
    }

    freeTree(node->left);
    freeTree(node->right);
    free(node);
}

// Main function
int main() {
    // Create a new B-tree
    Node* btree = createBtree();

    // Insert some key-value pairs
    insert(btree, "apple", "red");
    insert(btree, "banana", "yellow");
    insert(btree, "cherry", "red");
    insert(btree, "date", "yellow");
    insert(btree, "fig", "green");
    insert(btree, "grape", "purple");
    insert(btree, "kiwi", "green");
    insert(btree, "lemon", "yellow");

    // Print the B-tree
    printf("B-tree:\n");
    printTree(btree);

    // Retrieve a value using a key
    char* value = retrieve(btree, "apple");
    if (value!= NULL) {
        printf("Retrieved value: %s\n", value);
    }

    // Free memory used by the B-tree
    freeTree(btree);

    return 0;
}