//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_NODES 100

typedef struct {
    int num_edges;
    int **adjacency_list;
} Graph;

Graph create_graph() {
    Graph graph;
    graph.num_edges = 0;
    graph.adjacency_list = (int **) malloc(MAX_NODES * sizeof(int *));
    for (int i = 0; i < MAX_NODES; i++) {
        graph.adjacency_list[i] = (int *) malloc(MAX_NODES * sizeof(int));
    }
    return graph;
}

void destroy_graph(Graph *graph) {
    for (int i = 0; i < graph->num_edges; i++) {
        free(graph->adjacency_list[i]);
    }
    free(graph->adjacency_list);
}

void add_edge(Graph *graph, int src, int dest) {
    if (graph->num_edges >= MAX_NODES) {
        printf("Graph is full\n");
        return;
    }
    graph->adjacency_list[src][graph->num_edges] = dest;
    graph->num_edges++;
}

void print_graph(Graph *graph) {
    for (int i = 0; i < graph->num_edges; i++) {
        for (int j = 0; j < graph->num_edges; j++) {
            printf("%d ", graph->adjacency_list[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Graph graph = create_graph();
    add_edge(&graph, 0, 1);
    add_edge(&graph, 0, 2);
    add_edge(&graph, 1, 3);
    add_edge(&graph, 2, 4);
    add_edge(&graph, 2, 5);
    add_edge(&graph, 3, 6);
    add_edge(&graph, 4, 7);
    add_edge(&graph, 5, 8);
    print_graph(&graph);
    destroy_graph(&graph);
    return 0;
}