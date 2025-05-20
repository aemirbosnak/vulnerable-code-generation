//FormAI DATASET v1.0 Category: Graph representation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

struct Graph{
    int V; // number of vertices
    int **adj; // 2D adjacency matrix
};

// function to create a graph
struct Graph* createGraph(int vertices){
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->V = vertices;

    // allocate memory for 2D adjacency matrix
    graph->adj = (int **)malloc(vertices * sizeof(int *));
    for (int i=0; i<vertices; i++)
         graph->adj[i] = (int *)malloc(vertices * sizeof(int));

    // initialize all matrix elements to 0
    for(int i=0; i<vertices; i++){
        for(int j=0; j<vertices; j++){
            graph->adj[i][j] = 0;
        }
    }
    return graph;
}

// function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest){
    graph->adj[src][dest] = 1;
    graph->adj[dest][src] = 1;
}

// function to display the graph
void displayGraph(struct Graph* graph){
    printf("\nAdjacency Matrix Representation of the Graph:\n");
    for(int i=0; i<graph->V; i++){
        for(int j=0; j<graph->V; j++){
            printf("%d ", graph->adj[i][j]);
        }
        printf("\n");
    }
}

int main(){
    // create a graph with 5 vertices
    struct Graph* graph = createGraph(5);

    // add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // display the graph
    displayGraph(graph);

    return 0;
}