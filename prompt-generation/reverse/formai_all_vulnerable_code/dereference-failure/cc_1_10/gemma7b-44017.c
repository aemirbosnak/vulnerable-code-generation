//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

typedef struct Vertex {
    int index;
    struct Vertex *neighbors;
} Vertex;

void create_graph(Vertex **graph, int num_vertices) {
    *graph = malloc(sizeof(Vertex) * num_vertices);
    for (int i = 0; i < num_vertices; i++) {
        (*graph)[i].index = i;
        (*graph)[i].neighbors = NULL;
    }
}

void add_edge(Vertex *vertex, int neighbor_index) {
    Vertex *neighbor = malloc(sizeof(Vertex));
    neighbor->index = neighbor_index;
    neighbor->neighbors = vertex->neighbors;
    vertex->neighbors = neighbor;
}

void print_topology(Vertex *vertex) {
    printf("Vertex %d: ", vertex->index);
    for (Vertex *neighbor = vertex->neighbors; neighbor; neighbor = neighbor->neighbors) {
        printf("%d ", neighbor->index);
    }
    printf("\n");
}

int main() {
    Vertex **graph;
    create_graph(&graph, MAX_VERTICES);
    add_edge(graph[0], 1);
    add_edge(graph[0], 2);
    add_edge(graph[1], 2);
    add_edge(graph[1], 3);
    add_edge(graph[2], 3);
    add_edge(graph[2], 4);
    add_edge(graph[3], 4);
    add_edge(graph[3], 5);
    add_edge(graph[4], 5);

    print_topology(graph[0]);
    print_topology(graph[1]);
    print_topology(graph[2]);
    print_topology(graph[3]);
    print_topology(graph[4]);

    return 0;
}