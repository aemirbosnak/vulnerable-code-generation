//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 10
#define MAX_EDGES 20

typedef struct Edge {
    int src, dst;
    struct Edge* next;
} Edge;

typedef struct Vertex {
    int num;
    struct Vertex* neighbors;
} Vertex;

void create_graph(Vertex* v, Edge** e) {
    v = malloc(sizeof(Vertex) * MAX_VERTICES);
    e = malloc(sizeof(Edge) * MAX_EDGES);

    for (int i = 0; i < MAX_VERTICES; i++) {
        v[i].num = i + 1;
        v[i].neighbors = NULL;
    }

    for (int i = 0; i < MAX_EDGES; i++) {
        e[i] = NULL;
    }

    return;
}

void add_edge(Edge** e, int src, int dst) {
    Edge* new_edge = malloc(sizeof(Edge));
    new_edge->src = src;
    new_edge->dst = dst;
    new_edge->next = NULL;

    *e = new_edge;
}

void print_topology(Vertex* v) {
    for (int i = 0; i < MAX_VERTICES; i++) {
        printf("Vertex %d: ", v[i].num);
        for (Edge* edge = v[i].neighbors; edge; edge = edge->next) {
            printf("-> Vertex %d ", edge->dst);
        }
        printf("\n");
    }
}

int main() {
    Vertex* v = NULL;
    Edge** e = NULL;

    create_graph(v, e);

    add_edge(e, 1, 2);
    add_edge(e, 1, 3);
    add_edge(e, 2, 4);
    add_edge(e, 3, 5);
    add_edge(e, 4, 6);

    print_topology(v);

    return 0;
}