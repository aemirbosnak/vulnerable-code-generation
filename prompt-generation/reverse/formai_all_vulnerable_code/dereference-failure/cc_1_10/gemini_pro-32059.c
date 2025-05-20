//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_VERTICES 100

typedef struct {
    int n;
    int m;
    int graph[MAX_VERTICES][MAX_VERTICES];
    int colors[MAX_VERTICES];
} Graph;

Graph* create_graph(int n, int m) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->n = n;
    graph->m = m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph->graph[i][j] = 0;
        }
    }
    return graph;
}

void add_edge(Graph* graph, int u, int v) {
    graph->graph[u][v] = 1;
    graph->graph[v][u] = 1;
}

int is_safe(Graph* graph, int vertex, int color) {
    for (int i = 0; i < graph->n; i++) {
        if (graph->graph[vertex][i] && graph->colors[i] == color) {
            return 0;
        }
    }
    return 1;
}

int graph_color(Graph* graph, int vertex) {
    if (vertex == graph->n) {
        return 1;
    }

    for (int color = 1; color <= graph->n; color++) {
        if (is_safe(graph, vertex, color)) {
            graph->colors[vertex] = color;
            if (graph_color(graph, vertex + 1)) {
                return 1;
            }
            graph->colors[vertex] = 0;
        }
    }

    return 0;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    Graph* graph = create_graph(n, m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(graph, u, v);
    }

    if (graph_color(graph, 0)) {
        printf("The graph can be colored with %d colors.\n", graph->n);
        for (int i = 0; i < graph->n; i++) {
            printf("Vertex %d is colored with color %d.\n", i, graph->colors[i]);
        }
    } else {
        printf("The graph cannot be colored with %d colors.\n", graph->n);
    }

    free(graph);
    return 0;
}