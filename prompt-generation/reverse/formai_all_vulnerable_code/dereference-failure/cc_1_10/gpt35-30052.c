//FormAI DATASET v1.0 Category: Graph representation ; Style: expert-level
#include<stdio.h>

// Struct to define an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Struct to define a graph
struct Graph {
    int V, E;
    struct Edge* edge;
};

// Function to create a graph
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = malloc(sizeof(struct Edge) * E);
    return graph;
}

// Function to print the graph
void printGraph(struct Graph* graph) {
    for(int i = 0; i < graph->E; i++) {
        printf("(%d -> %d), weight = %d\n", graph->edge[i].src, graph->edge[i].dest, graph->edge[i].weight);
    }
}

// Driver function
int main() {
    int V = 4;
    int E = 5;
    struct Graph* graph = createGraph(V, E);
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
    printGraph(graph);
    return 0;
}