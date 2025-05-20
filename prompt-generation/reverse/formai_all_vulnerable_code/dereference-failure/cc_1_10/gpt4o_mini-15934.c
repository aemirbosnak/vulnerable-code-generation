//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_NAME_LEN 50

typedef struct Node {
    char name[MAX_NAME_LEN];
    struct Node* next;
} Node;

typedef struct Graph {
    int numNodes;
    Node* adjList[MAX_NODES];
} Graph;

Graph* createGraph();
void addNode(Graph* graph, const char* name);
void addEdge(Graph* graph, const char* src, const char* dest);
void displayGraph(Graph* graph);
Node* createNode(const char* name);

int main() {
    Graph* network = createGraph();

    addNode(network, "Router");
    addNode(network, "PC1");
    addNode(network, "PC2");
    addNode(network, "Printer");

    addEdge(network, "Router", "PC1");
    addEdge(network, "Router", "PC2");
    addEdge(network, "PC1", "Printer");

    printf("Network Topology:\n");
    displayGraph(network);

    // Free memory (omitted for brevity)

    return 0;
}

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
    strncpy(newNode->name, name, MAX_NAME_LEN);
    newNode->next = NULL;
    return newNode;
}

void addNode(Graph* graph, const char* name) {
    if (graph->numNodes < MAX_NODES) {
        graph->adjList[graph->numNodes++] = createNode(name);
    } else {
        printf("Max node limit reached!\n");
    }
}

void addEdge(Graph* graph, const char* src, const char* dest) {
    Node* srcNode = NULL;
    Node* destNode = NULL;
    
    for (int i = 0; i < graph->numNodes; i++) {
        if (strcmp(graph->adjList[i]->name, src) == 0) {
            srcNode = graph->adjList[i];
        }
        if (strcmp(graph->adjList[i]->name, dest) == 0) {
            destNode = graph->adjList[i];
        }
    }
    
    if (srcNode && destNode) {
        Node* newDestNode = createNode(dest);
        newDestNode->next = srcNode->next;
        srcNode->next = newDestNode;
    } else {
        printf("Error adding edge: nodes not found.\n");
    }
}

void displayGraph(Graph* graph) {
    for (int i = 0; i < graph->numNodes; i++) {
        Node* current = graph->adjList[i];
        printf("%s -> ", current->name);
        Node* temp = current->next;
        
        while (temp != NULL) {
            printf("%s ", temp->name);
            temp = temp->next;
        }
        printf("\n");
    }
}