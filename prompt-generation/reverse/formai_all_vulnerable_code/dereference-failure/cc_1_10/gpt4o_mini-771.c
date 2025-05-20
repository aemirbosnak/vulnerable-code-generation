//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 10

// Structure for a graph node
typedef struct GraphNode {
    int vertex;
    struct GraphNode* next;
} GraphNode;

// Structure for a graph
typedef struct Graph {
    int numVertices;
    GraphNode** adjLists;
} Graph;

// Function to create a new graph
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(GraphNode*));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

// Function to create a new graph node
GraphNode* createNode(int vertex) {
    GraphNode* newNode = (GraphNode*)malloc(sizeof(GraphNode));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    GraphNode* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function to print the graph
void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        GraphNode* temp = graph->adjLists[i];
        printf("Vertex %d: ", i);
        while (temp) {
            printf("-> %d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Utility function to wait for user input
void pause() {
    char c[2];
    printf("Press enter to continue...");
    fgets(c, sizeof(c), stdin);
}

// Function to visualize the graph using simple ASCII art
void visualizeGraph(Graph* graph) {
    printf("\nGraph Visualization:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        GraphNode* temp = graph->adjLists[i];

        printf("   %d\n", i);

        while (temp) {
            printf("    |  \n   -> %d\n", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    Graph* graph = createGraph(MAX_NODES);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 5);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);
    addEdge(graph, 4, 6);
    addEdge(graph, 5, 6);
    addEdge(graph, 7, 8);

    printGraph(graph);
    pause();
    visualizeGraph(graph);

    // Free the allocated memory
    for (int i = 0; i < graph->numVertices; i++) {
        GraphNode* temp = graph->adjLists[i];
        while (temp) {
            GraphNode* nextNode = temp->next;
            free(temp);
            temp = nextNode;
        }
    }
    free(graph->adjLists);
    free(graph);

    return 0;
}