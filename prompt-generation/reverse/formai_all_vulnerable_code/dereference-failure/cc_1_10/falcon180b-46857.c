//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_VERTEX 100
#define MAX_EDGE 200

typedef struct {
    int vertex;
    int weight;
    struct node* next;
} Edge;

typedef struct {
    int vertex;
    int inDegree;
    bool visited;
    struct node* edges;
} Vertex;

typedef struct {
    Vertex* vertices;
    int numVertices;
} Graph;

Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->vertices = (Vertex*) malloc(sizeof(Vertex) * numVertices);
    for (int i = 0; i < numVertices; i++) {
        graph->vertices[i].vertex = i;
        graph->vertices[i].inDegree = 0;
        graph->vertices[i].visited = false;
        graph->vertices[i].edges = NULL;
    }
    return graph;
}

void addEdge(Graph* graph, int from, int to, int weight) {
    Edge* edge = (Edge*) malloc(sizeof(Edge));
    edge->vertex = to;
    edge->weight = weight;
    edge->next = graph->vertices[from].edges;
    graph->vertices[from].edges = edge;
    graph->vertices[to].inDegree++;
}

void topologicalSort(Graph* graph) {
    int count = 0;
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->vertices[i].inDegree == 0) {
            printf("%d ", i);
            count++;
        }
    }
    printf("\n");
    if (count!= graph->numVertices) {
        printf("The graph is not a directed acyclic graph.\n");
    }
}

int main() {
    Graph* graph = createGraph(6);
    addEdge(graph, 0, 1, 1);
    addEdge(graph, 0, 2, 2);
    addEdge(graph, 1, 3, 1);
    addEdge(graph, 2, 1, 1);
    addEdge(graph, 2, 3, 1);
    addEdge(graph, 2, 4, 2);
    addEdge(graph, 3, 4, 1);
    addEdge(graph, 4, 5, 1);
    topologicalSort(graph);
    return 0;
}