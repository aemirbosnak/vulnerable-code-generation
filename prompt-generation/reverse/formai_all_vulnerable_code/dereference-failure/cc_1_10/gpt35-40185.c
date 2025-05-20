//FormAI DATASET v1.0 Category: Graph representation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

typedef struct Vertex {
    int value;
    int visited;
    struct Edge *edgeList;
} Vertex;

typedef struct Edge {
    struct Vertex *end;
    int weight;
    struct Edge *next;
} Edge;

typedef struct Graph {
    Vertex *vertices;
    int vertexCount;
} Graph;

void addEdge(Vertex *v, Vertex *w, int weight) {
    Edge *edge = (Edge*)malloc(sizeof(Edge));
    edge->end = w;
    edge->weight = weight;
    edge->next = v->edgeList;
    v->edgeList = edge;
}

void printGraph(Graph *G) {
    int i;
    for (i = 0; i < G->vertexCount; i++) {
        printf("%d: ", G->vertices[i].value);
        Edge *e = G->vertices[i].edgeList;
        while (e != NULL) {
            printf("(%d,%d) ", e->end->value, e->weight);
            e = e->next;
        }
        printf("\n");
    }
}

int main() {
    Graph G;
    G.vertexCount = 5;
    G.vertices = (Vertex*)malloc(sizeof(Vertex) * G.vertexCount);
    int i;
    for (i = 0; i < G.vertexCount; i++) {
        G.vertices[i].value = i+1;
        G.vertices[i].visited = 0;
        G.vertices[i].edgeList = NULL;
    }
    
    addEdge(&G.vertices[0], &G.vertices[1], 7);
    addEdge(&G.vertices[0], &G.vertices[2], 9);
    addEdge(&G.vertices[0], &G.vertices[5], 14);
    addEdge(&G.vertices[1], &G.vertices[2], 10);
    addEdge(&G.vertices[1], &G.vertices[3], 15);
    addEdge(&G.vertices[2], &G.vertices[5], 2);
    addEdge(&G.vertices[2], &G.vertices[3], 11);
    addEdge(&G.vertices[5], &G.vertices[4], 9);
    addEdge(&G.vertices[3], &G.vertices[4], 6);
    
    printf("Graph:\n");
    printGraph(&G);
    return 0;
}