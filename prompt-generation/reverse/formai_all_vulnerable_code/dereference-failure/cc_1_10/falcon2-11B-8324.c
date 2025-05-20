//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EDGES 100

typedef struct edge {
    int from, to;
    int weight;
} Edge;

typedef struct graph {
    int vertices;
    Edge* edges;
} Graph;

void add_edge(Graph* g, int from, int to, int weight) {
    if (g->vertices == MAX_EDGES) {
        printf("Graph is full, cannot add more edges\n");
        return;
    }

    g->edges[g->vertices].from = from;
    g->edges[g->vertices].to = to;
    g->edges[g->vertices].weight = weight;
    g->vertices++;
}

void print_graph(Graph* g) {
    printf("Vertices: %d\n", g->vertices);
    for (int i = 0; i < g->vertices; i++) {
        printf("Vertex %d: ", i);
        for (int j = 0; j < g->vertices; j++) {
            if (g->edges[i].to == j) {
                printf("%d (%d) ", j, g->edges[i].weight);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    Graph g;
    g.vertices = 5;
    g.edges = (Edge*)malloc(g.vertices * sizeof(Edge));

    add_edge(&g, 0, 1, 5);
    add_edge(&g, 0, 2, 10);
    add_edge(&g, 1, 2, 7);
    add_edge(&g, 1, 3, 9);
    add_edge(&g, 2, 4, 12);
    add_edge(&g, 3, 4, 6);

    print_graph(&g);

    return 0;
}