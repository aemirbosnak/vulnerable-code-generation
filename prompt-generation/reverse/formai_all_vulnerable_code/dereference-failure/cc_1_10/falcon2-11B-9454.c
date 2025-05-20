//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

// Function to print the graph
void printGraph(int** graph, int vertices) {
    printf("Vertices: %d\n", vertices);
    printf("Edges: %d\n", graph[0][0]);
    printf("Adjacency list:\n");
    for (int i = 0; i < vertices; i++) {
        printf("%d -> ", i);
        for (int j = 0; j < vertices; j++) {
            if (graph[i][j]) {
                printf("%d ", graph[i][j]);
            }
        }
        printf("\n");
    }
}

// Function to add an edge to the graph
void addEdge(int** graph, int vertices, int from, int to) {
    if (from >= vertices) {
        printf("Error: Vertex %d does not exist\n", from);
        return;
    }
    if (to >= vertices) {
        printf("Error: Vertex %d does not exist\n", to);
        return;
    }
    if (graph[from][to] == 1) {
        printf("Error: Edge already exists between vertices %d and %d\n", from, to);
        return;
    }
    graph[from][to] = 1;
    graph[to][from] = 1;
}

// Function to remove an edge from the graph
void removeEdge(int** graph, int vertices, int from, int to) {
    if (from >= vertices) {
        printf("Error: Vertex %d does not exist\n", from);
        return;
    }
    if (to >= vertices) {
        printf("Error: Vertex %d does not exist\n", to);
        return;
    }
    if (graph[from][to] == 0) {
        printf("Error: Edge does not exist between vertices %d and %d\n", from, to);
        return;
    }
    graph[from][to] = 0;
    graph[to][from] = 0;
}

int main() {
    int vertices = 6;
    int** graph = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        graph[i] = (int*)malloc(vertices * sizeof(int));
    }

    // Add edges to the graph
    addEdge(graph, vertices, 0, 1);
    addEdge(graph, vertices, 0, 2);
    addEdge(graph, vertices, 1, 3);
    addEdge(graph, vertices, 1, 4);
    addEdge(graph, vertices, 2, 3);
    addEdge(graph, vertices, 2, 4);
    addEdge(graph, vertices, 3, 5);
    addEdge(graph, vertices, 4, 5);

    // Print the graph
    printf("Graph:\n");
    printGraph(graph, vertices);

    // Remove an edge from the graph
    removeEdge(graph, vertices, 3, 4);

    // Print the updated graph
    printf("Updated graph:\n");
    printGraph(graph, vertices);

    // Free the memory
    for (int i = 0; i < vertices; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}