//FormAI DATASET v1.0 Category: Graph representation ; Style: genious
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure to store graph vertices and edges
typedef struct Graph{
    int vertices;
    int edges;
    int **adj_matrix;
} Graph;

// Initializes a graph with a given maximum number of vertices
Graph* create_graph(int vertices){
    Graph* graph = (Graph *)malloc(sizeof(Graph));
    graph->vertices = vertices;
    graph->edges = 0;
    graph->adj_matrix = (int **)malloc(vertices * sizeof(int *));

    for(int i = 0; i < vertices; i++){
        graph->adj_matrix[i] = (int *)calloc(vertices, sizeof(int));
    }
    return graph;
}

// Adds an edge to the graph
void add_edge(Graph *graph, int source, int destination){
    graph->adj_matrix[source][destination] = 1;
    graph->edges++;
}

// Prints the graph
void print_graph(Graph* graph){
    for(int i = 0; i < graph->vertices; i++){
        printf("[%d]: ", i);
        for(int j = 0; j < graph->vertices; j++){
            printf("%d ", graph->adj_matrix[i][j]);
        }
        printf("\n");
    }
}

// Driver program
int main(){
    // Create a graph with 5 vertices
    Graph* graph = create_graph(5);

    // Add edges to the graph
    add_edge(graph, 0, 1);
    add_edge(graph, 1, 2);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);
    add_edge(graph, 4, 0);

    // Print the graph
    print_graph(graph);

    // Free memory
    for(int i = 0; i < graph->vertices; i++){
        free(graph->adj_matrix[i]);
    }
    free(graph->adj_matrix);
    free(graph);

    return 0;
}