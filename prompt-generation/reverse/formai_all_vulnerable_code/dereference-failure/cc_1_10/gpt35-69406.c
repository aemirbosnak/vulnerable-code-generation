//FormAI DATASET v1.0 Category: Graph representation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Structure representing an edge in the graph
struct Edge {
    int src, dest;
};

// Structure representing the graph
struct Graph {
    int V, E;
    struct Edge* edge;
};

// Function to print the graph in adjacency matrix representation
void printGraph(int** adjMatrix, int V) {
    printf("Adjacency Matrix:\n\n");

    // Print the column headings
    printf("  ");
    for(int i=0; i<V; i++) {
        printf("%d ", i);
    }
    printf("\n");

    // Print the matrix row by row
    for(int i=0; i<V; i++) {
        printf("%d ", i);
        for(int j=0; j<V; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to convert the graph from edge list representation to adjacency matrix representation
int** edgeListToAdjMatrix(struct Graph* graph) {
    // Allocate memory for the adjacency matrix
    int** adjMatrix = (int**) malloc(graph->V * sizeof(int*));
    for(int i=0; i<graph->V; i++) {
        adjMatrix[i] = (int*) malloc(graph->V * sizeof(int));
        for(int j=0; j<graph->V; j++) {
            adjMatrix[i][j] = 0;
        }
    }

    // Fill the adjacency matrix with edge information
    for(int i=0; i<graph->E; i++) {
        int src = graph->edge[i].src;
        int dest = graph->edge[i].dest;
        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1;
    }

    return adjMatrix;
}

int main() {
    // Create the graph using edge list representation
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = 5;
    graph->E = 6;
    graph->edge = (struct Edge*) malloc(graph->E * sizeof(struct Edge));
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[2].src = 1;
    graph->edge[2].dest = 2;
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[5].src = 3;
    graph->edge[5].dest = 4;

    // Convert the graph from edge list representation to adjacency matrix representation
    int** adjMatrix = edgeListToAdjMatrix(graph);

    // Print the graph in adjacency matrix representation
    printGraph(adjMatrix, graph->V);

    // Free memory
    for(int i=0; i<graph->V; i++) {
        free(adjMatrix[i]);
    }
    free(adjMatrix);
    free(graph->edge);
    free(graph);

    return 0;
}