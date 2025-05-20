//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100

typedef struct Node {
    int index;
    struct Node* next;
} Node;

void printTopology(Node* head)
{
    while (head)
    {
        printf("%d ", head->index);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    Node** graph = (Node**)malloc(MAX_VERTICES * sizeof(Node*));
    for (int i = 0; i < MAX_VERTICES; i++)
    {
        graph[i] = NULL;
    }

    // Create a few nodes
    Node* node1 = (Node*)malloc(sizeof(Node));
    node1->index = 1;
    graph[0] = node1;

    Node* node2 = (Node*)malloc(sizeof(Node));
    node2->index = 2;
    graph[1] = node2;

    Node* node3 = (Node*)malloc(sizeof(Node));
    node3->index = 3;
    graph[2] = node3;

    // Connect the nodes
    node1->next = node2;
    node2->next = node3;

    // Print the topology
    printTopology(graph[0]);

    return 0;
}