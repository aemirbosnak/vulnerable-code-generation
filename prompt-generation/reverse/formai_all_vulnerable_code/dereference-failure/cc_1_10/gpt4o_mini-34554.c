//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_NAME_LENGTH 50

typedef struct Node {
    char name[MAX_NAME_LENGTH];
    int id;
    struct Node* next;
} Node;

typedef struct Graph {
    int numNodes;
    Node* adjacencyList[MAX_NODES];
} Graph;

// Function Prototypes
Graph* createGraph();
void addNode(Graph* graph, const char* name);
void addEdge(Graph* graph, int srcId, int destId);
void displayGraph(Graph* graph);
void freeGraph(Graph* graph);
Node* createNode(const char* name, int id);
void printMenu();
int getNodeById(Graph* graph, const char* name);

int main() {
    Graph* graph = createGraph();
    int choice;
    char name[MAX_NAME_LENGTH];
    int srcId, destId;

    while (1) {
        printMenu();
        scanf("%d", &choice);
        getchar(); // clear the newline character

        switch (choice) {
            case 1:
                printf("Enter node name: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline character
                addNode(graph, name);
                break;

            case 2:
                printf("Enter source node ID: ");
                scanf("%d", &srcId);
                printf("Enter destination node ID: ");
                scanf("%d", &destId);
                addEdge(graph, srcId, destId);
                break;

            case 3:
                displayGraph(graph);
                break;

            case 4:
                freeGraph(graph);
                printf("Exited the program.\n");
                return 0;

            default:
                printf("Invalid option. Please try again.\n");
        }
    }
}

Graph* createGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numNodes = 0;
    for (int i = 0; i < MAX_NODES; i++) {
        graph->adjacencyList[i] = NULL;
    }
    return graph;
}

Node* createNode(const char* name, int id) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->id = id;
    newNode->next = NULL;
    return newNode;
}

void addNode(Graph* graph, const char* name) {
    if (graph->numNodes >= MAX_NODES) {
        printf("Maximum node limit reached!\n");
        return;
    }
    
    graph->adjacencyList[graph->numNodes] = createNode(name, graph->numNodes);
    graph->numNodes++;
    printf("Node '%s' added with ID %d.\n", name, graph->numNodes - 1);
}

void addEdge(Graph* graph, int srcId, int destId) {
    if (srcId >= graph->numNodes || destId >= graph->numNodes) {
        printf("Invalid node ID(s).\n");
        return;
    }

    Node* newNode = createNode(graph->adjacencyList[destId]->name, destId);
    newNode->next = graph->adjacencyList[srcId]->next;
    graph->adjacencyList[srcId]->next = newNode;
    printf("Edge added from node %d to node %d.\n", srcId, destId);
}

void displayGraph(Graph* graph) {
    for (int i = 0; i < graph->numNodes; i++) {
        Node* current = graph->adjacencyList[i];
        printf("Node %d (%s): ", i, current->name);
        current = current->next;
        while (current != NULL) {
            printf("-> %s (ID %d) ", current->name, current->id);
            current = current->next;
        }
        printf("\n");
    }
}

void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->numNodes; i++) {
        Node* current = graph->adjacencyList[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(graph);
}

void printMenu() {
    printf("\n---- Network Topology Mapper ----\n");
    printf("1. Add Node\n");
    printf("2. Add Edge\n");
    printf("3. Display Graph\n");
    printf("4. Exit\n");
    printf("Select an option: ");
}