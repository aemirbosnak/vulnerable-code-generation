//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 1000
#define MAX_EDGES 10000

typedef struct {
    int node;
    int color;
} AdjList;

int num_nodes, num_edges;
int *graph;
int *colors;

void init_graph() {
    srand(time(NULL));
    num_nodes = rand() % MAX_NODES + 1;
    num_edges = rand() % MAX_EDGES + 1;

    graph = malloc(num_nodes * sizeof(int));
    for (int i = 0; i < num_nodes; i++) {
        graph[i] = rand() % num_nodes;
    }

    colors = malloc(num_nodes * sizeof(int));
    for (int i = 0; i < num_nodes; i++) {
        colors[i] = rand() % 6 + 1;
    }
}

int is_valid(int node, int color) {
    for (int i = 0; i < num_nodes; i++) {
        if (graph[i] == node && colors[i] == color) {
            return 0;
        }
    }
    return 1;
}

int dfs(int node, int color) {
    if (node == -1) {
        return 1;
    }
    if (!is_valid(node, color)) {
        return 0;
    }
    colors[node] = color;
    for (int i = 0; i < num_nodes; i++) {
        if (graph[i] == node) {
            if (!dfs(i, color + 1)) {
                return 0;
            }
        }
    }
    return 1;
}

int color_graph() {
    int start_node = rand() % num_nodes;
    return dfs(start_node, 1);
}

void print_graph() {
    for (int i = 0; i < num_nodes; i++) {
        printf("%d ", colors[i]);
    }
    printf("\n");
}

int main() {
    init_graph();
    int is_colored = color_graph();

    if (is_colored) {
        printf("Colored graph:\n");
        print_graph();
    } else {
        printf("Cannot color graph.\n");
    }

    return 0;
}