//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_NODES 100

typedef struct Node {
    char name[MAX_NAME_LENGTH];
    struct Node* next;
} Node;

typedef struct Graph {
    int numNodes;
    Node* adjList[MAX_NODES];
} Graph;

Graph* createGraph(int numNodes) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numNodes = numNodes;
    for (int i = 0; i < numNodes; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

Node* createNode(const char* name) {
    Node* newNode = malloc(sizeof(Node));
    strncpy(newNode->name, name, MAX_NAME_LENGTH);
    newNode->next = NULL;
    return newNode;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(graph->adjList[dest]->name);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = createNode(graph->adjList[src]->name);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

void displayGraph(Graph* graph) {
    for (int i = 0; i < graph->numNodes; i++) {
        Node* temp = graph->adjList[i];
        printf("Node %d (%s): ", i, temp->name);
        while (temp != NULL) {
            printf("-> %s ", temp->name);
            temp = temp->next;
        }
        printf("\n");
    }
}

void cleanupGraph(Graph* graph) {
    for (int i = 0; i < graph->numNodes; i++) {
        Node* temp = graph->adjList[i];
        while (temp != NULL) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph);
}

void populateGraph(Graph* graph) {
    const char* names[] = {"NodeA", "NodeB", "NodeC", "NodeD", "NodeE"};
    for (int i = 0; i < graph->numNodes; i++) {
        Node* node = createNode(names[i]);
        graph->adjList[i] = node;
    }

    addEdge(graph, 0, 1); // A-B
    addEdge(graph, 0, 2); // A-C
    addEdge(graph, 1, 2); // B-C
    addEdge(graph, 1, 3); // B-D
    addEdge(graph, 2, 4); // C-E
    addEdge(graph, 3, 4); // D-E
}

int main() {
    printf("Welcome to the Data Structures Visualization Program!\n");
    
    int numNodes = 5;
    Graph* graph = createGraph(numNodes);
    populateGraph(graph);

    printf("\nGraph Representation:\n");
    displayGraph(graph);

    cleanupGraph(graph);
    
    printf("\nThank you for using the Data Structures Visualization Program!\n");

    return 0;
}