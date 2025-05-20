//FormAI DATASET v1.0 Category: Graph representation ; Style: decentralized
/* Decentralized C graph program */

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct{
    int weight;
    int src;
    int dest;
} Edge;

typedef struct{
    Edge edges[MAX_VERTICES];
    int numVertices;
    int numEdges;
} Graph;

/* Function prototypes */
Graph* initGraph();
void addVertex(Graph*, int);
void addEdge(Graph*, int, int, int);
void printGraph(Graph*);

int main(){
    Graph* g = initGraph();
    
    /* Adding vertices to graph */
    addVertex(g, 0);
    addVertex(g, 1);
    addVertex(g, 2);
    addVertex(g, 3);
    
    /* Adding edges to graph */
    addEdge(g, 0, 1, 10);
    addEdge(g, 0, 2, 20);
    addEdge(g, 1, 2, 30);
    addEdge(g, 2, 3, 40);
    
    /* Displaying graph */
    printGraph(g);
    
    free(g);
    return 0;
}

/* Functions */
Graph* initGraph(){
    Graph* g = (Graph*) malloc(sizeof(Graph));
    g->numVertices = 0;
    g->numEdges = 0;
    return g;
}

void addVertex(Graph* g, int vertex){
    if(g->numVertices < MAX_VERTICES){
        g->edges[g->numVertices].src = vertex;
        g->numVertices++;
    }
}

void addEdge(Graph* g, int src, int dest, int weight){
    if(g->numEdges < MAX_VERTICES){
        g->edges[g->numEdges].src = src;
        g->edges[g->numEdges].dest = dest;
        g->edges[g->numEdges].weight = weight;
        g->numEdges++;
    }
}

void printGraph(Graph* g){
    int i;
    Edge e;
    printf("Vertices: %d\n", g->numVertices);
    printf("Edges: %d\n", g->numEdges);
    for(i=0; i < g->numEdges; i++){
        e = g->edges[i];
        printf("%d -> %d = %d\n", e.src, e.dest, e.weight);
    }
}