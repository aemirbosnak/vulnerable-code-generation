//FormAI DATASET v1.0 Category: Graph representation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct GraphNode {
    int vertex;
    struct GraphNode* next;
} GraphNode;

typedef struct Graph {
    int numVertices;
    GraphNode** adjList;
} Graph;

GraphNode* createGraphNode(int vertex);
Graph* createGraph(int numVertices);
void addEdge(Graph* graph, int srcVertex, int destVertex);
void displayGraph(Graph* graph);

int main() {
    int numVertices;

    printf("Enter number of vertices: ");
    scanf("%d", &numVertices);

    Graph* graph = createGraph(numVertices);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    displayGraph(graph);

    return 0;
}

// Create a new node for the graph
GraphNode* createGraphNode(int vertex) {
    GraphNode* newNode = malloc(sizeof(GraphNode));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Create a new graph with numVertices nodes
Graph* createGraph(int numVertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = numVertices;

    graph->adjList = malloc(sizeof(GraphNode*) * numVertices);

    int i;
    for (i = 0; i < numVertices; i++) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

// Add an undirected edge between two vertices of the graph
void addEdge(Graph* graph, int srcVertex, int destVertex) {
    GraphNode* newNode = createGraphNode(destVertex);
    newNode->next = graph->adjList[srcVertex];
    graph->adjList[srcVertex] = newNode;

    newNode = createGraphNode(srcVertex);
    newNode->next = graph->adjList[destVertex];
    graph->adjList[destVertex] = newNode;
}

// Display the graph
void displayGraph(Graph* graph) {
    int v;
    for (v = 0; v < graph->numVertices; v++) {
        GraphNode* temp = graph->adjList[v];
        printf("Adjacency list of vertex %d:\n", v);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}