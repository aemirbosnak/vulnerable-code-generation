//FormAI DATASET v1.0 Category: Graph representation ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>

// struct to store graph information
typedef struct Edge
{
    int source;
    int destination;
    int weight;
}Edge;

// struct to store graph
typedef struct Graph
{
    int V;
    int E;
    Edge* edge;
}Graph;

// function to create graph
Graph* createGraph(int V, int E)
{
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (Edge*)malloc(E * sizeof(Edge));
    return graph;
}

// function to print graph information
void printGraph(Graph* graph)
{
    printf("Number of vertices: %d\n", graph->V);
    printf("Number of edges: %d\n", graph->E);
    printf("Edges:\n");
    for(int i = 0; i < graph->E; i++)
    {
        printf("(%d, %d, %d)\n", graph->edge[i].source, graph->edge[i].destination, graph->edge[i].weight);
    }
}

int main()
{
    int V = 4; // number of vertices
    int E = 5; // number of edges
    Graph* graph = createGraph(V, E); // create graph

    // add edges to the graph
    graph->edge[0].source = 0;
    graph->edge[0].destination = 1;
    graph->edge[0].weight = 10;

    graph->edge[1].source = 0;
    graph->edge[1].destination = 2;
    graph->edge[1].weight = 6;

    graph->edge[2].source = 0;
    graph->edge[2].destination = 3;
    graph->edge[2].weight = 5;

    graph->edge[3].source = 1;
    graph->edge[3].destination = 3;
    graph->edge[3].weight = 15;

    graph->edge[4].source = 2;
    graph->edge[4].destination = 3;
    graph->edge[4].weight = 4;

    // print graph
    printGraph(graph);
    return 0;
}