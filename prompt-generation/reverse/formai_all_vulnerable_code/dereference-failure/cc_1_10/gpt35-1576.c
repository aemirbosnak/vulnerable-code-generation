//FormAI DATASET v1.0 Category: Graph representation ; Style: complete
#include<stdio.h>
#include<stdlib.h>

struct Graph{
    int V; // number of vertices in the graph
    int E; // number of edges in the graph
    int **adj; // 2D adjacency matrix
};

// function to create a new graph
struct Graph* createGraph(int V, int E){
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph)); // allocate memory for structure

    graph->V = V; // assign number of vertices
    graph->E = E; // assign number of edges

    graph->adj = (int**)malloc(V * sizeof(int*)); // allocate memory for 2D array
    for(int i=0; i<V; i++){
        graph->adj[i] = (int*)malloc(V * sizeof(int));
    }

    // initialize all elements of the adjacency matrix to 0
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            graph->adj[i][j] = 0;
        }
    }

    return graph; // return the created graph
}

// function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest){
    graph->adj[src][dest] = 1; // add edge from src to dest
    graph->adj[dest][src] = 1; // add edge from dest to src (assuming undirected graph)
}

// function to print the graph
void printGraph(struct Graph* graph){
    printf("Graph representation using adjacency matrix:\n");
    for(int i=0; i<graph->V; i++){
        for(int j=0; j<graph->V; j++){
            printf("%d ", graph->adj[i][j]);
        }
        printf("\n");
    }
}

// main function to test the graph implementation
int main(){
    int V = 5; // number of vertices
    int E = 4; // number of edges

    struct Graph* graph = createGraph(V, E); // create new graph

    addEdge(graph, 0, 1); // add edge
    addEdge(graph, 0, 4); // add edge
    addEdge(graph, 1, 2); // add edge
    addEdge(graph, 2, 3); // add edge

    printGraph(graph); // print the graph

    return 0;
}