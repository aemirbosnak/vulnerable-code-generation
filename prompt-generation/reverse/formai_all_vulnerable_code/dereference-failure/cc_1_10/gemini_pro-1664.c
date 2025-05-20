//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEYS 10000
#define MAX_VALUES 100000

// A node in the B-tree
struct node {
    int num_keys;
    int keys[MAX_KEYS];
    int values[MAX_VALUES];
    struct node *children[MAX_KEYS + 1];
};

// The root of the B-tree
struct node *root;

// Create a new node
struct node *create_node() {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->num_keys = 0;
    for (int i = 0; i < MAX_KEYS; i++) {
        new_node->keys[i] = -1;
        new_node->values[i] = -1;
        new_node->children[i] = NULL;
    }
    new_node->children[MAX_KEYS] = NULL;
    return new_node;
}

// Insert a key-value pair into the B-tree
void insert(int key, int value) {
    // If the tree is empty, create a new root node
    if (root == NULL) {
        root = create_node();
        root->keys[0] = key;
        root->values[0] = value;
        root->num_keys++;
        return;
    }

    // Find the leaf node where the key should be inserted
    struct node *current = root;
    while (current->children[current->num_keys] != NULL) {
        int i = 0;
        while (i < current->num_keys && key > current->keys[i]) {
            i++;
        }
        current = current->children[i];
    }

    // If the leaf node is full, split it
    if (current->num_keys == MAX_KEYS) {
        struct node *new_node = create_node();
        for (int i = MAX_KEYS / 2; i < MAX_KEYS; i++) {
            new_node->keys[i - MAX_KEYS / 2] = current->keys[i];
            new_node->values[i - MAX_KEYS / 2] = current->values[i];
            new_node->children[i - MAX_KEYS / 2] = current->children[i];
            current->keys[i] = -1;
            current->values[i] = -1;
            current->children[i] = NULL;
        }
        new_node->children[MAX_KEYS / 2] = current->children[MAX_KEYS];
        current->children[MAX_KEYS] = new_node;
        current->num_keys = MAX_KEYS / 2;
        new_node->num_keys = MAX_KEYS / 2;

        // If the key is greater than the median key, insert it into the new node
        if (key > current->keys[MAX_KEYS / 2 - 1]) {
            current = new_node;
        }
    }

    // Insert the key-value pair into the leaf node
    int i = current->num_keys;
    while (i > 0 && key < current->keys[i - 1]) {
        current->keys[i] = current->keys[i - 1];
        current->values[i] = current->values[i - 1];
        i--;
    }
    current->keys[i] = key;
    current->values[i] = value;
    current->num_keys++;
}

// Search for a key in the B-tree
int search(int key) {
    // If the tree is empty, return -1
    if (root == NULL) {
        return -1;
    }

    // Find the leaf node where the key should be located
    struct node *current = root;
    while (current->children[current->num_keys] != NULL) {
        int i = 0;
        while (i < current->num_keys && key > current->keys[i]) {
            i++;
        }
        current = current->children[i];
    }

    // Search for the key in the leaf node
    for (int i = 0; i < current->num_keys; i++) {
        if (current->keys[i] == key) {
            return current->values[i];
        }
    }

    // The key was not found
    return -1;
}

// Print the B-tree
void print_tree(struct node *node) {
    if (node == NULL) {
        return;
    }

    for (int i = 0; i < node->num_keys; i++) {
        printf("%d ", node->keys[i]);
    }
    printf("\n");

    for (int i = 0; i <= node->num_keys; i++) {
        print_tree(node->children[i]);
    }
}

// Free the B-tree
void free_tree(struct node *node) {
    if (node == NULL) {
        return;
    }

    for (int i = 0; i <= node->num_keys; i++) {
        free_tree(node->children[i]);
    }

    free(node);
}

int main() {
    // Insert some key-value pairs into the B-tree
    insert(1, 10);
    insert(2, 20);
    insert(3, 30);
    insert(4, 40);
    insert(5, 50);

    // Print the B-tree
    print_tree(root);

    // Search for a key in the B-tree
    int value = search(3);
    if (value == -1) {
        printf("Key not found\n");
    } else {
        printf("Key found: %d\n", value);
    }

    // Free the B-tree
    free_tree(root);

    return 0;
}