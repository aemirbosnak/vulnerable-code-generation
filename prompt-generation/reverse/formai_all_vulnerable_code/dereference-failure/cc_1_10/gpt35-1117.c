//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <omp.h>

struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
};

struct Node* createNode(int, int);
struct Graph* createGraph(int);
void addEdge(struct Graph*, int, int, int);
void printGraph(struct Graph*);
void dijkstra(struct Graph*, int);

int main() {
    int numVertices, sourceVertex;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);
    struct Graph* graph = createGraph(numVertices);
    printf("Enter the source vertex: ");
    scanf("%d", &sourceVertex);
    addEdge(graph, 0, 1, 5);
    addEdge(graph, 0, 2, 2);
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 1, 3, 3);
    addEdge(graph, 2, 3, 2);
    addEdge(graph, 2, 4, 4);
    addEdge(graph, 3, 4, 1);

    printf("\nAdjacency list of the given graph:\n");
    printGraph(graph);

    printf("\nShortest path from vertex %d:\n", sourceVertex);
    dijkstra(graph, sourceVertex);

    return 0;
}

/* creates a new node with the given vertex and weight */
struct Node* createNode(int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

/* creates a graph with the given number of vertices */
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));

    int i;
    for (i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

/* adds an edge between the given source and destination vertices with the given weight */
void addEdge(struct Graph* graph, int src, int dest, int weight) {
    struct Node* newNode = createNode(dest, weight);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src, weight);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

/* prints the adjacency list of the given graph */
void printGraph(struct Graph* graph) {
    int v;
    for (v = 0; v < graph->numVertices; v++) {
        struct Node* temp = graph->adjLists[v];
        printf("\nVertex %d: ", v);
        while (temp) {
            printf("%d (%d) -> ", temp->vertex, temp->weight);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

/* finds the shortest path from the given source node to all other nodes in the graph */
void dijkstra(struct Graph* graph, int sourceVertex) {
    int i, j, u, v, w, temp, current;
    int* distance = (int*)malloc(graph->numVertices * sizeof(int));
    bool* selected = (bool*)malloc(graph->numVertices * sizeof(bool));
    // initialize distance and selected arrays
    for (i = 0; i < graph->numVertices; i++) {
        distance[i] = INT_MAX;
        selected[i] = false;
    }
    // set distance of source vertex to 0
    distance[sourceVertex] = 0;

    // relaxation loop
    for (i = 0; i < graph->numVertices - 1; i++) {
        // find the node with the minimum distance that is not yet selected
        #pragma omp parallel for private(temp, current, j)
        for (j = 0; j < graph->numVertices; j++) {
            if (!selected[j] && (temp == -1 || distance[j] < distance[temp])) {
                temp = j;
            }
        }
        current = temp;
        selected[current] = true;
        struct Node* tempNode = graph->adjLists[current];
        // relax edges going out from the current node
        while (tempNode != NULL) {
            v = tempNode->vertex;
            w = tempNode->weight;
            if (distance[current] != INT_MAX && distance[current] + w < distance[v]) {
                distance[v] = distance[current] + w;
            }
            tempNode = tempNode->next;
        }
    }
    // print the distances
    for (i = 0; i < graph->numVertices; i++) {
        printf("Vertex %d: Distance to source = %d\n", i, distance[i]);
    }
}