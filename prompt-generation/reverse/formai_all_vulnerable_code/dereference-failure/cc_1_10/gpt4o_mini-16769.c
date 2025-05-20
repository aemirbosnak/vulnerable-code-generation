//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a node in the adjacency list
struct Node {
    int dest;
    struct Node* next;
};

// Define a structure to represent an adjacency list
struct AdjList {
    struct Node* head; // pointer to head node of list
};

// Define a structure to represent a graph
struct Graph {
    int V; // Number of vertices
    struct AdjList* array; // Array of adjacency lists
};

// Function to create a new adjacency list node
struct Node* newNode(int dest) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->dest = dest;
    new_node->next = NULL;
    return new_node;
}

// Function to create a graph of V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    // Create an array of adjacency lists. Size of array will be V
    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));

    // Initialize each adjacency list as empty by making head as NULL
    for (int v = 0; v < V; v++) {
        graph->array[v].head = NULL;
    }

    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest. A new node is added to the adjacency list
    struct Node* new_node = newNode(dest);
    new_node->next = graph->array[src].head;
    graph->array[src].head = new_node;

    // As it’s an undirected graph, add an edge from dest to src also
    new_node = newNode(src);
    new_node->next = graph->array[dest].head;
    graph->array[dest].head = new_node;

    printf("✨ Edge added between %d and %d! 🚀\n", src, dest);
}

// Function to print the graph
void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->V; v++) {
        struct Node* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl) {
            printf("-> %d ", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

// Main function to test the above functions
int main() {
    // Create a graph
    int V = 5; // Number of vertices
    struct Graph* graph = createGraph(V);

    // Adding edges
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Print the graph
    printf("🎉 Let's visualize our magical graph! 🎉\n");
    printGraph(graph);

    // Free up memory (don't forget this step!)
    for (int v = 0; v < graph->V; v++) {
        struct Node* temp = graph->array[v].head;
        while (temp) {
            struct Node* to_free = temp;
            temp = temp->next;
            free(to_free);
        }
    }
    free(graph->array);
    free(graph);

    printf("\n🌟 Love coding graphs! Until next time! 🌟\n");

    return 0;
}