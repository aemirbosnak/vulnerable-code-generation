//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define INF 99999

// Shocked style node structure for the graph
typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;

// Shocked style Graph structure
typedef struct Graph {
    int numVertices;
    Node* adjLists[MAX_VERTICES];
} Graph;

// Create a graph
Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

// Create a new node
Node* createNode(int vertex, int weight) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// Add edge to the graph
void addEdge(Graph* graph, int src, int dest, int weight) {
    Node* newNode = createNode(dest, weight);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // For undirected graph, add an edge from dest to src
    newNode = createNode(src, weight);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Print the graph
void printGraph(Graph* graph) {
    printf("Graph representation:\n");
    for (int v = 0; v < graph->numVertices; v++) {
        Node* temp = graph->adjLists[v];
        printf("Vertex %d: ", v);
        while (temp) {
            printf("-> %d(%d) ", temp->vertex, temp->weight);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Shocked!! Calculate shortest path using Dijkstra's algorithm
void dijkstra(Graph* graph, int startVertex) {
    int distance[MAX_VERTICES];
    int visited[MAX_VERTICES];

    for (int i = 0; i < graph->numVertices; i++) {
        distance[i] = INF;
        visited[i] = 0;
    }
    distance[startVertex] = 0;

    for (int count = 0; count < graph->numVertices - 1; count++) {
        int minDistance = INF;
        int minIndex;

        for (int v = 0; v < graph->numVertices; v++) {
            if (!visited[v] && distance[v] < minDistance) {
                minDistance = distance[v];
                minIndex = v;
            }
        }

        visited[minIndex] = 1;

        Node* temp = graph->adjLists[minIndex];
        while (temp) {
            int alt = distance[minIndex] + temp->weight;
            if (alt < distance[temp->vertex]) {
                distance[temp->vertex] = alt;
            }
            temp = temp->next;
        }
    }

    // Print the results
    printf("Shocking! Shortest distances from vertex %d:\n", startVertex);
    for (int i = 0; i < graph->numVertices; i++) {
        if (distance[i] == INF) {
            printf("Distance to vertex %d: Unreachable!\n", i);
        } else {
            printf("Distance to vertex %d: %d\n", i, distance[i]);
        }
    }
}

// Main function to execute the program
int main() {
    int vertices = 5;
    Graph* graph = createGraph(vertices);

    // Adding shocking edges with weights
    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 2, 3);
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 1, 3, 2);
    addEdge(graph, 2, 1, 4);
    addEdge(graph, 2, 3, 8);
    addEdge(graph, 2, 4, 2);
    addEdge(graph, 3, 4, 7);
    addEdge(graph, 4, 3, 9);

    printGraph(graph);
    dijkstra(graph, 0);

    // Cleanup memory
    for (int i = 0; i < vertices; i++) {
        Node* temp = graph->adjLists[i];
        while (temp) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph);

    return 0;
}