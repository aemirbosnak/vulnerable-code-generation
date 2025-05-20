//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// Structure to represent a node in the graph
struct Node {
    int label; // Label of the node
    struct Node* parent; // Parent node
    struct Node** children; // Children nodes
    int num_children; // Number of children
};

// Function to create a new node
struct Node* new_node(int label) {
    struct Node* node = malloc(sizeof(struct Node));
    node->label = label;
    node->parent = NULL;
    node->children = NULL;
    node->num_children = 0;
    return node;
}

// Function to add a child node to a parent node
void add_child(struct Node* parent, struct Node* child) {
    assert(parent != NULL);
    assert(child != NULL);
    if (parent->num_children == 0) {
        parent->children = malloc(sizeof(struct Node*) * 2);
        parent->children[0] = child;
        parent->num_children = 1;
    } else {
        int i = 0;
        for (; i < parent->num_children; i++) {
            if (parent->children[i] == NULL) {
                break;
            }
        }
        parent->children[i] = child;
        parent->num_children++;
    }
}

// Function to print a node and its children
void print_node(struct Node* node) {
    if (node == NULL) {
        printf("NULL\n");
        return;
    }
    printf("%d (%s): ", node->label, node->parent == NULL ? "root" : node->parent->label);
    for (int i = 0; i < node->num_children; i++) {
        print_node(node->children[i]);
    }
    printf("\n");
}

// Function to print a graph
void print_graph(struct Node* root) {
    print_node(root);
}

int main() {
    struct Node* root = new_node(1);
    struct Node* node1 = new_node(2);
    struct Node* node2 = new_node(3);
    struct Node* node3 = new_node(4);
    struct Node* node4 = new_node(5);

    add_child(root, node1);
    add_child(root, node2);
    add_child(node1, node3);
    add_child(node2, node4);

    print_graph(root);

    return 0;
}