//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define MAX_VERTICES 100
#define MAX_EDGES 100

struct vertex {
    int vertex_id;
    struct vertex *next;
};

struct vertex *vertices[MAX_VERTICES];
int vertex_count = 0;

struct edge {
    int src_vertex;
    int dest_vertex;
};

struct edge *edges[MAX_EDGES];
int edge_count = 0;

void add_vertex(int vertex_id) {
    struct vertex *new_vertex = (struct vertex *)malloc(sizeof(struct vertex));
    new_vertex->vertex_id = vertex_id;
    new_vertex->next = vertices[vertex_count];
    vertices[vertex_count] = new_vertex;
    vertex_count++;
}

void add_edge(int src_vertex, int dest_vertex) {
    struct edge *new_edge = (struct edge *)malloc(sizeof(struct edge));
    new_edge->src_vertex = src_vertex;
    new_edge->dest_vertex = dest_vertex;
    edges[edge_count] = new_edge;
    edge_count++;
}

void print_vertices() {
    for (int i = 0; i < vertex_count; i++) {
        printf("Vertex %d: ", i);
        struct vertex *vertex = vertices[i];
        while (vertex!= NULL) {
            printf("%d -> ", vertex->vertex_id);
            vertex = vertex->next;
        }
        printf("\n");
    }
}

void print_edges() {
    for (int i = 0; i < edge_count; i++) {
        printf("Edge %d: ", i);
        struct edge *edge = edges[i];
        printf("Source: %d -> Destination: %d\n", edge->src_vertex, edge->dest_vertex);
    }
}

int main() {
    add_vertex(1);
    add_vertex(2);
    add_vertex(3);

    add_edge(1, 2);
    add_edge(2, 3);

    print_vertices();
    print_edges();

    return 0;
}