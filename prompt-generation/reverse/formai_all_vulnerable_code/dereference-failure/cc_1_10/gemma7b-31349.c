//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_Vertices 100

typedef struct Edge
{
    int src, dest;
    struct Edge* next;
} Edge;

void topologicalSort(Edge* graph)
{
    int nVertices = graph->src + 1;
    int inDegree[nVertices];
    int outDegree[nVertices];
    int visited[nVertices];
    int stack[nVertices];
    int top = -1;

    for (Edge* edge = graph; edge; edge = edge->next)
    {
        inDegree[edge->src]++;
        outDegree[edge->dest]++;
    }

    for (int i = 0; i < nVertices; i++)
    {
        if (inDegree[i] == 0)
        {
            visited[i] = 1;
            stack[++top] = i;
        }
    }

    while (!top)
    {
        int current = stack[top--];
        for (Edge* edge = graph; edge; edge = edge->next)
        {
            if (edge->src == current)
            {
                inDegree[edge->dest]--;
                if (inDegree[edge->dest] == 0)
                {
                    visited[edge->dest] = 1;
                    stack[++top] = edge->dest;
                }
            }
        }
    }

    printf("The topological order is:");
    for (int i = 0; i < nVertices; i++)
    {
        if (visited[i] == 1)
        {
            printf("%d ", i);
        }
    }

    printf("\n");
}

int main()
{
    Edge* graph = NULL;
    graph = malloc(sizeof(Edge));
    graph->src = 0;
    graph->dest = 1;
    graph->next = malloc(sizeof(Edge));
    graph->next->src = 1;
    graph->next->dest = 2;
    graph->next->next = malloc(sizeof(Edge));
    graph->next->next->src = 2;
    graph->next->next->dest = 3;
    graph->next->next->next = NULL;

    topologicalSort(graph);

    return 0;
}