//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Node {
    char name[50];
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node** adjLists;
} Graph;

// Function prototypes
Graph* createGraph(int vertices);
Node* createNode(const char* name);
void addEdge(Graph* graph, int src, const char* dest);
void printGraph(Graph* graph);
void freeGraph(Graph* graph);
void visualizeGraph(Graph* graph);

int main() {
    int vertices = 5;
    Graph* graph = createGraph(vertices);

    addEdge(graph, 0, "Alice");
    addEdge(graph, 0, "Bob");
    addEdge(graph, 1, "Charlie");
    addEdge(graph, 1, "David");
    addEdge(graph, 2, "Edward");
    addEdge(graph, 3, "Frank");
    addEdge(graph, 3, "Alice");

    printf("Graph adjacency list:\n");
    printGraph(graph);

    printf("\nVisualizing the graph:\n");
    visualizeGraph(graph);

    freeGraph(graph);

    return 0;
}

Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(Node*));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

Node* createNode(const char* name) {
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    return newNode;
}

void addEdge(Graph* graph, int src, const char* dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjLists[i];
        printf("\nVertex %d:\n", i);
        while (temp) {
            printf(" -> %s", temp->name);
            temp = temp->next;
        }
        printf("\n");
    }
}

void visualizeGraph(Graph* graph) {
    printf("------ Graph Visualization ------\n");
    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjLists[i];
        printf("Vertex %d connects to:", i);
        while (temp) {
            printf(" %s", temp->name);
            temp = temp->next;
        }
        printf("\n");
    }
    printf("-------------------------------\n");
}

void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjLists[i];
        while (temp) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph->adjLists);
    free(graph);
}