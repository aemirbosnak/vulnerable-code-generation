//FormAI DATASET v1.0 Category: Graph representation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 20

typedef struct Edge {
    int src, dest, weight;
} Edge;

typedef struct Graph {
    int num_vertices, num_edges;
    Edge* edges[MAX_VERTICES];
} Graph;

Graph* createGraph(int num_vertices) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;
    graph->num_edges = 0;
    
    for (int i = 0; i < num_vertices; i++) {
        graph->edges[i] = NULL;
    }
    
    return graph;
}

void addEdge(Graph* graph, int src, int dest, int weight) {
    Edge* edge = (Edge*) malloc(sizeof(Edge));
    edge->src = src;
    edge->dest = dest;
    edge->weight = weight;
    
    graph->edges[src] = edge;
    graph->num_edges++;
}

void printGraph(Graph* graph) {
    printf("Number of vertices: %d\n", graph->num_vertices);
    printf("Number of edges: %d\n", graph->num_edges);
    printf("Edges:\n");
    
    for (int i = 0; i < graph->num_vertices; i++) {
        if (graph->edges[i] != NULL) {
            printf("(%d -> %d, weight: %d)\n", graph->edges[i]->src, graph->edges[i]->dest, graph->edges[i]->weight);
        }
    }
}

int main() {
    Graph* graph = createGraph(5);
    addEdge(graph, 0, 1, 10);
    addEdge(graph, 1, 2, 20);
    addEdge(graph, 2, 3, 30);
    addEdge(graph, 3, 4, 40);
    addEdge(graph, 4, 0, 50);
    printGraph(graph);
    
    return 0;
}