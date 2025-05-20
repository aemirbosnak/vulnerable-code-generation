//FormAI DATASET v1.0 Category: Graph representation ; Style: brave
#include <stdio.h>
#include <stdlib.h>

typedef struct Edge Edge;
typedef struct Vertex Vertex;
typedef struct Graph Graph;

struct Edge {
    Vertex* dest;
    int weight;
    Edge* next;
};

struct Vertex {
    int val;
    Edge* edges;
};

struct Graph {
    Vertex** vertices;
    int size;
};

Edge* createEdge(Vertex* dest, int weight);
void addEdge(Vertex* src, Vertex* dest, int weight);
Vertex* createVertex(int val);
Graph* createGraph(int size);
void printGraph(Graph* graph);

int main() {
    Graph* graph = createGraph(5);
    
    addEdge(graph->vertices[0], graph->vertices[1], 2);
    addEdge(graph->vertices[0], graph->vertices[2], 5);
    addEdge(graph->vertices[1], graph->vertices[2], 1);
    addEdge(graph->vertices[2], graph->vertices[3], 3);
    addEdge(graph->vertices[3], graph->vertices[4], 4);

    printGraph(graph);

    return 0;
}

Edge* createEdge(Vertex* dest, int weight) {
    Edge* edge = (Edge*) malloc(sizeof(Edge));
    edge->dest = dest;
    edge->weight = weight;
    edge->next = NULL;
    return edge;
}

void addEdge(Vertex* src, Vertex* dest, int weight) {
    Edge* edge = createEdge(dest, weight);
    edge->next = src->edges;
    src->edges = edge;
}

Vertex* createVertex(int val) {
    Vertex* vertex = (Vertex*) malloc(sizeof(Vertex));
    vertex->val = val;
    vertex->edges = NULL;
    return vertex;
}

Graph* createGraph(int size) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->vertices = (Vertex**) malloc(sizeof(Vertex*) * size);
    graph->size = size;

    for(int i = 0; i < size; i++) {
        graph->vertices[i] = createVertex(i);
    }

    return graph;
}

void printGraph(Graph* graph) {
    for(int i = 0; i < graph->size; i++) {
        Vertex* vertex = graph->vertices[i];
        printf("%d -> ", vertex->val);
        
        Edge* edge = vertex->edges;
        while(edge != NULL) {
            printf("%d (%d) ", edge->dest->val, edge->weight);
            edge = edge->next;
        }

        printf("\n");
    }
}