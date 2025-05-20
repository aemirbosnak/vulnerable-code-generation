//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct Vertex {
    int index;
    struct Vertex* next;
} Vertex;

void create_topology(Vertex** graph, int num_vertices) {
    *graph = (Vertex*)malloc(sizeof(Vertex) * num_vertices);
    for (int i = 0; i < num_vertices; i++) {
        (*graph)[i].index = i;
        (*graph)[i].next = NULL;
    }
}

void add_edge(Vertex** graph, int src, int dest) {
    Vertex* new_vertex = (Vertex*)malloc(sizeof(Vertex));
    new_vertex->index = dest;
    new_vertex->next = NULL;

    Vertex* current_vertex = graph[src];
    if (current_vertex) {
        current_vertex->next = new_vertex;
    } else {
        graph[src] = new_vertex;
    }
}

void print_topology(Vertex* graph) {
    for (Vertex* vertex = graph; vertex; vertex = vertex->next) {
        printf("%d ", vertex->index);
    }
    printf("\n");
}

int main() {
    int num_vertices = 5;
    Vertex** graph;
    create_topology(&graph, num_vertices);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);
    print_topology(graph[0]);

    return 0;
}