//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

// A linked list node
struct Node {
    int data;
    struct Node* next;
};

// A graph is an array of adjacency lists.
// Size of the array will be V (number of vertices in graph)
struct Graph {
    int V;
    struct Node** adjLists;
};

// A utility function to create a new adjacency list node
struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// A utility function to create a new Graph
struct Graph* createGraph(int V)
{
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    
    // Create an array of adjacency lists.  Size of the array will be V
    graph->adjLists = (struct Node**)malloc(V * sizeof(struct Node*));
   
    // Initialize each adjacency list as empty by making head as NULL
    for (int i = 0; i < V; ++i)
        graph->adjLists[i] = NULL;
    
    return graph;
}

// Adds an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest)
{
    // Add an edge from src to dest.  A new node is added to the adjacency
    // list of src.  The node is added at the beginning
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Since graph is undirected, add an edge from dest to src also
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// A utility function to print the adjacency list representation of graph
void printGraph(struct Graph* graph)
{
    for (int v = 0; v < graph->V; ++v)
    {
        struct Node* temp = graph->adjLists[v];
        printf("\n Adjacency list of vertex %d\n", v);
        while (temp) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Driver program to test above functions
int main()
{
    // Create a graph with 5 vertices
    struct Graph* graph = createGraph(5);

    // add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    
    // print the adjacency list representation of the graph
    printGraph(graph);
    
    return 0;
}