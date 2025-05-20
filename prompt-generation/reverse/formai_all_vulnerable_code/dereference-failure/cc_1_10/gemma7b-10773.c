//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 10
#define MAX_EDGES 20

typedef struct Edge {
    int src, dest;
    struct Edge* next;
} Edge;

typedef struct Vertex {
    char name[20];
    Edge* edges;
} Vertex;

void mapTopology(Vertex** graph) {
    for (int i = 0; i < MAX_VERTICES; i++) {
        graph[i] = NULL;
    }

    for (int i = 0; i < MAX_EDGES; i++) {
        Edge* edge = malloc(sizeof(Edge));
        edge->src = rand() % MAX_VERTICES;
        edge->dest = rand() % MAX_VERTICES;
        edge->next = NULL;

        Vertex* src = graph[edge->src];
        if (src == NULL) {
            src = graph[edge->src] = malloc(sizeof(Vertex));
            src->name[0] = 'A' + edge->src;
            src->edges = NULL;
        }

        Vertex* dest = graph[edge->dest];
        if (dest == NULL) {
            dest = graph[edge->dest] = malloc(sizeof(Vertex));
            dest->name[0] = 'A' + edge->dest;
            dest->edges = NULL;
        }

        edge->next = src->edges;
        src->edges = edge;
    }
}

int main() {
    Vertex** graph = malloc(sizeof(Vertex*) * MAX_VERTICES);

    mapTopology(graph);

    for (int i = 0; i < MAX_VERTICES; i++) {
        Vertex* vertex = graph[i];
        if (vertex) {
            printf("Vertex: %s\n", vertex->name);
            Edge* edge = vertex->edges;
            while (edge) {
                printf("  Edge to: %s\n", graph[edge->dest]->name);
                edge = edge->next;
            }
        }
    }

    return 0;
}