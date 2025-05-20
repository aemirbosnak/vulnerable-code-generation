//FormAI DATASET v1.0 Category: Graph representation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

typedef struct Edge {
    int src, dest, weight;
} Edge;

typedef struct Graph {
    int V, E;
    Edge* edges;
} Graph;

Graph* createGraph(int V, int E) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    graph->edges = (Edge*) malloc(E * sizeof(Edge));
    return graph;
}

int main() {
    int V = 5, E = 7;
    Graph* graph = createGraph(V, E);
    
    graph->edges[0].src = 0;
    graph->edges[0].dest = 1;
    graph->edges[0].weight = 2;
    
    graph->edges[1].src = 0;
    graph->edges[1].dest = 2;
    graph->edges[1].weight = 4;
    
    graph->edges[2].src = 1;
    graph->edges[2].dest = 2;
    graph->edges[2].weight = 1;
    
    graph->edges[3].src = 1;
    graph->edges[3].dest = 3;
    graph->edges[3].weight = 3;
    
    graph->edges[4].src = 2;
    graph->edges[4].dest = 3;
    graph->edges[4].weight = 5;
    
    graph->edges[5].src = 3;
    graph->edges[5].dest = 4;
    graph->edges[5].weight = 2;
    
    graph->edges[6].src = 2;
    graph->edges[6].dest = 4;
    graph->edges[6].weight = 1;
    
    return 0;
}