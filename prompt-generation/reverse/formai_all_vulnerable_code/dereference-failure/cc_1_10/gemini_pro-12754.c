//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_EDGES 1000

typedef struct {
    int id;
    char *name;
    int num_edges;
    int *edges;
} node_t;

typedef struct {
    int num_nodes;
    node_t *nodes;
} graph_t;

graph_t *create_random_graph(int num_nodes, int num_edges) {
    graph_t *graph = malloc(sizeof(graph_t));
    graph->num_nodes = num_nodes;
    graph->nodes = malloc(num_nodes * sizeof(node_t));

    for (int i = 0; i < num_nodes; i++) {
        graph->nodes[i].id = i;
        graph->nodes[i].name = malloc(16 * sizeof(char));
        sprintf(graph->nodes[i].name, "Node %d", i);
        graph->nodes[i].num_edges = 0;
        graph->nodes[i].edges = NULL;
    }

    for (int i = 0; i < num_edges; i++) {
        int node1 = rand() % num_nodes;
        int node2 = rand() % num_nodes;

        if (node1 == node2) {
            continue;
        }

        graph->nodes[node1].edges = realloc(graph->nodes[node1].edges, (graph->nodes[node1].num_edges + 1) * sizeof(int));
        graph->nodes[node1].edges[graph->nodes[node1].num_edges] = node2;
        graph->nodes[node1].num_edges++;
    }

    return graph;
}

void print_graph(graph_t *graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        printf("Node %d: ", graph->nodes[i].id);
        for (int j = 0; j < graph->nodes[i].num_edges; j++) {
            printf("%d ", graph->nodes[i].edges[j]);
        }
        printf("\n");
    }
}

void free_graph(graph_t *graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        free(graph->nodes[i].name);
        free(graph->nodes[i].edges);
    }
    free(graph->nodes);
    free(graph);
}

int main() {
    srand(time(NULL));

    int num_nodes = 10;
    int num_edges = 20;

    graph_t *graph = create_random_graph(num_nodes, num_edges);

    print_graph(graph);

    free_graph(graph);

    return 0;
}