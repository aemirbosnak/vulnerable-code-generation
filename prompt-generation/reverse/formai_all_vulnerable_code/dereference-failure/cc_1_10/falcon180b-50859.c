//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_VERTS 1000
#define MAX_EDGES 2000

typedef struct {
    int id;
    int degree;
    int *neighbors;
    double x, y;
} Vertex;

typedef struct {
    int src, dest;
    double weight;
} Edge;

Vertex *vertices;
Edge *edges;
int num_vertices, num_edges;

void init() {
    srand(time(NULL));
    vertices = (Vertex *)malloc(MAX_VERTS * sizeof(Vertex));
    edges = (Edge *)malloc(MAX_EDGES * sizeof(Edge));
    num_vertices = 0;
    num_edges = 0;
}

void add_vertex() {
    Vertex *v = &vertices[num_vertices++];
    v->id = num_vertices - 1;
    v->degree = 0;
    v->neighbors = (int *)malloc(MAX_EDGES * sizeof(int));
    v->x = rand() % 1000;
    v->y = rand() % 1000;
}

int find_vertex(char *name) {
    int i;
    for (i = 0; i < num_vertices; i++) {
        if (strcmp(vertices[i].id, name) == 0) {
            return i;
        }
    }
    return -1;
}

void add_edge(int src, int dest, double weight) {
    Edge *e = &edges[num_edges++];
    e->src = src;
    e->dest = dest;
    e->weight = weight;
    vertices[src].degree++;
    vertices[dest].degree++;
}

void print_graph() {
    int i, j;
    for (i = 0; i < num_vertices; i++) {
        printf("%s (%d neighbors): ", vertices[i].id, vertices[i].degree);
        for (j = 0; j < vertices[i].degree; j++) {
            printf("%d ", vertices[i].neighbors[j]);
        }
        printf("\n");
    }
}

int main() {
    init();
    add_vertex();
    add_vertex();
    add_vertex();
    add_edge(0, 1, 1.0);
    add_edge(1, 2, 2.0);
    print_graph();
    return 0;
}