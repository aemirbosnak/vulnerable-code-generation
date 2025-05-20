//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define NAME_LENGTH 30

typedef struct Node {
    char name[NAME_LENGTH];
    struct Node* next;
} Node;

typedef struct Graph {
    int numNodes;
    Node* adjList[MAX_NODES];
} Graph;

Graph* createGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numNodes = 0;
    for (int i = 0; i < MAX_NODES; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

Node* createNode(const char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strncpy(newNode->name, name, NAME_LENGTH - 1);
    newNode->name[NAME_LENGTH - 1] = '\0'; // Ensure null-termination
    newNode->next = NULL;
    return newNode;
}

void addEdge(Graph* graph, const char* source, const char* destination) {
    if (graph->numNodes >= MAX_NODES) {
        printf("Error: Maximum number of nodes reached.\n");
        return;
    }

    int srcIndex = -1;
    int destIndex = -1;

    // Find source node index
    for (int i = 0; i < graph->numNodes; i++) {
        if (graph->adjList[i] != NULL && strcmp(graph->adjList[i]->name, source) == 0) {
            srcIndex = i;
            break;
        }
    }

    // If source not found, add it
    if (srcIndex == -1) {
        srcIndex = graph->numNodes++;
        graph->adjList[srcIndex] = createNode(source);
    }

    // Find destination node index
    for (int i = 0; i < graph->numNodes; i++) {
        if (graph->adjList[i] != NULL && strcmp(graph->adjList[i]->name, destination) == 0) {
            destIndex = i;
            break;
        }
    }

    // If destination not found, add it
    if (destIndex == -1) {
        destIndex = graph->numNodes++;
        graph->adjList[destIndex] = createNode(destination);
    }

    // Add edge from source to destination
    Node* newNode = createNode(destination);
    newNode->next = graph->adjList[srcIndex]->next;
    graph->adjList[srcIndex]->next = newNode;

    // Add edge from destination to source
    newNode = createNode(source);
    newNode->next = graph->adjList[destIndex]->next;
    graph->adjList[destIndex]->next = newNode;
}

void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numNodes; i++) {
        if (graph->adjList[i] != NULL) {
            printf("%s: ", graph->adjList[i]->name);
            Node* temp = graph->adjList[i]->next;
            while (temp != NULL) {
                printf("%s -> ", temp->name);
                temp = temp->next;
            }
            printf("NULL\n");
        }
    }
}

void freeGraph(Graph* graph) {
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

int main() {
    Graph* graph = createGraph();
    addEdge(graph, "Router1", "Switch1");
    addEdge(graph, "Router1", "Switch2");
    addEdge(graph, "Switch1", "PC1");
    addEdge(graph, "Switch1", "PC2");
    addEdge(graph, "Switch2", "Server1");
    
    printf("Network Topology:\n");
    printGraph(graph);
    
    freeGraph(graph);
    return 0;
}