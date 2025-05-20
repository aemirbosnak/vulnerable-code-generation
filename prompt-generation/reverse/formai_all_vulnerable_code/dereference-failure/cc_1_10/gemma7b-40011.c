//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_Vertices 10

typedef struct Vertex {
    int index;
    struct Vertex* next;
} Vertex;

typedef struct Graph {
    Vertex** graph;
    int numVertices;
} Graph;

void insertVertex(Graph* g) {
    g->numVertices++;
    g->graph = realloc(g->graph, g->numVertices * sizeof(Vertex*));
    g->graph[g->numVertices - 1] = malloc(sizeof(Vertex));
    g->graph[g->numVertices - 1]->index = g->numVertices - 1;
    g->graph[g->numVertices - 1]->next = NULL;
}

void insertEdge(Graph* g, int src, int dest) {
    Vertex* v1 = g->graph[src];
    Vertex* v2 = g->graph[dest];
    v1->next = v2;
    v2->next = v1;
}

void graphColoring(Graph* g) {
    int* colors = malloc(g->numVertices * sizeof(int));
    for (int i = 0; i < g->numVertices; i++) {
        colors[i] = -1;
    }
    for (int i = 0; i < g->numVertices; i++) {
        int available = 1;
        for (Vertex* v = g->graph[i]->next; v; v) {
            if (colors[v->index] == colors[i]) {
                available = 0;
            }
        }
        colors[i] = available ? 1 : -1;
    }
    for (int i = 0; i < g->numVertices; i++) {
        printf("Vertex %d has color %d\n", g->graph[i]->index, colors[i]);
    }
    free(colors);
}

int main() {
    Graph* g = malloc(sizeof(Graph));
    g->graph = NULL;
    g->numVertices = 0;

    insertVertex(g);
    insertVertex(g);
    insertVertex(g);
    insertVertex(g);

    insertEdge(g, 0, 1);
    insertEdge(g, 1, 2);
    insertEdge(g, 2, 3);

    graphColoring(g);

    free(g);

    return 0;
}