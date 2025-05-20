//MISTRAL-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int vertex;
    int color;
} Vertex;

typedef struct {
    int size;
    int capacity;
    Vertex** data;
} AdjList;

void initializeAdjList(AdjList* adjList, int vertexCount) {
    adjList->size = 0;
    adjList->capacity = vertexCount;
    adjList->data = calloc(vertexCount, sizeof(Vertex*));
    for (int i = 0; i < vertexCount; i++) {
        adjList->data[i] = calloc(2, sizeof(Vertex));
        adjList->data[i][0].vertex = i;
        adjList->data[i][0].color = -1;
    }
}

void addEdge(AdjList* adjList, int source, int destination) {
    adjList->data[source][adjList->size].vertex = destination;
    adjList->data[source][adjList->size].color = -1;
    adjList->size++;
}

bool graphColoringHelper(AdjList* adjList, int vertex, int* color, int maxColors) {
    if (vertex >= adjList->size) {
        return true;
    }

    Vertex* currentVertex = &adjList->data[vertex][0];

    if (currentVertex->color != -1) {
        return (currentVertex->color == color[vertex]);
    }

    for (int i = 0; i < adjList->size; i++) {
        if (adjList->data[vertex][i].vertex != -1 && !graphColoringHelper(adjList, adjList->data[vertex][i].vertex, color, maxColors)) {
            return false;
        }
    }

    currentVertex->color = *color++;
    return graphColoringHelper(adjList, vertex + 1, color, maxColors);
}

bool graphColoring(AdjList* adjList, int vertexCount, int maxColors) {
    if (maxColors > vertexCount) {
        maxColors = vertexCount;
    }

    int* color = calloc(vertexCount, sizeof(int));
    bool result = graphColoringHelper(adjList, 0, color, maxColors);
    free(color);

    return result;
}

void printGraphColoringResult(AdjList* adjList, int vertexCount, int maxColors) {
    if (graphColoring(adjList, vertexCount, maxColors)) {
        printf("Romantic Graph Coloring Solution:\n");
        for (int i = 0; i < vertexCount; i++) {
            Vertex* currentVertex = &adjList->data[i][0];
            printf("Vertex %d has color %d\n", i, currentVertex->color);
        }
    } else {
        printf("Sorry, no romantic graph coloring solution exists for this graph.\n");
    }
}

int main() {
    int vertexCount = 5;

    AdjList graph;
    initializeAdjList(&graph, vertexCount);

    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 3);
    addEdge(&graph, 1, 3);
    addEdge(&graph, 1, 2);
    addEdge(&graph, 2, 3);
    addEdge(&graph, 3, 4);

    printGraphColoringResult(&graph, vertexCount, 3);

    free(graph.data);

    return 0;
}