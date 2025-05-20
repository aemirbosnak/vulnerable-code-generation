//FormAI DATASET v1.0 Category: Graph representation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

struct Graph {
    int num_vertices;
    int** adj_matrix;
};

// Helper function to create a new adjacency matrix with all 0's
int** createAdjMatrix(int size) {
    int** matrix = (int**) malloc(size * sizeof(int*));
    for(int i = 0; i < size; i++) {
        matrix[i] = (int*) calloc(size, sizeof(int));
    }
    return matrix;
}

// Helper function to add edges to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    graph->adj_matrix[src][dest] = 1;
    graph->adj_matrix[dest][src] = 1;
}

// Helper function to print the graph's adjacency matrix
void printGraph(struct Graph* graph) {
    printf("Graph:\n");
    for(int i = 0; i < graph->num_vertices; i++) {
        for(int j = 0; j < graph->num_vertices; j++) {
            printf("%d ", graph->adj_matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Create a new graph with 5 vertices
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->num_vertices = 5;
    graph->adj_matrix = createAdjMatrix(graph->num_vertices);

    // Add some edges
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 0);

    // Print the graph
    printGraph(graph);

    // Free allocated memory
    for(int i = 0; i < graph->num_vertices; i++) {
        free(graph->adj_matrix[i]);
    }
    free(graph->adj_matrix);
    free(graph);

    return 0;
}