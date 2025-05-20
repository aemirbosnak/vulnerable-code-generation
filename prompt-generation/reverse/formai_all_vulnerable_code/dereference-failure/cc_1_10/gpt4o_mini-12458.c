//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

// The structure for a graph edge
struct Edge {
    int dest;               // Destination vertex
    struct Edge* next;      // Pointer to the next edge
};

// The structure for a graph
struct Graph {
    int numVertices;        // Number of vertices
    struct Edge** adjLists; // Pointer to an array of adjacency lists
};

// Function to create a new edge (node)
struct Edge* createEdge(int dest) {
    struct Edge* newEdge = malloc(sizeof(struct Edge));
    newEdge->dest = dest;
    newEdge->next = NULL;
    return newEdge;
}

// Function to create a graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(struct Edge*));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Create a new edge from src to dest
    struct Edge* newEdge = createEdge(dest);
    
    // Add the edge to the beginning of the list
    newEdge->next = graph->adjLists[src];
    graph->adjLists[src] = newEdge;
}

// Function to print the graph
void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        struct Edge* temp = graph->adjLists[v];
        printf("Vertex %d: ", v);
        while (temp) {
            printf("-> %d ", temp->dest);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Function to free the graph
void freeGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        struct Edge* temp = graph->adjLists[i];
        while (temp) {
            struct Edge* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph->adjLists);
    free(graph);
}

// Main function - where the party begins!
int main() {
    // Creating a brainy graph with 5 vertices
    struct Graph* myGraph = createGraph(5);
    
    // Adding edges (like connecting dots)
    addEdge(myGraph, 0, 1);
    addEdge(myGraph, 0, 4);
    addEdge(myGraph, 1, 2);
    addEdge(myGraph, 1, 3);
    addEdge(myGraph, 1, 4);
    addEdge(myGraph, 2, 3);
    addEdge(myGraph, 3, 4);

    // Time to show off this fabulous graph!
    printf("Let's unveil our rollicking graph:\n");
    printGraph(myGraph);

    // Wrapping up and cleaning our mess
    freeGraph(myGraph);
    
    // All done, let's close the show!
    return 0;
}