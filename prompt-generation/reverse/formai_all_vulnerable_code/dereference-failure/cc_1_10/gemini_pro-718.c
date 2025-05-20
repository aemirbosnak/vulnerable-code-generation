//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100

typedef struct {
    int num_vertices;
    int num_edges;
    int** adjacency_matrix;
} graph;

typedef struct {
    int vertex;
    int color;
} colored_vertex;

int is_safe(graph* g, colored_vertex* colored_vertices, int vertex, int color) {
    for (int i = 0; i < g->num_vertices; i++) {
        if (g->adjacency_matrix[vertex][i] == 1 && colored_vertices[i].color == color) {
            return 0;
        }
    }
    return 1;
}

int graph_coloring(graph* g, colored_vertex* colored_vertices, int vertex) {
    if (vertex == g->num_vertices) {
        return 1;
    }

    for (int color = 1; color <= g->num_vertices; color++) {
        if (is_safe(g, colored_vertices, vertex, color)) {
            colored_vertices[vertex].color = color;

            if (graph_coloring(g, colored_vertices, vertex + 1)) {
                return 1;
            }

            colored_vertices[vertex].color = 0;
        }
    }

    return 0;
}

void print_solution(colored_vertex* colored_vertices, int num_vertices) {
    for (int i = 0; i < num_vertices; i++) {
        printf("Vertex %d is colored with color %d\n", colored_vertices[i].vertex, colored_vertices[i].color);
    }
}

int main() {
    graph g;

    printf("Enter the number of vertices: ");
    scanf("%d", &g.num_vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &g.num_edges);

    g.adjacency_matrix = (int**)malloc(g.num_vertices * sizeof(int*));
    for (int i = 0; i < g.num_vertices; i++) {
        g.adjacency_matrix[i] = (int*)malloc(g.num_vertices * sizeof(int));
    }

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < g.num_vertices; i++) {
        for (int j = 0; j < g.num_vertices; j++) {
            scanf("%d", &g.adjacency_matrix[i][j]);
        }
    }

    colored_vertex* colored_vertices = (colored_vertex*)malloc(g.num_vertices * sizeof(colored_vertex));
    for (int i = 0; i < g.num_vertices; i++) {
        colored_vertices[i].vertex = i;
        colored_vertices[i].color = 0;
    }

    if (graph_coloring(&g, colored_vertices, 0)) {
        printf("Graph is colorable\n");
        print_solution(colored_vertices, g.num_vertices);
    } else {
        printf("Graph is not colorable\n");
    }

    for (int i = 0; i < g.num_vertices; i++) {
        free(g.adjacency_matrix[i]);
    }
    free(g.adjacency_matrix);
    free(colored_vertices);

    return 0;
}