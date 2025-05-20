//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_NODES 1000
#define MAX_EDGES 1000

typedef struct graph_t {
    int nodes;
    int edges;
    int **adjacency_list;
} graph_t;

void print_graph(graph_t *g) {
    printf("Nodes: %d, Edges: %d\n", g->nodes, g->edges);
    for (int i = 0; i < g->nodes; i++) {
        printf("Node %d:\n", i);
        for (int j = 0; j < g->edges; j++) {
            printf(" - Adjacency List[%d][%d] = %d\n", i, j, g->adjacency_list[i][j]);
        }
    }
}

int main() {
    graph_t g;
    srand(time(NULL));

    g.nodes = MAX_NODES;
    g.edges = MAX_EDGES;
    g.adjacency_list = (int **)malloc(sizeof(int *) * g.nodes);
    for (int i = 0; i < g.nodes; i++) {
        g.adjacency_list[i] = (int *)malloc(sizeof(int) * g.edges);
    }

    int num_nodes = rand() % MAX_NODES;
    int num_edges = rand() % MAX_EDGES;

    for (int i = 0; i < num_nodes; i++) {
        int node = rand() % g.nodes;
        for (int j = 0; j < num_edges; j++) {
            int edge = rand() % g.nodes;
            g.adjacency_list[node][j] = edge;
        }
    }

    print_graph(&g);

    free(g.adjacency_list);
    free(g.adjacency_list);

    return 0;
}