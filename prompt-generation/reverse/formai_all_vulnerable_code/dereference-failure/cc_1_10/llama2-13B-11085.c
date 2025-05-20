//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a node in the graph
typedef struct {
    char *label;    // Label of the node
    int weight;     // Weight of the edge connecting the node to its parent
    struct node *parent; // Pointer to the parent node
    struct node *children[2]; // Pointers to the children nodes
} node_t;

// Function to create a new node
node_t *new_node(char *label, int weight) {
    node_t *node = malloc(sizeof(node_t));
    node->label = label;
    node->weight = weight;
    node->parent = NULL;
    node->children[0] = NULL;
    node->children[1] = NULL;
    return node;
}

// Function to add a child node to a parent node
void add_child(node_t *parent, char *label, int weight) {
    node_t *child = new_node(label, weight);
    if (parent->children[0] == NULL) {
        parent->children[0] = child;
    } else {
        parent->children[1] = child;
    }
    child->parent = parent;
}

// Function to traverse the graph
void traverse(node_t *root) {
    if (root == NULL) {
        return;
    }
    printf("%s (%d)\n", root->label, root->weight);
    traverse(root->children[0]);
    traverse(root->children[1]);
}

int main() {
    // Create the root node
    node_t *root = new_node("Start", 0);

    // Add child nodes to the root node
    add_child(root, "A", 2);
    add_child(root, "B", 3);
    add_child(root, "C", 1);

    // Traverse the graph
    traverse(root);

    return 0;
}