//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INITIAL_CAPACITY 10

typedef struct {
    int* data;
    int size;
    int capacity;
} ArrayList;

typedef struct {
    int vertexCount;
    ArrayList* adjacencyList;
} Graph;

ArrayList* createArrayList(int capacity) {
    ArrayList* list = (ArrayList*)malloc(sizeof(ArrayList));
    list->data = (int*)malloc(sizeof(int) * capacity);
    list->size = 0;
    list->capacity = capacity;
    return list;
}

void addEdge(ArrayList* list, int vertex) {
    if (list->size >= list->capacity) {
        list->capacity *= 2;
        list->data = (int*)realloc(list->data, sizeof(int) * list->capacity);
    }
    list->data[list->size++] = vertex;
}

Graph* createGraph(int vertexCount) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertexCount = vertexCount;
    graph->adjacencyList = (ArrayList*)malloc(vertexCount * sizeof(ArrayList));
    
    for (int i = 0; i < vertexCount; i++) {
        graph->adjacencyList[i] = *createArrayList(INITIAL_CAPACITY);
    }
    return graph;
}

void addEdgeGraph(Graph* graph, int src, int dest) {
    addEdge(&graph->adjacencyList[src], dest);
    addEdge(&graph->adjacencyList[dest], src); // For undirected graph
}

void printGraph(Graph* graph) {
    for (int i = 0; i < graph->vertexCount; i++) {
        printf("Vertex %d:", i);
        for (int j = 0; j < graph->adjacencyList[i].size; j++) {
            printf(" -> %d", graph->adjacencyList[i].data[j]);
        }
        printf("\n");
    }
}

void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->vertexCount; i++) {
        free(graph->adjacencyList[i].data);
    }
    free(graph->adjacencyList);
    free(graph);
}

void depthFirstSearchUtil(Graph* graph, int vertex, bool* visited) {
    visited[vertex] = true;
    printf("%d ", vertex);
    
    for (int i = 0; i < graph->adjacencyList[vertex].size; i++) {
        if (!visited[graph->adjacencyList[vertex].data[i]]) {
            depthFirstSearchUtil(graph, graph->adjacencyList[vertex].data[i], visited);
        }
    }
}

void depthFirstSearch(Graph* graph, int startingVertex) {
    bool* visited = (bool*)malloc(graph->vertexCount * sizeof(bool));
    for (int i = 0; i < graph->vertexCount; i++) {
        visited[i] = false;
    }
    printf("Depth First Search starting from vertex %d:\n", startingVertex);
    depthFirstSearchUtil(graph, startingVertex, visited);
    printf("\n");
    free(visited);
}

int main() {
    Graph* graph = createGraph(5);
    
    addEdgeGraph(graph, 0, 1);
    addEdgeGraph(graph, 0, 4);
    addEdgeGraph(graph, 1, 2);
    addEdgeGraph(graph, 1, 3);
    addEdgeGraph(graph, 1, 4);
    addEdgeGraph(graph, 2, 3);
    addEdgeGraph(graph, 3, 4);
    
    printGraph(graph);
    
    depthFirstSearch(graph, 0);

    freeGraph(graph);
    
    return 0;
}