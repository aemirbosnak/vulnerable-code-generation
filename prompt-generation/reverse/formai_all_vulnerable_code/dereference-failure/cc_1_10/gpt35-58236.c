//FormAI DATASET v1.0 Category: Graph representation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

typedef struct edge
{
    int src, dest;
} Edge;

typedef struct graph
{
    Node **adjList;
    int numVertices;
} Graph;

Graph *createGraph(Edge edges[], int numEdges, int numVertices)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = numVertices;

    graph->adjList = (Node **)malloc(numVertices * sizeof(Node *));

    for (int i = 0; i < numVertices; i++)
        graph->adjList[i] = NULL;

    for (int i = 0; i < numEdges; i++)
    {
        int src = edges[i].src;
        int dest = edges[i].dest;

        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = dest;
        newNode->next = graph->adjList[src];

        graph->adjList[src] = newNode;

        newNode = (Node *)malloc(sizeof(Node));
        newNode->data = src;
        newNode->next = graph->adjList[dest];

        graph->adjList[dest] = newNode;
    }
    return graph;
}

void displayGraph(Graph *graph)
{
    for (int i = 0; i < graph->numVertices; i++)
    {
        Node *current = graph->adjList[i];
        printf("Node %d: ", i);
        while (current != NULL)
        {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main()
{
    Edge edges[] = {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {2, 4}, {3, 4}};
    int numVertices = 5;
    int numEdges = sizeof(edges) / sizeof(edges[0]);

    Graph *graph = createGraph(edges, numEdges, numVertices);
    displayGraph(graph);

    return 0;
}