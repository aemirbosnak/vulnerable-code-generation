//FormAI DATASET v1.0 Category: Graph representation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// structure to represent a graph
struct Graph {
    int V, E;
    struct Edge* edge;
};

// function to create a new graph
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*) malloc(E * sizeof(struct Edge));
    return graph;
}

// function to print the graph
void printGraph(struct Graph* graph) {
    printf("Graph representation:\n");
    for (int i = 0; i < graph->E; i++) {
        printf("(%d,%d) weight=%d\n", graph->edge[i].src, graph->edge[i].dest, graph->edge[i].weight);
    }
}

int main() {
    // create a graph with 4 vertices and 5 edges
    struct Graph* graph = createGraph(4, 5);

    // add edges to the graph
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 10;

    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 6;

    graph->edge[2].src = 0;
    graph->edge[2].dest = 3;
    graph->edge[2].weight = 5;

    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 15;

    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 4;

    // print the graph
    printGraph(graph);

    return 0;
}