//FormAI DATASET v1.0 Category: Graph representation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 20

typedef struct Graph {
    int vertices[MAX_VERTICES][MAX_VERTICES];
    int num_vertices;
} Graph;

/* Create a new graph */
Graph* createGraph(int num_vertices) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;
    
    int i, j;
    for (i = 0; i < num_vertices; i++) {
        for (j = 0; j < num_vertices; j++) {
            graph->vertices[i][j] = 0;
        }
    }
    
    return graph;
}

/* Add an edge to the graph */
void addEdge(Graph* graph, int src, int dest) {
    graph->vertices[src][dest] = 1;
    graph->vertices[dest][src] = 1;
}

/* Print the graph */
void printGraph(Graph* graph) {
    int i, j;
    for (i = 0; i < graph->num_vertices; i++) {
        printf("Vertex %d: ", i);
        for (j = 0; j < graph->num_vertices; j++) {
            if (graph->vertices[i][j] == 1) {
                printf("%d->%d ", i, j);
            }
        }
        printf("\n");
    }
}

int main() {
    Graph* graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    
    printGraph(graph);
    
    return 0;
}