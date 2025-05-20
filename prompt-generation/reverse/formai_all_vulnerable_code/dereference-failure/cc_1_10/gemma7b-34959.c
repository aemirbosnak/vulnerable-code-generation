//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 10

typedef struct Vertex {
    char name[20];
    int degree;
    struct Edge **edges;
} Vertex;

typedef struct Edge {
    Vertex *source;
    Vertex *destination;
    int weight;
} Edge;

Vertex **graph_create(int numVertices) {
    Vertex **vertices = (Vertex *)malloc(numVertices * sizeof(Vertex));
    for (int i = 0; i < numVertices; i++) {
        vertices[i] = (Vertex *)malloc(sizeof(Vertex));
        vertices[i]->degree = 0;
        vertices[i]->edges = NULL;
    }
    return vertices;
}

void graph_add_edge(Vertex **vertices, Edge **edges, int weight, Vertex *source, Vertex *destination) {
    Edge *newEdge = (Edge *)malloc(sizeof(Edge));
    newEdge->source = source;
    newEdge->destination = destination;
    newEdge->weight = weight;

    source->degree++;
    source->edges = (Edge **)realloc(source->edges, source->degree * sizeof(Edge));
    source->edges[source->degree - 1] = newEdge;

    destination->degree++;
    destination->edges = (Edge **)realloc(destination->edges, destination->degree * sizeof(Edge));
    destination->edges[destination->degree - 1] = newEdge;
}

void graph_print(Vertex **vertices) {
    for (int i = 0; i < MAX_VERTICES; i++) {
        printf("%s has a degree of %d:\n", vertices[i]->name, vertices[i]->degree);
        Edge **edges = vertices[i]->edges;
        if (edges) {
            for (int j = 0; edges[j]; j++) {
                printf("  Edge to %s with weight %d\n", edges[j]->destination->name, edges[j]->weight);
            }
        }
    }
}

int main() {
    Vertex **vertices = graph_create(5);
    Edge **edges = (Edge **)malloc(MAX_VERTICES * MAX_VERTICES * sizeof(Edge));

    graph_add_edge(vertices, edges, 5, vertices[0], vertices[2]);
    graph_add_edge(vertices, edges, 3, vertices[0], vertices[3]);
    graph_add_edge(vertices, edges, 2, vertices[1], vertices[2]);
    graph_add_edge(vertices, edges, 4, vertices[2], vertices[4]);

    graph_print(vertices);

    return 0;
}