//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge in the graph
typedef struct Edge {
    int dest;           // Destination vertex
    struct Edge* next;  // Pointer to the next edge
} Edge;

// Structure to represent a vertex in the graph
typedef struct Vertex {
    int id;               // Vertex ID
    Edge* edges;         // List of edges from this vertex
} Vertex;

// Structure to represent the graph
typedef struct Graph {
    int numVertices;     // Number of vertices
    Vertex* vertices;    // Array of vertices
} Graph;

// Function to create a new edge
Edge* createEdge(int dest) {
    Edge* newEdge = (Edge*)malloc(sizeof(Edge));
    newEdge->dest = dest;
    newEdge->next = NULL;
    return newEdge;
}

// Function to create a new vertex
Vertex* createVertex(int id) {
    Vertex* newVertex = (Vertex*)malloc(sizeof(Vertex));
    newVertex->id = id;
    newVertex->edges = NULL;
    return newVertex;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    Edge* newEdge = createEdge(dest);
    newEdge->next = graph->vertices[src].edges; // Point to the old edge
    graph->vertices[src].edges = newEdge;       // Update the new edge
}

// Create and initialize a graph with a specified number of vertices
Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->vertices = (Vertex*)malloc(numVertices * sizeof(Vertex));
    
    for (int i = 0; i < numVertices; i++) {
        graph->vertices[i] = *createVertex(i);
    }
    return graph;
}

// Function to display the graph's adjacency list
void displayGraph(Graph* graph) {
    printf("Graph Adjacency List:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        Vertex vertex = graph->vertices[i];
        printf("Vertex %d:", vertex.id);
        Edge* edge = vertex.edges;

        while (edge != NULL) {
            printf(" -> %d", edge->dest);
            edge = edge->next;
        }
        printf("\n");
    }
}

// Function to free the memory allocated for the edges of a vertex
void freeEdges(Edge* edge) {
    while (edge != NULL) {
        Edge* temp = edge;
        edge = edge->next;
        free(temp);
    }
}

// Function to free the memory allocated for the graph
void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        freeEdges(graph->vertices[i].edges);
    }
    free(graph->vertices);
    free(graph);
}

// Main function to showcase the graph implementation
int main() {
    // Creating a graph with 5 vertices
    int numVertices = 5;
    Graph* graph = createGraph(numVertices);

    // Adding edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Displaying the graph
    displayGraph(graph);

    // Freeing the allocated memory for the graph
    freeGraph(graph);

    return 0;
}