//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Linked list node
typedef struct node {
    int data;
    struct node *next;
} node;

// Binary tree node
typedef struct tree_node {
    int data;
    struct tree_node *left;
    struct tree_node *right;
} tree_node;

// Graph node
typedef struct graph_node {
    int data;
    struct graph_node **neighbors;
    int num_neighbors;
} graph_node;

// Visualization function for linked list
void visualize_linked_list(node *head) {
    node *current = head;
    printf("[");
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(", ");
        }
        current = current->next;
    }
    printf("]\n");
}

// Visualization function for binary tree
void visualize_binary_tree(tree_node *root) {
    if (root == NULL) {
        printf("()");
        return;
    }

    printf("(%d", root->data);

    visualize_binary_tree(root->left);

    visualize_binary_tree(root->right);

    printf(")");
}

// Visualization function for graph
void visualize_graph(graph_node *nodes, int num_nodes) {
    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d: ", i);
        for (int j = 0; j < nodes[i].num_neighbors; j++) {
            printf("%d ", nodes[i].neighbors[j]->data);
        }
        printf("\n");
    }
}

int main() {
    // Create a linked list
    node *head = malloc(sizeof(node));
    head->data = 1;
    head->next = malloc(sizeof(node));
    head->next->data = 2;
    head->next->next = malloc(sizeof(node));
    head->next->next->data = 3;
    head->next->next->next = NULL;

    // Create a binary tree
    tree_node *root = malloc(sizeof(tree_node));
    root->data = 1;
    root->left = malloc(sizeof(tree_node));
    root->left->data = 2;
    root->left->left = NULL;
    root->left->right = NULL;
    root->right = malloc(sizeof(tree_node));
    root->right->data = 3;
    root->right->left = NULL;
    root->right->right = NULL;

    // Create a graph
    graph_node *nodes = malloc(sizeof(graph_node) * 4);
    nodes[0].data = 1;
    nodes[0].num_neighbors = 2;
    nodes[0].neighbors = malloc(sizeof(graph_node *) * 2);
    nodes[0].neighbors[0] = &nodes[1];
    nodes[0].neighbors[1] = &nodes[2];
    nodes[1].data = 2;
    nodes[1].num_neighbors = 1;
    nodes[1].neighbors = malloc(sizeof(graph_node *) * 1);
    nodes[1].neighbors[0] = &nodes[3];
    nodes[2].data = 3;
    nodes[2].num_neighbors = 1;
    nodes[2].neighbors = malloc(sizeof(graph_node *) * 1);
    nodes[2].neighbors[0] = &nodes[0];
    nodes[3].data = 4;
    nodes[3].num_neighbors = 0;
    nodes[3].neighbors = NULL;

    // Visualize the data structures
    visualize_linked_list(head);
    visualize_binary_tree(root);
    visualize_graph(nodes, 4);

    return 0;
}