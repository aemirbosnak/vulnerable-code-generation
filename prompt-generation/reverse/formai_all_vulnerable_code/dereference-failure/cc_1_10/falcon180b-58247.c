//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100000
#define MAX_COLORS 100000

int n, m;
int *colors;
int **graph;

void init_graph() {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
}

void init_colors() {
    int i;
    for (i = 0; i < n; i++) {
        colors[i] = -1;
    }
}

int is_valid(int node, int color) {
    int i, j;
    for (i = 0; i < n; i++) {
        if (graph[node][i] == 1 && colors[i] == color) {
            return 0;
        }
    }
    return 1;
}

void color_node(int node, int color) {
    colors[node] = color;
}

void backtrack(int node, int color) {
    int i, j;
    for (i = 0; i < n; i++) {
        if (graph[node][i] == 1) {
            if (colors[i] == -1) {
                color_node(i, color);
            } else if (colors[i]!= color) {
                backtrack(i, color);
            }
        }
    }
}

int main() {
    int i, j;
    scanf("%d %d", &n, &m);
    colors = (int *) malloc(n * sizeof(int));
    graph = (int **) malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        graph[i] = (int *) malloc(n * sizeof(int));
        memset(graph[i], 0, n * sizeof(int));
    }
    init_graph();
    init_colors();
    int num_colors = 0;
    for (i = 0; i < n; i++) {
        if (colors[i] == -1) {
            int color = num_colors++;
            color_node(i, color);
            backtrack(i, color);
        }
    }
    printf("%d\n", num_colors);
    return 0;
}