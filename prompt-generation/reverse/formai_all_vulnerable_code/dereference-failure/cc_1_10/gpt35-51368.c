//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Data structure to represent a graph
typedef struct Graph {
    int num_vertices;
    int num_edges;
    int adjacency_matrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Function to create a new graph
Graph* createGraph(int num_vertices) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;
    graph->num_edges = 0;
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            graph->adjacency_matrix[i][j] = 0;
        }
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int source, int destination) {
    graph->adjacency_matrix[source][destination] = 1;
    graph->adjacency_matrix[destination][source] = 1;
    graph->num_edges++;
}

// Function to print the graph
void printGraph(Graph* graph) {
    printf("Graph:\n");
    printf("Number of vertices: %d\n", graph->num_vertices);
    printf("Number of edges: %d\n", graph->num_edges);
    printf("Adjacency matrix:\n");
    for (int i = 0; i < graph->num_vertices; i++) {
        for (int j = 0; j < graph->num_vertices; j++) {
            printf("%d ", graph->adjacency_matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to color the vertices of the graph
void colorGraph(Graph* graph) {
    int color[MAX_VERTICES];
    color[0] = 0;
    for (int i = 1; i < graph->num_vertices; i++) {
        color[i] = -1;
    }
    // Find legal color for each vertex
    for (int i = 1; i < graph->num_vertices; i++) {
        for (int j = 0; j < i; j++) {
            if (graph->adjacency_matrix[i][j] && color[j] != -1) {
                color[i] = (color[j] + 1) % 2;
            }
        }
    }
    // Print colors of each vertex
    printf("Vertex colors:\n");
    for (int i = 0; i < graph->num_vertices; i++) {
        printf("Vertex %d: %s\n", i, color[i] == 0 ? "red" : "blue");
    }
}

int main() {
    Graph* graph = createGraph(7);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);
    addEdge(graph, 5, 6);
    printGraph(graph);
    colorGraph(graph);
    return 0;
}