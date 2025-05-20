//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct Vertex {
    int index;
    struct Vertex* neighbors;
} Vertex;

Vertex** graph;

void map_topology(int n) {
    graph = (Vertex**)malloc(n * sizeof(Vertex));
    for (int i = 0; i < n; i++) {
        graph[i] = (Vertex*)malloc(sizeof(Vertex));
        graph[i]->index = i;
        graph[i]->neighbors = NULL;
    }
}

void add_neighbor(int v, int neighbor) {
    Vertex* neighbor_vertex = (Vertex*)malloc(sizeof(Vertex));
    neighbor_vertex->index = neighbor;
    neighbor_vertex->neighbors = NULL;
    graph[v]->neighbors = neighbor_vertex;
}

void print_topology(int n) {
    for (int i = 0; i < n; i++) {
        printf("Vertex %d: ", graph[i]->index);
        for (Vertex* neighbor = graph[i]->neighbors; neighbor; neighbor = neighbor->neighbors) {
            printf("Neighbor: %d ", neighbor->index);
        }
        printf("\n");
    }
}

int main() {
    map_topology(5);
    add_neighbor(0, 1);
    add_neighbor(0, 2);
    add_neighbor(1, 2);
    add_neighbor(2, 3);
    add_neighbor(3, 4);
    add_neighbor(4, 0);

    print_topology(5);

    return 0;
}