//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100

typedef struct Node {
    char name[50];
    struct Node *next;
} Node;

typedef struct Graph {
    int numNodes;
    Node *adjList[MAX_NODES];
} Graph;

Graph* createGraph() {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numNodes = 0;
    for (int i = 0; i < MAX_NODES; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

void addNode(Graph *graph, const char *nodeName) {
    if (graph->numNodes >= MAX_NODES) {
        printf("Cannot add more nodes, maximum limit reached.\n");
        return;
    }
    strcpy(graph->adjList[graph->numNodes]->name, nodeName);
    graph->adjList[graph->numNodes] = (Node *)malloc(sizeof(Node));
    graph->adjList[graph->numNodes]->next = NULL;
    graph->numNodes++;
    printf("Node %s added.\n", nodeName);
}

void addConnection(Graph *graph, const char *nodeA, const char *nodeB) {
    int idxA = -1, idxB = -1;
    
    // Find indices of the nodes
    for (int i = 0; i < graph->numNodes; i++) {
        if (strcmp(graph->adjList[i]->name, nodeA) == 0) {
            idxA = i;
        }
        if (strcmp(graph->adjList[i]->name, nodeB) == 0) {
            idxB = i;
        }
    }
    
    if (idxA == -1 || idxB == -1) {
        printf("Error: One or both nodes do not exist.\n");
        return;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->name, nodeB);
    newNode->next = graph->adjList[idxA]->next;
    graph->adjList[idxA]->next = newNode;

    newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->name, nodeA);
    newNode->next = graph->adjList[idxB]->next;
    graph->adjList[idxB]->next = newNode;

    printf("Connection established between %s and %s.\n", nodeA, nodeB);
}

void displayNetwork(Graph *graph) {
    for (int i = 0; i < graph->numNodes; i++) {
        Node *ptr = graph->adjList[i];
        printf("Node %s is connected to: ", ptr->name);
        ptr = ptr->next;
        while (ptr != NULL) {
            printf("%s ", ptr->name);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

void freeGraph(Graph *graph) {
    for (int i = 0; i < graph->numNodes; i++) {
        Node *ptr = graph->adjList[i];
        Node *temp;
        while (ptr != NULL) {
            temp = ptr;
            ptr = ptr->next;
            free(temp);
        }
    }
    free(graph);
}

int main() {
    Graph *network = createGraph();
    int choice;
    char node1[50], node2[50];

    while (1) {
        printf("1. Add Node\n2. Add Connection\n3. Display Network\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter node name: ");
                scanf("%s", node1);
                addNode(network, node1);
                break;
            case 2:
                printf("Enter first node name: ");
                scanf("%s", node1);
                printf("Enter second node name: ");
                scanf("%s", node2);
                addConnection(network, node1, node2);
                break;
            case 3:
                displayNetwork(network);
                break;
            case 4:
                freeGraph(network);
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}