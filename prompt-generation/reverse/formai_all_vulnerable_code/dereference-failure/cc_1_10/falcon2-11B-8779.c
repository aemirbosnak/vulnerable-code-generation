//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to add an edge to the graph
void addEdge(int** graph, int** parent, int v, int w) {
    // If the parent array is NULL, initialize it
    if (parent == NULL) {
        for (int i = 0; i < 100; i++) {
            parent[i] = i;
        }
        return;
    }

    // If the parent[v] and parent[w] are the same, do nothing
    if (parent[v] == parent[w]) {
        return;
    }

    // If the parent[v] and parent[w] are not the same, update the parent array
    parent[w] = parent[v];

    // Add an edge to the graph
    graph[v][w] = 1;
}

// Function to print the graph
void printGraph(int** graph, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 1) {
                printf("(%d, %d) ", i, j);
            }
        }
        printf("\n");
    }
}

int main() {
    // Create a graph of size 5x5
    int** graph = (int**)malloc(sizeof(int*) * 5);
    for (int i = 0; i < 5; i++) {
        graph[i] = (int*)malloc(sizeof(int) * 5);
    }

    // Initialize the graph with NULL values
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            graph[i][j] = 0;
        }
    }

    // Add edges to the graph
    addEdge(graph, NULL, 0, 1);
    addEdge(graph, NULL, 0, 2);
    addEdge(graph, NULL, 0, 3);
    addEdge(graph, NULL, 1, 2);
    addEdge(graph, NULL, 1, 3);
    addEdge(graph, NULL, 2, 3);

    // Print the graph
    printf("Graph:\n");
    printGraph(graph, 5);

    // Free the memory allocated for the graph
    for (int i = 0; i < 5; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}