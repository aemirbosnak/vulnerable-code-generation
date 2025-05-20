//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODES 100
#define MAX_EDGES 1000

typedef struct node {
    int id;
    char *label;
    int num_edges;
    int *edges;
} node_t;

typedef struct graph {
    int num_nodes;
    int num_edges;
    node_t *nodes;
} graph_t;

graph_t *create_graph(int num_nodes, int num_edges) {
    graph_t *graph = malloc(sizeof(graph_t));
    graph->num_nodes = num_nodes;
    graph->num_edges = num_edges;
    graph->nodes = malloc(sizeof(node_t) * num_nodes);
    for (int i = 0; i < num_nodes; i++) {
        graph->nodes[i].id = i;
        graph->nodes[i].label = NULL;
        graph->nodes[i].num_edges = 0;
        graph->nodes[i].edges = NULL;
    }
    return graph;
}

void free_graph(graph_t *graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        free(graph->nodes[i].label);
        free(graph->nodes[i].edges);
    }
    free(graph->nodes);
    free(graph);
}

void add_edge(graph_t *graph, int node1, int node2) {
    if (node1 < 0 || node1 >= graph->num_nodes || node2 < 0 || node2 >= graph->num_nodes) {
        return;
    }
    graph->nodes[node1].edges = realloc(graph->nodes[node1].edges, sizeof(int) * (graph->nodes[node1].num_edges + 1));
    graph->nodes[node1].edges[graph->nodes[node1].num_edges++] = node2;
    graph->nodes[node2].edges = realloc(graph->nodes[node2].edges, sizeof(int) * (graph->nodes[node2].num_edges + 1));
    graph->nodes[node2].edges[graph->nodes[node2].num_edges++] = node1;
}

void remove_edge(graph_t *graph, int node1, int node2) {
    if (node1 < 0 || node1 >= graph->num_nodes || node2 < 0 || node2 >= graph->num_nodes) {
        return;
    }
    for (int i = 0; i < graph->nodes[node1].num_edges; i++) {
        if (graph->nodes[node1].edges[i] == node2) {
            graph->nodes[node1].edges[i] = graph->nodes[node1].edges[graph->nodes[node1].num_edges - 1];
            graph->nodes[node1].num_edges--;
            break;
        }
    }
    for (int i = 0; i < graph->nodes[node2].num_edges; i++) {
        if (graph->nodes[node2].edges[i] == node1) {
            graph->nodes[node2].edges[i] = graph->nodes[node2].edges[graph->nodes[node2].num_edges - 1];
            graph->nodes[node2].num_edges--;
            break;
        }
    }
}

void print_graph(graph_t *graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        printf("Node %d: ", i);
        if (graph->nodes[i].label != NULL) {
            printf("%s", graph->nodes[i].label);
        } else {
            printf("Unnamed");
        }
        printf(" (");
        for (int j = 0; j < graph->nodes[i].num_edges; j++) {
            printf("%d, ", graph->nodes[i].edges[j]);
        }
        printf(")\n");
    }
}

int main() {
    graph_t *graph = create_graph(5, 6);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 3);
    add_edge(graph, 2, 4);
    print_graph(graph);
    free_graph(graph);
    return 0;
}