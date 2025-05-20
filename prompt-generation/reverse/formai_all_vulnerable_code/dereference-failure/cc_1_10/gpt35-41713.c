//FormAI DATASET v1.0 Category: Graph representation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Structure to store a vertex (node)
struct Vertex {
    int data;
    struct Vertex* next;
};

// Function to create a new vertex
struct Vertex* newVertex(int data) {
    struct Vertex* vertex = malloc(sizeof(struct Vertex));
    vertex->data = data;
    vertex->next = NULL;
    
    return vertex;
}

// Function to add an edge between two vertices
void addEdge(struct Vertex** adjList, int src, int dest) {
    struct Vertex* vertex = newVertex(dest);
    vertex->next = adjList[src];
    adjList[src] = vertex;
}

// Function to print the adjacency list
void printGraph(struct Vertex** adjList, int vertices) {
    for (int i = 0; i < vertices; i++) {
        printf("Vertex %d :", i);
        struct Vertex* vertex = adjList[i];
        while (vertex) {
            printf(" %d ->", vertex->data);
            vertex = vertex->next;
        }
        printf(" NULL\n");
    }
}

int main() {
    int vertices = 5;
    struct Vertex** adjList = malloc(vertices * sizeof(struct Vertex*));
    
    // Initialize all elements of the adjacency list as NULL
    for (int i = 0; i < vertices; i++) {
        adjList[i] = NULL;
    }
    
    // Add edges to the graph
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 4);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 1, 4);
    addEdge(adjList, 2, 3);
    addEdge(adjList, 3, 4);
    
    // Print the adjacency list
    printGraph(adjList, vertices);
    
    return 0;
}