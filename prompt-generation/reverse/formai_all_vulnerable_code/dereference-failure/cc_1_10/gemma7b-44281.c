//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 10

typedef struct Vertex {
    int index;
    struct Vertex* next;
} Vertex;

void create_graph(Vertex** graph) {
    *graph = (Vertex*)malloc(MAX_VERTICES * sizeof(Vertex));
    for (int i = 0; i < MAX_VERTICES; i++) {
        (*graph)[i].index = -1;
        (*graph)[i].next = NULL;
    }
}

void add_vertex(Vertex** graph, int index) {
    Vertex* new_vertex = (Vertex*)malloc(sizeof(Vertex));
    new_vertex->index = index;
    new_vertex->next = NULL;

    graph[index] = new_vertex;
}

void add_edge(Vertex** graph, int src, int dest) {
    Vertex* src_vertex = graph[src];
    Vertex* dest_vertex = graph[dest];

    src_vertex->next = dest_vertex;
}

void traverse_graph(Vertex** graph) {
    for (int i = 0; i < MAX_VERTICES; i++) {
        Vertex* current_vertex = graph[i];
        if (current_vertex) {
            printf("Vertex %d: ", current_vertex->index);
            Vertex* next_vertex = current_vertex->next;
            while (next_vertex) {
                printf("-> Vertex %d ", next_vertex->index);
                next_vertex = next_vertex->next;
            }
            printf("\n");
        }
    }
}

int main() {
    Vertex** graph;
    create_graph(&graph);

    add_vertex(graph, 0);
    add_vertex(graph, 1);
    add_vertex(graph, 2);
    add_vertex(graph, 3);
    add_vertex(graph, 4);

    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);

    traverse_graph(graph);

    return 0;
}