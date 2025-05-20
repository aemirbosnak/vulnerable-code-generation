//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_NAME_LENGTH 20

typedef struct Node {
    char name[MAX_NAME_LENGTH];
    struct Node* next;
} Node;

typedef struct Graph {
    Node* adjacencyList[MAX_NODES];
    int nodeCount;
} Graph;

Graph* createGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->nodeCount = 0;
    for (int i = 0; i < MAX_NODES; i++)
        graph->adjacencyList[i] = NULL;
    return graph;
}

void addNode(Graph* graph, const char* name) {
    if (graph->nodeCount >= MAX_NODES) {
        printf("Graph is full! Cannot add more nodes.\n");
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    graph->adjacencyList[graph->nodeCount++] = newNode;
}

void connectNodes(Graph* graph, int fromIndex, int toIndex) {
    Node* temp = graph->adjacencyList[fromIndex];
    if (!temp) return;

    while (temp->next) {
        temp = temp->next;
    }
    
    Node* newConnection = (Node*)malloc(sizeof(Node));
    strcpy(newConnection->name, graph->adjacencyList[toIndex]->name);
    newConnection->next = NULL;
    temp->next = newConnection;
}

void displayGraph(Graph* graph) {
    printf("Network Topology Map:\n");
    for (int i = 0; i < graph->nodeCount; i++) {
        Node* node = graph->adjacencyList[i];
        if (node) {
            printf("Node %d (%s) connects to: ", i, node->name);
            Node* connection = node->next;
            while (connection) {
                printf("%s ", connection->name);
                connection = connection->next;
            }
            printf("\n");
        }
    }
}

void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->nodeCount; i++) {
        Node* temp = graph->adjacencyList[i];
        while (temp) {
            Node* toDelete = temp;
            temp = temp->next;
            free(toDelete);
        }
    }
    free(graph);
}

int main() {
    srand(time(NULL));

    Graph* network = createGraph();

    const char* nodeNames[] = {
        "Router A", "Router B", "Switch A", "Server A",
        "Workstation A", "Firewall", "Switch B", "Server B"
    };

    // Randomly adding nodes
    for (int i = 0; i < 8; i++) {
        addNode(network, nodeNames[i]);
    }

    // Randomly connecting nodes
    for (int i = 0; i < 20; i++) {
        int from = rand() % 8;
        int to = rand() % 8;
        if (from != to) {
            connectNodes(network, from, to);
        }
    }

    // Display the constructed network topology
    displayGraph(network);

    // Free resources
    freeGraph(network);
    return 0;
}