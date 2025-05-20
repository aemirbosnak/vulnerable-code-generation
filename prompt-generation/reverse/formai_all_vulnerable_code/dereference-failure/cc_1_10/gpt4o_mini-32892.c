//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node* adjLists[MAX_VERTICES];
} Graph;

Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = malloc(sizeof(Node));
    newNode->vertex = src;
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void printGraph(Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        Node* temp = graph->adjLists[v];
        printf("Vertex %d: ", v);
        while (temp) {
            printf("-> %d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

void greedyColoring(Graph* graph) {
    int result[MAX_VERTICES];
    for (int i = 0; i < graph->numVertices; i++) {
        result[i] = -1; // No color assigned
    }

    result[0] = 0; // Assign first color to first vertex

    for (int u = 1; u < graph->numVertices; u++) {
        // Track available colors
        int availableColors[MAX_VERTICES] = {0};

        Node* temp = graph->adjLists[u];
        while (temp) {
            if (result[temp->vertex] != -1) {
                availableColors[result[temp->vertex]] = 1;
            }
            temp = temp->next;
        }

        int cr;
        for (cr = 0; cr < graph->numVertices; cr++) {
            if (!availableColors[cr]) {
                break; // Find the first available color
            }
        }
        result[u] = cr; // Assign the found color
    }

    // Print the result
    for (int u = 0; u < graph->numVertices; u++) {
        printf("Vertex %d ---> Color %d\n", u, result[u]);
    }
}

void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjLists[i];
        while (temp != NULL) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph);
}

int main() {
    int numVertices, numEdges, src, dest;
    printf("Enter number of vertices: ");
    scanf("%d", &numVertices);
    Graph* graph = createGraph(numVertices);

    printf("Enter number of edges: ");
    scanf("%d", &numEdges);
    printf("Enter edges (src dest):\n");
    for (int i = 0; i < numEdges; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printf("\nGraph adjacency list:\n");
    printGraph(graph);

    printf("\nGraph coloring:\n");
    greedyColoring(graph);

    freeGraph(graph);
    return 0;
}