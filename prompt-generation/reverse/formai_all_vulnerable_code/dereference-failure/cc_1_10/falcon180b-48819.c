//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

int num_vertices; // number of vertices in the graph
int **adj_matrix; // adjacency matrix to represent the graph
int *color_map; // map to store the color assigned to each vertex

void init_graph(int n) {
    num_vertices = n;
    adj_matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        adj_matrix[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            adj_matrix[i][j] = 0;
        }
    }
    color_map = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        color_map[i] = -1;
    }
}

void add_edge(int u, int v) {
    adj_matrix[u][v] = 1;
    adj_matrix[v][u] = 1;
}

int is_safe(int v, int c, int u) {
    for (int i = 0; i < num_vertices; i++) {
        if (adj_matrix[v][i] == 1 && color_map[i] == c && i!= u) {
            return 0;
        }
    }
    return 1;
}

int color_graph(int v, int c) {
    if (v >= num_vertices) {
        return 1;
    }
    color_map[v] = c;
    for (int u = 0; u < num_vertices; u++) {
        if (adj_matrix[v][u] == 1) {
            int k = 1;
            while (!is_safe(v, k, u)) {
                k++;
            }
            if (!color_graph(u, k)) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    srand(time(NULL));
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    init_graph(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (rand() % 2 == 1) {
                add_edge(i, j);
            }
        }
    }
    int max_colors = 0;
    for (int i = 0; i < MAX_COLORS; i++) {
        if (color_graph(0, i)) {
            max_colors = i + 1;
            break;
        }
    }
    printf("Chromatic number: %d\n", max_colors);
    return 0;
}