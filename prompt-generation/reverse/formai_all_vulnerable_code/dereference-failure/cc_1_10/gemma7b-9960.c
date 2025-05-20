//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct Node
{
    int index;
    struct Node* next;
} Node;

void createGraph(Node** graph, int numVertices)
{
    *graph = (Node*)malloc(numVertices * sizeof(Node));
    for (int i = 0; i < numVertices; i++)
    {
        (*graph)[i].index = i;
        (*graph)[i].next = NULL;
    }
}

void addEdge(Node* graph, int src, int dest)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->index = dest;
    newNode->next = graph[src].next;
    graph[src].next = newNode;
}

void displayGraph(Node* graph)
{
    for (int i = 0; i < MAX_VERTICES; i++)
    {
        Node* current = graph[i].next;
        printf("%d ", graph[i].index);
        while (current)
        {
            printf("%d ", current->index);
            current = current->next;
        }
        printf("\n");
    }
}

int main()
{
    Node* graph;
    createGraph(&graph, 5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    displayGraph(graph);

    return 0;
}