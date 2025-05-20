//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 50

typedef struct Node {
    int id;
    char name[20];
    struct Node* next;
} Node;

typedef struct Graph {
    int numNodes;
    Node* adjList[MAX_NODES];
} Graph;

Graph* createGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numNodes = 0;
    for (int i = 0; i < MAX_NODES; i++)
        graph->adjList[i] = NULL;
    return graph;
}

void addNode(Graph* graph, int id, const char* name) {
    if (graph->numNodes >= MAX_NODES) {
        printf("Maximum number of nodes reached.\n");
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->next = NULL;
    graph->adjList[id] = newNode;
    graph->numNodes++;
}

void addEdge(Graph* graph, int src, int dest) {
    if (src < 0 || src >= MAX_NODES || dest < 0 || dest >= MAX_NODES) {
        printf("Invalid edge!\n");
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->id = dest;
    strcpy(newNode->name, graph->adjList[dest]->name);
    newNode->next = graph->adjList[src]->next;
    graph->adjList[src]->next = newNode;

    // Uncomment the following lines for an undirected graph
    // Node* newNodeRev = (Node*)malloc(sizeof(Node));
    // newNodeRev->id = src;
    // strcpy(newNodeRev->name, graph->adjList[src]->name);
    // newNodeRev->next = graph->adjList[dest]->next;
    // graph->adjList[dest]->next = newNodeRev;
}

void displayGraph(Graph* graph) {
    for (int i = 0; i < MAX_NODES; i++) {
        if (graph->adjList[i] != NULL) {
            printf("Node %d (%s):", i, graph->adjList[i]->name);
            Node* temp = graph->adjList[i]->next;
            while (temp) {
                printf(" -> %d (%s)", temp->id, temp->name);
                temp = temp->next;
            }
            printf("\n");
        }
    }
}

void removeEdge(Graph* graph, int src, int dest) {
    Node* temp = graph->adjList[src];
    Node* prev = NULL;
    while (temp != NULL && temp->id != dest) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Edge not found!\n");
        return;
    }
    if (prev == NULL) {
        graph->adjList[src]->next = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
}

void freeGraph(Graph* graph) {
    for (int i = 0; i < MAX_NODES; i++) {
        Node* temp = graph->adjList[i];
        while (temp != NULL) {
            Node* next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(graph);
}

int main() {
    Graph* g = createGraph();
    
    addNode(g, 0, "Router");
    addNode(g, 1, "PC1");
    addNode(g, 2, "PC2");
    addNode(g, 3, "Switch");

    printf("Adding edges...\n");
    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 3);
    addEdge(g, 2, 3);
    
    displayGraph(g);

    printf("Removing edge from Router to PC1...\n");
    removeEdge(g, 0, 1);
    displayGraph(g);

    printf("Freeing the graph...\n");
    freeGraph(g);
    
    return 0;
}