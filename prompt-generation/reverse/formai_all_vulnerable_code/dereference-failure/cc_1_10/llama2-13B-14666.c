//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Graph structure
typedef struct {
    int vertices;   // Number of vertices
    int edges;     // Number of edges
    int *edges_map; // Map of edges (vertex index -> edge index)
    int *vertices_map; // Map of vertices (vertex index -> data)
} Graph;

// Graph operations
void graph_init(Graph *g, int vertices, int edges) {
    g->vertices = vertices;
    g->edges = edges;
    g->edges_map = malloc(edges * sizeof(int));
    g->vertices_map = malloc(vertices * sizeof(int));
    for (int i = 0; i < edges; i++) {
        g->edges_map[i] = -1;
    }
    for (int i = 0; i < vertices; i++) {
        g->vertices_map[i] = -1;
    }
}

void graph_add_edge(Graph *g, int v1, int v2) {
    int edge_index = g->edges_map[v1 * g->edges + v2];
    if (edge_index == -1) {
        edge_index = g->edges++;
        g->edges_map[v1 * g->edges + v2] = edge_index;
    }
    g->vertices_map[edge_index] = v1;
    g->vertices_map[v1 * g->edges + v2] = v2;
}

void graph_print(Graph *g) {
    for (int i = 0; i < g->vertices; i++) {
        if (g->vertices_map[i] != -1) {
            printf("%d -> ", i);
            int j = g->vertices_map[i];
            while (j != -1) {
                printf("%d ", j);
                j = g->vertices_map[j];
            }
            printf("\n");
        }
    }
}

int main() {
    Graph g;
    graph_init(&g, 5, 10);
    graph_add_edge(&g, 0, 1);
    graph_add_edge(&g, 0, 2);
    graph_add_edge(&g, 1, 3);
    graph_add_edge(&g, 2, 3);
    graph_add_edge(&g, 3, 4);
    graph_add_edge(&g, 4, 5);
    graph_print(&g);
    return 0;
}