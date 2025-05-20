//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GRAPH_SIZE 100

struct graph {
    int vertex_count;
    int* edges;
    int* neighbors;
};

void initialize_graph(struct graph* graph, int vertex_count) {
    graph->vertex_count = vertex_count;
    graph->edges = (int*)malloc(vertex_count * sizeof(int));
    graph->neighbors = (int*)malloc(vertex_count * sizeof(int));
    for (int i = 0; i < vertex_count; i++) {
        graph->edges[i] = -1;
        graph->neighbors[i] = NULL;
    }
}

void add_edge(struct graph* graph, int v1, int v2) {
    graph->edges[v1] = v2;
    graph->neighbors[v2] = v1;
}

void print_graph(struct graph* graph) {
    for (int i = 0; i < graph->vertex_count; i++) {
        printf("Vertex %d: ", i);
        for (int j = 0; j < graph->vertex_count; j++) {
            if (graph->edges[i] == j) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int vertex_count = 4;
    struct graph graph;
    initialize_graph(&graph, vertex_count);
    add_edge(&graph, 0, 1);
    add_edge(&graph, 1, 2);
    add_edge(&graph, 2, 0);
    add_edge(&graph, 0, 3);
    print_graph(&graph);
    return 0;
}