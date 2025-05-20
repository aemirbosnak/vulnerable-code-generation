//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a node in a graph
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define a structure to represent a graph
typedef struct Graph {
    int numVertices;
    Node** adjacencyList;
} Graph;

// Function to insert a node into a graph
void insertNode(Graph* graph, int data)
{
    // Allocate memory for the new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    // If the graph is empty, create the first node
    if (graph->numVertices == 0)
    {
        graph->adjacencyList = (Node**)malloc(sizeof(Node*) * graph->numVertices);
        graph->adjacencyList[0] = newNode;
    }
    // Otherwise, insert the node into the adjacency list
    else
    {
        graph->adjacencyList[graph->numVertices] = newNode;
        graph->numVertices++;
    }
}

// Function to print the nodes of a graph
void printNodes(Graph* graph)
{
    for (int i = 0; i < graph->numVertices; i++)
    {
        Node* node = graph->adjacencyList[i];
        while (node)
        {
            printf("%d ", node->data);
            node = node->next;
        }
        printf("\n");
    }
}

int main()
{
    // Create a graph
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = 0;
    graph->adjacencyList = NULL;

    // Insert nodes into the graph
    insertNode(graph, 10);
    insertNode(graph, 20);
    insertNode(graph, 30);
    insertNode(graph, 40);

    // Print the nodes of the graph
    printNodes(graph);

    return 0;
}