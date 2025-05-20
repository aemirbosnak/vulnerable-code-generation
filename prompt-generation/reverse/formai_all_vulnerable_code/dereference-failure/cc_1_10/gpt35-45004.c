//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Definition for Adjacency Matrix
#define MAX_VERTICES 10
typedef struct {
    int adj_matrix[MAX_VERTICES][MAX_VERTICES];
    int num_vertices;
} Graph;

// Function to create a new Graph
Graph* createGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->num_vertices = 0;
    for(int i = 0; i < MAX_VERTICES; i++) {
        for(int j = 0; j < MAX_VERTICES; j++) {
            graph->adj_matrix[i][j] = 0;
        }
    }
    return graph;
}

// Function to add a new Vertex to the Graph
void addVertex(Graph* graph) {
    if(graph->num_vertices < MAX_VERTICES) {
        graph->num_vertices++;
    }
    else {
        printf("Maximum number of vertices have been reached.\n");
    }
}

// Function to add a new Edge to the Graph
void addEdge(Graph* graph, int start, int end) {
    if(start >= 0 && start < graph->num_vertices && end >= 0 && end < graph->num_vertices) {
        graph->adj_matrix[start][end] = 1;
        graph->adj_matrix[end][start] = 1;
    }
    else {
        printf("Invalid start or end vertex.\n");
    }
}

// Function to remove a Vertex from the Graph
void removeVertex(Graph* graph, int vertex) {
    if(vertex >= 0 && vertex < graph->num_vertices) {
        // Remove the vertex
        for(int i = vertex; i < graph->num_vertices; i++) {
            for(int j = 0; j < graph->num_vertices; j++) {
                graph->adj_matrix[i][j] = graph->adj_matrix[i+1][j];
            }
        }
        for(int i = 0; i < graph->num_vertices; i++) {
            for(int j = vertex; j < graph->num_vertices; j++) {
                graph->adj_matrix[i][j] = graph->adj_matrix[i][j+1];
            }
        }
        graph->num_vertices--;
    }
    else {
        printf("Invalid vertex.\n");
    }
}

// Function to remove an Edge from the Graph
void removeEdge(Graph* graph, int start, int end) {
    if(start >= 0 && start < graph->num_vertices && end >= 0 && end < graph->num_vertices) {
        graph->adj_matrix[start][end] = 0;
        graph->adj_matrix[end][start] = 0;
    }
    else {
        printf("Invalid start or end vertex.\n");
    }
}

// Function to display the Graph as an adjacency matrix
void displayGraph(Graph* graph) {
    printf("Adjacency Matrix\n");
    for(int i = 0; i < graph->num_vertices; i++) {
        for(int j = 0; j < graph->num_vertices; j++) {
            printf("%d ", graph->adj_matrix[i][j]);
        }
        printf("\n");
    }
}

// Main function to test the Graph implementation
int main() {
    Graph* graph = createGraph();
    addVertex(graph);
    addVertex(graph);
    addVertex(graph);
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    displayGraph(graph);
    removeEdge(graph, 0, 1);
    removeVertex(graph, 1);
    displayGraph(graph);
    return 0;
}