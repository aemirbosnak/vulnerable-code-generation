//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_VERTICES 1000
#define MAX_EDGES 2000

typedef struct {
    int id;
    double x, y, z;
} Vertex;

typedef struct {
    int id;
    int v1, v2;
} Edge;

typedef struct {
    int numVertices;
    int numEdges;
    Vertex *vertices;
    Edge *edges;
} Graph;

void generateRandomVertices(Graph *graph, int numVertices) {
    srand(time(NULL));
    graph->numVertices = numVertices;
    graph->vertices = (Vertex *) malloc(numVertices * sizeof(Vertex));
    for (int i = 0; i < numVertices; i++) {
        graph->vertices[i].id = i;
        graph->vertices[i].x = rand() % 1000;
        graph->vertices[i].y = rand() % 1000;
        graph->vertices[i].z = rand() % 1000;
    }
}

void generateRandomEdges(Graph *graph, int numEdges) {
    srand(time(NULL));
    graph->numEdges = numEdges;
    graph->edges = (Edge *) malloc(numEdges * sizeof(Edge));
    for (int i = 0; i < numEdges; i++) {
        int v1 = rand() % graph->numVertices;
        int v2 = rand() % graph->numVertices;
        while (v1 == v2) {
            v2 = rand() % graph->numVertices;
        }
        graph->edges[i].id = i;
        graph->edges[i].v1 = v1;
        graph->edges[i].v2 = v2;
    }
}

void printGraph(Graph *graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        printf("Vertex %d: (%lf, %lf, %lf)\n", graph->vertices[i].id, graph->vertices[i].x, graph->vertices[i].y, graph->vertices[i].z);
    }
    for (int i = 0; i < graph->numEdges; i++) {
        printf("Edge %d: (%d, %d)\n", graph->edges[i].id, graph->edges[i].v1, graph->edges[i].v2);
    }
}

int main() {
    Graph graph;
    generateRandomVertices(&graph, 10);
    generateRandomEdges(&graph, 20);
    printGraph(&graph);
    return 0;
}