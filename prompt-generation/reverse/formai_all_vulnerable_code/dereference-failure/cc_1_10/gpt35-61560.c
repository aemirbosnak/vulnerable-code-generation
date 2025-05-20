//FormAI DATASET v1.0 Category: Graph representation ; Style: complex
#include <stdio.h>
#include <stdlib.h>

typedef struct Graph{
    int V; //number of vertices
    int **adj; //adjacency matrix
} graph;

graph* create_graph(int V){
    graph *G = malloc(sizeof(graph));
    G->V = V;
    G->adj = malloc(sizeof(int *)*V);

    for(int i=0; i<V; i++){
        G->adj[i] = calloc(V, sizeof(int));
    }
    return G;
}

void add_edge(graph *G, int v, int w, int weight){
    G->adj[v][w] = weight;
    G->adj[w][v] = weight;
}

void print_graph(graph *G){
    printf("\nGRAPH: \n");
    for(int i=0; i<G->V; i++){
        for(int j=0; j<G->V; j++){
            printf("%d ", G->adj[i][j]);
        }
        printf("\n");
    }
}

int main(){
    printf("Creating a graph with 5 vertices...\n");
    graph *G = create_graph(5);

    printf("Adding edges...\n");
    add_edge(G, 0, 1, 2);
    add_edge(G, 1, 2, 3);
    add_edge(G, 2, 3, 4);
    add_edge(G, 3, 4, 5);
    add_edge(G, 4, 0, 1);

    printf("Printing graph...\n");
    print_graph(G);

    return 0;
}