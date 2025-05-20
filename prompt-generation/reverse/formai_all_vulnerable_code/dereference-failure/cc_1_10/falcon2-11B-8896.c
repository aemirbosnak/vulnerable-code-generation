//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int node;
    int color;
} Vertex;

typedef struct {
    int num_vertices;
    int num_edges;
    Vertex* vertices;
    int* edge_to;
    int* edge_from;
} Graph;

Graph* create_graph(int num_vertices, int num_edges) {
    Graph* g = (Graph*) malloc(sizeof(Graph));
    g->num_vertices = num_vertices;
    g->num_edges = num_edges;
    g->vertices = (Vertex*) malloc(num_vertices * sizeof(Vertex));
    g->edge_to = (int*) malloc(num_edges * sizeof(int));
    g->edge_from = (int*) malloc(num_edges * sizeof(int));
    return g;
}

void add_edge(Graph* g, int v1, int v2) {
    g->vertices[v1].color = -1;
    g->vertices[v2].color = -1;
    g->edge_to[g->num_edges] = v2;
    g->edge_from[g->num_edges] = v1;
    g->num_edges++;
}

int main() {
    int num_vertices = 5;
    int num_edges = 6;
    Graph* g = create_graph(num_vertices, num_edges);
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 3);
    add_edge(g, 2, 4);
    add_edge(g, 3, 4);

    int num_colors = 2;
    int* colors = (int*) malloc(num_vertices * sizeof(int));
    for (int i = 0; i < num_vertices; i++) {
        colors[i] = -1;
    }

    int color_count[num_colors];
    for (int i = 0; i < num_colors; i++) {
        color_count[i] = 0;
    }

    int result = 0;
    while (result < num_vertices) {
        for (int i = 0; i < num_vertices; i++) {
            if (colors[i] == -1 && (color_count[g->vertices[i].color] < num_colors)) {
                colors[i] = g->vertices[i].color;
                color_count[g->vertices[i].color]++;
                result++;
            }
        }
    }

    if (result == num_vertices) {
        printf("Graph coloring problem is solved.\n");
    } else {
        printf("Graph coloring problem is not solved.\n");
    }

    free(g->vertices);
    free(g->edge_to);
    free(g->edge_from);
    free(g);
    free(colors);

    return 0;
}