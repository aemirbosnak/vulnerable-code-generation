//FormAI DATASET v1.0 Category: Graph representation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

typedef struct edge {
    int src;
    int dest;
} Edge;

typedef struct graph {
    int vertices;
    int edges;
    int** adj_matrix;
} Graph;

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));

    graph->vertices = vertices;
    graph->edges = 0;

    graph->adj_matrix = (int**) malloc(sizeof(int*) * vertices);
    for (int i = 0; i < vertices; i++) {
        graph->adj_matrix[i] = (int*) calloc(vertices, sizeof(int));
    }

   return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    graph->adj_matrix[src][dest] = 1;
    graph->edges++;
}

void printGraph(Graph* graph) {
    printf("Graph Representation: \n");

    for (int i = 0; i < graph->vertices; i++) {
        for (int j = 0; j < graph->vertices; j++) {
            printf("%2d ", graph->adj_matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int vertices = 5;
    Graph* graph = createGraph(vertices);

    Edge edges[] = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 0}
    };
    int numEdges = sizeof(edges) / sizeof(edges[0]);

    for (int i = 0; i < numEdges; i++) {
        addEdge(graph, edges[i].src, edges[i].dest);
    }

    printGraph(graph);
    return 0;
}