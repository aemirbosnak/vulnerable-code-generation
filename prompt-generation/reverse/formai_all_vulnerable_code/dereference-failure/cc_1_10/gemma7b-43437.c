//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct Vertex {
    int index;
    struct Vertex *next;
} Vertex;

void traverse(Vertex *vertex)
{
    printf("Vertex %d: ", vertex->index);
    Vertex *neighbor = vertex->next;
    while (neighbor)
    {
        printf("-> Neighbor %d ", neighbor->index);
        neighbor = neighbor->next;
    }
    printf("\n");
}

int main()
{
    Vertex *vertices[MAX_VERTICES];
    for (int i = 0; i < MAX_VERTICES; i++)
    {
        vertices[i] = NULL;
    }

    // Create a few vertices
    vertices[0] = malloc(sizeof(Vertex));
    vertices[0]->index = 0;

    vertices[1] = malloc(sizeof(Vertex));
    vertices[1]->index = 1;

    vertices[2] = malloc(sizeof(Vertex));
    vertices[2]->index = 2;

    vertices[3] = malloc(sizeof(Vertex));
    vertices[3]->index = 3;

    // Connect the vertices
    vertices[0]->next = vertices[1];
    vertices[1]->next = vertices[2];
    vertices[2]->next = vertices[3];

    // Traverse the network topology
    traverse(vertices[0]);

    return 0;
}