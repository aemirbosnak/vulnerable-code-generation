//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_NODES 20
#define MAX_NAME_LENGTH 30

typedef struct Node {
    char name[MAX_NAME_LENGTH];
    int id;
    struct Node* next;
} Node;

typedef struct Graph {
    Node* nodes[MAX_NODES];
    int adjacencyMatrix[MAX_NODES][MAX_NODES];
    int nodeCount;
} Graph;

// Function declarations
Graph* createGraph();
void addNode(Graph* graph, const char* name);
void addEdge(Graph* graph, int sourceId, int destId);
void displayGraph(Graph* graph);
void vibrateScreen();
void displayMenu();
void clearScreen();

int main() {
    Graph* cyberGraph = createGraph();
    int choice, sourceId, destId;

    while (1) {
        clearScreen();
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                {
                    char name[MAX_NAME_LENGTH];
                    printf("Enter node name: ");
                    scanf("%s", name);
                    addNode(cyberGraph, name);
                }
                break;
            case 2:
                printf("Enter source node ID: ");
                scanf("%d", &sourceId);
                printf("Enter destination node ID: ");
                scanf("%d", &destId);
                addEdge(cyberGraph, sourceId, destId);
                break;
            case 3:
                displayGraph(cyberGraph);
                vibrateScreen();
                break;
            case 4:
                printf("Exiting the Cyberpunk Network...\n");
                free(cyberGraph);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        sleep(1); // Wait for 1 second before showing the menu again
    }

    return 0;
}

Graph* createGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->nodeCount = 0;

    for (int i = 0; i < MAX_NODES; i++) {
        graph->nodes[i] = NULL;
        for (int j = 0; j < MAX_NODES; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }
    return graph;
}

void addNode(Graph* graph, const char* name) {
    if (graph->nodeCount < MAX_NODES) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        strncpy(newNode->name, name, MAX_NAME_LENGTH);
        newNode->id = graph->nodeCount;
        newNode->next = NULL;

        graph->nodes[graph->nodeCount] = newNode;
        graph->nodeCount++;
        printf("Node '%s' added with ID %d.\n", name, newNode->id);
    } else {
        printf("Maximum node limit reached!\n");
    }
}

void addEdge(Graph* graph, int sourceId, int destId) {
    if (sourceId >= 0 && sourceId < graph->nodeCount && destId >= 0 && destId < graph->nodeCount) {
        graph->adjacencyMatrix[sourceId][destId] = 1;
        graph->adjacencyMatrix[destId][sourceId] = 1; // Undirected graph
        printf("Edge added between node %d and node %d.\n", sourceId, destId);
    } else {
        printf("Invalid node IDs!\n");
    }
}

void displayGraph(Graph* graph) {
    for (int i = 0; i < graph->nodeCount; i++) {
        printf("Node %d (%s): ", graph->nodes[i]->id, graph->nodes[i]->name);
        for (int j = 0; j < graph->nodeCount; j++) {
            if (graph->adjacencyMatrix[i][j]) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

void vibrateScreen() {
    printf("Vibrating the screen like a tech-haunted memory...\n");
    for (int i = 0; i < 5; i++) {
        printf("\033[5m"); // Blink effect
        printf("...Loading...\n");
        printf("\033[0m"); // Reset 
        usleep(500000); // Sleep for 0.5 seconds
    }
}

void displayMenu() {
    printf("\033[1;32m"); // Green text
    printf("==== Cyberpunk Network Management ====\n");
    printf("1. Add Node\n");
    printf("2. Add Edge\n");
    printf("3. Display Graph\n");
    printf("4. Exit\n");
    printf("=======================================\n");
    printf("\033[0m"); // Reset text color
}

void clearScreen() {
    printf("\033[H\033[J"); // ANSI escape codes to clear the screen
}