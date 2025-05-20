//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 9

// Create a structure for a graph vertex
struct Vertex {
    int vertexNumber;
    bool visited;
    struct Vertex* parent;
};

// Create a structure for a graph
struct Graph {
    struct Vertex* vertices;
};

// Create a graph with the given number of vertices
struct Graph* createGraph(int v) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = (struct Vertex*)malloc(v * sizeof(struct Vertex));

    // Initialize all vertices as not visited
    for (int i = 0; i < v; i++) {
        graph->vertices[i].vertexNumber = i;
        graph->vertices[i].visited = false;
        graph->vertices[i].parent = NULL;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int v, int w) {
    graph->vertices[v].parent = &graph->vertices[w];
    graph->vertices[w].parent = &graph->vertices[v];
}

// Function to perform depth-first search on the graph
void DFSUtil(struct Graph* graph, int v) {
    printf("%d ", v);
    graph->vertices[v].visited = true;

    // Recur for all the vertices adjacent to this vertex
    struct Vertex* vertex = graph->vertices[v].parent;

    while (vertex!= NULL) {
        int u = vertex->vertexNumber;

        if (!graph->vertices[u].visited) {
            DFSUtil(graph, u);
        }

        vertex = vertex->parent;
    }
}

// Function to perform depth-first search starting from a given vertex
void DFS(struct Graph* graph, int v) {
    if (graph->vertices[v].visited == false) {
        DFSUtil(graph, v);
    }
}

// Main function
int main() {
    struct Graph* graph = createGraph(V);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 7);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 7);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 5);
    addEdge(graph, 2, 8);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);
    addEdge(graph, 5, 6);
    addEdge(graph, 6, 7);
    addEdge(graph, 7, 8);

    // Perform depth-first search starting from vertex 2
    DFS(graph, 2);

    return 0;
}