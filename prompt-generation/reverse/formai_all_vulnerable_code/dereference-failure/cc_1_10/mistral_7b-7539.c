//MISTRAL-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100
#define MIN_COLOR 0
#define MAX_COLOR 6

typedef struct {
    int vertex;
    int color;
} AdjList;

typedef struct {
    int num_vertices;
    int num_edges;
    AdjList *adj_list;
} Graph;

void init_graph(Graph *graph) {
    graph->adj_list = (AdjList *) calloc(MAX_VERTICES, sizeof(AdjList));
    graph->num_vertices = 0;
    graph->num_edges = 0;
}

void add_edge(Graph *graph, int u, int v) {
    graph->adj_list[u].vertex = v;
    graph->adj_list[v].vertex = u;
    graph->num_edges++;
}

void free_graph(Graph *graph) {
    free(graph->adj_list);
}

void print_graph(Graph *graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        printf("%d : %d\n", i, graph->adj_list[i].color);
        for (int j = 0; j < graph->num_vertices; j++) {
            if (i == j) continue;
            if (graph->adj_list[i].vertex == j) {
                printf(" -> %d : %d\n", j, graph->adj_list[j].color);
            }
        }
    }
}

void graph_coloring_helper(Graph *graph, int m, int v, int color) {
    if (v >= graph->num_vertices) {
        m++;
        return;
    }

    graph->adj_list[v].color = color;
    for (int i = 0; i < graph->num_vertices; i++) {
        if (graph->adj_list[i].vertex == v) continue;
        if (graph->adj_list[v].color == graph->adj_list[i].color) {
            graph_coloring_helper(graph, m, i, (color + 1) % (MAX_COLOR + 1));
            graph->adj_list[v].color = -1;
            if (m >= MAX_COLOR) {
                printf("Graph cannot be colored with %d colors\n", MAX_COLOR);
                exit(1);
            }
            break;
        }
    }

    graph_coloring_helper(graph, m, v + 1, color);
}

void graph_coloring(Graph *graph) {
    int m = 0;
    graph_coloring_helper(graph, m, 0, 0);
}

int main() {
    Graph g;
    init_graph(&g);

    add_edge(&g, 0, 1);
    add_edge(&g, 0, 2);
    add_edge(&g, 1, 2);
    add_edge(&g, 1, 3);
    add_edge(&g, 2, 3);
    add_edge(&g, 2, 4);
    add_edge(&g, 3, 4);
    add_edge(&g, 4, 5);

    graph_coloring(&g);
    print_graph(&g);

    free_graph(&g);
    return 0;
}