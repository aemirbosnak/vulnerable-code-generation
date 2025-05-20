//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100

typedef struct Node {
    char name[30];
    int value;
    struct Node* next;
} Node;

typedef struct Graph {
    int numNodes;
    Node* adjacencyList[MAX_NODES];
} Graph;

// Function prototypes
Graph* createGraph();
void addNode(Graph* graph, const char* name, int value);
void addEdge(Graph* graph, const char* srcName, const char* destName);
void printGraph(Graph* graph);
void visualizeGraph(Graph* graph);
void freeGraph(Graph* graph);

// Create a new graph
Graph* createGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numNodes = 0;
    for (int i = 0; i < MAX_NODES; i++) {
        graph->adjacencyList[i] = NULL;
    }
    return graph;
}

// Add a node to the graph
void addNode(Graph* graph, const char* name, int value) {
    if (graph->numNodes >= MAX_NODES) {
        printf("Cannot add more nodes, graph is full.\n");
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->value = value;
    newNode->next = NULL;
    graph->adjacencyList[graph->numNodes++] = newNode;
}

// Add an edge between two nodes
void addEdge(Graph* graph, const char* srcName, const char* destName) {
    Node* srcNode = NULL;
    Node* destNode = NULL;

    for (int i = 0; i < graph->numNodes; i++) {
        if (strcmp(graph->adjacencyList[i]->name, srcName) == 0) {
            srcNode = graph->adjacencyList[i];
        }
        if (strcmp(graph->adjacencyList[i]->name, destName) == 0) {
            destNode = graph->adjacencyList[i];
        }
    }

    if (srcNode && destNode) {
        Node* newEdgeNode = (Node*)malloc(sizeof(Node));
        strcpy(newEdgeNode->name, destName);
        newEdgeNode->value = destNode->value;
        newEdgeNode->next = srcNode->next;
        srcNode->next = newEdgeNode;
    } else {
        printf("One or both nodes not found.\n");
    }
}

// Print the graph
void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numNodes; i++) {
        Node* current = graph->adjacencyList[i];
        printf("%s(%d):", current->name, current->value);
        current = current->next;
        while (current != NULL) {
            printf(" -> %s(%d)", current->name, current->value);
            current = current->next;
        }
        printf("\n");
    }
}

// Visualize the graph using Graphviz dot format
void visualizeGraph(Graph* graph) {
    FILE *f = fopen("graph.dot", "w");
    if (f == NULL) {
        fprintf(stderr, "Could not open file graph.dot for writing.\n");
        return;
    }

    fprintf(f, "digraph G {\n");

    for (int i = 0; i < graph->numNodes; i++) {
        Node* current = graph->adjacencyList[i];
        while (current != NULL && current->next != NULL) {
            fprintf(f, "  \"%s\" -> \"%s\";\n", current->name, current->next->name);
            current = current->next;
        }
    }

    fprintf(f, "}\n");
    fclose(f);
    printf("Graph has been visualized in graph.dot. Use 'dot graph.dot -Tpng -o graph.png' to create an image.\n");
}

// Free the graph
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

int main() {
    Graph* graph = createGraph();

    addNode(graph, "NodeA", 1);
    addNode(graph, "NodeB", 2);
    addNode(graph, "NodeC", 3);
    addNode(graph, "NodeD", 4);

    addEdge(graph, "NodeA", "NodeB");
    addEdge(graph, "NodeA", "NodeC");
    addEdge(graph, "NodeB", "NodeD");
    addEdge(graph, "NodeC", "NodeD");

    printGraph(graph);
    visualizeGraph(graph);
    freeGraph(graph);

    return 0;
}