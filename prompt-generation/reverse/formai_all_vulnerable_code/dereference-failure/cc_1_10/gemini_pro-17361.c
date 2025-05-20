//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// A node in a linked list
struct node {
    int data;
    struct node *next;
};

// A binary tree node
struct tree_node {
    int data;
    struct tree_node *left;
    struct tree_node *right;
};

// A graph node
struct graph_node {
    int data;
    struct graph_node **neighbors;
    int num_neighbors;
};

// Create a new linked list node
struct node *create_node(int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Create a new binary tree node
struct tree_node *create_tree_node(int data) {
    struct tree_node *new_node = malloc(sizeof(struct tree_node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Create a new graph node
struct graph_node *create_graph_node(int data) {
    struct graph_node *new_node = malloc(sizeof(struct graph_node));
    new_node->data = data;
    new_node->neighbors = NULL;
    new_node->num_neighbors = 0;
    return new_node;
}

// Insert a node into a linked list
void insert_node(struct node **head, int data) {
    struct node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Insert a node into a binary tree
void insert_tree_node(struct tree_node **root, int data) {
    if (*root == NULL) {
        *root = create_tree_node(data);
    } else if (data < (*root)->data) {
        insert_tree_node(&(*root)->left, data);
    } else {
        insert_tree_node(&(*root)->right, data);
    }
}

// Insert a node into a graph
void insert_graph_node(struct graph_node **graph, int data) {
    struct graph_node *new_node = create_graph_node(data);
    *graph = new_node;
}

// Print a linked list
void print_list(struct node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Print a binary tree
void print_tree(struct tree_node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        print_tree(root->left);
        print_tree(root->right);
    }
}

// Print a graph
void print_graph(struct graph_node *graph) {
    if (graph != NULL) {
        printf("%d ", graph->data);
        for (int i = 0; i < graph->num_neighbors; i++) {
            print_graph(graph->neighbors[i]);
        }
    }
}

int main() {
    // Create a linked list
    struct node *head = NULL;
    insert_node(&head, 1);
    insert_node(&head, 2);
    insert_node(&head, 3);
    print_list(head); // Output: 3 2 1

    // Create a binary tree
    struct tree_node *root = NULL;
    insert_tree_node(&root, 10);
    insert_tree_node(&root, 5);
    insert_tree_node(&root, 15);
    insert_tree_node(&root, 2);
    insert_tree_node(&root, 7);
    insert_tree_node(&root, 12);
    insert_tree_node(&root, 20);
    print_tree(root); // Output: 10 5 2 7 15 12 20

    // Create a graph
    struct graph_node *graph = NULL;
    insert_graph_node(&graph, 1);
    insert_graph_node(&graph->neighbors, 2);
    insert_graph_node(&graph->neighbors, 3);
    insert_graph_node(&graph->neighbors, 4);
    insert_graph_node(&graph->neighbors[1], 5);
    insert_graph_node(&graph->neighbors[1], 6);
    insert_graph_node(&graph->neighbors[2], 7);
    insert_graph_node(&graph->neighbors[2], 8);
    insert_graph_node(&graph->neighbors[3], 9);
    insert_graph_node(&graph->neighbors[3], 10);
    print_graph(graph); // Output: 1 2 5 6 3 7 8 4 9 10

    return 0;
}