//FormAI DATASET v1.0 Category: Graph representation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// define the maximum number of vertices in the graph
#define MAX_VERTICES 10

// define the maximum degree of a vertex
#define MAX_DEGREE 10

// define the graph data structure
typedef struct graph {
    int n;  // number of vertices
    int a[MAX_VERTICES][MAX_DEGREE]; // adjacency matrix
} GRAPH;

// function to add an edge between two vertices
void add_edge(GRAPH* g, int u, int v) {
    if (g->n == MAX_VERTICES) {
        printf("Error: graph has too many vertices\n");
        return;
    }
    if (u < 0 || u >= g->n || v < 0 || v >= g->n) {
        printf("Error: invalid vertex index\n");
        return;
    }
    if (g->a[u][MAX_DEGREE-1] != -1 || g->a[v][MAX_DEGREE-1] != -1) {
        printf("Error: vertex degree too high\n");
        return;
    }
    int i;
    for (i = 0; i < MAX_DEGREE; i++) {
        if (g->a[u][i] == -1) {
            g->a[u][i] = v;
            break;
        }
    }
    for (i = 0; i < MAX_DEGREE; i++) {
        if (g->a[v][i] == -1) {
            g->a[v][i] = u;
            break;
        }
    }
}

// function to print the graph
void print_graph(GRAPH* g) {
    int i, j;
    for (i = 0; i < g->n; i++) {
        printf("Vertex %d: ", i);
        for (j = 0; j < MAX_DEGREE; j++) {
            if (g->a[i][j] != -1) {
                printf("%d ", g->a[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    // create a new graph
    GRAPH* g = (GRAPH*) malloc(sizeof(GRAPH));
    g->n = 0;
    int i, j;
    for (i = 0; i < MAX_VERTICES; i++) {
        for (j = 0; j < MAX_DEGREE; j++) {
            g->a[i][j] = -1;
        }
    }
    // add some edges to the graph
    add_edge(g, 0, 1);
    add_edge(g, 1, 2);
    add_edge(g, 2, 3);
    add_edge(g, 3, 0);
    // print the graph
    print_graph(g);
    // free the memory used by the graph
    free(g);
    return 0;
}