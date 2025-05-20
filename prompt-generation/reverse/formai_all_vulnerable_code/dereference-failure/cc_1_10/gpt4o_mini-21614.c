//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100

typedef struct Node {
    int id;
    char name[50];
    struct Node* next;
} Node;

typedef struct Graph {
    int numNodes;
    Node* adjLists[MAX_NODES];
} Graph;

// Function to create a new node
Node* createNode(int id, const char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
Graph* createGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numNodes = 0;
    for (int i = 0; i < MAX_NODES; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

// Function to add a node to the graph
void addNode(Graph* graph, int id, const char* name) {
    if (graph->numNodes < MAX_NODES) {
        Node* newNode = createNode(id, name);
        graph->adjLists[graph->numNodes++] = newNode;
    }
}

// Function to add an edge between two nodes in the graph
void addEdge(Graph* graph, int srcId, int destId) {
    Node* srcNode = graph->adjLists[srcId];
    Node* destNode = graph->adjLists[destId];

    if (srcNode && destNode) {
        Node* newNode = createNode(destId, destNode->name);
        newNode->next = srcNode->next;
        srcNode->next = newNode;
    }
}

// Function to display the graph
void displayGraph(Graph* graph) {
    for (int i = 0; i < graph->numNodes; i++) {
        Node* temp = graph->adjLists[i];
        printf("Node %d (%s):", temp->id, temp->name);
        temp = temp->next;
        while (temp) {
            printf(" -> %d (%s)", temp->id, temp->name);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Clean up the graph data
void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->numNodes; i++) {
        Node* temp = graph->adjLists[i];
        while (temp) {
            Node* next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(graph);
}

int main() {
    // Create a graph
    Graph* graph = createGraph();

    // Add nodes
    addNode(graph, 0, "Alice");
    addNode(graph, 1, "Bob");
    addNode(graph, 2, "Charlie");
    addNode(graph, 3, "Diana");

    // Add edges
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 1, 3);
    addEdge(graph, 0, 2);

    // Display the graph
    displayGraph(graph);

    // Free graph resources
    freeGraph(graph);
    
    return 0;
}