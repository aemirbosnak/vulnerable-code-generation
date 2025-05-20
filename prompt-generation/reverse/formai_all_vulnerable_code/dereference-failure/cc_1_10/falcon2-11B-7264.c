//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100
#define MAX_COLOURS 10

typedef struct {
    int node;
    int colour;
} node_colour_pair;

typedef struct {
    int num_nodes;
    int num_edges;
    int **adjacency_list;
    int *visited;
    int *graph_colouring;
} graph_t;

void init_graph(graph_t *graph) {
    graph->num_nodes = 0;
    graph->num_edges = 0;
    graph->adjacency_list = NULL;
    graph->visited = NULL;
    graph->graph_colouring = NULL;
}

void add_node(graph_t *graph, int node) {
    graph->num_nodes++;
    graph->visited = (int *)realloc(graph->visited, graph->num_nodes * sizeof(int));
    graph->adjacency_list = (int **)realloc(graph->adjacency_list, graph->num_nodes * sizeof(int *));
    graph->graph_colouring = (int *)realloc(graph->graph_colouring, graph->num_nodes * sizeof(int));
    graph->visited[node] = 0;
    graph->graph_colouring[node] = 0;
    graph->adjacency_list[node] = (int *)malloc(graph->num_nodes * sizeof(int));
}

void add_edge(graph_t *graph, int source, int target) {
    graph->num_edges++;
    graph->adjacency_list[source][graph->num_nodes] = target;
    graph->adjacency_list[target][graph->num_nodes] = source;
}

void print_graph(graph_t *graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        if (graph->visited[i]) {
            printf("Node %d: ", i);
            for (int j = 0; j < graph->num_nodes; j++) {
                if (graph->adjacency_list[i][j]!= 0) {
                    printf("%d ", graph->adjacency_list[i][j]);
                }
            }
            printf("\n");
        }
    }
}

int is_valid_colouring(graph_t *graph, int node, int colour) {
    for (int i = 0; i < graph->num_nodes; i++) {
        if (i!= node && graph->graph_colouring[i] == colour) {
            return 0;
        }
    }
    return 1;
}

void assign_colours(graph_t *graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        graph->graph_colouring[i] = 0;
    }
    int num_unassigned_nodes = graph->num_nodes;
    while (num_unassigned_nodes > 0) {
        for (int i = 0; i < graph->num_nodes; i++) {
            if (graph->visited[i] == 0 && is_valid_colouring(graph, i, num_unassigned_nodes)) {
                graph->graph_colouring[i] = num_unassigned_nodes;
                graph->visited[i] = 1;
                num_unassigned_nodes--;
                break;
            }
        }
    }
}

int main() {
    graph_t graph;
    init_graph(&graph);
    add_node(&graph, 0);
    add_node(&graph, 1);
    add_node(&graph, 2);
    add_edge(&graph, 0, 1);
    add_edge(&graph, 1, 2);
    add_node(&graph, 3);
    add_edge(&graph, 2, 3);
    print_graph(&graph);
    assign_colours(&graph);
    print_graph(&graph);
    return 0;
}