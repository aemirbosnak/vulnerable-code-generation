//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a graph as an adjacency list
struct AdjListNode {
    int dest;
    struct AdjListNode* next;
};

struct AdjList {
    struct AdjListNode* head;
};

// Structure to represent the graph
struct Graph {
    int V; // Number of vertices
    struct AdjList* array;
};

// Function to create a new adjacency list node
struct AdjListNode* newAdjListNode(int dest) {
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    // Create an array of adjacency lists
    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));

    // Initialize each adjacency list as empty by setting head pointer to NULL
    for (int i = 0; i < V; i++) {
        graph->array[i].head = NULL;
    }

    return graph;
}

// Function to add an edge to the graph (undirected)
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Since the graph is undirected, add an edge from dest to src also
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Function to print the graph
void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->V; v++) {
        struct AdjListNode* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl) {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

// Function to check if a graph is cyclic using DFS helper
int isCyclicUtil(struct Graph* graph, int v, int visited[], int parent) {
    visited[v] = 1;
    struct AdjListNode* pCrawl = graph->array[v].head;

    while (pCrawl != NULL) {
        if (!visited[pCrawl->dest]) {
            if (isCyclicUtil(graph, pCrawl->dest, visited, v))
                return 1;
        } else if (pCrawl->dest != parent) {
            return 1;
        }
        pCrawl = pCrawl->next;
    }
    return 0;
}

// Function to check if the graph contains a cycle
int isCyclic(struct Graph* graph) {
    int* visited = (int*)malloc(graph->V * sizeof(int));

    // Initialize all vertices as not visited
    for (int i = 0; i < graph->V; i++) {
        visited[i] = 0;
    }

    // Call the recursive helper function to detect cycle in different DFS trees
    for (int u = 0; u < graph->V; u++) {
        if (!visited[u]) {
            if (isCyclicUtil(graph, u, visited, -1)) {
                free(visited);
                return 1;
            }
        }
    }

    free(visited);
    return 0;
}

int main() {
    // Create the graph with 5 vertices
    struct Graph* graph = createGraph(5);

    // Adding edges to create a cycle
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 1, 3);
    addEdge(graph, 3, 4);

    // Print the graph
    printGraph(graph);

    // Check if the graph is cyclic
    if (isCyclic(graph))
        printf("Graph contains a cycle\n");
    else
        printf("Graph does not contain a cycle\n");

    // Free the allocated memory (not shown here for simplicity)
    // In a robust implementation, you would need to free every node of the adjacency lists and the graph itself.

    return 0;
}