//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Graph structure
typedef struct {
    int vertices;
    int edges[10];
} graph_t;

// Graph operations
void add_vertex(graph_t* g, int v) {
    if (g->vertices == 10) {
        printf("Error: Graph is full\n");
        return;
    }
    g->vertices++;
    g->edges[g->vertices] = v;
}

void add_edge(graph_t* g, int u, int v) {
    if (u > g->vertices || v > g->vertices) {
        printf("Error: Vertex not found\n");
        return;
    }
    g->edges[u] = v;
}

int degree(graph_t* g, int v) {
    int degree = 0;
    for (int i = 0; i < g->vertices; i++) {
        if (g->edges[i] == v) degree++;
    }
    return degree;
}

// Graph traversal
void dfs(graph_t* g, int start) {
    int i, j;
    for (i = 0; i < g->vertices; i++) {
        if (g->edges[i] == start) {
            printf("Visiting %d\n", i);
            dfs(g, g->edges[i]);
        }
    }
}

int main() {
    graph_t* g = (graph_t*)malloc(sizeof(graph_t));
    g->vertices = 5;
    for (int i = 0; i < 5; i++) {
        g->edges[i] = i + 1;
    }

    add_vertex(g, 6);
    add_edge(g, 0, 6);
    add_edge(g, 1, 6);
    add_edge(g, 2, 6);
    add_edge(g, 3, 6);
    add_edge(g, 4, 6);

    printf("Graph:\n");
    for (int i = 0; i < g->vertices; i++) {
        printf("%d -> ", i + 1);
        for (int j = 0; j < g->edges[i]; j++) {
            printf("%d ", g->edges[i * 2 + j] + 1);
        }
        printf("\n");
    }

    dfs(g, 0);

    free(g);
    return 0;
}