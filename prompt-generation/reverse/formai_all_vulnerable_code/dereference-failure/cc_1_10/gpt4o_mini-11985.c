//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: scientific
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

Graph* createGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numNodes = 0;
    for (int i = 0; i < MAX_NODES; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

void addNode(Graph* graph, const char* name) {
    if (graph->numNodes >= MAX_NODES) {
        printf("Max nodes limit reached. Cannot add node: %s\n", name);
        return;
    }
    
    if (strcmp(name, "") == 0) {
        printf("Node name cannot be empty.\n");
        return;
    }
    
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    
    graph->adjList[graph->numNodes] = newNode;
    graph->numNodes++;
    
    printf("Node added: %s\n", name);
}

void addEdge(Graph* graph, const char* from, const char* to) {
    int fromIndex = -1, toIndex = -1;
    
    for (int i = 0; i < graph->numNodes; i++) {
        if (strcmp(graph->adjList[i]->name, from) == 0) {
            fromIndex = i;
        }
        if (strcmp(graph->adjList[i]->name, to) == 0) {
            toIndex = i;
        }
    }
    
    if (fromIndex == -1 || toIndex == -1) {
        printf("One or both nodes not found.\n");
        return;
    }
    
    Node* newEdge = (Node*)malloc(sizeof(Node));
    strcpy(newEdge->name, to);
    newEdge->next = graph->adjList[fromIndex]->next;
    graph->adjList[fromIndex]->next = newEdge;
    
    // Uncomment the following lines for undirected graph
    // Node* reverseEdge = (Node*)malloc(sizeof(Node));
    // strcpy(reverseEdge->name, from);
    // reverseEdge->next = graph->adjList[toIndex]->next;
    // graph->adjList[toIndex]->next = reverseEdge;
    
    printf("Edge added from %s to %s\n", from, to);
}

void displayGraph(Graph* graph) {
    printf("\nNetwork Topology:\n");
    for (int i = 0; i < graph->numNodes; i++) {
        Node* temp = graph->adjList[i];
        printf("%s -> ", temp->name);
        
        temp = temp->next;
        while (temp != NULL) {
            printf("%s ", temp->name);
            temp = temp->next;
        }
        printf("\n");
    }
}

void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->numNodes; i++) {
        Node* temp = graph->adjList[i];
        while (temp != NULL) {
            Node* toDelete = temp;
            temp = temp->next;
            free(toDelete);
        }
    }
    free(graph);
}

int main() {
    Graph* graph = createGraph();
    int choice;
    char from[MAX_NAME_LEN], to[MAX_NAME_LEN];
    
    while (1) {
        printf("\nNetwork Topology Mapper\n");
        printf("1. Add Node\n");
        printf("2. Add Edge\n");
        printf("3. Display Topology\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter node name: ");
                scanf("%s", from);
                addNode(graph, from);
                break;
            case 2:
                printf("Enter from node: ");
                scanf("%s", from);
                printf("Enter to node: ");
                scanf("%s", to);
                addEdge(graph, from, to);
                break;
            case 3:
                displayGraph(graph);
                break;
            case 4:
                freeGraph(graph);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}