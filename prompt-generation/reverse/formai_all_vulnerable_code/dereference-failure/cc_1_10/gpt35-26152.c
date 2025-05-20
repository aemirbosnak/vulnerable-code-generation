//FormAI DATASET v1.0 Category: Benchmarking ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_N 100000
#define MAX_M 1000000

// structure to represent a weighted edge in the graph
struct Edge {
    int src, dest, weight;
};

// structure to represent a connected, weighted and undirected graph
struct Graph {
    int V, E;
    struct Edge* edges;
};

// TODO: fill in the implementation for all four benchmarking functions

void benchmark_1() {
    // TODO: implement benchmark_1
}

void benchmark_2() {
    // TODO: implement benchmark_2
}

void benchmark_3() {
    // TODO: implement benchmark_3
}

void benchmark_4() {
    // TODO: implement benchmark_4
}

// TODO: additional helper functions may be needed

int main() {
    struct Graph* graph;
    int n, m, i;

    // TODO: get input values for n and m from user

    // allocate memory for graph
    graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = n;
    graph->E = m;
    graph->edges = (struct Edge*) malloc(graph->E * sizeof(struct Edge));

    // generate random edges with weights between 1 and 100
    srand(time(NULL));
    for (i = 0; i < graph->E; i++) {
        graph->edges[i].src = rand() % graph->V;
        graph->edges[i].dest = rand() % graph->V;
        graph->edges[i].weight = rand() % 100 + 1;
    }

    // TODO: call benchmarking functions and print results

    // free memory
    free(graph->edges);
    free(graph);

    return 0;
}