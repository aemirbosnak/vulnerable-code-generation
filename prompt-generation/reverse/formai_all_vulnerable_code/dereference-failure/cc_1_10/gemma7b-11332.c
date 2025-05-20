//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 10

typedef struct Vertex
{
    char name[MAX_VERTICES];
    int degree;
    struct Edge *edges;
} Vertex;

typedef struct Edge
{
    Vertex *source;
    Vertex *destination;
    struct Edge *next;
} Edge;

void createVertex(Vertex **vertex, char name)
{
    *vertex = (Vertex *)malloc(sizeof(Vertex));
    (*vertex)->name[0] = name;
    (*vertex)->degree = 0;
    (*vertex)->edges = NULL;
}

void createEdge(Edge **edge, Vertex *source, Vertex *destination)
{
    *edge = (Edge *)malloc(sizeof(Edge));
    (*edge)->source = source;
    (*edge)->destination = destination;
    (*edge)->next = NULL;
}

void addEdge(Vertex *vertex, Vertex *destination)
{
    Edge *edge = (Edge *)malloc(sizeof(Edge));
    createEdge(&edge, vertex, destination);
    vertex->degree++;
    vertex->edges = edge;
}

void displayVertex(Vertex *vertex)
{
    printf("Vertex: %s, Degree: %d\n", vertex->name, vertex->degree);
    Edge *edge = vertex->edges;
    printf("Edges:");
    while (edge)
    {
        printf(" %s", edge->destination->name);
        edge = edge->next;
    }
    printf("\n");
}

int main()
{
    Vertex **vertices = (Vertex *)malloc(MAX_VERTICES * sizeof(Vertex));
    for (int i = 0; i < MAX_VERTICES; i++)
    {
        createVertex(&vertices[i], 'A' + i);
    }

    addEdge(vertices[0], vertices[1]);
    addEdge(vertices[0], vertices[2]);
    addEdge(vertices[1], vertices[2]);
    addEdge(vertices[2], vertices[3]);

    displayVertex(vertices[0]);
    displayVertex(vertices[1]);
    displayVertex(vertices[2]);
    displayVertex(vertices[3]);

    return 0;
}