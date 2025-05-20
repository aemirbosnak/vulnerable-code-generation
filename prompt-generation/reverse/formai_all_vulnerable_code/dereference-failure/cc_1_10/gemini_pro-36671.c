//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Define a custom data structure to represent a Graph
typedef struct Graph {
    int V;                  // Number of vertices
    int E;                  // Number of edges
    struct AdjListNode** adj;  // Pointer to an array of adjacency lists
} Graph;

// Define a custom data structure to represent a Node in an adjacency list
typedef struct AdjListNode {
    int dest;               // Destination vertex
    int weight;             // Weight of the edge
    struct AdjListNode* next;  // Pointer to the next node
} AdjListNode;

// Function to create a new Graph
Graph* createGraph(int V, int E) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;

    // Create an array of adjacency lists. Each adjacency list is a linked list.
    graph->adj = (AdjListNode**) malloc(V * sizeof(AdjListNode*));
    for (int i = 0; i < V; i++) {
        graph->adj[i] = NULL;
    }

    return graph;
}

// Function to add an edge to a Graph
void addEdge(Graph* graph, int src, int dest, int weight) {
    // Create a new node for the adjacency list
    AdjListNode* newNode = (AdjListNode*) malloc(sizeof(AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;

    // Add the new node to the adjacency list of the source vertex
    newNode->next = graph->adj[src];
    graph->adj[src] = newNode;
}

// Function to print the Graph
void printGraph(Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        AdjListNode* curr = graph->adj[i];
        printf("Vertex %d: ", i);
        while (curr) {
            printf("(%d, %d) -> ", curr->dest, curr->weight);
            curr = curr->next;
        }
        printf("NULL\n");
    }
}

int main() {
    // Create a new Graph
    Graph* graph = createGraph(5, 6);

    // Add edges to the Graph
    addEdge(graph, 0, 1, 1);
    addEdge(graph, 0, 2, 2);
    addEdge(graph, 1, 3, 3);
    addEdge(graph, 1, 4, 4);
    addEdge(graph, 2, 4, 5);
    addEdge(graph, 3, 4, 6);

    // Print the Graph
    printGraph(graph);

    return 0;
}