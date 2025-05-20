//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

int n; // number of nodes
int **adj_matrix; // adjacency matrix
int *colors; // node colors
int *parent; // parent node for each node

void init() {
    int i;
    n = rand() % MAX_NODES + 1; // randomly generate number of nodes
    adj_matrix = (int **) malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        adj_matrix[i] = (int *) malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            if (rand() % 2 == 0) { // randomly generate edges
                adj_matrix[i][j] = rand() % 100 + 1;
            } else {
                adj_matrix[i][j] = 0;
            }
        }
    }
    colors = (int *) malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        colors[i] = -1;
    }
    parent = (int *) malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        parent[i] = -1;
    }
}

void print_solution() {
    int i;
    printf("Node colors:\n");
    for (i = 0; i < n; i++) {
        printf("%d: %d\n", i, colors[i]);
    }
}

int is_valid(int node, int color) {
    int i;
    for (i = 0; i < n; i++) {
        if (adj_matrix[node][i]!= 0 && colors[i] == color) {
            return 0;
        }
    }
    return 1;
}

void color_graph(int node, int color) {
    int i;
    colors[node] = color;
    for (i = 0; i < n; i++) {
        if (adj_matrix[node][i]!= 0 && colors[i] == -1) {
            parent[i] = node;
        }
    }
}

int find_parent(int node) {
    if (parent[node] == -1) {
        return node;
    } else {
        return find_parent(parent[node]);
    }
}

int main() {
    init();
    int start_node = rand() % n;
    int color = rand() % 100 + 1;
    color_graph(start_node, color);
    int curr_node = start_node;
    while (curr_node!= -1) {
        curr_node = find_parent(curr_node);
        int curr_color = colors[curr_node];
        int new_color = (curr_color + 1) % 100;
        if (is_valid(curr_node, new_color)) {
            color_graph(curr_node, new_color);
        } else {
            curr_node = -1;
        }
    }
    print_solution();
    return 0;
}