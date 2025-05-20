//FormAI DATASET v1.0 Category: Graph representation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX_COUNT 10

// Structure for the graph node
typedef struct GraphNode {
    int vertex;
    struct GraphNode* next;
} GraphNode;

// Structure for the graph 
typedef struct Graph {
    int vertexCount;
    GraphNode* adjacencyList[MAX_VERTEX_COUNT];
} Graph;

// Function to create a new graph node
GraphNode* createGraphNode(int vertex) {
    GraphNode* newNode = (GraphNode*)malloc(sizeof(GraphNode));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new graph
Graph* createGraph(int vertexCount) {
    Graph* newGraph = (Graph*)malloc(sizeof(Graph));
    newGraph->vertexCount = vertexCount;
    int i;
    for (i = 0; i < vertexCount; ++i) {
        newGraph->adjacencyList[i] = NULL;
    }
    return newGraph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int startVertex, int endVertex) {
    GraphNode* newNode = createGraphNode(endVertex);
    newNode->next = graph->adjacencyList[startVertex];
    graph->adjacencyList[startVertex] = newNode;
}

// Function to print the graph
void printGraph(Graph* graph) {
    int i;
    for (i = 0; i < graph->vertexCount; ++i) {
        GraphNode* adjacencyList = graph->adjacencyList[i];
        printf("\nVertex %d: ", i);
        while (adjacencyList) {
            printf("%d->", adjacencyList->vertex);
            adjacencyList = adjacencyList->next;
        }
        printf("NULL\n");
    }
}

int main() {
    // Create a new graph
    Graph* graph = createGraph(5);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Print the graph
    printf("\nGraph:\n");
    printGraph(graph);

    return 0;
}