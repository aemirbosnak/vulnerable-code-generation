//FormAI DATASET v1.0 Category: Graph representation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// struct to represent a graph
typedef struct Graph {
    int V;
    int E;
    int **adjMatrix;
} Graph;

// function to create a new graph with V vertices
Graph* createGraph(int V) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->V = V;
    graph->E = 0;
    graph->adjMatrix = (int**) malloc(V * sizeof(int*));
    
    // initialize all values in matrix to 0
    for(int i = 0; i < V; i++) {
        graph->adjMatrix[i] = (int*) calloc(V, sizeof(int));
    }
    return graph;
}

// function to add an undirected edge between two vertices
void addEdge(Graph* graph, int v1, int v2) {
    if(v1 >= graph->V || v1 < 0 || v2 >= graph->V || v2 < 0) {
        printf("Invalid vertex!\n");
    } else {
        graph->adjMatrix[v1][v2] = 1;
        graph->adjMatrix[v2][v1] = 1;
        graph->E++;
    }
}

// function to print the adjacency matrix of the given graph
void printGraph(Graph* graph) {
    printf("Adjacency Matrix:\n");
    for(int i = 0; i < graph->V; i++) {
        for(int j = 0; j < graph->V; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // create a graph with 5 vertices
    Graph* graph = createGraph(5);
    
    // add edges between vertices
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    
    // print the graph
    printGraph(graph);
    
    // free memory
    for(int i = 0; i < graph->V; i++) {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
    free(graph);
    
    return 0;
}