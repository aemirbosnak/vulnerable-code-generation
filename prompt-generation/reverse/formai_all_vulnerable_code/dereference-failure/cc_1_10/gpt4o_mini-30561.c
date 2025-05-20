//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define MAX_NODES 50

typedef struct Node {
    char name[MAX_LENGTH];
    struct Node* next;
} Node;

typedef struct Graph {
    Node* adjList[MAX_NODES];
    int numNodes;
} Graph;

Graph* createGraph(int nodes) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numNodes = nodes;
    for (int i = 0; i < nodes; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

Node* createNode(const char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    return newNode;
}

void addEdge(Graph* graph, int src, int dest, const char* name) {
    Node* newNode = createNode(name);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // For undirected graph, also add edge from dest to src
    newNode = createNode(name);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numNodes; i++) {
        Node* temp = graph->adjList[i];
        printf("Node %d: ", i);
        while (temp) {
            printf("-> %s ", temp->name);
            temp = temp->next;
        }
        printf("\n");
    }
}

void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->numNodes; i++) {
        Node* temp = graph->adjList[i];
        while (temp) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph);
}

char* inputString(const char* prompt) {
    char* str = (char*)malloc(MAX_LENGTH);
    printf("%s", prompt);
    fgets(str, MAX_LENGTH, stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove newline character
    return str;
}

int main() {
    int nodes;
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &nodes);
    getchar(); // Consume the newline character left by scanf

    Graph* graph = createGraph(nodes);

    int edges;
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    getchar();

    for (int i = 0; i < edges; i++) {
        int src, dest;
        char* name = inputString("Enter edge name: ");
        printf("Enter source node (0 to %d): ", nodes - 1);
        scanf("%d", &src);
        getchar();
        printf("Enter destination node (0 to %d): ", nodes - 1);
        scanf("%d", &dest);
        getchar();
        addEdge(graph, src, dest, name);
        free(name);
    }

    printf("\nGraph representation:\n");
    printGraph(graph);
    
    freeGraph(graph);
    return 0;
}