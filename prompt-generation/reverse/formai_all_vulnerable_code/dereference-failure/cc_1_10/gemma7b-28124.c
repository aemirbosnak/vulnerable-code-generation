//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 10

typedef struct Vertex {
    int index;
    struct Vertex* next;
    char name[20];
    int visited;
} Vertex;

typedef struct Graph {
    Vertex**adjList;
    int numVertices;
} Graph;

Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjList = (Vertex**)malloc(numVertices * sizeof(Vertex*));
    for (int i = 0; i < numVertices; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

void addVertex(Graph* graph, char* name) {
    Vertex* vertex = (Vertex*)malloc(sizeof(Vertex));
    vertex->index = graph->numVertices++;
    vertex->next = NULL;
    strcpy(vertex->name, name);
    vertex->visited = 0;
    graph->adjList[vertex->index] = vertex;
}

void addEdge(Graph* graph, int src, int dest) {
    Vertex* source = graph->adjList[src];
    Vertex* destination = graph->adjList[dest];
    source->next = destination;
}

void traverseGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Vertex* vertex = graph->adjList[i];
        if (!vertex->visited) {
            vertex->visited = 1;
            printf("Visiting vertex %s\n", vertex->name);
            traverseGraph(graph);
        }
    }
}

int main() {
    Graph* graph = createGraph(5);
    addVertex(graph, "A");
    addVertex(graph, "B");
    addVertex(graph, "C");
    addVertex(graph, "D");
    addVertex(graph, "E");
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 0);

    traverseGraph(graph);

    return 0;
}