//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100

typedef struct Node {
    int id;
    char name[50];
    struct Node* next;
} Node;

typedef struct Graph {
    int numNodes;
    Node* adjacencyList[MAX_NODES];
} Graph;

Graph* createGraph(int numNodes);
void addEdge(Graph* graph, int src, int dest);
void printGraph(Graph* graph);
void visualizeGraph(Graph* graph);
void freeGraph(Graph* graph);

int main() {
    int numNodes = 5;
    Graph* graph = createGraph(numNodes);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    
    printGraph(graph);
    visualizeGraph(graph);
    freeGraph(graph);
    
    return 0;
}

Graph* createGraph(int numNodes) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numNodes = numNodes;

    for (int i = 0; i < numNodes; i++) {
        graph->adjacencyList[i] = NULL;
    }

    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->id = dest;
    snprintf(newNode->name, sizeof(newNode->name), "Node %d", dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;
}

void printGraph(Graph* graph) {
    printf("Graph adjacency list:\n");
    for (int i = 0; i < graph->numNodes; i++) {
        Node* temp = graph->adjacencyList[i];
        printf("Node %d:", i);
        while (temp) {
            printf(" -> %s", temp->name);
            temp = temp->next;
        }
        printf("\n");
    }
}

void visualizeGraph(Graph* graph) {
    FILE* file = fopen("graph.dot", "w");
    if (!file) {
        fprintf(stderr, "Failed to create graph visualization file.\n");
        return;
    }
    
    fprintf(file, "digraph G {\n");
    
    for (int i = 0; i < graph->numNodes; i++) {
        Node* temp = graph->adjacencyList[i];
        while (temp) {
            fprintf(file, "    Node%d -> Node%d;\n", i, temp->id);
            temp = temp->next;
        }
    }
    
    fprintf(file, "}\n");
    fclose(file);

    system("dot -Tpng graph.dot -o graph.png");
    printf("Graph visualization saved as graph.png\n");
}

void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->numNodes; i++) {
        Node* temp = graph->adjacencyList[i];
        while (temp) {
            Node* toDelete = temp;
            temp = temp->next;
            free(toDelete);
        }
    }
    free(graph);
}