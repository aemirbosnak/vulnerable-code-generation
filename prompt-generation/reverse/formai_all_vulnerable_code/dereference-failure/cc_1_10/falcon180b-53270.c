//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Define the structure of the graph node
typedef struct {
    int value;
    struct node *left, *right;
} node;

// Function to create a new node
node *createNode(int value) {
    node *newNode = (node *) malloc(sizeof(node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to add a node to the graph
void addNode(node **graph, int value) {
    if (*graph == NULL) {
        *graph = createNode(value);
    } else {
        node *current = *graph;
        while (current->right!= NULL) {
            current = current->right;
        }
        current->right = createNode(value);
    }
}

// Function to traverse the graph in pre-order
void preOrderTraversal(node *graph) {
    if (graph == NULL) {
        return;
    }
    printf("%d ", graph->value);
    preOrderTraversal(graph->left);
    preOrderTraversal(graph->right);
}

// Function to traverse the graph in in-order
void inOrderTraversal(node *graph) {
    if (graph == NULL) {
        return;
    }
    inOrderTraversal(graph->left);
    printf("%d ", graph->value);
    inOrderTraversal(graph->right);
}

// Function to traverse the graph in post-order
void postOrderTraversal(node *graph) {
    if (graph == NULL) {
        return;
    }
    postOrderTraversal(graph->left);
    postOrderTraversal(graph->right);
    printf("%d ", graph->value);
}

// Function to search for a value in the graph
node *searchGraph(node *graph, int value) {
    if (graph == NULL || graph->value == value) {
        return graph;
    }
    if (value < graph->value) {
        return searchGraph(graph->left, value);
    } else {
        return searchGraph(graph->right, value);
    }
}

// Function to delete a node from the graph
node *deleteNode(node **graph, int value) {
    if (*graph == NULL) {
        return NULL;
    }
    if ((*graph)->value == value) {
        node *temp = *graph;
        *graph = NULL;
        free(temp);
        return NULL;
    }
    if (value < (*graph)->value) {
        (*graph)->left = deleteNode(&(*graph)->left, value);
    } else {
        (*graph)->right = deleteNode(&(*graph)->right, value);
    }
    return *graph;
}

// Main function to test the graph operations
int main() {
    node *graph = NULL;
    addNode(&graph, 1);
    addNode(&graph, 2);
    addNode(&graph, 3);
    addNode(&graph, 4);
    addNode(&graph, 5);
    printf("Pre-order traversal of the graph:\n");
    preOrderTraversal(graph);
    printf("\n");
    printf("In-order traversal of the graph:\n");
    inOrderTraversal(graph);
    printf("\n");
    printf("Post-order traversal of the graph:\n");
    postOrderTraversal(graph);
    printf("\n");
    printf("Searching for value 4 in the graph:\n");
    node *result = searchGraph(graph, 4);
    if (result!= NULL) {
        printf("%d found in the graph.\n", result->value);
    } else {
        printf("Value 4 not found in the graph.\n");
    }
    printf("\n");
    printf("Deleting value 2 from the graph:\n");
    graph = deleteNode(&graph, 2);
    printf("Pre-order traversal of the updated graph:\n");
    preOrderTraversal(graph);
    printf("\n");
    return 0;
}