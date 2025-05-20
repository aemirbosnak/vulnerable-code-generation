//FormAI DATASET v1.0 Category: Graph representation ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

typedef struct Edge
{
    int src;
    int dest;
    int weight;
} Edge;

typedef struct Graph
{
    int vertices;
    Edge* edges[MAX_VERTICES];
} Graph;

int main()
{
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->vertices = 6; // number of vertices in our example graph

    // edge data in our example graph
    Edge edgeData[] = {
        {0, 1, 5},
        {0, 2, 4},
        {1, 3, 6},
        {2, 3, 7},
        {3, 4, 8},
        {2, 4, 9},
        {4, 5, 3}
    };

    // adding edges to the graph
    for (int i = 0; i < sizeof(edgeData)/sizeof(Edge); i++)
    {
        Edge* edge = (Edge*) malloc(sizeof(Edge));
        edge->src = edgeData[i].src;
        edge->dest = edgeData[i].dest;
        edge->weight = edgeData[i].weight;

        graph->edges[edge->src] = edge;
    }

    // printing the adjacency matrix of the graph
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->vertices; i++)
    {
        for (int j = 0; j < graph->vertices; j++)
        {
            if (graph->edges[i] && graph->edges[i]->dest == j)
            {
                printf("%d ", graph->edges[i]->weight);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }

    // freeing memory
    for (int i = 0; i < sizeof(edgeData)/sizeof(Edge); i++)
    {
        free(graph->edges[i]);
    }
    free(graph);

    return 0;
}