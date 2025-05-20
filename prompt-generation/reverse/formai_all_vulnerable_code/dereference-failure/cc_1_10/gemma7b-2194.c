//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 10

typedef struct Vertex
{
    int index;
    struct Vertex* next;
} Vertex;

void traverse(Vertex* v)
{
    printf("Vertex %d: ", v->index);
    Vertex* w = v->next;
    while (w)
    {
        printf("-> Vertex %d ", w->index);
        w = w->next;
    }
    printf("\n");
}

int main()
{
    Vertex* graph[MAX_VERTICES] = {NULL};
    for (int i = 0; i < MAX_VERTICES; i++)
    {
        graph[i] = NULL;
    }

    graph[0] = malloc(sizeof(Vertex));
    graph[0]->index = 0;
    graph[0]->next = NULL;

    graph[1] = malloc(sizeof(Vertex));
    graph[1]->index = 1;
    graph[1]->next = graph[0];

    graph[2] = malloc(sizeof(Vertex));
    graph[2]->index = 2;
    graph[2]->next = graph[0];

    graph[3] = malloc(sizeof(Vertex));
    graph[3]->index = 3;
    graph[3]->next = graph[1];

    traverse(graph[0]);
    traverse(graph[2]);

    return 0;
}