//MISTRAL-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_VERTICES 100
#define MIN_COLOR 0
#define MAX_COLOR 6

typedef struct {
    int vertex;
    int color;
} vertex_t;

typedef struct {
    int num_vertices;
    int num_edges;
    vertex_t* vertices;
} graph_t;

void print_graph(graph_t* g) {
    printf("Graph with %d vertices and %d edges:\n", g->num_vertices, g->num_edges);
    for (int i = 0; i < g->num_vertices; i++) {
        printf("Vertex %d is colored %d\n", g->vertices[i].vertex, g->vertices[i].color);
    }
}

bool is_valid_color(graph_t* g, int vertex, int color) {
    for (int i = 0; i < g->num_vertices; i++) {
        if (g->vertices[i].vertex != vertex && g->vertices[i].color == color) {
            return false;
        }
    }
    return true;
}

bool graph_coloring(graph_t* g) {
    if (g->num_vertices == 0) {
        return true;
    }

    int current_vertex = 0;
    for (int color = MIN_COLOR; color <= MAX_COLOR; color++) {
        if (is_valid_color(g, current_vertex, color)) {
            g->vertices[current_vertex].color = color;
            if (graph_coloring(g + 1)) {
                return true;
            }
            g->vertices[current_vertex].color = -1; // backtrack
        }
        current_vertex++;
    }

    return false;
}

void add_edge(graph_t* g, int vertex1, int vertex2) {
    g->vertices[vertex1].vertex = vertex1;
    g->vertices[vertex1].color = -1;
    g->vertices[vertex2].vertex = vertex2;
    g->vertices[vertex2].color = -1;
    g->num_vertices++;
    g->num_edges++;
}

int main() {
    graph_t g = { 0 };

    add_edge(&g, 0, 1);
    add_edge(&g, 1, 2);
    add_edge(&g, 2, 0);
    add_edge(&g, 2, 3);
    add_edge(&g, 3, 3);

    if (graph_coloring(&g)) {
        print_graph(&g);
    } else {
        printf("Graph cannot be colored with given colors.\n");
    }

    return 0;
}