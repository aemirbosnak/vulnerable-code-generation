//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(1)

typedef struct Node {
    char name[20];
    struct Node* next;
} Node;

typedef struct Graph {
    Node** graph;
    int size;
} Graph;

Graph* createGraph(int size)
{
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->graph = (Node**)malloc(size * sizeof(Node));
    g->size = size;

    return g;
}

void insertNode(Graph* g, char* name)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (g->size == 0)
    {
        g->graph[0] = newNode;
    }
    else
    {
        g->graph[g->size - 1]->next = newNode;
        g->size++;
    }
}

void traverseGraph(Graph* g)
{
    for (int i = 0; i < g->size; i++)
    {
        printf("%s ", g->graph[i]->name);
    }
    printf("\n");
}

int main()
{
    Graph* g = createGraph(5);
    insertNode(g, "John");
    insertNode(g, "Mary");
    insertNode(g, "Bob");
    insertNode(g, "Alice");
    insertNode(g, "Tom");

    traverseGraph(g);

    return 0;
}