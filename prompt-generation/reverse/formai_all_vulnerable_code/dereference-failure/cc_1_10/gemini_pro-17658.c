//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a node in the B-tree
typedef struct node {
    int *keys;
    struct node **children;
    int n;
    int is_leaf;
} node;

// Create a new node
node *create_node(int m, int is_leaf) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->keys = (int *)malloc(sizeof(int) * (m - 1));
    new_node->children = (node **)malloc(sizeof(node *) * m);
    new_node->n = 0;
    new_node->is_leaf = is_leaf;
    return new_node;
}

// Insert a key into a node
void insert_key(node *root, int key) {
    // Find the child which should contain the new key
    int i = 0;
    while (i < root->n && key > root->keys[i]) {
        i++;
    }

    // If the child is a leaf, insert the key
    if (root->is_leaf) {
        for (int j = root->n; j > i; j--) {
            root->keys[j] = root->keys[j - 1];
        }
        root->keys[i] = key;
        root->n++;
    }
    // Otherwise, insert the key into the child
    else {
        insert_key(root->children[i], key);
    }
}

// Search for a key in a node
int search_key(node *root, int key) {
    // Find the child which should contain the key
    int i = 0;
    while (i < root->n && key > root->keys[i]) {
        i++;
    }

    // If the child is a leaf, search for the key
    if (root->is_leaf) {
        for (int j = 0; j < root->n; j++) {
            if (root->keys[j] == key) {
                return j;
            }
        }
        return -1;
    }
    // Otherwise, search for the key in the child
    else {
        return search_key(root->children[i], key);
    }
}

// Print the keys in a node
void print_node(node *root) {
    for (int i = 0; i < root->n; i++) {
        printf("%d ", root->keys[i]);
    }
    printf("\n");
}

// Print the B-tree
void print_btree(node *root) {
    // Print the keys in the root node
    print_node(root);

    // Print the keys in the child nodes
    for (int i = 0; i < root->n; i++) {
        print_btree(root->children[i]);
    }
}

// Free the memory allocated for a node
void free_node(node *root) {
    free(root->keys);
    free(root->children);
    free(root);
}

// Free the memory allocated for the B-tree
void free_btree(node *root) {
    // Free the memory allocated for the root node
    free_node(root);

    // Free the memory allocated for the child nodes
    for (int i = 0; i < root->n; i++) {
        free_btree(root->children[i]);
    }
}

// Main function
int main() {
    // Create the root node
    node *root = create_node(3, 1);

    // Insert some keys into the B-tree
    insert_key(root, 10);
    insert_key(root, 20);
    insert_key(root, 30);
    insert_key(root, 40);
    insert_key(root, 50);

    // Print the B-tree
    print_btree(root);

    // Search for a key in the B-tree
    int key = 30;
    int index = search_key(root, key);
    if (index != -1) {
        printf("The key %d was found at index %d\n", key, index);
    } else {
        printf("The key %d was not found\n", key);
    }

    // Free the memory allocated for the B-tree
    free_btree(root);

    return 0;
}