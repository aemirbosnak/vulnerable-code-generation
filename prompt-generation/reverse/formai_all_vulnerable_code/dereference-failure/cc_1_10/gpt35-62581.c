//FormAI DATASET v1.0 Category: Graph representation ; Style: complete
#include<stdio.h>
#include<stdlib.h>

/* A structure to represent an edge in the graph */
struct Edge {
    int src, dest;
};

/* A structure to represent a graph */
struct Graph {
    int vertexCount, edgeCount;
    struct Edge* edges;
};

/* Create a graph with the given number of vertices and edges*/
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->vertexCount = V;
    graph->edgeCount = E;
    graph->edges = (struct Edge*) malloc(graph->edgeCount * sizeof(struct Edge));
    return graph;
}

/* Display the graph representation */
void displayGraph(struct Graph* graph) {
    int i;
    printf("Vertices: %d, Edges: %d\n\n", graph->vertexCount, graph->edgeCount);
    for(i = 0; i < graph->edgeCount; i++) {
        printf("Edge %d: %d -> %d\n", i+1, graph->edges[i].src, graph->edges[i].dest);
    }   
}

int main() {
    struct Graph* graph = createGraph(5, 6);
    graph->edges[0].src = 0;
    graph->edges[0].dest = 1;

    graph->edges[1].src = 0;
    graph->edges[1].dest = 4;

    graph->edges[2].src = 1;
    graph->edges[2].dest = 2;

    graph->edges[3].src = 1;
    graph->edges[3].dest = 3;

    graph->edges[4].src = 1;
    graph->edges[4].dest = 4;

    graph->edges[5].src = 3;
    graph->edges[5].dest = 4;

    displayGraph(graph);

    return 0;
}