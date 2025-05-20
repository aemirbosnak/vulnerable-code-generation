//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: puzzling
// Puzzle time! Can you decipher this perplexing graph representation?

#include <stdio.h>
#include <stdlib.h>

// Define the mysterious data structure - a Node
struct Node {
    int key;          // The key - a unique identifier
    struct Node *next; // A pointer to the next node in the linked list
    struct Node *prev; // A pointer to the previous node in the linked list
};

// Define the equally cryptic Graph structure
struct Graph {
    int num_nodes;        // The number of nodes in the graph
    struct Node *nodes;   // An array of nodes
    struct Node **adjList; // An adjacency list - an array of pointers to linked lists of nodes
};

// Get ready to unveil the secrets of this enigmatic graph
struct Graph *createGraph(int num_nodes) {
    // Allocate memory for the graph
    struct Graph *graph = malloc(sizeof(struct Graph));

    // Initialize the number of nodes
    graph->num_nodes = num_nodes;

    // Allocate memory for the nodes
    graph->nodes = malloc(sizeof(struct Node) * num_nodes);

    // Initialize the adjacency list
    graph->adjList = malloc(sizeof(struct Node *) * num_nodes);
    for (int i = 0; i < num_nodes; i++) {
        graph->adjList[i] = NULL;
    }

    // Return the newly created graph
    return graph;
}

// Insert a node into the graph
void insertNode(struct Graph *graph, int key) {
    // Create a new node
    struct Node *node = malloc(sizeof(struct Node));

    // Initialize the node's key
    node->key = key;

    // Initialize the node's next and prev pointers
    node->next = NULL;
    node->prev = NULL;

    // Insert the node into the graph's node array
    graph->nodes[key] = *node;

    // Increment the number of nodes in the graph
    graph->num_nodes++;
}

// Add an edge between two nodes
void addEdge(struct Graph *graph, int source, int destination) {
    // Get the source and destination nodes
    struct Node *sourceNode = &graph->nodes[source];
    struct Node *destinationNode = &graph->nodes[destination];

    // Create a new node for the adjacency list
    struct Node *newNode = malloc(sizeof(struct Node));

    // Initialize the new node's key
    newNode->key = destination;

    // Insert the new node into the adjacency list
    newNode->next = graph->adjList[source];
    graph->adjList[source] = newNode;

    // Update the previous pointer of the first node in the adjacency list
    if (graph->adjList[source] != NULL) {
        graph->adjList[source]->prev = newNode;
    }
}

// Display the contents of the graph
void printGraph(struct Graph *graph) {
    // Loop through the nodes
    for (int i = 0; i < graph->num_nodes; i++) {
        // Get the current node
        struct Node *node = &graph->nodes[i];

        // Print the node's key
        printf("%d ", node->key);

        // Print the adjacency list for the node
        struct Node *adjNode = graph->adjList[i];
        while (adjNode != NULL) {
            printf("-> %d ", adjNode->key);
            adjNode = adjNode->next;
        }

        // Print a newline
        printf("\n");
    }
}

// The main function - where the magic happens
int main() {
    // Create a graph with 5 nodes
    struct Graph *graph = createGraph(5);

    // Insert nodes into the graph
    insertNode(graph, 0);
    insertNode(graph, 1);
    insertNode(graph, 2);
    insertNode(graph, 3);
    insertNode(graph, 4);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);

    // Display the contents of the graph
    printGraph(graph);

    return 0;
}