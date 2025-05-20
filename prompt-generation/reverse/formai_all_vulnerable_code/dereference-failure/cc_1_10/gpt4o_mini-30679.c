//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100
#define MAX_NAME_LENGTH 50

typedef struct Vertex {
    char name[MAX_NAME_LENGTH];
    struct Vertex* next;
} Vertex;

typedef struct Graph {
    Vertex* vertices[MAX_VERTICES];
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
    int vertexCount;
} Graph;

Graph* createGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertexCount = 0;
    for (int i = 0; i < MAX_VERTICES; i++) {
        graph->vertices[i] = NULL;
        for (int j = 0; j < MAX_VERTICES; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }
    return graph;
}

void addVertex(Graph* graph, const char* name) {
    if (graph->vertexCount >= MAX_VERTICES) {
        printf("The garden of love is full; cannot add more vertices!\n");
        return;
    }
    Vertex* newVertex = (Vertex*)malloc(sizeof(Vertex));
    strncpy(newVertex->name, name, MAX_NAME_LENGTH);
    newVertex->next = NULL;
    graph->vertices[graph->vertexCount] = newVertex;
    graph->vertexCount++;
    printf("The beautiful flower, '%s', has blossomed in our garden!\n", name);
}

void addEdge(Graph* graph, const char* from, const char* to) {
    int fromIndex = -1, toIndex = -1;
    for (int i = 0; i < graph->vertexCount; i++) {
        if (strcmp(graph->vertices[i]->name, from) == 0) {
            fromIndex = i;
        }
        if (strcmp(graph->vertices[i]->name, to) == 0) {
            toIndex = i;
        }
    }
    
    if (fromIndex == -1 || toIndex == -1) {
        printf("Alas, one or both flowers do not exist in our garden.\n");
        return;
    }

    graph->adjacencyMatrix[fromIndex][toIndex] = 1;
    graph->adjacencyMatrix[toIndex][fromIndex] = 1; // undirected graph
    printf("A romantic connection has been forged between '%s' and '%s'.\n", from, to);
}

void printGraph(Graph* graph) {
    printf("\nThe blossoms of our graph love:\n");
    for (int i = 0; i < graph->vertexCount; i++) {
        printf("%s: ", graph->vertices[i]->name);
        for (int j = 0; j < graph->vertexCount; j++) {
            if (graph->adjacencyMatrix[i][j] == 1) {
                printf("%s ", graph->vertices[j]->name);
            }
        }
        printf("\n");
    }
}

void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->vertexCount; i++) {
        free(graph->vertices[i]);
    }
    free(graph);
    printf("Our garden of love has been beautifully dismantled; fare thee well!\n");
}

int main() {
    Graph* loveGraph = createGraph();

    // Adding vertices representing lovers.
    addVertex(loveGraph, "Juliet");
    addVertex(loveGraph, "Romeo");
    addVertex(loveGraph, "Hermia");
    addVertex(loveGraph, "Lysander");

    // Creating romantic edges (relationships)
    addEdge(loveGraph, "Juliet", "Romeo");
    addEdge(loveGraph, "Hermia", "Lysander");
    addEdge(loveGraph, "Juliet", "Hermia");
  
    // Display the graph
    printGraph(loveGraph);

    // Release the memory
    freeGraph(loveGraph);
    return 0;
}