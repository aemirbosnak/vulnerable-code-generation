//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_NODES 100
#define MAX_COLOR 10

typedef struct node {
    int node;
    struct node* next;
} node;

typedef struct graph {
    int num_nodes;
    int** adjacency_list;
    int* color;
} graph;

void initialize_graph(graph* g, int num_nodes) {
    g->num_nodes = num_nodes;
    g->adjacency_list = (int**)malloc(num_nodes * sizeof(int*));
    g->color = (int*)malloc(num_nodes * sizeof(int));
    for (int i = 0; i < num_nodes; i++) {
        g->adjacency_list[i] = (int*)malloc(num_nodes * sizeof(int));
        memset(g->adjacency_list[i], 0, num_nodes * sizeof(int));
    }
}

void add_edge(graph* g, int node1, int node2) {
    g->adjacency_list[node1][node2] = 1;
}

int dfs(graph* g, int node, int color) {
    if (g->color[node]!= 0) {
        return 0;
    }

    g->color[node] = color;

    int i;
    for (i = 0; i < g->num_nodes; i++) {
        if (g->adjacency_list[node][i] == 1) {
            if (dfs(g, i, 1 + color) == 0) {
                return 0;
            }
        }
    }

    return 1;
}

int can_color(graph* g, int num_colors) {
    int i;
    for (i = 0; i < g->num_nodes; i++) {
        if (g->color[i] == 0) {
            if (dfs(g, i, 1) == 0) {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    int num_nodes = 6;
    graph g;
    initialize_graph(&g, num_nodes);

    add_edge(&g, 0, 1);
    add_edge(&g, 0, 2);
    add_edge(&g, 1, 2);
    add_edge(&g, 1, 3);
    add_edge(&g, 2, 3);
    add_edge(&g, 2, 4);
    add_edge(&g, 3, 4);

    int num_colors = 3;
    if (can_color(&g, num_colors)) {
        printf("The graph can be colored with %d colors.\n", num_colors);
    } else {
        printf("The graph cannot be colored with %d colors.\n", num_colors);
    }

    return 0;
}