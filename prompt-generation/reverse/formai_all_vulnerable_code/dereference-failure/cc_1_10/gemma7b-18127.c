//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 10

typedef struct Vertex
{
    int index;
    struct Vertex* next;
} Vertex;

void create_graph(Vertex** graph)
{
    *graph = (Vertex*)malloc(MAX_VERTICES * sizeof(Vertex));

    for (int i = 0; i < MAX_VERTICES; i++)
    {
        graph[i] = NULL;
    }
}

void add_vertex(Vertex** graph, int index)
{
    Vertex* new_vertex = (Vertex*)malloc(sizeof(Vertex));

    new_vertex->index = index;
    new_vertex->next = NULL;

    if (graph[index] == NULL)
    {
        graph[index] = new_vertex;
    }
    else
    {
        graph[index]->next = new_vertex;
    }
}

void display_graph(Vertex* graph)
{
    while (graph)
    {
        printf("%d ", graph->index);
        graph = graph->next;
    }
}

int main()
{
    Vertex** graph;
    create_graph(&graph);

    add_vertex(graph, 0);
    add_vertex(graph, 1);
    add_vertex(graph, 2);
    add_vertex(graph, 3);
    add_vertex(graph, 4);

    display_graph(graph[0]);

    return 0;
}