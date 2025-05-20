//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTS 10

typedef struct Vertex {
    int index;
    struct Vertex* next;
    char name[20];
} Vertex;

typedef struct Graph {
    int numVertices;
    Vertex** vertices;
} Graph;

void insertVertex(Graph* graph, char* name) {
    Vertex* newVertex = (Vertex*)malloc(sizeof(Vertex));
    newVertex->index = graph->numVertices++;
    strcpy(newVertex->name, name);
    newVertex->next = NULL;

    if (graph->vertices == NULL) {
        graph->vertices = (Vertex**)malloc(sizeof(Vertex*) * MAX_VERTS);
    }

    graph->vertices[newVertex->index] = newVertex;
}

void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        printf("%s ", graph->vertices[i]->name);
    }

    printf("\n");
}

int main() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = 0;
    graph->vertices = NULL;

    insertVertex(graph, "A");
    insertVertex(graph, "B");
    insertVertex(graph, "C");
    insertVertex(graph, "D");

    printGraph(graph);

    return 0;
}