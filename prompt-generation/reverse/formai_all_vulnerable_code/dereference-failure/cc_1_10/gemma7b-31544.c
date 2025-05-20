//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

typedef struct Vertex {
    int index;
    struct Vertex* next;
} Vertex;

void create_graph(Vertex** graph) {
    *graph = (Vertex*)malloc(sizeof(Vertex) * MAX_VERTICES);
    for (int i = 0; i < MAX_VERTICES; i++) {
        (*graph)[i].index = -1;
        (*graph)[i].next = NULL;
    }
}

void add_vertex(Vertex** graph, int index) {
    (*graph)[index].index = index;
    (*graph)[index].next = NULL;
}

void add_edge(Vertex** graph, int src, int dest) {
    Vertex* vertex = (Vertex*)malloc(sizeof(Vertex));
    vertex->index = dest;
    vertex->next = NULL;
    (*graph)[src].next = vertex;
}

void traverse_graph(Vertex** graph) {
    for (int i = 0; i < MAX_VERTICES; i++) {
        if ((*graph)[i].index != -1) {
            printf("Vertex %d: ", (*graph)[i].index);
            Vertex* current = (*graph)[i].next;
            while (current) {
                printf("-> Vertex %d ", current->index);
                current = current->next;
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
    add_edge(graph, 0, 1);
    add_edge(graph, 1, 2);
    add_edge(graph, 2, 3);
    traverse_graph(graph);

    return 0;
}