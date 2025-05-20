//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a Graph
typedef struct Graph {
    int vertices; // Number of vertices
    int **adjMatrix; // Adjacency matrix
} Graph;

// Function to create a Graph
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;

    // Allocate memory for adjacency matrix
    graph->adjMatrix = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = (int*)malloc(vertices * sizeof(int));
        memset(graph->adjMatrix[i], 0, vertices * sizeof(int)); // Initialize with 0
    }

    return graph;
}

// Function to add an edge to the Graph
void addEdge(Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1; // For undirected graph
}

// Function to display the adjacency matrix
void displayGraph(Graph* graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->vertices; i++) {
        for (int j = 0; j < graph->vertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to free associated memory
void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->vertices; i++) {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
    free(graph);
}

// Structure for a Node in a Binary Tree
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new Node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to print Binary Tree in Inorder
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Function to free Binary Tree memory
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Main function to visualize the data structures
int main() {
    printf("Creating and Displaying a Graph:\n");
    
    Graph* myGraph = createGraph(5);

    addEdge(myGraph, 0, 1);
    addEdge(myGraph, 0, 4);
    addEdge(myGraph, 1, 2);
    addEdge(myGraph, 1, 3);
    addEdge(myGraph, 1, 4);
    addEdge(myGraph, 2, 3);
    addEdge(myGraph, 3, 4);

    displayGraph(myGraph);
    
    // Now let’s visualize a Binary Tree
    printf("\nCreating and Displaying a Binary Tree:\n");
    
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    // Cleaning up memory
    freeGraph(myGraph);
    freeTree(root);

    return 0;
}