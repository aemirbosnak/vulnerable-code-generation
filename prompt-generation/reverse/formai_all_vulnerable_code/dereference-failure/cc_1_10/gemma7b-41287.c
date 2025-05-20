//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 50

typedef struct Vertex
{
    int index;
    struct Vertex* next;
    struct Vertex* prev;
    int color;
} Vertex;

Vertex* createVertex(int index)
{
    Vertex* vertex = (Vertex*)malloc(sizeof(Vertex));
    vertex->index = index;
    vertex->next = NULL;
    vertex->prev = NULL;
    vertex->color = -1;
    return vertex;
}

void addEdge(Vertex* u, Vertex* v)
{
    u->next = v;
    v->prev = u;
}

void graphColoring(Vertex* v)
{
    if (v == NULL)
    {
        return;
    }

    if (v->color != -1)
    {
        return;
    }

    int availableColors = 0;
    for (int i = 0; i < MAX_VERTICES; i++)
    {
        if (v->prev == NULL || v->prev->color != i)
        {
            availableColors++;
        }
    }

    v->color = availableColors % MAX_VERTICES;

    graphColoring(v->next);
}

int main()
{
    Vertex* graph = createVertex(0);
    addEdge(graph, createVertex(1));
    addEdge(graph, createVertex(2));
    addEdge(graph, createVertex(3));
    addEdge(graph, createVertex(4));

    graphColoring(graph);

    for (Vertex* v = graph; v; v = v->next)
    {
        printf("Vertex %d has color %d\n", v->index, v->color);
    }

    return 0;
}