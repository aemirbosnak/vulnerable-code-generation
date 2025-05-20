//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_NAME_LENGTH 20

typedef struct Node {
    char name[MAX_NAME_LENGTH];
    struct Node* next;
} Node;

typedef struct Graph {
    Node* adjacencyList[MAX_NODES];
    int numNodes;
} Graph;

Graph* createGraph();
void addNode(Graph* graph, const char* name);
void addEdge(Graph* graph, const char* src, const char* dest);
void printGraph(Graph* graph);
void DFS(Graph* graph, const char* startNode, int visited[], int level);
void freeGraph(Graph* graph);

int main() {
    Graph* graph = createGraph();
    addNode(graph, "Router1");
    addNode(graph, "Switch1");
    addNode(graph, "Server1");
    addNode(graph, "PC1");
    addNode(graph, "PC2");

    addEdge(graph, "Router1", "Switch1");
    addEdge(graph, "Switch1", "Server1");
    addEdge(graph, "Switch1", "PC1");
    addEdge(graph, "Switch1", "PC2");

    printf("Network Topology:\n");
    printGraph(graph);

    printf("\nDepth-First Search traversal starting from Router1:\n");
    int visited[MAX_NODES] = {0};
    DFS(graph, "Router1", visited, 0);

    freeGraph(graph);
    return 0;
}

Graph* createGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numNodes = 0;
    for (int i = 0; i < MAX_NODES; i++) {
        graph->adjacencyList[i] = NULL;
    }
    return graph;
}

void addNode(Graph* graph, const char* name) {
    if (graph->numNodes < MAX_NODES) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        strncpy(newNode->name, name, MAX_NAME_LENGTH);
        newNode->next = NULL;
        graph->adjacencyList[graph->numNodes++] = newNode;
    } else {
        printf("Cannot add more nodes, maximum limit reached.\n");
    }
}

void addEdge(Graph* graph, const char* src, const char* dest) {
    Node* srcNode = NULL;
    Node* destNode = NULL;
    for (int i = 0; i < graph->numNodes; i++) {
        if (strcmp(graph->adjacencyList[i]->name, src) == 0) {
            srcNode = graph->adjacencyList[i];
        }
        if (strcmp(graph->adjacencyList[i]->name, dest) == 0) {
            destNode = graph->adjacencyList[i];
        }
    }
    if (srcNode && destNode) {
        Node* newEdge = (Node*)malloc(sizeof(Node));
        strncpy(newEdge->name, dest, MAX_NAME_LENGTH);
        newEdge->next = srcNode->next;
        srcNode->next = newEdge;
    } else {
        printf("Error: One or both nodes not found.\n");
    }
}

void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numNodes; i++) {
        Node* temp = graph->adjacencyList[i];
        printf("%s -> ", temp->name);
        temp = temp->next;
        while (temp) {
            printf("%s ", temp->name);
            temp = temp->next;
        }
        printf("\n");
    }
}

void DFS(Graph* graph, const char* startNode, int visited[], int level) {
    int index = -1;
    for (int i = 0; i < graph->numNodes; i++) {
        if (strcmp(graph->adjacencyList[i]->name, startNode) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1 || visited[index]) {
        return;
    }

    visited[index] = 1;
    printf("%*s%s\n", level * 2, "", startNode);

    Node* temp = graph->adjacencyList[index]->next;
    while (temp) {
        DFS(graph, temp->name, visited, level + 1);
        temp = temp->next;
    }
}

void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->numNodes; i++) {
        Node* temp = graph->adjacencyList[i];
        while (temp) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph);
}