//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 10

typedef struct Vertex {
    char name[20];
    int degree;
    struct Vertex **neighbors;
} Vertex;

void create_graph(Vertex **vertices, int num_vertices) {
    for (int i = 0; i < num_vertices; i++) {
        vertices[i] = malloc(sizeof(Vertex));
        vertices[i]->degree = 0;
        vertices[i]->neighbors = NULL;
    }
}

void add_edge(Vertex **vertices, char *src, char *dest) {
    Vertex *src_vertex = NULL;
    Vertex *dest_vertex = NULL;

    for (int i = 0; i < vertices[0]->degree; i++) {
        if (strcmp(vertices[i]->name, src) == 0) {
            src_vertex = vertices[i];
        }
    }

    for (int i = 0; i < vertices[0]->degree; i++) {
        if (strcmp(vertices[i]->name, dest) == 0) {
            dest_vertex = vertices[i];
        }
    }

    if (src_vertex && dest_vertex) {
        src_vertex->neighbors = realloc(src_vertex->neighbors, (src_vertex->degree + 1) * sizeof(Vertex *));
        src_vertex->neighbors[src_vertex->degree++] = dest_vertex;
    }
}

void print_topology(Vertex **vertices) {
    for (int i = 0; i < vertices[0]->degree; i++) {
        printf("%s -> %s\n", vertices[i]->name, vertices[i]->neighbors[0]->name);
    }
}

int main() {
    Vertex **vertices = NULL;
    int num_vertices = MAX_VERTICES;
    create_graph(&vertices, num_vertices);

    add_edge(vertices, "A", "B");
    add_edge(vertices, "A", "C");
    add_edge(vertices, "B", "D");
    add_edge(vertices, "C", "E");

    print_topology(vertices);

    return 0;
}