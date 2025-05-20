//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: secure
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

// A linked list node
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// A graph edge
typedef struct Edge {
    int source;
    int destination;
    int weight;
} Edge;

// A graph
typedef struct Graph {
    int numVertices;
    int numEdges;
    Node **adjLists;
    Edge **edges;
} Graph;

// Create a new graph
Graph* createGraph(int numVertices) {
    Graph *graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->numEdges = 0;
    graph->adjLists = (Node**)malloc(numVertices * sizeof(Node*));
    for (int i = 0; i < numVertices; i++) {
        graph->adjLists[i] = NULL;
    }
    graph->edges = NULL;
    return graph;
}

// Add an edge to the graph
void addEdge(Graph *graph, int source, int destination, int weight) {
    // Check if the vertices are valid
    if (source < 0 || source >= graph->numVertices || destination < 0 || destination >= graph->numVertices) {
        return;
    }

    // Create a new edge
    Edge *edge = (Edge*)malloc(sizeof(Edge));
    edge->source = source;
    edge->destination = destination;
    edge->weight = weight;

    // Add the edge to the list of edges
    graph->edges = (Edge**)realloc(graph->edges, (graph->numEdges + 1) * sizeof(Edge*));
    graph->edges[graph->numEdges++] = edge;

    // Add the edge to the adjacency list of the source vertex
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = destination;
    newNode->next = graph->adjLists[source];
    graph->adjLists[source] = newNode;
}

// Print the graph
void printGraph(Graph *graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        printf("Vertex %d: ", i);
        Node *temp = graph->adjLists[i];
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Free the graph
void freeGraph(Graph *graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node *temp = graph->adjLists[i];
        while (temp != NULL) {
            Node *next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(graph->adjLists);
    free(graph->edges);
    free(graph);
}

// Main function
int main() {
    // Create a graph
    Graph *graph = createGraph(5);

    // Add edges to the graph
    addEdge(graph, 0, 1, 1);
    addEdge(graph, 0, 2, 2);
    addEdge(graph, 1, 2, 3);
    addEdge(graph, 1, 3, 4);
    addEdge(graph, 2, 3, 5);
    addEdge(graph, 3, 4, 6);

    // Print the graph
    printGraph(graph);

    // Free the graph
    freeGraph(graph);

    return 0;
}