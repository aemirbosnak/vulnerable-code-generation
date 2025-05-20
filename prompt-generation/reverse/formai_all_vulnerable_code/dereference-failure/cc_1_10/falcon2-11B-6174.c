//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure
typedef struct node
{
    int data;
    struct node* next;
} Node;

// Graph structure
typedef struct graph
{
    Node* head;
    int vertices;
} Graph;

// Function to create a new graph
Graph* createGraph(int vertices)
{
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->vertices = vertices;
    g->head = NULL;
    return g;
}

// Function to add a node to the graph
void addNode(Graph* g, int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (g->head == NULL)
    {
        g->head = newNode;
    }
    else
    {
        Node* currNode = g->head;
        while (currNode->next!= NULL)
        {
            currNode = currNode->next;
        }
        currNode->next = newNode;
    }
    g->vertices++;
}

// Function to print the graph
void printGraph(Graph* g)
{
    Node* currNode = g->head;
    while (currNode!= NULL)
    {
        printf("%d ", currNode->data);
        currNode = currNode->next;
    }
    printf("\n");
}

int main()
{
    Graph* g = createGraph(4);
    addNode(g, 1);
    addNode(g, 2);
    addNode(g, 3);
    addNode(g, 4);
    printGraph(g);

    return 0;
}