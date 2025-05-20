//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct graph {
    int num_vertices;
    int num_edges;
    int **adj_matrix;
} graph;

typedef struct color {
    int value;
    bool used;
} color;

bool is_safe(graph *g, int vertex, color *colors, int color) {
    for (int i = 0; i < g->num_vertices; i++) {
        if (g->adj_matrix[vertex][i] && colors[i].value == color) {
            return false;
        }
    }
    return true;
}

bool color_graph(graph *g, color *colors, int vertex) {
    if (vertex == g->num_vertices) {
        return true;
    }

    for (int i = 0; i < g->num_vertices; i++) {
        if (!colors[i].used && is_safe(g, vertex, colors, colors[i].value)) {
            colors[i].used = true;
            colors[vertex].value = colors[i].value;
            if (color_graph(g, colors, vertex + 1)) {
                return true;
            }
            colors[i].used = false;
        }
    }

    return false;
}

void print_graph(graph *g) {
    for (int i = 0; i < g->num_vertices; i++) {
        for (int j = 0; j < g->num_vertices; j++) {
            printf("%d ", g->adj_matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    graph g = {
        .num_vertices = 4,
        .num_edges = 4,
        .adj_matrix = (int **)malloc(sizeof(int *) * g.num_vertices)
    };

    for (int i = 0; i < g.num_vertices; i++) {
        g.adj_matrix[i] = (int *)malloc(sizeof(int) * g.num_vertices);
    }

    g.adj_matrix[0][1] = 1;
    g.adj_matrix[0][2] = 1;
    g.adj_matrix[1][2] = 1;
    g.adj_matrix[2][3] = 1;

    color colors[4] = {
        {0, false},
        {1, false},
        {2, false},
        {3, false}
    };

    if (color_graph(&g, colors, 0)) {
        printf("Graph is colored successfully.\n");
        for (int i = 0; i < g.num_vertices; i++) {
            printf("Vertex %d is colored %d\n", i, colors[i].value);
        }
    } else {
        printf("Graph cannot be colored.\n");
    }

    return 0;
}